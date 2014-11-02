#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std ;
string g[50];
string usd[ 50 ];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int N;
bool poda = false;
int k ;
vector< vector<pair<int,int> > > pos( 50 );
void back( int x, int y, int T, int cur ){
	if ( poda ) return;
	if ( T == 0 && cur == k/2 )  {
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < N; j++ )
				cout << usd[i][j] <<" ";
			cout << endl;
		}
		cout << endl;
		poda = true;
		return;
	}
	int num ;
	if ( isdigit( usd[x][y] ) ) num = usd[x][y] - '0';
	else num = usd[x][y] - 'A' + 10;

	if ( cur == num  && x == pos[cur][1].first && y == pos[cur][1].second ) {
		back( pos[ cur+1 ][0].first, pos[ cur+1 ][0].second, T , cur + 1 );
		return ;
	}


	for( int i = 0; i < 4; i++){
		int nx = x +dx[i];
		int ny = y +dy[i];
		if ( nx < 0 || ny < 0 || nx >= N || ny >= N ) continue;
		if ( (nx == pos[cur][1].first && ny == pos[cur][1].second ) || usd[nx][ny] == 'X' ) {
			int r = (usd[nx][ny] == 'X');

			char p ;
			if ( isdigit( usd[x][y] ) ) p = cur + '0';
			else p = cur + 'A' - 10;

			usd[nx][ny] = p;
			back( nx, ny, T - r , cur);
			if ( r )
				usd[nx][ny] = 'X';
		}
	}
}

int main(){

	cin >> N;
	 k = 0;
	for(int i = 0; i < N; i++) {
		cin >> usd[i];
		for( int j = 0; j < usd[i].size() ; j++){
			if ( usd[i][j] != 'X' ){
				if ( isdigit( usd[i][j] ) )
					pos[ usd[i][j] - '0' ].push_back( make_pair( i , j ) );
				else
					pos[ usd[i][j] - 'A' + 10 ].push_back( make_pair( i , j ) );
				k++;
			}
		}
	}
	back(pos[1][0].first,pos[1][0].second,N*N-k, 1);

	return 0;
}
