#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct node{
	char str[100];
	char ss[26];
	struct node *next;
};

void fill(char *s,char *a)
{
	while(*s != '\0')
	{
		a[*s-'a']++;
		s++;
	}
}
struct node * newnode(char *arr)
{
	struct node *temp;
	
	temp = malloc(sizeof(struct node));
	memset(temp,0,sizeof(struct node));
	strncpy(temp->str,arr,strlen(arr));
	fill(temp->str,temp->ss);
	temp->next=NULL;
	return temp;
}

int isana(char *t,char *s)
{
	int i;

	for(i=0;i<26;i++)
	{
		if(t[i] != s[i])
			return 0;
	}
	return 1;
}
int checkana(struct node *temp)
{
	int cnt=0;
	struct node *cur;

	cur=temp;
	temp=temp->next;
	while(temp!=NULL)	
	{
		cnt=cnt+isana(temp->ss,cur->ss);
		temp=temp->next;
	}
//	printf("\nstring %s cnt %d ",cur->str,cnt);
	return cnt;
}

struct node *listadd(struct node *temp,char *s)
{
	struct node *t;
	if(temp==NULL)
	{
		temp=newnode(s);
	}
	else
	{
		t=newnode(s);
		t->next=temp;
		temp=t;	
	}

	return temp;
}

void main()
{
	char s[100],c[100];
	int i,j,k,len,cnt=0,ana=0,t;
	struct node *head=NULL;

	scanf("%d",&t);
	while(t--)
	{
	scanf("%s",s);
	len=strlen(s);

	for(i=0;i<len;i++)
	{
//		printf("%c\n",s[i]);
		c[0]=s[i];
		c[1]='\0';
		head=listadd(head,c);
		ana=ana+checkana(head);
//		printf("ana %d\n",ana);
		for(j=1;j<len;j++)
		{
	//		for(k=i+1;k<len;k++)
	//		{
				k=i+1;
				if(k+j<=len)
				{
//				printf("%c",s[i]);
				c[cnt]=s[i];
				while(cnt<j)
				{
//					printf("%c",s[k+cnt]);
					c[cnt+1]=s[k+cnt];
					cnt++;
				}	
				c[cnt+1]='\0';
				head=listadd(head,c);
				ana=ana+checkana(head);
//				printf("ana %d\n",ana);
				cnt=0;
				//printf("\n");
				}
	//		}
		}
	}

	printf("list is \n");
	while(head!=NULL)
	{
		printf("%s\n",head->str);
		head=head->next;
	}

	printf("%d\n",ana);
	ana=0;
	head=NULL;
	cnt=0;
	}
	
}
