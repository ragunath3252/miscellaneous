#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

typedef struct addrinfo ADDRI;
typedef struct sockaddr_in SOCKIN;

void main()
{	
	int rv=0;
	ADDRI hints,*res;
	SOCKIN *s;
	char ipstr[20];
	void *addr;
	char *port="ftp";
	

	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_socktype = SOCK_DGRAM;
//	hints.ai_flags = AI_PASSIVE;

	rv = getaddrinfo("www.google.com",NULL,&hints,&res);
//	rv = getaddrinfo("127.0.0.1",NULL,&hints,&res);
	if(rv != 0)
	{
		printf("ERROR: %s\n",gai_strerror(rv));
		return;
	}

	s = (SOCKIN *)res->ai_addr;
	printf("%d %d %d\n",s->sin_family,s->sin_port,s->sin_addr.s_addr);
	inet_ntop(s->sin_family,&(s->sin_addr),ipstr,sizeof(ipstr));
	printf("ip address is %s proto %d port %hd\n",ipstr,res->ai_protocol,s->sin_port);
	

}
