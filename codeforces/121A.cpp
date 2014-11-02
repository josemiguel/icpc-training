#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long Int;
vector< Int > a;

vector< Int > v;

void F( int len, Int sum ){

	if (len == 1) return;
	if (sum)a.push_back( sum );

	F( len - 1, sum * 10 + 4 );
	F( len - 1, sum * 10 + 7 );
	
}

#define All(x) x.begin(),x.end()
int main(){
	F( 10 , 0 );


	sort(All(a));
	for (int i = 0; i < 10; i++){
		cout << a[i]<<endl;
	}
	int l, r;
	cin >> l >> r;
	
	int lo = 0;

	for (int i = 1; i < a.size(); i++){
		if ( a[ i ] < l ) lo = i;
		else break;
	}

	int hi = 0;

	for (int i = 1; i < a.size(); i++) {
		if ( a[ i ] < r ) hi = i;
		else break;
	}

	for (int i = lo; i <= hi; i++){
		v.push_back( a[ i ] );
	}
	int pos = l - 1;
	Int ans = 0;
	for (int i = 0; i < v.size(); i++){
		ans += v[ i ] * ( v[ i ] -  pos  ) ;
		pos = v[ i ];
	}

	cout << ans << endl;


	return 0;
}
