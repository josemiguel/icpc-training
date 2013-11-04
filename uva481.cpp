#include <vector>
#include <iostream>

using namespace std;
 
void find_lis(vector<int> &a, vector<int> &b){
	vector<int> p(a.size());

	if (a.empty()) return;

	b.push_back(0);
	int lo,hi;
	for (int i = 1; i < a.size(); i++){
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

		for (lo = 0, hi = b.size()-1; lo < hi;){
			int mid = (lo + hi) / 2;
			if (a[b[mid]] < a[i]) lo = mid + 1; 
			else hi = mid;
		}
		
		if (a[i] < a[b[lo]]){
			if (lo > 0) p[i] = b[lo-1];
			b[lo] = i;
		}	
	}

	for (lo = b.size(), hi = b.back(); lo--; hi = p[hi]) b[lo] = hi;
}
 

int main(){
	vector<int> seq, lis;
	int t;
	while(cin>>t) seq.push_back(t);

    find_lis(seq, lis);
 	cout<<lis.size()<<endl<<"-"<<endl;
	for (int i = 0; i < lis.size(); i++) cout<<seq[lis[i]]<<endl;
 
	return 0;
}
