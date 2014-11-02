#include<iostream>
#include<vector>
using namespace std;
#define MAX 10005
bool p[MAX];
vector<int> a;
void criba(){
	p[0] = p[1] = 1;
	for(int i = 2; i < MAX; i++){
		if (!p[i]){
			for(int j = i+i; j < MAX; j+=i){
				p[j] = 1;
			}
			a.push_back(i);
		}
	}
}

int main(){
	int n;
	criba();
	while(cin>>n && n){
		int res = 0;
		for(int i = 0; i < a.size(); i++){
			int tmp = a[i];
			for(int j = i+1; j < a.size(); j++){
				if (tmp == n) { res++; break; }
				if (tmp > n) break;
				tmp += a[j];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
