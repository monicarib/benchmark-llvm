typedef struct cells {
        int f_free;
	int faulty;
        struct cells *next;
        }misr_type;
        
int misr(int iterations, misr_type *present, double prob, char *structure);