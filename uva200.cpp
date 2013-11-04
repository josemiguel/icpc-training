#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>

using namespace std;
#define N 30
vector<int> g[N];
string tops;
int visited[N];

int dfs_visit(int v){
	visited[v]=0;
	for(int i = 0; i < g[v].size() ; i++){
		int u = g[v][i];
		if (visited[u]==-1) dfs_visit(u);
	}
	tops = (char)(v+'A') + tops;
}

void dfs(){
	for(int v = 0 ; v < N; v++)
		if (visited[v]==-1)	dfs_visit(v);
}

int main(){

	vector<string> st;
	int n=0;
	char c;
	while(1){
		string s = "";
		while((c = getchar()) && c!='\n' && c!='#'){
			visited[c-'A'] = -1;
			s+=c;
		}
		if (c == '#') break;
		st.push_back(s); 
		n++;
	}
	tops = "";
	for(int i = 0; i < n-1 ;i++){
		int min_len = min(st[i].size(),st[i+1].size());
		for(int k = 0 ; k < min_len; k++){
			if (st[i][k] == st[i+1][k]) continue;
            else{
            	g[st[i][k]-'A'].push_back(st[i+1][k]-'A');
                break;
            }
 
		}
	}
	
	
	dfs();
	cout<<tops<<endl;
	return 0;
}


