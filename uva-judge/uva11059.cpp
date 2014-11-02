#include<iostream>
#include<cstdio>
using namespace std ;

int main(){

	int n,r=1;
	while ( cin >> n ){
		int a[ n ],s[ n ];
		for( int i = 0; i < n; i++){
			cin >> a [ i ];
		
		}
		long long best = 0;
		for( int i = 0; i < n; i++){
			long long tmp = 1;
			for(int j = i; j < n; j++){
				tmp *= a[ j ];
				best = max ( tmp , best);
			}

		}
		cout<< "Case #"<<r++<<": The maximum product is " << best <<"." <<endl<<endl;
	}

	return 0;
}
