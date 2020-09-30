#include <stdio.h>
#include "string.h"
#define MAXNUM 256

typedef struct{
	char Str[MAXNUM];
	int Length;
}strtype;

strtype substrq(strtype s,int i,int k){
	strtype t;
	int j,n;
	n = s.Length;
	if (i>=0&&i<=n&&k>0&&k<=n-i){
		for (j = 0;j<k;j++)
			t.Str[j]=s.Str[i+j];
		t.Str[k] = '\0';
		t.Length = k;
		return(t);
	}
	else{
		t.Str[0] = NULL;
		t.Length = 0;
		return (t);
	}
}

int main(){
	strtype s1,s2;
	strcpy(s1.Str,"They are students");
	s1.Length=sizeof("They are students");
	s2=substrq(s1,9,8);
	printf("The host-string is : They are students\n");
	printf("The sub-string is :");
	printf("%s\n",s2.Str);
}
