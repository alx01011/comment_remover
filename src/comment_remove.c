#include <stdio.h>

typedef enum state {
    comment_cpp,
    comment_c_enter,
    comment_c_exit,
    comment_cpp_multi,
    comment_cpp_multi_enter,
    comment_decide,
    normal
}state_t;


state_t state_cpp(int c) {
    if (c == '\n') {
        return normal;
    } else if (c == '\\') {
       return comment_cpp_multi_enter;
    }
    return comment_cpp;
}

state_t state_cpp_multiline(int c) {
    if (c == '\n') {
        return comment_cpp_multi;
    } 
    return comment_cpp;
}

state_t state_cpp_multi(int c) {
    if (c == '\n') {
        return normal;
    }
    return comment_cpp_multi;
}

state_t state_c_exit_comment(int c) {
    if (c == '/') {
        return normal;
    }
    return comment_c_enter;
}

state_t state_c_enter_comment(int c) {
    if (c == '*') {
        return comment_c_exit;
    }
    return comment_c_enter;
}

state_t state_decide(int c) {
    if (c == '/') {
        return comment_cpp;
    } else if (c == '*') {
        return comment_c_enter;
    } 
    // just a regular / within the code
    putchar('/');
    putchar(c);
    return normal;
}

state_t state_normal(int c) {
    if (c == '/') {
        return comment_decide;
    }
    putchar(c);
    return normal;
}


state_t (*state[])(int) = {
    state_cpp, // match the order of enum
    state_c_enter_comment,
    state_c_exit_comment,
    state_cpp_multiline,
    state_cpp_multi,
    state_decide,
    state_normal
};


int main(void) {
    state_t s = normal;
    int c;

    while ((c = getchar()) != EOF) {
        s = state[s](c);
    }
    putchar('\n');


    return 0;
}