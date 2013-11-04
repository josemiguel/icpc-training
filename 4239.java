import java.util.*;
import java.math.*;

class Main{
	static int [] pre = new int[22];
	static void solve(){
		BigInteger k = BigInteger.valueOf( 4 );
		pre[ 1 ] = 1;
		for( int r = 2; r <= 20; r++){
			BigInteger tmp = BigInteger.valueOf( 2 );
			BigInteger r10 = BigInteger.ONE;
			for( int i = 0; i < r; i++) r10 = r10.multiply( BigInteger.valueOf(10) );
			BigInteger x = tmp.modPow( k , r10 );
			String s = x.toString();
			boolean c = false;
			while( true ){
				if ( s.length() >= r){
					for ( int i = 0; i < s.length(); i++){
						if ( s.charAt(i) != '1' && s.charAt(i) != '2' ) c = true;
					}
					if ( !c ) {
						pre[ r ] = k.intValue();
						break;
					}
				}
				k = k.add( BigInteger.valueOf( 4 ) );
			}
			k.multiply( BigInteger.valueOf( 5 )) ;
		}
		
	}

	public static void main(String [] args){
		Scanner sc = new Scanner( System.in );
		int runs = sc.nextInt();
		solve();
		for( int c = 1; c <= runs; c++){
			int r = sc.nextInt();
			System.out.println( c + " " + r + " " + pre[r]);
		}
	}
}
