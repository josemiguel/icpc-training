#include <iostream>
#define N 50
using namespace std;

typedef long long ll;

int main(){
    ll F[N];
    F[0] = 1, F[1] = 2;
    for(int i = 2; i < N; i++) F[i] = F[i-2] + F[i-1];
    int n;   
    while((cin >> n) && n)
        cout << F[n-1] << endl;
   
    return 0;
}
