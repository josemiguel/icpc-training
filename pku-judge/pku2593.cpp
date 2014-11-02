#include<iostream>
#include<cmath>
#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int l[100005],r[100005];
int main(){
	int n;
	while(scanf("%d",&n) && n){
		memset(a,0,sizeof a);	
		for(int i = 0; i < n; i++) {
			scanf("%d",a+i);
		}
		l[0] = a[0]; 
		int best = a[0];
		for(int i = 1; i < n; i++) {
			best = best > 0 ? best+a[i] : a[i];
			l[i] = max(best,l[i-1]);
			cout<<l[i]<<" ";
		}
		cout<<endl;
		r[n-1] = a[n-1];
		best = a[n-1];
		for(int i = n-2, j = 0; i >=0 ; i--,j++) {
			best = best > 0 ? best+a[i] : a[i];
			r[i] = max(best,r[i+1]);
			cout<<r[i]<<" ";
		}
		cout<<endl;
		int res = -1<<30;
		for(int i = 0; i < n-1; i++) res = max(res,l[i]+r[i+1]);
		printf("%d\n",res);
	}
	return 0;
}
