#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define INF 1<<29
int F[101][1002];
int W[101][101];

int main(){
	int c,s,t,e;
	while(scanf("%d%d%d%d",&c,&s,&e,&t)!=-1 && c+s+t+e){
		for(int i=0;i<c;i++)
			for(int j=0;j<c;j++)
				scanf("%d",&W[i][j]);
				
		for(int i=0;i<t+1;i++)
			for(int j=0;j<c;j++) 
				F[j][i]=-INF;
			
		F[s-1][0]=0;
		
		for(int i=0;i<t;i++)
			for(int u=0;u<c;u++)
				for(int v=0;v<c;v++)
					F[v][i+1] = max(F[v][i+1],W[u][v]+F[u][i]);
		
		int Max = -INF;
		int k;
		
		for(int i=0;i<e;i++){
			scanf("%d",&k);
			Max = max(Max,F[k-1][t]);
		}
		printf("%d\n",Max);
	
	}

}
