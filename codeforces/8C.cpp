#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[1<<24];
int dist[30][30],d[30],n;
int F(int mask){
	if (mask == 0) return 0;
	if (dp[mask] != -1) return dp[mask];
	int res = 0;
	for(int i = 0; i < n; i++){
		if (mask & (1 << i)){
			res = 2*d[i] + F(mask ^ (1<<i));
			for(int j = 0; j < n; j++){
				if (i != j && (mask&(1<<j))){
					int tmp = d[i] + dist[i][j] + d[j] + F(mask ^ (1<<i) ^ (1<<j));
					if ( tmp < res ){
						res = tmp;
					}
				}
			
			}
			break;
		
		}
	}
	return dp[mask] = res;
}


void path(int mask){
	if (mask == 0) return;
	int who = 1;
	int u,v,res = 0;
	for(int i = 0; i < n; i++){
		if (mask & (1 << i)){
			u = i;
			res = 2*d[i] + dp[mask ^ (1<<i)];
			
			for(int j = 0; j < n; j++){
				if (i != j && (mask&(1<<j))){
					int tmp = d[i] + dist[i][j] + d[j];
					tmp += dp[mask ^ (1<<i) ^ (1<<j)];
					if ( tmp < res ){
						res = tmp;
						who = 2;
						v = j;
					}
				}
			
			}
			break;
		
		}
	}
	if (who == 1){
		cout<<" "<<u+1<<" 0";
		path(mask ^ (1<<u));
	}else if (who == 2){
		cout<<" "<<u+1<<" "<<v+1<<" 0";
		path(mask ^ (1<<u) ^ (1<<v));
	}

}

int main(){
	
	
	vector<pair<int,int> > p;
	int x,y;
	cin>>x>>y;
	cin>>n; 
	for(int i = 0; i < n; i++){
		int u,v;
		cin>>u>>v; p.push_back(make_pair(u,v));
	}
	for(int i = 0; i < n; i++) d[i] = (p[i].first-x)*(p[i].first-x) + (p[i].second-y)*(p[i].second-y);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[i][j] = dist[j][i] = (p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second);
		}
	}
	memset(dp,-1,sizeof dp);
	cout<<F((1<<n)-1)<<endl;
	cout<<0;
	path((1<<n)-1);
	return 0;
}
