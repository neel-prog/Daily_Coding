#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd;
    char buffer[100];
    pid_t pid;

    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());

    fd = open("test.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "Operating Systems Lab\n", 22);

    lseek(fd, 0, SEEK_SET);

    int n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';

    printf("File Content: %s", buffer);

    close(fd);

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child Process ID: %d\n", getpid());
        printf("Child Process Executing\n");
    }
    else
    {
        printf("Parent Process ID: %d\n", getpid());
        wait(NULL);
        printf("Child Process Completed\n");
    }

    return 0;
}
                              