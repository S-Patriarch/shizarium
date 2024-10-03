/*
 * Что будет если для беззнаковой переменной равной 0 сделать декремент?
 * Ответ: 4294967295.
 *
 * Если сделать декремент (--) для беззнаковой переменной, значение которой
 * равно 0, это приведет к переполнению, и переменная примет максимальное
 * значение, которое может быть представлено этим типом.
 * Для беззнаковой переменной unsigned int диапазон значений от 0 до
 * 4292967295 (для 32-битной реализации).
 * Когда переменная x равна 0 и выполняется --x, происходит следующее:
 * - значение 0 уменьшается на 1
 * - поскольку unsigned int не может представлять отрицательные значения,
 *   происходит переполнение
 * - переполнение для беззнакового типа приводит к "оборачиванию" значения
 *   через максимальное значение типа
 * - максимальное значение для unsigned int (при 32-битной реализации)
 *   равно 4292967295
 * Таким образом, после выполнения --x, значение x становится 4292967295.
 */

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned int x{0};
  cout
    << "x before decrement: "
    << x
    << endl;

  --x;

  cout
    << "x after decrement:  "
    << x
    << endl;

  std::exit(0);
}