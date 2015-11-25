#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

typedef struct addrinfo ADDRI;
typedef struct sockaddr_in SOCKIN;

void main()
{	
	int rv=0,sz,sockfd;
	ADDRI hints,*res;
	SOCKIN *s,cli,serv;
	char ipstr[20],buf[100];
	void *addr;
	char *port="8888";
	

	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
//	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

//	rv = getaddrinfo("www.google.com",NULL,&hints,&res);
	rv = getaddrinfo(INADDR_ANY,port,&hints,&res);
	if(rv != 0)
	{
		printf("ERROR: %s\n",gai_strerror(rv));
		return;
	}

	s = (SOCKIN *)res->ai_addr;
	printf("%d %d %d\n",s->sin_family,s->sin_port,s->sin_addr.s_addr);
	inet_ntop(s->sin_family,&(s->sin_addr),ipstr,sizeof(ipstr));
	printf("ip address is %s proto %d port %hu\n",ipstr,res->ai_protocol,s->sin_port);

	sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);

	rv = bind(sockfd,res->ai_addr,res->ai_addrlen);
	sz=sizeof(*s);
	fflush(stdout);
	rv = recvfrom(sockfd,buf,100,0,(struct sockaddr *)&serv,&sz);	
	if(rv <= 0)
	{
		printf("ERROR: %s\n",gai_strerror(rv));
		close(sockfd);
                return;	
	}
	printf("RECV: %s\n",buf);
	
	close(sockfd);
}
