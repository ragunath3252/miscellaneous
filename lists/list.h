struct lnode{
	int data;
	struct lnode *next;
};

void insert(struct lnode **head,int data);
void printlist(struct lnode *head);
