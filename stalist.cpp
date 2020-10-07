#include "stdio.h"
#define MAXSIZE 100
#include <malloc.h>
#include <iostream>
using namespace std;

typedef int datatype;
typedef struct{
	datatype data;
	int cur;
}component,SList[MAXSIZE];
SList space;

datatype a[]={2,3,4};
datatype b[]={3,4,5};

int head,rear;

int locate(SList &s,datatype e);
int locatePrior(SList &s,datatype e);
int malloc_sl(SList &space);
void free_sl(SList &space,int k);
void Createlist(SList &space ,int n);
void different (SList &space,int &s,int n);
void show(int &s);

void initspace_sl(SList &space);
void InsertRear(SList &s,datatype e);
void DeleteA(SList &s,int p);

int main(){
	const int lengthA=3;
	const int lengthB=3;
	initspace_sl(space);
	Createlist(space,lengthA);
	cout<<"\nOriginal set A::\n";
	show(head);

	different(space,head,lengthB);
	cout<<"\nSet((A-B)and(B-A)):\n";
	show(head);

	return 0;
}

int locate(SList &s,datatype e){
	int i=s[1].cur;
	while (i&&s[i].data!=e)
		i=s[i].cur;
	return i;
}

int locatePrior(SList &s,datatype e){
	int i=s[1].cur;
	while (i&& s[s[i].cur].data!=e)
		i=s[i].cur;
	return i;
}

void initspace_sl(SList &space){
	for (int i=0;i<MAXSIZE-1;i++)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
}

int malloc_sl(SList &space){
	int i=space[0].cur;
	if (space[0].cur) space[0].cur=space[i].cur;
	return i;
}

void free_sl(SList &space,int k){
	space[k].cur=space[0].cur;
	space[0].cur=k;
}

void Createlist(SList &space,int n){
	head=malloc_sl(space);
	rear=head;
	for(int i=0;i<n;i++){
		int s=malloc_sl(space);
		space[s].data=a[i];
		space[rear].cur=s;
		rear=s;
	}
	space[rear].cur=0;
}

void different(SList &space ,int &s,int n){
	int i;
	cout<<"Set B:\n";
	for(i=0;i<2;i++)
		cout<<" "<<b[i]<<"-->";
	cout<<b[i]<<endl;

	for(i=0;i<n;i++){
		int p,k;
		p=locatePrior(space,b[i]);
		k=space[p].cur;

		if(p==space[rear].cur)
			InsertRear(space,b[i]);
		else
			DeleteA(space,p);
	}
}

void InsertRear(SList &space,datatype e){
	int s=malloc_sl(space);
	space[s].data=e;
	space[s].cur=space[rear].cur;
	space[rear].cur=s;
}

void DeleteA(SList &s,int p){
	int k=space[p].cur;
	space[p].cur=space[k].cur;
	free_sl(space,k);
	if (rear==k) rear=p;
}

void show(int &s){
	int i;
	i=s;
	i=space[i].cur;
	while(space[i].cur!=0){
		cout <<" "<<space[i].data<<"-->";
		i=space[i].cur;
	}
	cout << space[i].data<<endl;
}