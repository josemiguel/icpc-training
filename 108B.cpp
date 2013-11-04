#include <cmath>
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

typedef long long Int;

int main(){

    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
    	int k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    int last = v.back();
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] != last){
            Int a = v[i]*2;
            if(a > last){
            	cout<<"YES"<<endl;
            	return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    
    return 0;
}
