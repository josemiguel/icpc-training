import java.util.*;
import java.math.*;

class Main{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		while(sc.hasNext()){
			BigInteger tmp = sc.nextBigInteger();
			if (tmp.equals(BigInteger.ZERO)) break;
			sum = sum.add(tmp);
		}
		System.out.println(sum);
	}
}
