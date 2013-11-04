import java.util.*;
import java.io.*;
import java.math.*;

class Main{
	public static void main(String [] args){
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n;
		try{
			while((n = Integer.parseInt(br.readLine())) > 0){
				int N = (1<<n)-1;			
				BigInteger [] dp = new BigInteger[N*4];
				String linea = br.readLine();
				StringTokenizer st = new StringTokenizer(linea);
				for (int i = 0; i < N && st.hasMoreTokens(); i++)
					dp[i] = new BigInteger(st.nextToken());
					
				BigInteger uno = BigInteger.ONE;
				for( int u = (1<<n)-2 ; u >= 0 ; u-- ){
					int id = ((u+1)<<1)-1;
					BigInteger R = id >= N ? uno : dp[id];				
					id++;
					BigInteger L = id >= N ? uno : dp[id];
					dp[u] = R.max(L).multiply(dp[u]);
				}
				System.out.println(dp[0].mod(new BigInteger("1000000007")));
			}
		}catch(Exception ex){}
	}
}
