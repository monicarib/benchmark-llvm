/*******************************************************************
create and initialize the MISR's which is a linked list of misr_type
*******************************************************************/
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "misr.h"

#define MAX_REG_LN 100
#define INF 10000

# define seed48(x) srand(x)

#pragma DATA_ALIGN(x, 8); 

/******************************************************************
release linked list when finished
******************************************************************/
void kill_list(misr_type *present)
{
        misr_type *temp;
 
        while (present != NULL) {
                temp = present->next;
                free(present);
                present = temp;
        }
}


/******************************************************************
make both MISR's identical to start the experiment
******************************************************************/
void init(misr_type *present)
{

	while (present->next != NULL) {
		present->faulty = present->f_free;
		present = present->next;
	}
}


/******************************************************************
create and initialize a list, returning its link
******************************************************************/
void create_link_list(misr_type **cell_array, int reg_len)
{
    *cell_array = (misr_type *) malloc(sizeof(misr_type));

    //memset(cell_array, 0, sizeof(*cell_array));
    (*cell_array)->f_free = 0;
    (*cell_array)->faulty = 0;
    (*cell_array)->next = NULL;

    int i;
    misr_type *temp, *present = *cell_array;
    for(i = 0; i < reg_len+1; i++) {
        temp = (misr_type *) malloc(sizeof(misr_type));
        temp->f_free = 1;
        temp->faulty = 1;
        temp->next = NULL;
        present->next = temp; 
        present = present->next;
    }
}


/******************************************************************
                          Main Program
******************************************************************/
int main() {

    misr_type * cell_array;

    int reg_len   = 10; // 3;
    int num_vect  = 10;
    int num_times = 100; // 30000;
    double prob   = 0.25;
    unsigned short seed[3] = { 1, 0, 0 };

    char structure[MAX_REG_LN];
    int i;
    structure[0] = '1';
    for (i = 1; i < reg_len; i++) structure[i] = '0';
    structure[reg_len] = 0;

    // initialize random f'n generator
    seed48((int)seed);

    #pragma monitor start

    // create MISRs of reg_len length
    create_link_list(&cell_array, reg_len);

    // simulate both circuits
    int num_true = 0; 
    if (num_vect != 0) {
        for (i = 0; i < num_times; i++) {
            init(cell_array);
            num_true += misr(num_vect, cell_array, prob, structure, reg_len);
        }
    }
    else {  // ie. infinite case
        init(cell_array); 
        misr(INF, cell_array, prob, structure, reg_len);
        for (i = 0; i < num_times; i++) {
            num_true += misr(1, cell_array, prob, structure, reg_len);
        }
    }

    #pragma monitor stop

    kill_list(cell_array);

    printf("%d\n", num_true); // Debug
	
    if (num_true < 99) { // num_true < 80 (num_times = 100 e reg_len = 3) // num_true < 99 (num_times = 100 e reg_len = 10) // num_true < 29965 (num_times = 30000 e reg_len = 10)
        return 1; // num_time; // Debug
    }
	
    return 10;
}
