#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define MAX 2660
vector<int> a;
void criba(){
	vector<bool> p(MAX,true);
	p[0] = p[1] = false;
	for(int i = 2; i*i <= MAX; i++){
		if (p[i]){
			a.push_back(i);
			for(int j = i*i; j<=MAX; j+=i){
				p[j]=false;
			}
		}
	}
}

string solve(int x, int y){
	for(int i = 0; i < a.size(); i++) if (x == a[i] && y == a[i+1]) return "YES";
	return "NO";
}

int main(){
	criba();
	int n,m;
	cin>>n>>m;
	cout<<solve(n,m)<<endl;
	return 0;
}
