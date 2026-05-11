/* GCC позволяет запускать код еще до старта main().
   
   __attribute__((constructor)) помечает функцию, которая выполняется на этапе
   загрузки.
   __attribute((destructor)) выполняется после возврата из main().

   Числовой приоритет - это то, что делает механизм реально управляемым.
   Меньшее число выполняется раньше, поэтому если две библиотеки регистрируют
   конструкторы, функция с приоритетом 101 отработает до 102.
   glibc резервирует все ниже 100 под себя, туда лучше не лезть.

   Деструкторы работают в обратном порядке: большее число выполняется раньше
   при завершении, симметрия сделана специально.  */

#include <stdio.h>
#include <stdlib.h>

__attribute__((constructor(101)))
void
con_first(void) 
{
        printf("runs first constructor\n");
}

__attribute__((constructor(102)))
void
con_second(void) 
{
        printf("runs second constructor\n");
}

__attribute__((destructor(102)))
void
des_second(void) 
{
        printf("runs second destructor\n");
}

__attribute__((destructor(101)))
void
des_first(void) 
{
        printf("runs first destructor\n");
}

int
main(void) 
{
        printf("runs main\n");
        exit(0);
}

