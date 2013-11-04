#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#define REPN(i,a,N) for( int i = (int)a ; i < (int) N ; i++ )
#define REP(i,N) REPN(i,0,N)
#define all(x) x.begin(),x.end()
#define MAXN 500
#define MAXM 500

using namespace std;

typedef pair< int , int > pii;

int matchL[MAXN];
int matchR[MAXM];
int seen[MAXM];
vector< int > adj[MAXN];
int path( int u  ){
	REP( i , adj[u].size() ){
		int v = adj[u][i];
		if( seen[v] ) continue;
		seen[v] = 1;
		if( matchR[v] == -1 or path( matchR[v] ) ){
			matchR[v] = u;
			matchL[u] = v;
			return 1;
		}
	}
	return 0;
}
	

int bmp( int n , int m ){
	int res = 0;
	REP( i , n ){
		REP( j , m ) seen[j] = 0;
		res += path( i );
	}
	return res;
}

int init_bmp( int n ,  int m  ){
	REP( i , n ) adj[i].clear();
	REP( i , n ) matchL[i] = -1;
	REP( i , m ) matchR[i] = -1;
}

int main(){
   int cases,caseno;
   
   scanf("%d",&cases);
   for(caseno=1;caseno<=cases;caseno++){
	int n,m;
  scanf("%d%d",&n,&m);
   init_bmp(n,m);     
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
      	int k;
        scanf("%d",&k);
        if (k) adj[i].push_back(j);
      }
   }

      int bestmatched = bmp( n , m ); 
      printf("Case %d: ",caseno);
      printf("a maximum of %d nuts and bolts ",bestmatched);
      printf("can be fitted together\n");
   }
	return 0;
}

