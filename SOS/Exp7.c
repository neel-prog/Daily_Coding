#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char buffer[100];
    struct stat file_info;

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        perror("File opening failed");
        return 1;
    }

    write(fd, "Linux File Operations\n", 21);

    lseek(fd, 0, SEEK_SET);

    int n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';

    printf("File Content:\n%s", buffer);

    if (stat("sample.txt", &file_info) == -1)
    {
        perror("stat");
        close(fd);
        return 1;
    }

    printf("\nFile Size: %ld bytes\n", file_info.st_size);

    if (file_info.st_mode & S_IRUSR)
        printf("Owner: Read permission\n");

    if (file_info.st_mode & S_IWUSR)
        printf("Owner: Write permission\n");

    if (file_info.st_mode & S_IXUSR)
        printf("Owner: Execute permission\n");

    if (file_info.st_mode & S_IRGRP)
        printf("Group: Read permission\n");

    if (file_info.st_mode & S_IWGRP)
        printf("Group: Write permission\n");

    if (file_info.st_mode & S_IROTH)
        printf("Others: Read permission\n");

    if (file_info.st_mode & S_IWOTH)
        printf("Others: Write permission\n");

    chmod("sample.txt", 0600);

    printf("\nAccess control changed to: Owner Read/Write only\n");

    close(fd);

    return 0;
}
