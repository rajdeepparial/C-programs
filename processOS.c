#include <stdio.h>
#include <unistd.h>
int main()
{
    int x = fork();
    if(x>0)
    {
        sleep(10);
        printf("\nParent PID=%d PPID=%d\n", getpid(), getppid());
    }
    if(x==0)
    {
        printf("\nChild PID=%d PPID=%d\n", getpid(), getppid());
    }
}