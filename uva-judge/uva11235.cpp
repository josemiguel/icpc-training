#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,n) for(int i = 0; i < n; i++)
#define ff(i,a,b) for(int i = a; i < b; i++)
#define gbit(i,a,b) for(int i = b; i >= a; i = (i & (i+1))-1)
#define ubit(i,k,n) for(int i = k; i < n; i |= i+1)



int main(){
	int n,q;
	while(cin >> n >> q && n){
		int bef = 1<<30;
		int freq = 0;
		vector<int> a(n+1);
		vector<pair<int,int> > pre(n+1),bit(n+1,make_pair(0,0));
		f(i,n) {
			cin>>a[i];
			if (bef == 1<<30) pre[i] = make_pair(a[i],++freq);
			else {
				if ( bef == a[i])	pre[i] = make_pair(a[i],++freq);
				else {
					freq = 0;
					pre[i] = make_pair(a[i],++freq);
				}
			}
			bef = a[i];
			
			for(int j = i ; j < n; j |= j+1) {
				if (bit[j].second < pre[i].second){
					bit[j] = pre[i];
				}
			}
			
		}
		f(i,n) cout<<"("<<pre[i].first<<","<<pre[i].second<<") ";
		cout<<endl;
		f(j,q){
			int a,b;
			cin >> a >> b;
			pair<int,int> res(0,0);
			
			for(int i = b; i >= a; i = (i & (i+1) ) - 1 ) {
				if ( bit[i].second > res.second){
					res = bit[i];
				}
			}
			cout <<a << " " << b <<" : "<< res.second <<endl;
		}
	}

	return 0;
}
