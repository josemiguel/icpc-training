#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std ;

int main(){

	double R, r[4], l[4];
	int cases = 1;
	while( cin >> R >> r[1] >> r[2] >> r[3] ){
		if ( R < 0 && r[1] < 0 && r[2] < 0 && r[3] < 0 ) break;
		double sum = 0;
		for( int i = 1; i <= 3; i++){
			sum += 2 * R * sqrt( R * r[i]) / ( R - r[i] );
		}
		printf("Case %d: %.2lf\n",cases++, sum * R );
	
	}

	return 0;
}
