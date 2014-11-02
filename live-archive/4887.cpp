#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std ;

vector<pair<int,int> > play( vector<pair<int,int> > t, int f , int g, int u ){

	t[u].first += f;
	t[u].second += g;

	return t;
}

vector<int> best,worst;
vector<pair<int,int > > sc;
vector<pair<int,int> > np;

void F( vector<pair<int,int>  > t, int u ){
	if ( u == t.size() ){
		vector< pair<int,int> > tsc = sc;
		for( int j = 0; j < t.size() ; j++){
			int a = np[ j ].first;
			int b = np[ j ].second;
			tsc[ a ].first += t[ j ].first;
			tsc[ b ].first += t[ j ].second;
		}
		sort( tsc.rbegin() , tsc.rend());
		int ant = -1;
		for( int i = 0, j = 0; i < tsc.size(); i++ ){
			if ( tsc[i].first != ant || ant == -1 ) j = i ;
			best[ tsc[i].second ] = min( best[ tsc[i].second ], j+1);
			worst[ tsc[i].second ] = max( worst[ tsc[i].second ], j+1);
			ant = tsc[i].first ;
		}
		return ;
	}

	F( play( t , 1 , 1 , u), u + 1 );
	F( play( t , 3 , 0 , u), u + 1 );
	F( play( t , 0 , 3 , u), u + 1 );
}

map<string,int> mp;
vector<string> team;
int main(){
	int n , m;
	int r = 0;
	while( cin >> n >> m && n + m ){
		if( r ) cout << endl;
		r++;
		mp.clear();
		sc = vector<pair<int,int > > (n, make_pair(0,0) );
		best = vector<int> (n, 1<<30);
		worst = vector<int> (n, 0 );
		team = vector<string> ( n );
		np.clear();
		for( int i = 0; i < n; i++ ) cin >> team[i], mp[team[i]] = i, sc[ i ].second = i;
		for( int i = 0; i < m; i++ ){
			string a,b,c;
			int pa,pb;
			cin >> a >> c >> b >> pa >> pb;
			b.resize(b.size()-1);
			if ( pa == -1 && pb == -1 ) {
				np.push_back( make_pair( mp[a], mp[b] ) );	
				continue;
			}

			int p = pa > pb ? 3 : ( pa == pb ? 1 : 0 ) ;
			int q = pb > pa ? 3 : ( pa == pb ? 1 : 0 ) ;
			sc[ mp[a] ].first += p;
			sc[ mp[b] ].first += q;

		}
		vector<pair<int,int> > t( np.size(), make_pair(0,0) );
		F( t, 0 );
		for( int i = 0; i < n; i++){
			string high = best[i] == 1 ? "st" : best[i] == 2 ? "nd" : best[i] == 3 ? "rd" : "th";
			string low = worst[i] == 1 ? "st" : worst[i] == 2 ? "nd" : worst[i] == 3 ? "rd" : "th";
			cout <<"Team "<<team[i]<<" can finish as high as "<<best[i]<<high<<" place and as low as "<<worst[i]<<low<<" place.\n";
		}
	}


	return 0;
}
