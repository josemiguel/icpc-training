#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n && n){
		vector<int> d;
		
		for(int k = 1; k*k <= n; k++){
			if (n%k == 0){
				d.push_back(k);
				d.push_back(n/k);
			}
		}

		int res = 0;
		sort(d.begin(),d.end());
		for(int i = 0; i < d.size(); i++){
			for(int j = i+1; j < d.size(); j++){
				if (__gcd(d[i],d[j]) == 1) res++;
			}
		}
		cout<<n<<" "<<res<<endl;
	}
}

