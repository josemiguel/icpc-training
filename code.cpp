#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    int runs;

    cin >> runs;

    for( int r = 1; r <= runs ;r++){
        int n,m;
        cin >> n >> m;
        vector< string > D( n ), L( m );
        vector< vector< int > > mask( n, vector< int > ( 30 , 0 ));
        vector< vector< int > > exist( n, vector< int > ( 30 , 0 ));
	vector<int> mp ( 30 , 0);

        for( int i = 0; i < n; i++){
            cin >> D[i];
        }
        for( int i = 0; i < m; i++){
            cin >> L[i];
        }

	cout << "Case #" <<r<<":";
        for( int i = 0; i < n; i++){
            for( int j = 0; j < D[i].size(); j++) mask[i][D[i][j]-'a'] |= ( 1 << j ), exist[i][D[i][j]-'a']=mp[D[i][j]-'a']=true;
        }

        for( int i = 0; i < m; i++){
            vector< int > res( n , 0 );
            for( int k = 0; k < D.size(); k++){
                vector< int > usd( n , 2 );
                for( int j = 0; j < L[i].size(); j++){
                    int c = L[i][j] - 'a';
		    if (!mp[c]) continue;

                    if ( !exist[k][c] ) {
                    	for( int l = 0; l < D.size(); l++){
                        	if ( usd[l] == 0) continue;

                	        if ( k == l ) continue;
	                        if ( D[k].size() != D[l].size() ) continue;
        	                if ( !exist[l][c] ) continue;	
                       		res[k]++;
				usd[l] = 0;
				break;
			}
			
                    }else{
			bool cagao = true;
                        for( int l = 0; l < D.size(); l++){
                            if ( usd[l] == 0 ) continue;
                            if ( !exist[l][c] ) continue;
                            usd[l] = 0;
                            if (  D[k].size() != D[l].size() ) continue;
                            if ( k == l ) continue;
                            if ( mask[k][c] == mask[l][c]){
                                usd[l] = 1;
				cagao = false;
                            }
                            
                        }
			if ( cagao ) break;
			for( int l = 0; l < D.size(); l++ ) if ( usd[l] == 2 ) usd[l] = 0;
                    }
                }

            }
            int idx = 0;
            for( int i = 0; i < n; i++){
  //              cout << res[i] << endl;
                if ( res[ i ] > res[ idx ]  ) idx = i;
            }
            cout <<" "<< D[idx];
        }
        cout << endl;

    }

    return 0;
}
