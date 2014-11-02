#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std ;


int r, n, sum;
int a[10005];
bool F( int pos ){
	if ( pos == n ) return true;
	int tmp = 0;
	bool res = false;
	for( int i = pos ; i < n; i++){
		tmp += a[i];
		if ( sum == tmp ){
			res |= F( i + 1 );
			if ( res ) break;
		} 
	}
	return res;
}

int main(){
	int P;
	scanf("%d",&P);
	while( P--){
		scanf("%d %d",&r, &n );
		int T = 0;
		for( int i = 0; i < n; i++) scanf( "%d", a+i), T += a[i];
		sum = 0;
		for( int i = 0; i < n; i++ ){
			sum += a[i];
			if ( T % sum == 0 && F( i + 1 )){
				printf("%d %d\n",r,sum);
				break;
			}
		}

	}
	return 0;
}
