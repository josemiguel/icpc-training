#include<cstdio>
#include<cstring>
using namespace std;
int main(){

	int runs,n,q,m;
	int f[1005];	
	char s[100005],t[1005];
	scanf("%d\n",&runs);
	while(runs--){
		gets(s);
		m = strlen(s);
		scanf("%d\n",&q);
		while(q--){
			gets(t); n = strlen(t); 
			bool y = false;
			for(int i = 1, j = f[0] = -1; i < n; f[i] = ++j, i++) while(j>=0 && t[j] != s[i]) j = f[j];
			for(int i = 0, j = 0; i < m; i++) {
				while(j>=0 && t[j] != s[i]) j = f[j];
				if (++j >= n) { y = true; break; }
			}
			if (y) putchar('y');
			else putchar('n');
			putchar(10);
		}
	}
}
