#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
#include<map>

using namespace std;
#define MAXN 1024

char g[MAXN][MAXN];

int dx[] = { 1 , 0, -1 , 0};
int dy[] = { 0, -1,  0 , 1};

int n,m;

inline bool in(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y, char c){
    g[x][y] = '*';
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

bool operator <(pair<char,int> x, pair<char,int> y){
	if (x.second < y.second){
		return true;			
	}else if (x.second == y.second){
		if (x.first > y.first){
			return true;
		}
		return false;
	}
	return false;
}




int main(){
    int rr;
    scanf("%d",&rr);
    for(int r = 1; r <= rr; r++){
        scanf("%d%d",&n,&m);
        bool existe[28];
        memset(existe,false,sizeof(existe));
        getchar();
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < m ; j++){
                g[i][j] = getchar();
                existe[g[i][j]-'a'] = true;
            }
            getchar();
        }
       pair<char,int> arr[28];
       memset(arr,0,sizeof(arr));
       for(int k = 0; k < 28 ; k++){
	       if (existe[k])for(int i = 0; i < n ; i++) for(int j = 0; j < m ; j++)
	            if (g[i][j] == (k + 'a')){
	 	           dfs(i,j,g[i][j]);
   	               arr[k].first = k +'a';       
                   arr[k].second++;
                }
       }
        

//		sort(arr,arr+28);WTF no me corrio el sort
		for(int i = 0; i < 27; i++){
			for(int j = i+1 ; j < 28; j++){
				if (arr[i] < arr[j]) {
					swap(arr[i],arr[j]);
				}
			}
		}
		
        printf("World #%d\n",r);
        for(int i = 0; i < 28 ; i++){
        	if (arr[i].first)
	        	printf("%c: %d\n",arr[i].first,arr[i].second);        	
			
        }
        
    }
    return 0;
}
