/*
 * Собирать этот загадочный код следует следующим образом:
 *    > gcc shiza_05.cc -nostartfiles
 * После успешной сборки, запускаем исполняемый файл и
 * получаем странный результат:
 *    > ./a.out
 *    Hello world!
 */

#include <iostream>

using std::cout;
using std::endl;

int foo();

void _start()
{
  int x =foo();
  exit(x);
}

int foo()
{
  cout
    << "Hello world!"
    << endl;
  return 0;
}
