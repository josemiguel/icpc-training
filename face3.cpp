#include <iostream>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <numeric>
#define FOR(i,A) for(typeof (A).begin() i = (A).begin() ; i != (A).end() ; i++)
#define mp make_pair
#define clr(v,x) memset( v, x , sizeof v ) 
#define all(x) (x).begin() , (x).end()
#define TAM 30

using namespace std;

typedef pair<int,int> ii ;
typedef long long LL ;
typedef pair<int,ii> pii ;

int ms[ TAM ] ;
string cad = "HACKERCUP" ;

int main(){

	int test ;
	string s ;
	cin >> test ;
	cin.ignore() ;
	for(int k = 1 ; k <= test ; k++){
		getline( cin , s ) ;
		clr( ms , 0 ) ;
		for(int i = 0 ; i < s.size() ; i++){
			if( s[ i ] == ' ' ) continue ;
			char c = s[ i ] - 'A' ;
			ms[ c ]++ ;
		}
		int resp = 1<<30 ;
		for(int i = 0 ; i < cad.size() ; i++){
			char c = cad[ i ] - 'A' ;
			resp = min( resp , ms[ c ] ) ;
		}
		printf("Case #%d: %d\n", k , resp ) ;
	}
	return 0 ;
}
