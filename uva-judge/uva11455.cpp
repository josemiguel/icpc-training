#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std ;

int main(){
	int runs,a[4];
	cin >> runs;
	while( runs-- ){
		for(int i = 0; i < 4 ; i++) cin >> a[ i ];
		if ( a[0] == a[1] && a[2] == a[1] && a[2] == a[3] ) {
			cout << "square" << endl;
		}else{
			sort( a , a + 4 );
			if ( a[0] == a[1] && a[2] == a[3] ){
				cout << "rectangle" << endl;
			}else{
				bool q = false;
				if ( a[0] + a[1] + a[2] > a[3]  ){

					cout << "quadrangle" << endl;
				}else{
					cout << "banana" << endl;
				}
			}
			
		}

	}

	return 0;
}
