#include<iostream>
using namespace std;
int bit[50005], N ;
int get( int x ) {
	int sum = 0;
	for( ; x > 0; x-=x&-x){
		sum += bit[x];
	}
	return sum;
}
void update( int x, int val ){
	for( ; x <= N ; x+=x&-x){
		bit[x] += val;
	}
}

int main(){
	
	int N, x,M;
	cin >> N;
	for( int i = 1; i <= N; i++) cin >> x, update( i , x);
	cin >> M;
	for( int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cout << get( b ) - get( a - 1 ) << endl;
	}
		

	return 0;
}
