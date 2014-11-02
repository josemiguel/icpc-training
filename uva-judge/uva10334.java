import java.util.*;
import java.math.*;

class Main{

	static BigInteger F[] = new BigInteger[1010];

	public static void main(String [] args){
		F[0] = F[1] = BigInteger.ONE;
		for(int i = 2; i <= 1005; i++) F[i] = F[i-1].add(F[i-2]);
		
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int x = sc.nextInt();
			System.out.println(F[x+1]);
		}
	}
}
