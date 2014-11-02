#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<set>
using namespace std ;

struct state{
	string t;
	char mid;
	state *prev;
	int move;
	char p;
	state(){}
	state( string t, char mid, int move , char p): t(t),mid(mid), move(move), p(p){
	}
	bool isDone(){
		return  t == "ABCDEF";
	}
};
queue< state > Q;
map< string, state > pai;

void play( state v){
	string t = v.t;
	char mid = v.mid;
	int move = v.move;
	state next;
	if ( mid == 0 ){
		string s = t; 
		s[4] = '$';
		if ( !pai.count(s) ){
			next =  state( s, t[4], move + 1, t[4] );
			pai[s] = v;
			Q.push( next );
		}
		s = t;
		s[1] = '$';

		if ( !pai.count(s) ){
			next =  state( s, t[1], move + 1, t[1] );
			pai[s] = v;
			Q.push( next );
		}
	}else{
		string s = t;
		char pp;

		for( int i = 0; i < s.size(); i++){
			if ( s[i] == '$' ){
				if ( i == 0 ) swap(s[0], s[s.size()-1] );
				else swap( s[i], s[i-1]);
				pp = s[i];
				break;
			}
		}

		if ( !pai.count(s) ){
			
			next =  state( s, mid, move + 1, pp );
			pai[s] = v;
			Q.push ( next );
		}
		s = t;
		for( int i = 0; i < s.size(); i++){
			if ( s[i] == '$' ){
				if ( i == s.size()-1 ) swap(s[0], s[s.size()-1] );
				else swap( s[i], s[i+1]);
				pp = s[i];
				break;
			}
		}
		if ( !pai.count(s) ){
			next =  state( s, mid, move + 1, pp );
			pai[s] = v;
			Q.push ( next);
		}
		s = t;
		if ( t[1] == '$'){
			s[1] = mid ;
			if ( !pai.count(s) ){
				next =  state( s, 0, move + 1, mid );
				pai[s] = v;
				Q.push ( state( s, 0 , move + 1, mid ));
			}
		}else if ( t[4] == '$') {
			s[4] = mid;
			if ( !pai.count(s) ){
				next =  state( s, 0, move + 1, mid );
				pai[s] = v;
				Q.push ( next );
			}
		}
	}
}
	


void track( state cur ){
	if ( !cur.p ) return;
	track( pai[cur.t] );
	cout << cur.p;
//	putchar( cur.p);

}

int main(){
	
	int T;
	cin >> T;
	while( T--) {
		int r; string s;
		cin >> r >> s;
		state ini( s, 0, 0, 0 );
		while( !Q.empty()) Q.pop();
		pai.clear();
		Q.push( ini );
		pai[ s ] = state( "" , 0, 0, 0 ); 
		while( !Q.empty() ){
			state v = Q.front(); Q.pop();
			if ( v.isDone() ) {
				cout << r << " " << v.move << " ";
				track( v );
				cout << endl;
				goto hell;
			}
			play(v);
		}
		cout << r << " NO SOLUTION"<<endl;
		hell:;
	}
	
	return 0;
}
