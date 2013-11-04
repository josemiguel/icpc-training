#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
using namespace std ;
string g[10];


struct state{
	int x, y, ver;
	state(int x, int y, int ver): x(x), y(y), ver(ver) {}
};
int dx[]={-1,-1,-1,0,0,1,1,1,0};
int dy[]={-1,0,1,-1,1,-1,0,1,0}; 
bool usd[ 10 ][ 10 ][ 100 ];
int main(){
	vector<pair<int,int> > S;
	
	for(int i = 0; i < 8; i++) cin >> g[i];

	for(int i = 0; i < 8; i++) 
		for(int j = 0; j < 8; j++)
			if (g[ i ][ j ] == 'S') S.push_back(make_pair( i , j ));

	queue< state > Q;
	
	Q.push( state ( 7, 0 , 0 ) );
	
	memset(usd, 0, sizeof usd );
	
	usd[ 7 ][ 0 ][ 0 ] = true;
	
	while(!Q.empty()){
	
		state v = Q.front();Q.pop();
		

		for(int i = 0; i < 9; i++){
			int nx = dx[i] + v.x;
			int ny = dy[i] + v.y;
			int nver = v.ver + 1;
			if ( nx < 0 || ny < 0 || nx > 7  || ny > 7 ) continue;
			bool cagao = false;
			for(int j = 0; j < S.size(); j++){
				if ( ny == S[j].second && nx == S[j].first + v.ver) cagao = true;
			}
			for(int j = 0; j < S.size(); j++){
				if ( ny == S[j].second &&  nx == S[j].first + nver) cagao = true;
			}
			if ( cagao ) continue;
			if (nver > 40) continue;
			if ( usd[ nx ][ ny ][ nver ] ) continue;

			Q.push( state( nx, ny, nver ) );
			usd[ nx ][ ny ][ nver ] = true;

		}
	}
	
	bool win = false;
	for(int k = 0; k < 20; k++){
		if ( usd[ 0 ][ 7 ][ k ]) win = true;
	}

	if ( win ){
		cout << "WIN" << endl;
	}else{
		cout << "LOSE" << endl;
	}



	return 0;
}
