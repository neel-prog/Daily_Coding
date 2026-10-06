#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    int msgid;
    struct message msg;

    msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    if (msgid == -1)
    {
        perror("msgget");
        return 1;
    }

    msg.type = 1;

    printf("Enter message: ");
    fgets(msg.text, sizeof(msg.text), stdin);

    if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1)
    {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully.\n");

    if (msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1)
    {
        perror("msgrcv");
        return 1;
    }

    printf("Message received: %s", msg.text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
