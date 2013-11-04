#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std ;
typedef long long Int;
int F( Int a, Int b,Int c){
	if ( a <= 0 || b <= 0 || c <= 0 ) return false;
	return a < b+c && b < a+ c && c < a+b;
}

int main(){

	int runs;
	cin >> runs;
	char res[][15] ={"Invalid","Equilateral","Isosceles","Scalene"};
	for(int r = 1; r <= runs; r++){
		Int a,b,c;
		int k = 0;
		cin >> a >> b >> c;
		if ( F( a,b,c)){
			if ( a == b && b == c) k = 1;
			else if ( a == b || b == c || a == c) k = 2;
			else k = 3;
		}
		
		printf("Case %d: %s\n", r, res[k]);
	}

	return 0;
}
