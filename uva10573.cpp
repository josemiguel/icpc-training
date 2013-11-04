#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double pi = 2*acos( 0 );
int main(){

	int runs;
	cin >> runs;
	while( runs--) {
		char c; int r1,r2;
		scanf("%d%c", &r1, &c );
		double r,res ;
		if ( c != '\n' ){
			scanf("%d",&r2);
			res = 2*(r1*r2) * pi;
		}else{

			res = (r1*r1*pi) / 8.0 ;

		}

		if ( r1 < 0 || r2 < 0 ){
			printf("Impossible\n");
			continue;
		}

		printf("%.4lf\n", res );
	
	}

	return 0;
}
