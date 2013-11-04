
import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        String a,b;
        String _a,_b;
        int minA,minB;
        Scanner buffer=new Scanner(System.in);
        BigInteger A,B;
        int i,j;
        i=j=0;
        boolean done;
        while(buffer.hasNext())
        {
            a=buffer.next();
            b=buffer.next();
            _a=a;
            _b=b;
            minA=dameMinBase(a);
            minB=dameMinBase(b);
            done=false;
            for(i=minA; i<=36; i++)
            {
                for(j=minB; j<=36; j++)
                {
                    A=new BigInteger(a,i);
                    B=new BigInteger(b,j);
                    if(A.compareTo(B)==0){done=true; break;}
                }
                if(done) break;
            }
            if(done)System.out.println(_a +" (base "+i+") = "+_b+" (base "+j+")");
            else System.out.println(_a+" is not equal to "+_b+" in any base 2..36");
        }

    }

    private static int dameMinBase(String a) {
        int resp=2;
        for(int i=0; i<a.length();i++)
        {
            if(a.charAt(i)<='9' && a.charAt(i)>=0)
                resp=Math.max(resp, a.charAt(i)-'0'+1);
            else
            {
                resp=Math.max(resp, a.charAt(i)-'A'+11);
            }
        }
        return resp;
    }

}
