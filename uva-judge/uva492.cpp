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
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30
#define MAX
//int g[MAX][MAX];
//vector<vector<int> > g;

bool isvowel(char c){
	c = toupper(c);
	return c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c=='U';
}

int main(){
    string str;
    int b;
    char ini;
    while(getline(cin, str, '\n')){
        b = 0;
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i])){
               if(b == 0){
                   if(isvowel(str[i])){
                       cout << str[i];
                       b = -1;
                   }
                   else{
                       ini = str[i];
                       b = 1;
                   }
               }
               else cout << str[i];
            }
            else{
                if(b == 1) cout << ini << "ay";
                else if(b == -1) cout << "ay";
                b = 0;
                cout << str[i];
            }
        }
        
        if(b == 1) cout << ini << "ay";
        if(b == -1) cout << "ay";
        cout << endl;
    }
    
    return 0;
}
