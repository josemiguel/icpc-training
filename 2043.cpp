#include<iostream>
#include<cstring>
using namespace std ;

int dentro ( int mid1, int mid2, int left, int right ){
	return left <= mid1 && mid1 <= right && left <= mid2 && mid2 <= right;
}

int main(){
	int n;
	while( cin >> n ){
		int xmin[n],xmax[n],ymin[n],ymax[n];
		for( int i = 0; i < n; i++){
			cin >> xmin[i] >> xmax[i] >> ymin[i] >> ymax[i];
		}
		bool usd[ n ];
		memset( usd, 0 ,sizeof usd);
		for( int i = 0; i < n; i++){
			for( int j = 0; j < n; j++){
				if ( i == j ) continue;
				if ( usd[j] ) continue;
				if ( dentro( xmin[j], xmax[j] , xmin[i], xmax[i] ) && dentro( ymin[j], ymax[j], ymin[i], ymax[i] ) ) usd[j] = true;
			}
		}
		int res = 0;
		for( int i = 0; i < n; i++) res += usd[i];
		cout << res << endl;
	}
	return 0;
}
