#include<cstdio>
#include<stack>
#include<map>
#include<set>
#include<sstream>
#include<cassert>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back
const int inf = (1<<27);
const int N= 200;

int cost[N][N];
int path[N][N];
int tax[N];

void wf(int n){
  rep(k,n){
    rep(i,n){
      rep(j,n){
	if (cost[i][k]+cost[k][j] < cost[i][j]){
	  cost[i][j]=cost[i][k]+cost[k][j];
	  path[i][j]=k;
	}
      }
    }
  }
}

int getdata(string &in){
  stringstream sin(in);
  int cnt=0;
  while(sin>>cost[0][cnt]){
    if (cost[0][cnt] == -1)cost[0][cnt]=inf;
    cnt++;
  }
  return cnt;
}

void oppath(int f,int t){
  if (f==-1||t==-1||path[f][t] == f)return;
  oppath(f,path[f][t]);
  printf("%d-->",path[f][t]+1);
  oppath(path[f][t],t);
}

void solve(int n,int f,int t){

  printf("From %d to %d :\n",f+1,t+1);

  if (f == t){
    printf("Path: %d",f+1);
  }else {
  printf("Path: %d-->",f+1);
  oppath(f,t);
  printf("%d",t+1);
  }

  printf("\n");	
  printf("Total cost : %d\n",cost[f][t]-tax[t]);
}

main(){
  int te;string t;
  cin>>te;getline(cin,t);getline(cin,t);
  while(te--){
    string in;
    getline(cin,in);
    int n=getdata(in);
    REP(i,1,n){
      rep(j,n){
	cin>>cost[i][j];
	if (cost[i][j] == -1)cost[i][j]=inf;
      }
    }

    rep(i,n){
      rep(j,n){
	path[i][j]=i;
      }
      path[i][i]=-1;
    }

    rep(i,n)cin>>tax[i];
    rep(i,n){
      rep(j,n){
	if (cost[i][j]!=inf)cost[i][j]+=tax[j];
      }
    }
    
    wf(n);

    getline(cin,in);
    for(int i=0;getline(cin,in) && in.size();i++){
      if (i)printf("\n");
      stringstream sin(in);
      int f,t;
      sin>>f>>t;
      solve(n,f-1,t-1);
    }
    if(te)printf("\n");
  }
}

