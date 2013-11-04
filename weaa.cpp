
 #include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int gcd(int a, int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N,K,Q;
  scanf("%d%d",&N,&K);
  double A[N];
  bool was[N];
  REP(i,N)scanf("%lf",&A[i]);
  REP(i,N)was[i] = false;
  scanf("%d",&Q);
  int W = N/K;
  int card[W];
  
  double mini = 1000;
  double maxi = -1000;
  
  REP(i,Q){
    REP(j,W)scanf("%d",&card[j]);
    REP(j,W)--card[j];
    if(was[card[0]])continue;
    --K;
    double sum = 0;
    REP(j,W) {
      was[card[j]] = true;
      sum += A[card[j]];
    }    
    sum /= W;
    mini = min(mini, sum);
    maxi = max(maxi, sum);
  }
  
  if(K) {
    vector<double> rest;
    REP(i,N)
      if(!was[i])
        rest.pb(A[i]);
    sort(rest.begin(), rest.end());
    
    double s1 = 0;
    REP(i,W)
      s1 += rest[i];
    mini = min(mini,s1/W);
    
    double s2 = 0;
    FOR(i,rest.size()-W, rest.size())
      s2 += rest[i];
    maxi = max(maxi,s2/W);    
  }  
  
  printf("%0.9lf %0.9lf\n",mini,maxi);
}
