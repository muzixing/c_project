#include <stdlib.h>
#include "time_server.h"
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int time_server(int port)//You should change the ip addr into int.
{
	int server_fd;  
	int client_fd;
	struct sockaddr_in server_addr, client_addr;
	int sock_size;//size of socket_in.
	
	printf("> server start.\n");
	//create a socket.
	server_fd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==server_fd)
	{
		printf("> create socket failed.\n");
		return -1;
	}
	printf("> create socket successful.\n");

	//set the parameters of socket
	bzero(&server_addr,sizeof(struct sockaddr_in));//fill 0 of server_addr
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	server_addr.sin_port = htons(port);

	//bind to port
	if (-1 == bind(server_fd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr)))
	{
		printf("> bind failed\n");
		return -1;
	}
	printf("> bind seccessful\n");
	//listen 
	if (-1== listen(server_fd,10))//listen(socket_fd, listen number)
	{
		printf("> listen failed\n");
		return -1;
	}
	printf("> listen seccessful\n");
	//recv
	while(1)
	{
		sock_size = sizeof(struct sockaddr_in);
		client_fd = accept(server_fd,(struct sockaddr*)(&client_addr),&sock_size);//(server_socket_fd,store_mem,length)
		if (-1 ==client_fd)
		{
			printf("> accept failed.\n");
			return -1;
		}
		printf("> accept seccessful\n");

		time_t t;
		time(&t);
		
		if (-1 == send(client_fd,asctime(localtime((const time_t*)&time)),sizeof(asctime(localtime((const time_t*)&time))),0))
		{
			printf("> send failed.\n");
			return -1;
		}
		printf("send time seccessful\n");
		close(client_fd);
	}
close(server_fd);

return 0;
}

char* get_time(int ip, int port)
{	
	int client_fd;
	int recv_length;
	int sock_size = sizeof(struct sockaddr_in);
	char buffer[1024] = {0};
	struct sockaddr_in server_addr, client_addr;

	printf("> client start.\n");
	//create a socket.
	client_fd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==client_fd)
	{
		printf("> create socket failed.\n");
		return -1;
	}
	printf("> create socket successful.\n");

	//set the parameters of socket
	bzero(&server_addr,sizeof(struct sockaddr_in));//set the server addr.
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = ip;
	server_addr.sin_port = htons(port);

	if (-1 == connect(client_fd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr)))
	{
		printf("connect failed\n");
		return -1;
	}
	printf("connect successful\n");
	if (-1 == (recv_length =recv(client_fd,buffer,1024,0)))
	{
		printf("receive failed\n");
		return -1;
	}
	printf("receive:\n");
	buffer[recv_length] = '\0';//end of buffer.
	printf("%s\n",buffer );
	getchar();
	close(client_fd);
	return buffer;
}
