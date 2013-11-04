#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef long long Int;
int n;
Int dp[15][2];
int a[15],b[15];;

Int F(int pos, bool last ){
	if ( pos == n ) return 1LL;
	if ( dp[ pos ][ last ] != -1 ) return dp[ pos ][ last ];
	
	if ( last && a[pos] < b[pos] ) return 0;
	Int res = 0;

	if ( a[ pos ] != 10 ){
		res += F(pos + 1, last && ( a[pos] == b[pos] ) );
	}else{
		int ini = last ? b[pos] : 0;
		if (pos == n - 1 && last) {
			ini++;
		}
		//cout << "ini  : " << ini << endl;
		for (int i = ini; i <= 9; i++){
			res += F(pos + 1 , last && ( b[pos] == i ) );
		}
	}

	return dp[ pos ][ last ] = res;
}


int main(){
	string A,B;
	while( cin >> A ){
		if (A == "#") break;
		cin >> B;
		n = A.size();
		if ( A == B ) {
			cout<<0<<endl;
			continue;
		}

		for(int i = 0; i < n; i++){
			a[ i ] = A[ i ] - '0';
			if (A[i] == '?') a[i] = 10;
			b[ i ] = B[ i ] - '0';
		}
		memset( dp , -1 , sizeof dp );
		Int res = F(0, 1 );
		
		cout << res << endl;

	}
	return 0;


}
