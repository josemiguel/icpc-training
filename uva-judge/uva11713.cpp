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

bool isvowel(char a){
	return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
}

bool solve(string a, string b){
	if (a.size() == b.size()){
		for(int i = 0; i < a.size(); i++){
			if (isvowel(a[i]) && isvowel(a[i])) continue;
			if (a[i] != b[i]){
				return false;
			}
		}
		return true;
	}
	return false;
	
}

int main(){
	int runs;
	scanf("%d",&runs);
	cin.ignore();	
	for(int r = 1 ; r <= runs ; r++){
		string a,b;
		getline(cin,a);
		getline(cin,b);
		if (solve(a,b))
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
