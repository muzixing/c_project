#include <stdlib.h>
#include <stdio.h>
#include "time_server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
int main(int argc, char const *argv[])
{	
	int server_ip = inet_addr("0.0.0.0");
	time_server(50000);
	//get_time(server_ip,50000);
	return 0;
}