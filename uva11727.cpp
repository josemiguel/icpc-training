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
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define pq priority_queue

#define INF 1<<30
#define to first
#define we second

/*typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef greater<pair<int,int> > gpii;*/

int main(){
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ;i++){
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		printf("Case %d: %d\n",i,a[1]);
	}
	return 0;
}

/*
3
1000 2000 3000
3000 2500 1500
1500 1200 1800

 
*/
