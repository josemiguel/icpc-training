#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

void parse( char *a, int &e, int &n, int &d){
    e = n = d = 0;
    char s = a[0];
    a++;
    int len = strlen( a ) , p = 0;
    for( int i = p; i < len && a[i] != '-'; i++, p++){
        e = e * 10 + a[i]-'0';
    }
    p++;
    for( int i = p; i < len && a[i] != '/'; i++, p++){
        n = n * 10 + a[i]-'0';
    }
    p++;
    for( int i = p; i < len ; i++){
        d = d * 10 + a[i]-'0';
    }
    if ( s == '-') e = -e;
}
//maximo comun divisor
int gcd( int a, int b){
    return b == 0 ? a : gcd( b, a % b);
}
//minimo comun multiplo
int lcm( int a, int b){
    return (a * b) /  gcd( a, b );
}
// por si lo necesitan, yo no lo usare

char *suma( char *a, char *b){

    int ae, an, ad;
    int be, bn, bd;
    int e, n , d;

    parse( a, ae, an, ad);
    parse( b, be, bn, bd);

    e = ae + be;

    n = an * bd + ad * bn ;
    d = bd * bn;

    //reduccion
    int g = gcd( n, d );

    n /= g;
    d /= g;
    // fin de reduccion
     if ( fabs(n) > fabs(d) ) {
        e += n % d;
        n = n / d;
    }


    char tmp[ 100 ], *res, s = '+';
    if ( e < 0 ) {
        e = -e;
        s = '-';
    }
    sprintf( tmp, "%c%d-%d/%d", s, e, n , d);
    res = new char[ strlen( tmp ) + 1];
    strcpy( res, tmp );
}

char *multiplica( char *a, char *b){
    int ae, an, ad;
    int be, bn, bd;
    int e, n, d;

    parse( a, ae, an, ad);
    parse( b, be, bn, bd);
    // solo en fraccion es decir ae = 0, be = 0
    an = ad * ae + an;
    bn = bd * be + bn;

    n = an * bn;
    d = ad * bd;
    //reduccion
    int g = gcd( n, d );

    n /= g;
    d /= g;
    // fin de reduccion
    if ( fabs(n) > fabs(d) ) {
        e = n % d;
        n = n / d;
    }else{
        e = 0;
    }

    if ( n < 0 ) n = -n;

    char tmp[ 100 ], *res, s = '+';
    if ( e < 0 ) {
            s = '-';
            e = -e;
    }
    sprintf( tmp, "%c%d-%d/%d", s ,e, n , d);
    res = new char[ strlen( tmp ) + 1];
    strcpy( res, tmp );
}

int main(int narg, char *args[]){
    bool isSum = !strcmp("SUMA", args[1]);

    char *acum = args[ 2 ];

    for( int i = 3; i < narg; i++){

        if ( isSum ){
            acum = suma( acum , args[i]);
        }else{
            acum = multiplica( args[i], acum );
        }
    }
    printf( "Resultado : %s" , acum );


    return 0;
}
