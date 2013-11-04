#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[200002],bit[200002],n;

int get(int a, int b){
  	int res = 0; 
  	for(int i = b; i >= a; i = (i & (i+1) ) - 1 ) res = max(res,bit[i]);
	return res;
}

void update(int idx, int val) { 
	for(int i = idx ; i < n; i |= i+1) bit[i] = max(bit[i],val);
}
	 	


int main(){
	int r = 0,i;char c;
	while(scanf("%d",&n) && n){
		if (r) putchar(10);
		for(i = 0; i < n;i++) bit[i] = 0;
		for(i = 0; i < n; i++) {
			a[i] = 0;
			scanf("%d",&a[i]);
			update(i,a[i]);
		}
		printf("Case %d:\n",++r);
		char op;
		getchar();
		while((op=getchar()) != 'E'){
			int l = 0 ,r = 0;
			scanf("%d %d",&l,&r);
			if (op == 'M') 	printf("%d\n",get(l-1,r-1));
			else{
				l--;
				update(l,r);
				a[l] = r;
			}
			getchar();
		}while((getchar()!='\n'));
	}
	return 0;
}
