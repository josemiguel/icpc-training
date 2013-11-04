import java.util.*;
import java.math.*;

class Main{

	static BigInteger F[] = new BigInteger[510];

	public static void main(String [] args){
		F[0] = F[1] = BigInteger.ONE;
		for(int i = 2; i <= 505; i++) F[i] = F[i-1].add(F[i-2]);
		
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			BigInteger x = sc.nextBigInteger();
			BigInteger y = sc.nextBigInteger();
			if (x.equals(BigInteger.ZERO) && y.equals(BigInteger.ZERO)) break;
			int posIni = 1,posFin = 503;
			while(x.compareTo(F[posIni]) > 0) posIni++;
			while(y.compareTo(F[posFin]) < 0) posFin--;
			int ways = posFin - posIni + 1;
			System.out.println(ways);
		}
	}
}
