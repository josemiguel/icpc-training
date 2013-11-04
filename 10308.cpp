#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define mp make_pair
#define to first
#define co second
#define N 10000
typedef pair<int,int> Edge;

vector<Edge> edge[N];
bool visited[N];
int cost[N];
void dfs(int now,int tc){
  visited[now]=true;
  cost[now]=tc;
  rep(i,edge[now].size()){
    if ( visited[edge[now][i].to] == false)
      dfs(edge[now][i].to,tc+edge[now][i].co);
  }
}


int solve(int n){
  rep(i,n)visited[i]=false,cost[i]=0;
  dfs(0,0);
  int farthest = 0;
  REP(i,1,n){
    if ( cost[farthest]<cost[i])farthest=i;
  }
  rep(i,n)visited[i]=false,cost[i]=0;
  dfs(farthest,0);
  farthest=0;
  REP(i,1,n){
    if ( cost[farthest]<cost[i])farthest=i;
  }
  return cost[farthest];
}


void get_input(string &in,int &n){
  stringstream sin(in);
  int f,t,c;
  sin>>f>>t>>c;
  edge[f-1].push_back(mp(t-1,c));
  edge[t-1].push_back(mp(f-1,c));
  n = max(n,max(f-1,t-1));
}

main(){
  string in;
  while(getline(cin,in) ){
    int n=0;
    rep(i,N)edge[i].clear();
    if ( in.size()){
      get_input(in,n);
      while(getline(cin,in) && in.size() != 0){
	get_input(in,n);
      }
    }
    n++;
    cout << solve(n ) << endl;
  }
}

