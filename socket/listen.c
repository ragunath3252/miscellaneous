#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

typedef struct addrinfo ADDRI;
typedef struct sockaddr_in SOCKIN;

void main()
{	
	int rv=0,sockfd;
	ADDRI hints,*res;
	SOCKIN *s;
	char ipstr[20];
	void *addr;
	char *port="ftp";
	

	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

//	rv = getaddrinfo("www.google.com",port,&hints,&res);
	rv = getaddrinfo(NULL,"4496",&hints,&res);
	if(rv != 0)
	{
		printf("ERROR: %s\n",gai_strerror(rv));
		return;
	}

	s = (SOCKIN *)res->ai_addr;
	printf("%d %d %d\n",s->sin_family,s->sin_port,s->sin_addr.s_addr);
	inet_ntop(s->sin_family,&(s->sin_addr),ipstr,sizeof(ipstr));
	printf("ip address is %s proto %d port %hu\n",ipstr,res->ai_protocol,s->sin_port);
	

	/*OPEN socket with obtained info*/
//	while(1)
//	{
		/* Max limit goes till 1023 because max open files for a proc is 1024  given by ulimit -n*/
		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		printf("sockfd is %d\n",sockfd);
		//if(sockfd==-1)
		//	break;
//	}

	rv = bind(sockfd,res->ai_addr,res->ai_addrlen);
	if(rv != 0)
        {
                printf("ERROR: %d\n",rv);
                return;
        }

	rv = listen(sockfd,5);
	if(rv != 0)
        {
                printf("ERROR: %d\n",rv);
                return;
        }

	

	close(sockfd);
	

}
