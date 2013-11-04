#include<stdio.h>
int main(){
	int a, b , i =1;
	char s[4];
	char res[2][10] = {"false","true"};
	
	while(scanf("%d %s %d",&a,s,&b) && s[0]!='E'){
		if (s[0]=='>' && !s[1]) printf("Case %d: %s\n",i,res[a>b]);
		else if (s[0]=='>' && s[1]=='=') printf("Case %d: %s\n",i,res[a>=b]);		
		else if (s[0]=='<' && !s[1]) printf("Case %d: %s\n",i,res[a<b]);		
		else if (s[0]=='<' && s[1]=='=') printf("Case %d: %s\n",i,res[a<=b]);
		else if (s[0]=='=') printf("Case %d: %s\n",i,res[a==b]);
		else if (s[0]=='!')  printf("Case %d: %s\n",i,res[a!=b]);
		i++;
	}

}


