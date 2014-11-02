#include<cstdio>
#include<iostream>
using namespace std;


int main(){

	int n;while(scanf("%d",&n) && n){
		int res = n;
		if (n >= 0 && n <= 102) res = 91;
		else res -= 11;
		printf("f91(%d) = %d\n",n,F(n));
	}
	return 0;
}
