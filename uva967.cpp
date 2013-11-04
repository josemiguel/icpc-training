#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 1000002
int p[MAX];
int dp[MAX];
void criba(){
	for(int i = 2; i*i < MAX; i++)
		if (!p[i]) for(int j = i*i; j < MAX; j+=i)
			p[j] = i;
}

int len(int u){
	int res = 0;
	while(u) u /= 10, res++;
	return res;
}
int pot[10];

int rota(int N,int cant, int L){
	int dif = L - cant;
	int mitadIzq = N % pot[dif];
	int mitadDer = N / pot[dif];
	for(int i = cant-1; i >= 0; i--){
		 int dig = mitadDer / pot[i];
		 mitadIzq = mitadIzq*10 + dig;
		 mitadDer %= pot[i];
	}
	return mitadIzq;
}

int S[MAX];
bool sirve(int u){
	if (S[u] != -1) return S[u];
	int L = len(u);
	for(int i = 1; i <= L; i++){
		int tmp = rota(u,i,L);
		if (p[tmp]) return S[u] = false;		
	}	
	return S[u] = true;
}

void pre(){
	memset(S,-1,sizeof S);
	pot[0] = 1;
	for(int i = 1; i < 10; i++) pot[i] = 10*pot[i-1];
	dp[2] = 1;
	for(int i = 3; i < MAX; i++) dp[i] = dp[i-1] + sirve(i);	
}

int main(){
	criba();pre();
	int a,b;
	while(cin>>a>>b && a > 0){
		int res = dp[b]-dp[a-1];
		if (res == 0) puts("No Circular Primes.");
		else if (res == 1) puts("1 Circular Prime.");
		else printf("%d Circular Primes.\n",res);
	}
	return 0;
}
