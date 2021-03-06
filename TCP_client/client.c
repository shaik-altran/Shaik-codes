#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>

#define PORT 9002


int main()
{
        int client_socket;
        struct sockaddr_in server_address;
        char server_response[255];

        client_socket = socket(AF_INET,SOCK_STREAM,0);

        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr.s_addr = INADDR_ANY;

        int connect_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

        if(connect_status == -1)
        {
                printf("Error connecting to remote socket\n");
                exit(0);
        }
        printf("Connected to the Server\n");
        
	recv(client_socket, &server_response, sizeof(server_response),0);

	printf("recieved data from server %s\n",server_response);

	close(client_socket);
}


