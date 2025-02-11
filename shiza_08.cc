/*++

    Вывод строки в GNU/Linux с использованием
    системного вызова syscall.

--*/

#include <unistd.h>
#include <sys/syscall.h>
#include <cstdlib>

int main()
{
    const char *str {"Hello, World!\n"};
    syscall(SYS_write, STDOUT_FILENO, str, 14);

    std::exit(0);
}
