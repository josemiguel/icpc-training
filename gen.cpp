#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std ;

const double PI = acos( -1 );

struct chromosome{
	int b;
	chromosome(){}
	double f( double x ){
		return x  * sin( 10*PI*x ) + 1.0;
	}
	double eval(){
		return f(-1.0 + b * ( 3.0 / ( (1<<22) -1 ) ));
	}
};

struct genetic{
	int it;
	vector<chromosome> tmp;
	genetic(){}
	genetic( int it, vector<chromosome> tmp):it(it),tmp(tmp){}

	double run(){
		int k = 0;
		vector<chromosome> init = tmp;
		double res = 0;
		while( k++ < it ){
			int prob = rand() % 1000 + 1;
			if ( prob > 10 && prob <= 250 ){
				mutation();
			}else if ( prob < 10 ){
				crossover();
			}
			for( int i = 0; i < tmp.size(); i++){
				
				if ( tmp[i].eval() < res ){
					tmp.erase( tmp.begin()+ i );
				}
			}
			double r = 0;
			for( int i = 0; i < tmp.size(); i++){
				r = max ( tmp[i].eval(), r );
			}
			cout << "it: "<<k+1<<" "<< r << endl;
		}
	}
	void mutation(){
		for( int i = 0; i < tmp.size(); i++){
			if ( rand() % 1 ){
				tmp[i].b = tmp[i].b ^ ( 1 << 10 );
			}
		}
	}
	void crossover(){
		for( int i = 0; i < tmp.size() - 1; i++){
			cross_op( tmp[i] , tmp[ i + 1 ] );
		}
	}
	void cross_op( chromosome &x, chromosome &y ){
		int pos = rand() % 22 ;

		int mask = ( 1 << pos ) - 1;
		int s =  mask << pos;

		int _x = x.b & mask;
		int _y = y.b & mask; 

		x.b = (s & x.b ) | _y;
		y.b = (s & y.b) | _x;
	}
};



int main(){

	int cases = 16;

	while( cases--){

		srand( time ( NULL ) );
		vector<chromosome> pop( 2000 );
		
		for( int i = 0; i < pop.size(); i++){
			pop[i].b = rand() % ( 1 << 22 );
		}

		genetic g( 50 , pop );
		g.run();
	}
	return 0;
}


