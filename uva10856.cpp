#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 2703664
int p[MAX];

vector<int> f(MAX);
int F(int n){
	int res = 1;
	while(p[n]){
		n /= p[n];
		res++;
	}
	return res;
}
void pre(){
	p[0] = p[1] = 1;
	for(int i = 4; i < MAX; i+=2) p[i] = 2;
	for(int i = 3; i*i < MAX; i+=2){
		if ( !p[i] ){
			for(int j = i*i; j < MAX; j+=2*i){
				p[j] = i;
			}
		}
	}
	f[0] = f[1] =0;
	for(int i = 2; i < MAX; i++) f[i] = f[i-1] + F(i);
}

int main(){
	pre();	
	int n,r=1;
	while(scanf("%d",&n)!=EOF && n>=0){
		int idx = lower_bound(f.begin(),f.end(),n)-f.begin();
		if (f[idx] == n){
			printf("Case %d: %d!\n",r++,idx);
		}else{
			printf("Case %d: Not possible.\n",r++);
		}
	}

	return 0;
}
