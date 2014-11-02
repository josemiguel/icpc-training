#include<iostream>
#include<algorithm>
using namespace std;
int main(){

	int r1,r2,d1,d2,c1,c2;

	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

	int a[] = {1,2,3,4,5,6,7,8,9}, b[4];
	bool sirve = false;
	for( int mask = 0; mask < ( 1 << 9 ) ; mask++){

		if ( __builtin_popcount( mask ) == 4 ) {
			 int k = 0;
			for( int i= 0; i < 9; i++){
				if ( mask & ( 1 << i ) ){
					b[k++] = a[i];
				}
			}
			do{
				if ( r1 == b[0] + b[1])
				if ( r2 == b[2] + b[3])
				if ( d1 == b[0] + b[3])
				if ( c1 == b[0] + b[2])
				if ( c2 == b[1] + b[3])
				if ( d2 == b[1] + b[2])
					if ( b[0] != b[1] && b[0] != b[2] && b[0] != b[3] && b[1] != b[2] && b[1] != b[3] && b[2] != b[3]){
						sirve = true;
						goto hell;
					}
									
			}while( next_permutation( b, b + k) );
		}

		
	}
	
	hell:
	if ( sirve ){
		cout << b[0] << " " << b[1] << "\n" << b[2] << " " << b[3] <<endl;
	}else{
		cout << -1 << endl;
	}


	return 0;
}
