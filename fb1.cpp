#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){

 ios_base::sync_with_stdio(false);

 int test ;
 cin >> test;
 long long X;
 while( test-- ){
 cin >> X;
 long long res = 0;
 for( long long i = 0 ; (i*i*2LL) <= X ; i++ ){

 long long a = i;
 long long sqrb = X - a*a;
 long long b = sqrt(sqrb);
 if( b*b == sqrb ){

 if( X == a*a + b*b ) res++;
 }
 }
 cout << res << endl;

 }
 return 0; 
 }
