#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	
	int runs;
	cin>>runs;
	for(int r = 1; r<=runs; r++){
		int n;
		cin>>n;
		string g[n];
		int si,sj,ei,ej;
		for(int i= 0;i<n;i++) {
			cin>>g[i];
			
			for(int j = 0;j < n;j++){
				if (g[i][j] =='S') si=i,sj=j;
				else if (g[i][j] == 'T') ei=i,ej=j;
			}
		}

		queue<int> q;
		q.push(si),q.push(sj);
		int res=-1;
		int dist[n+1][n+1];
		memset(dist,-1,sizeof dist);
		dist[si][sj]=0;
		while(!q.empty()){
			int x=q.front();q.pop();
			int y=q.front();q.pop();
			if (x==ei&&y==ej) {res=dist[ei][ej];break;}
			for(int i = -1;i<=1;i++)
			for(int j = -1;j<=1;j++){
				if(i==j)continue;
				int xx = x+i;
				int yy = y+j;
				if (xx <0 || yy<0 || y >=n || x >= n) continue;
				if (g[xx][yy]=='#') continue;
				if (dist[xx][yy]==-1){
					dist[xx][yy] = dist[x][y]+1;
					cout<<xx<<" "<<yy<<endl;
					q.push(xx);q.push(yy);
				}
			}
		}
	
		printf("Case %d: %d\n",r,res);
	}

	return 0;
}

