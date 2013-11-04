#include<iostream>
#include<algorithm>
using namespace std ;

int main(){
	int a[3];
	while( cin >> a[0] >> a[1] >> a[2] ){
		int b = 0;
		for(int i = 0; i < 3;i++){
			b |= a[i];
		}
		if (!b) break;
		sort( a, a + 3 );
		if (a[2]*a[2] == a[0]*a[0] + a[1]*a[1]){
			cout << "right" << endl;
		}else{
			cout << "wrong" << endl;
		}
	}

	return 0;
}
