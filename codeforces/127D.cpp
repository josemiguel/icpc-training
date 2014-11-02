#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXN 10010

int RA[MAXN], SA[MAXN], LCP[MAXN], *FC, *SC, step;
char S[MAXN];

bool cmp(int a, int b){
	if (step == -1 || FC[a] != FC[b]) return FC[a] < FC[b];
	return FC[a+(1<<step)] < FC[b+(1<<step)];
}


void suffix_array(char *S, int n){
	for(int i = 0; i < n; i++) RA[i] = S[SA[i] = i];
	for(FC = RA, SC = LCP, step = -1; (1<<step) < n; step++){
		sort(SA,SA+n,cmp);
		int cnt = 0;
		SC[SA[0]] = 0;
		for(int i = 1; i < n; i++){
			if ( cmp(SA[i-1],SA[i]) ) cnt++;
			SC[SA[i]] = cnt;
		}
		if (cnt == n-1) break;
		swap(FC,SC);
	}
	for(int i = 0; i < n; i++) RA[SA[i]] = i;
	
	for (int i = 0, k = 0; i < n; i++) {
	       if (k > 0) k--;
        	if (RA[i] == n-1) { LCP[n-1] = -1; k = 0; continue; }
	       	int j = SA[RA[i]+1];
        	while (S[i+k] == S[j+k]) k++;
	        LCP[RA[i]] = k;
	}
	
	
	for(int i = 1; i < n; i++){
		char *p = S + SA[i];
		cout << p << endl;
	}


	
}

int main(){
	int runs;
	scanf("%d\n",&runs);
	while(runs--){
		gets(S);
		int n = strlen(S);
		int i;
		for(i = 1; i < n; i++) if (S[i] != S[i-1]) break;
		if (i < n) suffix_array(S, n + 1 ) ;
		else printf("1\n");
	}
}

