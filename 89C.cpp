#include<iostream>
#include<string>
using namespace std ;

int N,M;
string g[5001];
short int back[5001][5001][2], next[5001][5001][2];

void play(int x, int y){
    if(next[x][y][0] != -1) back[next[x][y][0]][y][0] = back[x][y][0];
    if(back[x][y][0] != N) next[back[x][y][0]][y][0] = next[x][y][0];
    if(next[x][y][1] != -1) back[x][next[x][y][1]][1] = back[x][y][1];
    if(back[x][y][1] != M) next[x][back[x][y][1]][1] = next[x][y][1];
}
bool cagao (int x, int y){
	return x < 0 || y < 0 || x >= N || y >= M;
}
int F(int x, int y){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			back[i][j][0] = next[i][j][0] = i;
	        back[i][j][0]++; next[i][j][0]--;
	        back[i][j][1] = next[i][j][1] = j ;
    	    back[i][j][1]++; next[i][j][1]--;
		}
	}
	
	for(int i= 0 ; i < N; i++){
		for(int j = 0; j < M; j++){
			if ( g[i][j] == '.' )
				play( i , j );
		}
	}
	int res = 0;
	while ( !cagao(x, y) ){
		play ( x, y );
		char c = g[x][y];
		if ( c == 'U') x = next[x][y][0];
		else if ( c == 'D') x = back[x][y][0];
		else if ( c == 'L') y = next[x][y][1];
		else if ( c == 'R') y = back[x][y][1];
		res++;
	}
	return res;
}

int main(){

	while ( cin >> N >> M ){
		for(int i = 0; i < N; i++){
			cin >> g[i];
		}
		int best = -2, ways = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if ( g[i][j] != '.'){
					int tmp = F(i,j);
					if ( tmp == best){
						ways++;

					}else{
						if ( tmp > best ){
							best = tmp;
							ways = 1;
						}
					}
				
				}
			}
		}
		while ( best == -2);
		cout << best << " " << ways << endl;
	}

	return 0;
}
