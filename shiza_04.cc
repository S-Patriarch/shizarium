/*
 * Собирать этот загадочный код следует следующим образом:
 *    > clang++ shiza_04.cc -O1 -Wall
 * После успешной сборки, запускаем исполняемый файл и
 * получаем странный результат:
 *    > ./a.out
 *    Hello world!
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  for (;;);
}

void foo()
{
  cout
    << "Hello world!"
    << endl;
}
