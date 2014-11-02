#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std ;

int n;
int dp[1005][1005];
int ta, tb;
bool done = false;
bool F( int a, int b){
	if ( done ) return false;
	if ( b == n ) return done = true;
		
	if (dp[a][b] != -1) return dp[a][b];

//	cout << a << " " << b << endl;
	int &res = dp[a][b] = 0;


	res |= F( ta, b );
	res |= F( a, tb );
	res |= F( 0 , b );
	res |= F( a , 0 );

	if ( a+b >= tb){
		res |= F( a - (tb-b) , tb );
	}else{
		res |= F( 0 , a + b );
	}

	if ( a+b >= ta){
		res |= F( ta , b - (ta-a) );
	}else{
		res |= F(  a + b,0 );
	}

	return res;
}

void track( int a, int b){
	if ( b == n ) return;
	if ( a < 0 || a > ta || b < 0 || b > tb) return;


	if ( F(ta, b) ){
		cout << "fill A" << endl;
		track( ta, b );
	}else if ( F( a, tb )) {
		cout << "fill B" << endl;
		track( a, tb );
	}else if ( F( 0 , b ) ){
		cout << "empty A" << endl;
		track (0,b);
	}else if ( F( a, 0 ) ){
		cout << "empty B" << endl;
		track( a, 0) ;
	}else if (F( a+b>=tb?a - (tb-b):0 ,a+b>=tb? tb:a+b )){
		cout << "pour A B" << endl;
		track ( a+b>=tb?a-(tb-b):0, a+b>=tb?tb:a+b);
	}else if ( F(a+b>=ta? ta :a+b, a+b>=ta?b - (ta-a):0 )){
		cout << "pour B A"<<endl;
		track( a+b>=ta?ta:a+b,a+b>=ta?b-(ta-a):0);

	}	

}
int main(){
	while (cin >> ta >> tb >> n  ){
		int i;
		memset( dp, -1, sizeof dp);
		done = false;
		cout << F( 0,0 ) << endl;
		track( 0, 0);
		cout <<"success"<<endl;
	}

	return 0;
}
