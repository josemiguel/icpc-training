#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std ;

bool f(int &h, int &m){
	if ( h % 10 == m / 10 && m % 10 == h / 10 ) return true;
	if ( m == 59 ) 
		h = ( h + 1 ) % 24;
	m = ( m + 1 ) % 60;
	
	return false;	
}

int main(){
	int hh,mm;
	scanf("%d:%d",&hh,&mm);
	if ( f( hh, mm) ) {
		mm = (mm+1)%60;
		hh = (hh+1)%24;
	}
	while ( !f(hh,mm) ){
	}
	printf("%02d:%02d\n",hh,mm);

	return 0;
}
