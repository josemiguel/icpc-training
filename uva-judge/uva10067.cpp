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

int paso[2] = {9,1};

int dist[10][10][10][10];

struct conf{//configuracion
	int m[4];
	conf(int a,int b,int c, int d){
		m[0] = a;
		m[1] = b;
		m[2] = c;
		m[3] = d;
	}
	conf (){}
	
	conf (conf const&v){
		for(int i = 0; i < 4; i++){
			m[i] = v.m[i];
		}
	}
	
	bool operator ==(conf o){
		return (m[0]==o.m[0]  && m[1]==o.m[1] && m[2]==o.m[2] && m[3]==o.m[3] );
	}

};

int bfs(conf start,conf end,vector<conf> forb){
	queue<conf> q;
	q.push(start);
	memset(dist,0,sizeof(dist));
	while(!q.empty()){
		conf v = q.front(); q.pop();
		if ( v == end ) return dist[v.m[0]][v.m[1]][v.m[2]][v.m[3]];
		for(int k = 0; k < 4;k++){
			for(int i = 0 ; i < 2; i++){
				conf u(v);
				u.m[k] = (v.m[k] + paso[i])%10;
				if (!dist[u.m[0]][u.m[1]][u.m[2]][u.m[3]]){
					bool NO = false;
					for(int j = 0; j < forb.size(); j++){
						if (forb[j] == u){
							NO = true;
							break;		
						}
					}
					if (!NO){
						q.push(u);
						dist[u.m[0]][u.m[1]][u.m[2]][u.m[3]] = dist[v.m[0]][v.m[1]][v.m[2]][v.m[3]] + 1;
					}
				}
			}
		}
	}
	
	return -1;

}

int main(){
	int N,n;
	scanf("%d",&N);
	while(N--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		conf start(a,b,c,d);
		scanf("%d%d%d%d",&a,&b,&c,&d);
		conf end(a,b,c,d);
		scanf("%d",&n);
		vector<conf> v;
		while(n--){
			scanf("%d%d%d%d",&a,&b,&c,&d);		
			conf forb(a,b,c,d);
			v.push_back(conf(forb));
		}
		printf("%d\n",bfs(start,end,v));
		
		
	}
	return 0;
}
