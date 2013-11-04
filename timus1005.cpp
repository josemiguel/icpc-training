#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int a[21];
int mask, res, tot,n;
void F(int p){
	for(int i = 0; i < n; i++){
		if (!((mask>>i) & 1)){
			int diff = abs(tot - 2*(p+a[i]));
			if (diff < res){
				res = diff;			
				mask |= (1<<i);
				F(p + a[i]);
				mask &= (~(1<<i));
			}
		}
	}
}

int main(){

	while(scanf("%d",&n) != -1){
		tot = 0;
		for(int i = 0; i < n; i++) scanf("%d",a+i), tot += a[i];
		mask = 0;
		res = 1<<30;
		F(0);
		printf("%d\n",res);
	}
}


