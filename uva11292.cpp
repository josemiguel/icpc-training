#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 20005
int h[MAX],k[MAX];
int main(){	
	int n,m;
	while(cin>>n>>m && n+m){
		for(int i = 0; i < n; i++) cin>>h[i];
		for(int i = 0; i < m; i++) cin>>k[i];
		if (m < n) { cout<<"Loowater is doomed!"<<endl; continue; }
		sort(h,h+n); sort(k,k+m);
		int i,j,s = 0;
		for(i = 0, j = 0; i < n && j < m ; j++)	if (h[i] <= k[j]) i++, s+=k[j];
		if (i < n) cout<<"Loowater is doomed!"<<endl;
		else cout<<s<<endl;
	}
	return 0;
}
