#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;


int main(){
	int runs;
	scanf("%d",&runs);
	cin.ignore();
	cin.ignore();	
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) cout<<endl;
		string alph, ciph;
		getline(cin,alph);
		getline(cin,ciph);

		cout<<ciph<<endl;		
		cout<<alph<<endl;		
		map<char,char> M;
		for(int i = 0; i < alph.size(); i++){
			M[alph[i]] = ciph[i];
		}
		string s;
		while(getline(cin,s) && s!=""){
			for(int i = 0; i < s.size(); i++){
				if (M[s[i]] != 0)
					s[i] =  M[s[i]];
			}
			cout<<s<<endl;
		}
		
	}
	
	return 0;
}
