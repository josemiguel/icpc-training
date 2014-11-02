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

#define MAXN 1002

int dist[MAXN];

vector<int> fill(int n){
	int i,k;
	vector<int> v;
	int nn = n;
	for(i = 2 ; i*i <= n ; i++){
		int a=0;
        while(n%i==0){
            n/=i;
            a++;
        }
        if(a!=0) v.push_back(i);
    }
    if(n>1 && n!=nn) v.push_back(n);
    
	return v;
}

int bfs(int A, int B){
	queue<int> q;
	q.push(A);

	memset(dist,0,sizeof(dist));
	while(!q.empty()){
		int v = q.front();q.pop();
		vector<int> fs =  fill(v);
		if (v == B) return dist[B];
		for(int i = 0; i < fs.size() ; i++){
			int u = v + fs[i];
			if (!dist[u]  && u <= B){
				q.push(u);
				dist[u] = dist[v] + 1;
			}
		}
	}
	return -1;
}

//cout<<v<<" + "<<f[v][i]<<" = "<<u<<endl;

int main(){
	
	int r = 1, A, B;
	while(scanf("%d%d",&A,&B)!=-1 && A+B){
		printf("Case %d: %d\n",r++,bfs(A,B));
	}

	return 0;
}
