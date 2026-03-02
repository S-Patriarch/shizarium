/*
   Люди думают, что С это строгий язык.
   А С позволяет между делом вплести switch внутрь while, поломать
   пространство-время, и оно спокойно скомпилируется.
*/

#include <stdlib.h>
#include <stdio.h>

int
main(void) 
{
        int     i = 0;

        switch (i) {
        case 0:
                while (i < 3) {
                        printf("%d", i);
        case 1:
                        i++;
                }
        }

        exit(0);
}

