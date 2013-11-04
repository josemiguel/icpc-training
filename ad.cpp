#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<sstream>
#include<cctype>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin,x.rend()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define INF 1<<30
#define x first
#define y second
#define ll long long
using namespace std;


vector < long long > l;
void go(long long num, int longi){
	if(longi == 10) return;
	l.push_back(num);	
	go(num*10+4,longi+1);
	go(num*10+7,longi+1);	
}


int main(){

	go(4LL,1);
	go(7LL,1);
	
	sort(all(l));
	ll pl,pr,vr,vl,k;
	cin>>pl>>pr>>vl>>vr>>k;
	
	
	
	
		int ll = lower_bound(v.begin(),v.end(),A) - v.begin();
		int uu = upper_bound(v.begin(),v.end(),B) - v.begin();
		cout<<uu-ll<<endl;	
	
	//for(int i = 0; i < N; i++) cout<<l[i]<<" ";
	//cout<<endl;
	
	return 0;
}
