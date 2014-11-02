#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int M[50000][50];
int Q[50000];

int main(){
	int v,p,q;
	scanf("%d%d%d",&v,&p,&q);
	for(int i=0;i<v;i++){
		for(int j=0;j<p;j++){
			scanf("%d",&M[i][j]);
		}
	}
	//querys
	int preg,val;
	for(int i = 0; i < q; i++){
		scanf("%d%d",&preg,&val);
		for(int k = 0; k < v ; k++){
			if (M[k][preg] == val) Q[k]++;
		}
	
	}
	int best = -1;
	for(int i=0;i<v;i++)best=max(best,Q[i]);
	printf("%d\n",best);
	return 0;
}
