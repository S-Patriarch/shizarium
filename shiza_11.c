#include <stdio.h>

struct object {
        int  x;
        int  y;
};

typedef struct object object;

object *mkobj(void) 
{
        static object z;

        object f(void) { object z = {.x=5, .y=2}; return z; }

        z = f();

        return &z, &z;
}

int main(void) 
{
        return mkobj() -> y;
}

