import java.util.*;
import java.math.*;

class Main{
	public static void main(String [] args){
		
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String line = sc.next();
			if (line.equals("0")) break;						
			int last = 5 * (line.charAt(line.length()-1) - '0');			
			line = line.substring(0,line.length()-1);
			BigInteger n =  new BigInteger(line);
			BigInteger rem = BigInteger.valueOf(last);
			if (n.subtract(rem).mod(BigInteger.valueOf(17)).equals(BigInteger.ZERO)){
				System.out.println(1);
			}else{
				System.out.println(0);
			}
		}
	}
}

