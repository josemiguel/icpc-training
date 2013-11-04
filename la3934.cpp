#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10005];
int d[10005];
int main(){

	int A,D;
	while(scanf("%d %d",&A,&D) && A+D){
		for(int i = 0; i < A; i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < D; i++){
			scanf("%d",&d[i]);
		}

		sort(a,a+A);sort(d,d+D);
		bool cagao = false;
		for(int i = 0; i < A; i++){
			int tmp = 0;
			for(int j = 0; j < D; j++){
				if (a[i] < d[j]) continue;
				tmp++;
			}
			if (tmp < 2) cagao = true;
		}

		if (cagao) putchar('Y');
		else putchar('N');
		putchar(10);


	}
	
	return 0;
}
