#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i = 1; i < n; i++){
		cin >> a[i];
	}
	int x,y;
	cin >> x >> y;
	int res=0;
	for(int i = x; i <= y-1; i++) res+=a[i];
	cout<<res<<endl;
	return 0;
}
