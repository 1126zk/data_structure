#include "stdio.h"
#include "malloc.h"
#include datatype int

typedef struct dnode{
	datatype data;
	struct dnode *prior,*next;
}Dlinklist;
Dlinklist *head;

Dlinklist *CreateDListF();

void Dinsert(Dlinklist *p,datatype x);
void Ddelete(Dlinklist *p);
void ShowSList(Dlinklist * head);

int main(){
	Dlinklist *p;
	head=CreateDListF();
	printf("The original list:\n");
	ShowSList(head);

	p=head;
	p=p->next;
	Dinsert(p,99);
	printf("Insert before the 2nd node:\n");
	ShowSList(head);

	Ddelete(p);
	printf("Delete the 3rd node:\n");
	ShowSList(head);l
}

Dlinklist *CreateDListF(){
	datatype ch;
	Dlinklist *head,*s;
	head=NULL;
	printf("Please input integer until '0' :\n");
	scanf("%d",&ch);
	while (ch!=0){
		s=(Dlinklist *)malloc(sizeof(Dlinklist));
		s->data=ch;
		s->next=head;
		if (head !=NULL) head->prior=s;
		head=s;
		printf("Please intput integer unitl '0' :\n");
		scanf("%d",&ch);
	}
	return head;
}

void Dinsert(Dlinklist *p,datatype x){
	Dlinklist *s;
	s=(Dlinklist *)malloc(sizeof(Dlinklist));
	s->data=x;
	s->prior=p->prior;
	s->next=p;
	p->priop->next=s;
	p->prior=s;
}

void Ddelete(Dlinklist *p){
	p->prior ->next=p->next;
	p->next->prior=p->prior;
	free(p);
}

void ShowSList(Dlinklist* head){
	Dlinklist *p;
	p=head;
	if (p->data==0) p=p->next;

	while(p->next!=0){
		printf("%d<==>",p->data);
		p=p->next;
	}
	printf("%d\n\n",p->data);
}