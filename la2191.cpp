#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[200002],bit[200002],n;

int get(int x){ int res = 0;  for(; x ; x -= x & -x ) res += bit[x]; return res; }
void update(int x, int v) { for( ;x <= n; x += x & -x ) bit[x] += v; }

int main(){
	int r = 0,i;char c;
	while(scanf("%d",&n) && n){
		if (r) putchar(10);
		for(i = 0; i <= n;i++) bit[i] = 0;
		for(i = 1; i <= n; i++) {
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
			if (op == 'M') 	printf("%d\n",get(r)-get(l-1));
			else{
				update(l,r-a[l]);
				a[l] = r;
			}
			getchar();
		}while((getchar()!='\n'));
	}
	return 0;
}
