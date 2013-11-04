import java.util.*;
import java.math.*;

class Main{
	public static void main (String [] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			BigInteger N = sc.nextBigInteger(), res = BigInteger.ZERO;
			BigInteger val = N.subtract(BigInteger.ONE).divide(new BigInteger("2"));
			val = val.multiply(val);
			
			BigInteger a = val.add(BigInteger.ONE);
			a = a.multiply(a);
			a = a.subtract(val.multiply(val));

			for(int i = 1; i <= 3; i++){
				res = res.add(a.add(N.subtract(new BigInteger(Integer.valueOf(i).toString())).multiply(new BigInteger("2"))));
			}
			System.out.println(res);
		}
	}
}
