#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

bool intersect( pair<int,int> a, pair<int,int> b){
/*	int y= max(a.first,b.first);
	int x= min(a.second,b.second);
	return x <= y;*/
	return a.first >= b.second;

}

int main(){
	int n,m;
	while(cin>>n>>m && n+m){
		vector<string> dic(n);

		for(int i = 0; i < n; i++) cin>>dic[i];
		cin.ignore();	
		int res = 0;
		for(int r = 0; r < m; r++){
			vector<pair<int,int> > a;
			string t;
			getline(cin,t);
			for(int k = 0; k < n; k++){
				int fail[300];
				string s = dic[k];
				int j = fail[0] = -1;
				for(int i = 1; i <= s.size(); i++){
					while( j >= 0 && s[j] != s[i-1] ) j = fail[j];
					fail[i] = ++j;
				}
				
				for(int i = 0, j = 0; i < t.size(); i++){
					while( j >= 0 && s[j] != t[i]) j = fail[j];
					if (++j >= s.size()){
						a.push_back(make_pair(i,i-s.size()+1));
						j = fail[j];
					}

				}

			}
			
			sort(a.begin(),a.end());
			int tmp = 0;
			for(int i = 0, j = 1; i < a.size();){
				tmp++;
				while( intersect( a[i], a[j] ) && j < a.size()) j++;
				i = j;
				j++;
				
			}
			res += tmp;


		}
		cout<<res<<endl;

	}

	return 0;
}
