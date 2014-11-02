#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int ru;
	cin>>ru;
	for(int r = 1; r <=ru; r++){
		int n;
		cin>>n;
		int a[55];
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		int h = 0, l = 0;
		for(int i = 1; i < n; i++){
			h += a[i-1] < a[i];
			l += a[i-1] > a[i];
		}
		printf("Case %d: %d %d\n",r,h,l);
	}
}
