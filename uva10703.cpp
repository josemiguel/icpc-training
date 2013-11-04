#include<iostream>
#include<cstring>
using namespace std ;

int g[505][505];
int n,m,r;
void pinta(int a, int b,int c, int d){
	int res = 0;
	if ( a <= c){
		for(int i = a; i <= c; i++){
			if ( b <= d){
				for(int j = b; j <= d; j++){
					g[i][j] = 1;
					res++;
				}

			}else{
				for(int j = b; j >= d; j--){
					g[i][j] =  1;
					res++;
				}
			}

		}
	}else{
		for(int i = a; i >= c; i--){
			if ( b <= d){
				for(int j = b; j <= d; j++){
					g[i][j] = 1;
					res++;
				}
			}else{
				for(int j = b; j >= d; j--){
					g[i][j] = 1;
					res++;
				}
			}
		}
	}
	

}

int main(){


	while( cin >> n >> m >> r && n + m + r){
		
		memset(g,0,sizeof g);int res=0;
		for(int i = 0; i < r; i++){
			int a,b,c,d;
			cin >> a >> b >> c >> d;


			pinta(a,b,c,d);
		/*	for(int i =1 ; i<= n; i++){
				for(int j = 1; j <=m; j++){
					cout << g[i][j];
				}
				cout<< endl;
			}
			cout<<endl;*/
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				res += !g[i][j];
			}
		}
		if ( res == 0) cout << "There is no empty spots."<<endl;
		else if (res == 1) cout << "There is one empty spot."<<endl;
		else cout <<"There are "<<res<<" empty spots."<<endl;
	}

	return 0;
}
