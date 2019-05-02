#include "objinst.h"

char toggle_value(Toggle *this) {
    return(this->state);
}
Toggle *toggle_activate(Toggle *this) {
    this->state = !this->state;
    return(this);
}
Toggle *init_Toggle(Toggle *this, char start_state) {
    this->state = start_state;
    this->value = toggle_value;
    this->activate = toggle_activate;
    return(this);
}
Toggle *new_Toggle(char start_state) {
    Toggle *this = (Toggle *)malloc(sizeof(Toggle));
    return(init_Toggle(this, start_state));
}

NthToggle *nth_toggle_activate(NthToggle *this) {
    if (++this->counter >= this->count_max) {
	this->base.state = !this->base.state;
	this->counter = 0;
    }
    return(this);
}
NthToggle *init_NthToggle(NthToggle *this, int max_count) {
    this->count_max = max_count;
    this->counter = 0;
    this->base.activate = (Toggle *(*)(Toggle *))nth_toggle_activate;
    return(this);
}
NthToggle *new_NthToggle(char start_state, int max_count) {
    NthToggle *this = (NthToggle *)malloc(sizeof(NthToggle));
    this = (NthToggle *)init_Toggle((Toggle *)this, start_state);
    return(init_NthToggle(this, max_count));
}

int main(int argc, char *argv[]) {
    // int length = 700;
    int i = 0;
    int length = 100;

    Toggle *tog;
    NthToggle *ntog;

    tog = new_Toggle(true);
    for (i=0; i<5; i++) {
	// puts((tog->activate(tog)->value(tog)) ? "true" : "false");
    }
    DESTROY(tog);
    for (i=0; i<length; i++) {
	tog = new_Toggle(true);
	DESTROY(tog);
    }

    // puts("");

    ntog = new_NthToggle(true, 3);
    for (i=0; i<8; i++) {
    	const char *Msg;
        if (ntog->base.activate((Toggle*)ntog)->value((Toggle*)ntog))
            Msg = "true";
        else
            Msg = "false";
        // puts(Msg);
    }
    DESTROY(ntog);

#pragma monitor start
    int *result = objinst(length, ntog);

#pragma monitor stop

    if(result[0] != 3 || result[1] != 0) {
        return 1;
    }

    return 10;
}
