#include<iostream>
#include<string>
using namespace std;
#define MAX 105
char g[MAX][MAX];
int fx,fy;
int n,m;

bool busca(string s, int x, int y, int r){
	if (r == 0){
		int i,j;
		for(i = x, j = 0; j < s.size() && i < n && s[j] == g[i][y] ; i++, j++);
		fx = i-1; fy = y;
		if (j == s.size()) return true;
	}else if (r == 1){
		int i,j;
		for(i = x, j = 0; j < s.size() && i >= 0 && s[j] == g[i][y] ; i--, j++);
		fx = i+1; fy = y;		
		if (j == s.size()) return true;
	}else if (r == 2){
		int i,j;
		for(i = y, j = 0; j < s.size() && i < m && s[j] == g[x][i] ; i++, j++);
		fx = x; fy = i-1;
		if (j == s.size()) return true;
	}else if (r == 3){
		int i,j;
		for(i = y, j = 0; j < s.size() && i >= 0 && s[j] == g[x][i] ; i--, j++);
		fx = x; fy = i+1;		
		if (j == s.size()) return true;
	}else if (r == 4){
		int i,j,k;
		for(i = x , j = y, k = 0; i < n && j < m && g[i][j] == s[k]; i++, j++,k++);
		fx = i-1, fy = j-1;
		if (k == s.size()) return true;
	}else if (r == 5){
		int i,j,k;
		for(i = x , j = y, k = 0; i >= 0 && j < m && g[i][j] == s[k]; i--, j++,k++);
		fx = i+1, fy = j-1;
		if (k == s.size()) return true;
	}else if (r == 6){
		int i,j,k;
		for(i = x , j = y, k = 0; i < n && j >= 0 && g[i][j] == s[k]; i++, j--,k++);
		fx = i-1, fy = j+1;
		if (k == s.size()) return true;
	}else if (r == 7){
		int i,j,k;
		for(i = x , j = y, k = 0; i >= 0 && j >= 0 && g[i][j] == s[k]; i--, j--,k++);
		fx = i+1, fy = j+1;
		if (k == s.size()) return true;
	}
	
	return false;
}

int main(){
	
	cin>>n;
	m = n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>g[i][j];
		}
	}
	string s;
	while(cin>>s && s != "0"){
		bool f = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int K = 0; K < 8; K++){
					if (busca(s,i,j,K)) {
						f = true;
						cout<<i+1<<","<<1+j<<" "<<fx+1<<","<<fy+1<<endl;
						break;						
					}
				}
				if (f) break;
			}
			if (f) break;
		}
		if (!f) cout<<"Not found"<<endl;
	}
}
