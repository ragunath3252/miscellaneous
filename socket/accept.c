#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

typedef struct addrinfo ADDRI;
typedef struct sockaddr_in SOCKIN;

void main()
{	
	int rv=0,sockfd,new;
	ADDRI hints,*res;
	SOCKIN *s,cli,serv;
	char ipstr[20],buf[100];
	void *addr;
	char *port="4502";
	socklen_t size;
	

	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

//	rv = getaddrinfo("www.google.com",port,&hints,&res);
	rv = getaddrinfo(NULL,port,&hints,&res);
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
	size=sizeof(cli);
	new = accept(sockfd,(struct sockaddr *)&cli,&size);	
	if(new < 0)
        {
                printf("ERROR: %d\n",rv);
		close(sockfd);
                return;
        }

	printf("New connection %d \n",new);
	printf("%d %d %d\n",cli.sin_family,cli.sin_port,cli.sin_addr.s_addr);
	inet_ntop(cli.sin_family,&(cli.sin_addr),ipstr,sizeof(ipstr));
        printf("ip address is %s proto %d port %hu\n",ipstr,res->ai_protocol,cli.sin_port);

	while(1)
	{
	scanf("%s",buf);
	rv = send(new,buf,strlen(buf),0);
	if(rv < 0)
        {
                printf("SEND ERROR: %d\n",rv);
                close(sockfd);
		close(new);
                return;
        }
	rv = recv(new,buf,100,0);
	if(rv < 0)
        {
                printf("RECV ERROR: %d\n",rv);
                close(sockfd);
                close(new);
                return;
        }
	printf("RCV: %s\n",buf);

	}

	close(sockfd);
	close(new);
	

}
