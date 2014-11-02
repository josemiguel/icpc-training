#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define MAXN 52
using namespace std;

int n,m;

int g[MAXN][MAXN];

int dx[] = { 1 , 0, -1 , 0};
int dy[] = { 0, -1,  0 , 1};


bool foo(pair<char,int> x, pair<char,int> y){
	if (x.second > y.second){
		return true;			
	}else if (x.second == y.second){
		if (x.first < y.first){
			return true;
		}
	}
	return false;
}



inline bool in(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int nodos;

void dfs(int x, int y, char c){
    g[x][y] = '*';
    nodos++;
    for(int i = 0; i < 4 ; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (in(xx,yy)){
            if (g[xx][yy] == c){
                dfs(xx,yy,c);
            }
        }
    }
}

int main(){
	int r = 1;
	while(scanf("%d%d",&n,&m) && n+m){
		getchar();
		int p[28] = {0};
		vector<pair<char,int> > v;

		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m; j++){
				g[i][j] = getchar();
				p[g[i][j]-'A'] = 1;
			}
			getchar();
		}
		for(int k = 0;  k < 28; k++){
			if (p[k]){
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m ; j++){
						if (g[i][j] - 'A' == k){
							nodos = 0;
							dfs(i,j,g[i][j]);
							v.push_back(make_pair(k+'A',nodos));
						}	
					}
				}
			}
		}
		
		sort(v.begin(),v.end(),foo);
		
		printf("Problem %d:\n",r++);
        for(int i = 0; i < v.size() ; i++){
        	printf("%c %d\n",v[i].first,v[i].second);        	
        }
        		

		
	}
	
	
		
	return 0;
}
