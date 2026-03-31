/*
   В С можно объявить struct прямо в возвращаемом типе функции.
   Это полностью валидный С. Определение struct и объявление
   функции происходят одновременно.
*/

#include <stdlib.h>
#include <stdio.h>

struct foo_s { int a, b, c; } make_foo(void) 
{
        struct foo_s ret = { .c = 3 };

        ret.a = 11 + ret.c;
        ret.b = ret.a * 3;

        return(ret);
}

int
main(void) 
{
        struct foo_s f = make_foo();

        printf("a=%d, b=%d, c=%d\n", f.a, f.b, f.c);
        exit(0);
}

