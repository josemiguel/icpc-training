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
	string s,b,todo;
	set<string> dic;
	int p=0;
	while(getline(cin,b)){
		if (p){
			if (s[s.size()-1]=='-'){
				if (todo[todo.size()-1] == '-') todo.erase(todo.end()-1);
				todo+=b;
			}else{
				todo+= " " + b;
			}
		}else todo = b;
		p = 1;
		
		s = b;
	}
	for(int i = 0; i < todo.size(); i++){
		if (!isalpha(todo[i]) && todo[i]!='-'){
			todo[i] = ' ';
		}else{
			todo[i] = tolower(todo[i]);
		}
	}
	istringstream is(todo);
	string pal;
	while(is>>pal){
		dic.insert(pal);
	}
	for(set<string>::iterator it = dic.begin(); it != dic.end(); it++){
		cout<<*it<<endl;
	}
	
	return 0;
}
