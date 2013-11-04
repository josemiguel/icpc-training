#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
bool b[10005];
int main(){
	int n,k,q;
	cin>>n>>k;
	int a[n+1];
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	cin>>q;
	int div = n/k;
	int low = 1<<30, hi = 0;
	while(q--){
		int s = 0;
		for(int i = 0; i < div; i++) {
			int idx;
			cin>>idx;
			s += a[idx-1];
			b[idx-1] = true;
		}
		low = min(s,low);
		hi = max(s,hi);
	}
	vector<int> v;
	for(int i = 0; i < n; i++){
		if (!b[i]){
			v.push_back(a[i]);
		}
	}	
	if (v.size() >= k){
		sort(v.begin(),v.end());
		int mi = 0, ma = 0;
		for(int i = 0; i < div; i++) mi += v[i];
		int tmp = div;
		for(int i = v.size()-1; tmp-- ; i--) ma += v[i];
		printf("%.9lf %.9lf\n",(double)min(mi,low)/div,(double)max(ma,hi)/div);		
	}else{
		printf("%.9lf %.9lf\n",(double)low/div,(double)hi/div);			
	}

}
