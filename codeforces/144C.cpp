#include<iostream>
#include<cstring>
#include<cstdio>

char s[100005],p[100005];

using namespace std;
int sc[300],pc[300];
int main(){
	gets( s );
	gets( p );
	int plen = strlen( p );
	int slen = strlen( s );
	for( int i = 0; i < plen; i++){
		pc[p[i]]++;
	}
	int res = 0; bool cagao;
	for( int i = 0; i < slen; i++){
		memset( sc, 0, sizeof sc);
		for(int j = i,k = 0; k < plen;j++,k++){
			if ( s[j] !='?'&& pc[s[j]] == 0) goto hell;
			if ( sc[s[j]]++);
		}
		 cagao = false;
		for( int c = 'a'; c <='z';c++){
			if (sc[c] > pc[c]){
				cagao = true;
			}
		}
		if ( !cagao ) res++;
		hell:;
	}
	cout << res << endl;

}
