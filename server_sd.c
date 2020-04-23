#include <stdio.h>
#include <string.h>   
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <systemd/sd-daemon.h>

#define LOG_FILE "/tmp/username.log"
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[100];
    FILE *logfilePointer ; 
    
    int num = sd_listen_fds(0);
	if (num > 1) {
		printf("sd_listen_fds returned %d fds", num);
		return -1;
	} else if (num == 1) 
    {
		socket_desc = SD_LISTEN_FDS_START + 0;
		printf("using fd %d from sd_listen_fds", socket_desc);
    }
    else
    {
        printf("No fd found");
        return 0;
    }
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 15000 );

    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    while ( client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c) )
    {
        logfilePointer = fopen(LOG_FILE, "a+") ; 
        if ( logfilePointer == NULL ) 
        { 
            printf( "Failed to open log file %s", LOG_FILE ) ; 
            continue;
        } 
        if (client_sock < 0)
        {
            perror("accept failed");
            return 1;
        }
        puts("Connection accepted");

        while( (read_size = read(client_sock , client_message , sizeof(client_message))) > 0 )
        {
            printf("username: %s ", client_message);
            fprintf(logfilePointer, "%s\n", client_message);
            memset(client_message, 0, sizeof client_message);
        }

        if(read_size == 0)
        {
            puts("Client disconnected");
            fflush(stdout);
        }
        else if(read_size == -1)
        {
            perror("recv failed");
        }
        fclose(logfilePointer) ; 
    }
    return 0;
}
