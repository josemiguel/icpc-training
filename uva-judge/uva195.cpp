#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define All(a) (a).begin(),(a).end()


int cmp(char a, char b){
	char aa = tolower(a);
	char bb = tolower(b);
	if (aa == bb){
		if (isupper(a) && islower(b)){
			return -1;
		}else if (isupper(b) && islower(a)){
			return 1;
		}
		return 0;
	}
	return aa-bb;
}

struct we{
	string s;
	we(){}
	we(string s):s(s){}
	bool operator < (const we &x)const{
		string b = x.s;
		for(int i = 0; i < s.size(); i++){
			int res = cmp(s[i],b[i]);
			if (res == 0) continue;
			if (res < 0) return true;
			return false;
		}
		return false;
	}
};


int main(){
	int runs;
	cin>>runs;
	while(runs--){
		string a;
		cin>>a;
		sort(All(a));
		vector<we> res;
		do{
			res.push_back(we(a));		
		}while(next_permutation(All(a)));

		sort(All(res));

		for(int i = 0; i < res.size();i++) cout<<res[i].s<<endl;

	}
	return 0;
}
