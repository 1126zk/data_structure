#include <stdio.h>
#include "malloc.h"
#include "string.h"
#define MAXNUM 256

typedef struct node{
	char data;
	struct node *next;
}nodetype;

nodetype *CreateString(char ss[]){
	int p=0;
	nodetype *head,*s,*r;

	head = (nodetype *)malloc(sizeof(nodetype));
	head -> data = strlen(ss);
	r = head;
	while(ss[p]!='\0'){
		s = (nodetype *)malloc(sizeof(nodetype));
		s ->data = ss[p++];
		r->next=s;
		r=s;
	}
	s->next=NULL;
	return head;
}

void ShowString(nodetype* head){
	nodetype *p;
	p=head;
	
	while(p->next!=NULL){
		p=p->next;
		printf("%c",p->data);
	}
	printf("\n");
}

nodetype *substr1(nodetype *s,int i,int k){
	nodetype *t,*p,*q,*v;
	int j,n;
	n = s->data;

	if(i>=0&&i<n&&k>0&&k<=n-i){
		p = s;
		for (j = 0;j<i;j++)
			p = p->next;

		t = (nodetype *)malloc(sizeof(nodetype));

		t -> data=k;
		v = t;
		for (j=0;j<k;j++){
			q=(nodetype *)malloc(sizeof(nodetype));
			v->next=q;
			v=q;
			q->data=p->data;
			p=p->next;
		}
		v->next=NULL;
		return (t);
	}
	else return (NULL);
}

int main(){
	nodetype *head,*sub;
	char s[]="They are students";
	head = CreateString(s);
	printf("The host-string is:");
	ShowString(head);

	sub=substr1(head,9,8);

	printf("The sub-string is:");
	ShowString(sub);
}
