#include <stdio.h>
#include "malloc.h"
#include "string.h"
#define MAXNUM 256
#define NODENUM 3

typedef struct node{
	char data[NODENUM];
	struct node *next;
}nodetype;

typedef struct head{
	int len;
	nodetype *next;
}headtype;

headtype *CreateString(char ss[]){
	int p=0;
	int i=0;
	headtype *head;
	nodetype *s,*r;

	head=(headtype *)malloc(sizeof(headtype));
	head -> len=strlen(ss);

	while(ss[p]!='\0'){
		if (p%NODENUM==0) s=(nodetype *)malloc(sizeof(nodetype));
		s -> data[p%NODENUM]=ss[p++];
		if (i==0) head ->next=s;
		else r->next=s;
		r=s;
		i++;
	}

	for (i=p%NODENUM;i!=3;i++) s->data[i]='#';
	s->next=NULL;
	return head;
}

void ShowString(headtype * head){
	headtype *p1;
	nodetype *p2;
	int i;
	p1 = head;
	if (p1->next!=NULL) p2=p1->next;
	while(p2->next!=NULL){
		for (i=0;i<NODENUM;i++) printf("%c",p2->data[i]);
		p2 = p2->next;
	printf("|");
	}
	for (i=0;i<NODENUM;i++) printf("%c",p2->data[i]);
	printf("\n");
}

headtype *substr12(headtype *s,int i,int k){
	headtype *t;
	nodetype *p,*v;
	int j,n,m,w,l,u;
	n = s->len;
	p=s->next;
	if (i>=0&&i<n&&k>0&&k<=n-i){
		m = i/NODENUM;
		for(j=0;j<m;j++)
			p=p->next;
		t = (headtype *)malloc(sizeof(nodetype));

		t->len=k;
		t->next=(nodetype *)malloc(sizeof(nodetype));
		v=t->next;
		w=1;
		u=m;
		l=i;
		for (j=0;j<k;j++){
			if (j==NODENUM*w){
				w++;
				v->next=(nodetype *)malloc(sizeof(nodetype));
				v= v->next;
			}
			if (l==NODENUM*(u+1)){
				u++;
				p=p->next;
			}
			v->data[j%NODENUM]=p->data[l%NODENUM];
			i++;
		}
		for (i=j%NODENUM;i!=3;i++) v->data[i]='#';
		v->next=NULL;
		return t;
	}
	else return NULL;
}

int main(){
	headtype *head,*sub;
	char s[]="They are students";
	head=CreateString(s);
	printf("The host-string is:");
	ShowString(head);

	sub=substr12(head,10,7);
	printf("The sub-string is:");
	ShowString(sub);
}
