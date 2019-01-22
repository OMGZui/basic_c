#include "apue.h"

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
    int var; /* automatic variable on the stack */
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    {
        err_sys("write error");
    }
    printf("before fork\n"); /* we don't flush stdout */

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {              /* child */
        globvar++; /* modify variables */
        var++;
    }
    else
    {
        sleep(2); /* parent */
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    // 结论是子进程对变量的修改不会影响父进程中变量的值
    // pid = 95836, glob = 7, var = 89 子进程进行++运算
    // pid = 95835, glob = 6, var = 88 父进程等待2s
    exit(0);
}
