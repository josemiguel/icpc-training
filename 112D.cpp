#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 100005
int x[MAX],y[MAX],n;

map<int,vector<int> > m;
vector<int> div[MAX];

vector<int> go(int n){
	if (m.count(n)) return m[n];
	vector<int> res;
	for(int i = 1; i*i <= n; i++) if (n % i == 0) {
		res.push_back(i);
		if ( i == n/i) continue;
		res.push_back(n/i);
	}
	return res;
}
int pos[MAX];
int main(){
	cin >> n;
	memset(pos,-1,sizeof pos);
	for(int i = 0; i < n; i++) cin>>x[i]>>y[i], div[i] = go(x[i]);
	for(int i = 0; i < n; i++){
		int res = 0;
		for(int j = 0; j < div[i].size(); j++){
			if (pos[div[i][j]] < i-y[i]) res++;
			pos[div[i][j]] = i;//mas cerca			
		}
		cout<<res<<endl;
	} 
	
	return 0;
}

