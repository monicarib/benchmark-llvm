#include "chomp.h"

#define LENGTH 55


#pragma DATA_ALIGN(x, 8);  

int main(void)
{
    int i, nrow, TAM,
        resp[LENGTH],

// NORMAL
    saida[LENGTH] = {
                      0,2,2, // Jogada 1: jodador e posicao (x,y)
                      1,7,1, // Jogada 2
                      0,0,2, // Jogada 3
                      1,7,0, // Jogada 4
                      0,6,1, // Jogada 5
                      1,6,0, // Jogada 6
                      0,5,1, // Jogada 7
                      1,5,0, // Jogada 8
                      0,4,1, // Jogada 9
                      1,4,0, // Jogada 10
                      0,3,1, // Jogada 11
                      1,3,0, // Jogada 12
                      0,2,1, // Jogada 13
                      1,2,0, // Jogada 14
                      0,1,1, // Jogada 15
                      1,1,0, // Jogada 16
                      0,0,1, // Jogada 17
                      1,0,0, // Jogada 18
                      1      // Perdedor
                    };

    nrow = 8;
    TAM = LENGTH;
/*
// SMALL
    saida[LENGTH] = {
                      0,1,1, // Jogada 1: jodador e posicao (x,y)
                      1,6,0, // Jogada 2
                      0,0,6, // Jogada 3
                      1,5,0, // Jogada 4
                      0,0,5, // Jogada 5
                      1,4,0, // Jogada 6
                      0,0,4, // Jogada 7
                      1,3,0, // Jogada 8
                      0,0,3, // Jogada 9
                      1,2,0, // Jogada 10
                      0,0,2, // Jogada 11
                      1,1,0, // Jogada 12
                      0,0,1, // Jogada 13
                      1,0,0, // Jogada 14
                      1      // Perdedor
                    };

    nrow = 7;
    TAM = LENGTH-12;
*/

    #pragma monitor start
    chomp(nrow, resp);
    #pragma monitor stop

    for (i=0; i < TAM; i++) {
        // DEBUG
        //printf("Posicao %d: desejado [ %d ] vs. obtido [ %d ]\n", i, saida[i], resp[i]);

        if (resp[i] != saida[i]) {
           return 0;
        }
    }
    return 10;
}

