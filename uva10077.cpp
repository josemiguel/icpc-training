#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N first
#define D second
#define pii pair<int,int>
#define mp make_pair

pii operator + (pii a, pii b){ return mp(a.N + b.N, a.D + b.D);}
bool p(pii a, pii b){ return a.N*b.D > a.D*b.N; }

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)){
		if (a == 1 && b == 1) break;
		pii izq(0,1), der(1,0), in(a,b);
		pii mid = izq + der;
		while(!(mid.N == in.N && mid.D == in.D)){
			if (p(mid,in)){
				der = mid;
				mid = mid + izq; putchar('L');
			}else{
				izq = mid;
				mid = mid + der; putchar('R');
			}
		}
		putchar(10);
	}	
	return 0;
}
