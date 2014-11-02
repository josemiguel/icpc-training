import java.util.*;
import java.math.*;

class Main{
	static String A;
	static String B;	
	
	static BigInteger [][] dp = new BigInteger[10005][105];
	BigInteger F(int a, int b){
		if (a == A.length() && b == B.length()) return BigInteger.ONE;
		else{
			if (!dp[a][b].equals(new BigInteger("-1"))) return dp[a][b];
			BigInteger tmp = BigInteger.ZERO;
			if (a < A.length() && b < B.length()){
				if (A.charAt(a) == B.charAt(b))	tmp = F(a + 1,b + 1);
			}
			if (a < A.length())	tmp = tmp.add(F(a + 1,b));
			dp[a][b] = tmp;
			return dp[a][b];		
		}

	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int runs = sc.nextInt();
			for(int k = 0; k < runs ; k++){
				A = sc.next();
				B = sc.next();
				for(int i = 0; i < 10005; i++) for(int j = 0; j < 105; j++) dp[i][j] = new BigInteger("-1");
				System.out.println(new Main().F(0,0));
			}
		}
	}
}


