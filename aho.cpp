#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;

#define forc(c) for(char c = 0; c < 30; c++)
int N,out[101000],f[101000];
int g[101000][30];
int dist[101000];
void reset(){
	N = 1;
	out[0] = false;
	memset(g,-1,sizeof g);
	memset(f,0,sizeof 0);
	memset(dist,0,sizeof dist);	
}

void add(string s){
	int node = 0;
	for(int i = 0; i < s.size(); i++){
		char c = s[i]-'a';
		if (g[node][c] == -1){
			out[N] = false;
			g[node][c] = N++;
		}
		node = g[node][c];
	}
	out[node] = true;
}

int create(){
	queue<int> Q;
	forc(c){
		if (g[0][c] != -1) {
			f[g[0][c]] = 0;
			Q.push(g[0][c]);
		}
		else g[0][c] = 0;
	}
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		forc(c){
			int v = g[u][c];
			if (v == -1) continue;
			int t = f[u];
			while(t != 0 && g[t][c] == -1) t = f[t];
			f[v] = g[t][c];
			dist[v] = max(dist[f[v]],dist[u]) + out[v];
			out[v] |= out[f[v]];
			Q.push(v);
		}
	}
	
	int res = 0;
    for(int i = 0; i < N; i++) res = max(res, dist[i]);
	return res;
}


int main(){
	int n;
    while(cin>>n && n){
    	reset(); 
	    for(int i = 0; i < n; i++){
			string s; cin>>s;
			add(s);
	    }

	    cout<<create()<<endl;
//	    printf("%d\n",make_fail());
    }
		
	
	return 0;
}
