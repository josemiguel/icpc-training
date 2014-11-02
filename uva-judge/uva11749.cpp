#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

class DisjointSet{
public:
  vector<int> rank,p;
  
  DisjointSet(){};
  DisjointSet(int n){
    rank.resize(n);
    p.resize(n);
  }
  void make_set(int x){
    p[x]=x;
    rank[x]=0;
  }
  void merge(int x,int y){
    link(find_set(x),find_set(y));
  }
  void link(int x,int y){
    if ( rank[x] > rank[y]){
      p[y]=x;
    }else {
      p[x]=y;
      if  (rank[x]==rank[y])rank[y]++;
    }
  }
  int find_set(int x){
    if (x != p[x] )p[x]=find_set(p[x]);
    return p[x];
  }
};



class Edge{
public:
  int f,t,c;
  bool operator<(const Edge& a)const{
    return c > a.c;
  }
 
};

Edge in[1000000];
int num[500];
int ppa[500];


int solve(int n,int m){
  int cnt = 0;
  DisjointSet dj(n);
  rep(i,n)dj.make_set(i);
  sort(in,in+m);
    rep(i,n)num[i]=0,ppa[i]=-1;
  int maxcost=in[0].c;

  rep(i,m){
    if ( in[i].c != maxcost)break;
    dj.merge(in[i].t,in[i].f);
  }


  rep(i,n){
    num[dj.find_set(i)]++;
  }

  int ans = 0;
  rep(i,n){
    ans=max(ans,num[i]);
  }
  return ans ;
}

main(){
  int n,m;
  while(cin>>n>>m ){
    if ( n == 0 && m== 0)break;
    rep(i,m){
      cin>>in[i].f>>in[i].t>>in[i].c;
      in[i].f--;
      in[i].t--;
    }
    cout << solve(n,m) << endl;
  }
}


