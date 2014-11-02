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

using namespace std;

map<string,int> dist;

string adj(string s){
	int end,len = s.size();
	end = len -1;
	if (s[end] == 'z'){
		while(s[end]-s[end-1] == 1){
			end--;
		}
		if (!end) {s.insert(0,"a");len++;end++;}
		else s[end-1]++;
		for(int i = end ; i < len ; i++){
			s[i] = s[i-1] + 1;
		}
		
	}else{
		s[end]++;
	}
	return s;
}


void bfs(string end){
	queue<string> q;
	q.push("a");
	dist["a"] = 1;
	while(!q.empty()){
		string v = q.front(); q.pop();
		string  u = adj(v);
		if (!dist[u]){
			q.push(u);
			dist[u] = dist[v] + 1;
			if (u == end) break;
		}
	}
}

int main(){
	string s;
	bfs("vwxyz");
	while(cin>>s){
		cout<<dist[s]<<endl;
	}
	return 0;
}
