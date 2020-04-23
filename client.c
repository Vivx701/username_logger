#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){


    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create a socket\n");
    }

    struct sockaddr_in server;
    char *IP = "127.0.0.1";
    unsigned short OPEN_PORT = 15000; 

    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(OPEN_PORT);

    //connect to the server
    if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        puts("Connect error\n");
        return 1;
    }
    //send login name to server
    char *message = getenv("USER");
    if (NULL != message)
    {
        if (send(socket_desc, message, strlen(message), 0) < 0) {
            puts("Send failed\n");
            return 1;
        }
    }
    close(socket_desc);
    return 0;
}
