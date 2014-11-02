#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std ;

int main(){

	int T;
	cin >> T;
	while( T --){
		int n,r;
		cin >> r>> n;
		int a[n];
		for( int i = 0; i < n; i++ ){
			scanf("%d",&a[i]);
			
		}
		printf("%d %d\n", r,1 + n/2 );
		int j = 0;
		for( int i = 0; i < n; i++){
			if ( (i+1) % 2 ){
				sort( a , a + i + 1 );
				if ( j ) putchar(32);
				printf("%d", a[ (i+1) / 2 ]   );
				if ( (j+1) % 10 == 0 ) putchar(10),j=-1;
				j++;
			}
		}
		putchar(10);


	}

	return 0;		
}
