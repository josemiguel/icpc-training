#include<cstdio>
using namespace std;

int dig(int n) { int res = 0; while(n){ res+= n%10; n/=10; } return res;} 

int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		int nn,res = 0;
		scanf("%d",&nn);
		for(int j = nn+1; ; j++){
			int n = j, s = 0;
			int t = dig(n), a = 1;
			for(int i = 2; i*i <= n; i++){
				int d = n%i?0:dig(i);
				while (n%i == 0){
					s += d;
					n /= i;
				}
			}
			if (s == 0) continue;
			if (n != 1) s += dig(n);
			if (t == s) { res = j; break;}
		}
		printf("%d\n",res);
	}
	return 0;
}
