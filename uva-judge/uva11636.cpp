#include<cstdio>
#include<algorithm>
using namespace std ;
int pot[16];
int main(){
	pot[0] = 1;
	int i;
	for(  i = 1; pot[i-1] <= 10001 ; i++ ) pot[i] = 2*pot[i-1];
	int n,r=1;

	while( scanf("%d",&n) && n>0){
		printf("Case %d: %d\n",r++, lower_bound( pot, pot + i,n ) - pot);
	}
}
