/*
 * -std=c++20
 * Магическое заклинание +[]{}
 *
 * Какой результат попытки компиляции и выполнения этого кода?
 * Ответ: программа успешно завершится.
 *
 * Лямбду можно записывать без списка параметров, это разрешенная тема.
 * Да и работает это в целом довольно энтуитивно: если лямда не принимает
 * параметров, то можно их не указывать и все будет работать также, как и с
 * пустыми круглыми скобками.
 * Здесь мы рассматриваем, что присвоение лямбд запрещено и приводит к ошибке
 * компиляции. Каким образом один + переворачивает все с ног на голову и код
 * работает?
 * Стандарт нам говорит, что лямбды без захваченных значений имеют возможность
 * прикидываться указателями на функции. И так вышло, что оператор+ определен
 * для всех типов указателей в виде: T* operator+(T*);
 * Он ничего не делает с указателем и просто его возвращает наружу.
 * Когда ставится + спереди лямбды, компилятор пытается найти подходящую
 * перегрузку для оператора+. Логично, что для любого замыкания он не
 * перегружен, поэтому он не нужен там. Но зато есть перегрузка для указателя,
 * под который может косить лямбда. Что она успешно и делает.
 * Поэтому здесь компилятор выведет тип указателя на функцию, а не замыкание.
 * И ничего нам не мешает перенаправлять этот указатель на другую функцию.
 */

#include <cstdlib>

int main()
{
  auto test = +[]{};
  test = []{};

  std::exit(0);
}
