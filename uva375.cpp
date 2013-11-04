#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std ;
#define eps 1e-6
const double pi = 2*acos( 0 );
int main(){

	int runs, r = 1;
	cin >> runs;
	while( runs-- ){
		if ( r != 1 ) cout << endl;
		r++;
		double H,B;
		cin >> B >> H;
		double r , res = 0;
		double l = sqrt( B*B/4 + H*H) ;
		r = ( B*H )/( B + 2*l);
		do{
					
			res += 2 * pi * r;
			double R = r;
			r *= ( H - 2*R ) / H;
			H = H - 2 * R;

		}while( r >= eps );
		printf("%13.6lf\n", res );
				
	}

	return 0;
}
