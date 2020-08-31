struct cells {
       int f_free;
       int faulty;
       struct cells *next;
};

typedef struct cells misr_type;
        
int misr(int iterations, misr_type *present, double prob, char *structure, int reg_len);
