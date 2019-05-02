#include <stdlib.h>

#define TOGGLE \
    char state; \
    char (*value)(struct Toggle *); \
    struct Toggle *(*activate)(struct Toggle *)

#define DESTROY free

typedef struct Toggle {
    TOGGLE;
} Toggle;

enum {false, true};

typedef struct NthToggle {
    Toggle base;
    int count_max;
    int counter;
} NthToggle;

int objinst(int length, NthToggle *ntog);
NthToggle *new_NthToggle(char start_state, int max_count);