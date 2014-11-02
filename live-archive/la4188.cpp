#include<iostream>
#include<set>
using namespace std ;
int p[20005],re[2000005];

void Init( int n ) { for(int i= 0; i < n; i++) p[ i ] = re[ i ] = i;}

int Find( int u ){ return (u == p[ u ] ? u : p[ u ] = Find( p[ u ] ) ); }

void Union( int u, int v) {  p[ Find( u ) ] = Find( v ); }


int main(){
	
	int n;
	while(cin >> n){
		int yes = 0,no = 0, r = n + 1;
		Init( r );
		char q;
		while( cin >> q ){
			int u,v;
			if ( q == 'c' ){
				cin >> u >> v;

				Union( re[ u ] ,re[ v ] );

			}else if (q == 'd'){
				cin >> u;

				re[ u ] = p[ r ] = r;

				r++;
			}else if (q == 'q'){
				cin >> u >> v;

				int tmp = (Find( re[ u ] ) == Find( re[ v ] ));

				if ( tmp ) yes++; else no++;
			}else break;

		}
		cout << yes << " , "<< no << endl;
	}
	
}
