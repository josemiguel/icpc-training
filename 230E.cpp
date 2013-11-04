#include<iostream>
#include<cstdio>
using namespace std ;
typedef long long Int;
Int g[1000005];
int main(){

	Int n , m ;
	cin >> n >> m;
	Int res = n*(n-1)*(n-2);
	res /= 6;
	int a;
	for( int i = 0; i < 2*m; i++){
		scanf("%d",&a);
		g[a]++;
	}
	Int quita = 0;
	for( int i = 1; i <= n; i++){
		quita += (g[i]*(n-1-g[i]));
	}
	cout << res - quita/2 << endl;

	return 0;
}
