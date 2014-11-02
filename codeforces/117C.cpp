#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define RESET(a,b) memset(a, b, sizeof(a))
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define INF 1000000000

vector <int> G[5002];

struct st{
    int cant;
    int a[3];

};

queue<st> cola;

int main() {
    int n;
    cin>>n;
    getchar();
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (getchar()=='1')
                G[i].push_back(j);
        }
        getchar();
    }
    st f,aux;
    for (int i=0; i<n; i++){
        aux.cant=1;
        aux.a[0]=i;
        cola.push(aux);
        while(!cola.empty()){
            f=cola.front();
            cola.pop();
            for (int j=0; j<G[f.a[f.cant-1]].size(); j++){
                aux.cant=f.cant+1;
                aux.a[0]=f.a[0];
                aux.a[1]=f.a[1];
                aux.a[2]=f.a[2];
                if (f.cant==3){
                    if (f.a[0]==G[f.a[2]][j]){
                        cout<<f.a[0]+1<<" "<<f.a[1]+1<<" "<<f.a[2]+1<<endl;
                        return 0;
                    }
                    continue;
                }
                aux.a[f.cant]=G[f.a[f.cant-1]][j];
                cola.push(aux);
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
