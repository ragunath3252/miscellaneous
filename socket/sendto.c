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
	SOCKIN *s,cli,si_other;
	char ipstr[20],buf[100];
	void *addr;
	char *port="8888";
	int sz;

	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
//	hints.ai_socktype = SOCK_DGRAM;
	//hints.ai_flags = AI_PASSIVE;

//	rv = getaddrinfo("www.google.com",NULL,&hints,&res);
	rv = getaddrinfo("127.0.0.1",port,&hints,&res);
	if(rv != 0)
	{
		printf("ERROR: %s\n",gai_strerror(rv));
		return;
	}

	s = (SOCKIN *)res->ai_addr;
	printf("%d %d %d\n",s->sin_family,s->sin_port,s->sin_addr.s_addr);
	inet_ntop(s->sin_family,&(s->sin_addr),ipstr,sizeof(ipstr));
	printf("ip address is %s proto %d port %hu\n",ipstr,res->ai_protocol,s->sin_port);
	sockfd=(res->ai_family,res->ai_socktype,res->ai_protocol);
	if(sockfd<0)
	{
		printf("SOCKET ERROR: %s\n",strerror(errno));
	}
//	scanf("%s",buf);
	sz=sizeof(*s);
	memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8888);

    if (inet_aton("127.0.0.1" , &si_other.sin_addr) == 0)
    {
        fprintf(stderr, "inet_aton() failed\n");
        //exit(1);
    }
//	if ( (sockfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
//        die("socket");
    }
	printf("%d %d %d %d %d %d\n",AF_INET,SOCK_DGRAM, IPPROTO_UDP,res->ai_family,res->ai_socktype,res->ai_protocol);
	sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	
//	rv = sendto(sockfd,"hi",100,0,(struct sockaddr *)res->ai_addr,sz);
	rv = sendto(sockfd,"hi",100,0,(struct sockaddr *)&si_other,sz);

	if(rv < 0)
        {
                printf("SEND ERROR: %d %s\n",sockfd,strerror(errno));
		close(sockfd);
                return;
        }

	close(sockfd);

}
