#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<string>
#include<cctype>
#include<set>
#include<map>
#include<numeric>

#define ll long long
#define vi vector<int>
#define mp make_pair
#define oo (1<<20)
#define ones(x) __builtin_popcount(x)
#define clr(x) memset((x),0,sizeof(x))
#define rclr(x) memset((x),-1,sizeof(x))
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)
#define MAX 30

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;
pair<int, pair<int, int> > W[2001];
int x, s, r, n;
double t;
int len;
pair<double, double> v[2000];

bool cmp(const pair<double, double>& A, const pair<double, double>& B){
  return A.y * (r + B.x) > B.y * (r + A.x);
}
double F(){
    double res = 0, torig = t, run, move;
    rep(i,len){
      run = min(t, v[i].y / (v[i].x + r));
      move = run * (v[i].x + r);
      t -= run;
      res += run;
      res += (v[i].y - move) / (double)(v[i].x + s);
    }
    t = torig;
    return res;
}
int main(){
  int tt; scanf("%d", &tt);
  for(int RR = 1; RR <= tt; RR++){
    cin >> x >> s >> r >> t >> n;

	rep(i,n) cin >> W[i].y.x >> W[i].y.y >> W[i].x;
    sort(W, W + n);

    int TOT = x;
    len = 0;
    rep(i,n){
        TOT -= W[i].y.y - W[i].y.x;
        v[len++] = mp(W[i].x, W[i].y.y - W[i].y.x);
    }
    v[len++] = mp(0, TOT);
    sort(v, v + len, cmp);
    double res = F();
    sort(v, v + len);
    res = F();
    cout << "Case #" << RR << ": ";
    printf("%.08f\n", res);

  }
}
