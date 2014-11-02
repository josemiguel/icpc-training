#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 22

int pre[] = {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};

int main() {
	int n;
	while(scanf("%d",&n)  && n) {
		if(n >= pre[MAX-1]) { printf("0\n"); continue; }
		int f = 0;
		int M;
		for(M = 1; M <= n; M *= 10);
		for(int i = 0; i < MAX && pre[i] < M; i++) {
			if(pre[i] > n){
		        printf("%d\n",pre[i]);
		        f = 1;
		        break;
		    }
		}
		if (!f)	printf("0\n");

	}
}
