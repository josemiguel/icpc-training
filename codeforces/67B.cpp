#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,t,k;
	cin>>n>>k>>t;
	t = t*k*n/100.0;
	while(n--){
		cout<<min(t,k)<<" ";
		t-=min(t,k);
	}
	return 0;
}

