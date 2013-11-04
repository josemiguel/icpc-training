#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[200002],bit[200002],n;

int get(int b){
  	int sum = 0; 
  	while(b >= 0) sum += bit[b], b = (b & (b+1)) - 1;
	return sum;
}
void update(int k, int v) {  while(k < n) bit[k] += v, k |= k+1; }	


int main(){
	int r = 0,i;char c;
	while(scanf("%d",&n) && n){getchar();
		if (r) putchar(10);
		for(i = 0; i < n;i++) bit[i] = 0;
		for(i = 0; i < n; i++) {
			a[i] = 0;
			while((c=getchar()) && c!=' ' && c!='\n') a[i] = a[i]*10 + c-'0';
			update(i,a[i]);
		}
		printf("Case %d:\n",++r);
		char op;
		while((op=getchar()) != 'E'){
			getchar();
			int l = 0 ,r = 0;
			while((c=getchar()) && c!=' ' && c!='\n') l = l*10 + c-'0';
			while((c=getchar()) && c!=' ' && c!='\n') r = r*10 + c-'0';
			if (op == 'M') 	printf("%d\n",get(r-1)-get(l-2));
			else{
				l--;
				update(l,r-a[l]);
				a[l] = r;
			}
		}while((getchar()!='\n'));
	}
	return 0;
}
