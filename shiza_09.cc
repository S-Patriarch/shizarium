/*++

    Вывод строки в GNU/Linux с использованием
    ассемблерной вставки x86-64.

--*/

#include <cstdlib>

int main()
{
    const char *str {"Hello, World!\n"};
    long len {14};

    __asm__ volatile (
        "movq $1, %%rax\n"  // системный вызов write (1)
        "movq $1, %%rdi\n"  // файловый дескриптор (STDOUT)
        "movq %0, %%rsi\n"  // указатель на строку
        "movq %1, %%rdx\n"  // длина строки
        "syscall\n"         // вызов ядра
        :
        : "r"(str), "r"(len)
        : "rax", "rdi", "rsi", "rdx"
    );

    std::exit(0);
}
