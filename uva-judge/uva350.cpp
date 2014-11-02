#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
using namespace std;
int next(int z, int i, int m, int l){
	return (z%m*l%m + i%m)%m;
}
int main(){
	int r = 1,Z,L,M,I;
	while(scanf("%d %d %d %d",&Z,&I,&M,&L) && Z+I+M+L){
		set<int> h;
		
		while(1){
			L = next(Z,I,M,L);
			if (h.count(L)) break;		
			h.insert(L);
		}
		printf("Case %d: %d\n",r++,h.size());
	}
	return 0;
}
