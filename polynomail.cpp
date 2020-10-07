#include "stdio.h"
#include "malloc.h"

typedef struct node{
	float coef;
	int exp;
	struct node *next;
}polynode;
polynode *pa,*pb;

polynode *CreatePolym(int m);
void polyadd(polynode *pa,polynode *pd);
void ShowPolym(polynode* head);

int main(){
	printf("Please input coef and exp of PA:\n");
	pa=CreatePolym(4);
	printf("Polym A is:");
	ShowPolym(pa);

	printf("Please input coef and exp of PB:\n");
	pb=CreatePolym(3);
	printf("Polym B is:");
	ShowPolym(pb);

	polyadd(pa,pb);
	printf("Polym A+B is:\n");
	ShowPolym(pa);

	return 0;
}

polynode *CreatePolym(int m){
	float c;
	int e;
	polynode *head,*s,*r;
	head = (polynode *)malloc(sizeof(polynode));
	head->exp=9999;
	r=head;
	for(int i=0;i<m;i++){
		scanf("%f%d",&c,&e);
		s=(polynode *)malloc(sizeof(polynode));
		s->coef=c;
		s->exp=e;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;
}

void polyadd (polynode *pa,polynode *pd){

	polynode *qa,*qb,*pre,*r;
	float x;
	pre=pa;
	qa=pa->next;
	qb=pb->next;
	while (qa&&qb){
		if(qa->exp<qb->exp){
			pre=qa; qa=pre->next;}
		else if (qa->exp==qb->exp){
			x=qa->coef + qb->coef;
			if(x!=0)
				{qa->coef = x;pre=qa;}
			else
			{pre->next=qa->next; free(qa);}
			qa = pre->next;
			r=qb;
			qb=qb->next;
			free(r);
		}
		else if(qa->exp>qb->exp){
			r=qb->next;
			qb->next=qa;
			pre->next=qb;
			pre = qb;
			qb = r;
		}
	}
	if (qb!=NULL) pre->next=qb;
	free(pb);
}

void ShowPolym(polynode* head){
	polynode *p;
	p=head;
	p=p->next;
	while(p->next!=0){
		printf("%5.1fx%d+",p->coef,p->exp);
		p=p->next;
	}
	printf("%5.1fx%d\n",p->coef,p->exp);
}