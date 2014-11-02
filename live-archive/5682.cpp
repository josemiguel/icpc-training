#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int runs, r = 1;
	cin >> runs;
	while( runs-- ){
		int n;
		cin >> n;
		int a[ n ];

		for( int i = 0; i < n; i++ ) cin >> a[ i ];
		
		sort( a, a + n );
		int gap = 0;
		for(int i = 1; i < n; i++){
			gap = max( gap, a[i] - a[i-1] ) ;
		}
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n",r++,a[n-1],a[0],gap);


	}
}
