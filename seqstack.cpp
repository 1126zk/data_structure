#include "stdio.h"
#include "malloc.h"
#define stacksize 10
typedef char datatype;

typedef struct {
	datatype data[stacksize];
	int top;
}seqstack;

seqstack s;
seqstack *ps=&s;

void initstack(seqstack *ps){
	(ps->top)=-1;
}

int stackempty(seqstack *ps){
	return (ps->top==1);
}

int stackfull(seqstack *ps){
	return (ps->top==stacksize-1);
}

void push(seqstack *ps,char x){
	if (stackfull(ps)) {
		printf("stack overflow");
		return ;
	}
	ps->data[++ps->top]=x;
}

char pop(seqstack *ps){
	char x;
	if(stackempty(ps)) {printf("stack underflow");
	return ('$');
	}
	x=ps->data[ps->top];
	ps->top--;
	return (x);
}

datatype stacktop(seqstack *ps){
	if (stackempty(ps))
		printf("stack is empty");
		return (ps->data[ps->top]);
};

int main(){
	char a,b,c,x,y,z;
	a='A';
	b='B';
	c='C';
	initstack(ps);
	push(ps,a);
	push(ps,b);
	push(ps,c);
	x=pop(ps);
	y=pop(ps);
	z=pop(ps);
	printf("%c\n",x );
	printf("%c\n",y );
	printf("%c\n",z );

	return 0;
}


