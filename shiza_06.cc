/*
 * Вызываем функцию в глобальном пространстве.
 *
 * В отличие от С в С++ можно вызывать код до входа в main. В С нельзя вызывать
 * функции в глобальном пространстве, и глобальные переменные там должны быть
 * инициализированы констнантным выражением. Одноко, для С++ были ослаблены
 * правила. Это было нужно для возможности создания объектов кастомных классов,
 * как глобальных переменных. Для создания объектов нужны конструкторы, а это
 * обычные функции.
 *
 * Поэтому в С++ можно выполнять пользовательский код до main. Но этот код
 * должен содержаться внутри конструкторов и вызываемых ими функциях.
 * Но просто так вызвать функция нельзя. Это запрещено.
 * Со стандартом не договоришься.
 *
 * В данном коде пользуемся уникальными свойствами оператора запятая:
 * результат первого операнда вычисляется до вычисления второго и после просто
 * отбрасывается. А значение всего выражения задается вторым операндом.
 *
 * Получается, что здесь мы создаем статическую переменную-пустышку, чтобы
 * получить возможность оперировать в глобальном пространстве.
 * Инициализаторы глобальных переменных в С++ могут быть вычисляемыми.
 * Поэтому используется свойство оператора запятой, чтобы беспоследственно
 * вычислить foo_function, а инициализировать pacifier нулем.
 */

#include <iostream>

using std::cout;
using std::endl;

void foo_function()
{
  cout
    << "\nW: ... and vote and decision.\n"
    << endl;
}

static int pacifier
  =(foo_function(),0);

int main() {}
