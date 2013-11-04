#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

ll POW(int i, int p){
    ll sum = i; for ( int k = 2; k <= p; k++ ) sum *= i;
    return sum;
}
int main (){
    double n;
    while ( scanf ("%lf", &n) && n ) {
        bool F = false;
        int N;

        if (n < 0) {
            N = sqrt (n * -1);
            for ( int i = -2; i >= -N; i-- ) {
                ll ans = i;
                int p = 2;
                while (ans > n){
                    ans = POW(i, p);
                    p++;
                }
                if (ans == n){
                    printf ("%d\n", p - 1);
                    F = true;
                    break;
                }
            }
            if (!F) printf ("1\n");
        }
        else{
            N = sqrt (n);
            for ( int i = 2; i <= N; i++ ) {
                ll ans = i;
                int p = 2;
                while (ans < n){
                    ans = POW(i, p);
                    p++;
                }
                if (ans == n){
                    printf ("%d\n", p - 1);
                    F = true; break;
                }
            }
            if (!F) printf ("1\n");
        }
    }
    return 0;
}

