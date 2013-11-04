import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        
        Scanner buffer=new Scanner(System.in);
        int from,to;
        String num;
        String numC;
        BigInteger num1;
        while(buffer.hasNext())
        {
            num=buffer.next();
            from=buffer.nextInt();
            to=buffer.nextInt();
            
            
            num1=new BigInteger(num,from);
            numC=num1.toString(to);
            System.out.println(Convierte(numC));
        }

    }
    private static String Convierte(String s)
    {
        
        String resp="  ERROR";
        if(s.length()>7) return resp;
        resp=s.toUpperCase();
        for(int i=0; i<7-s.length(); i++)
            resp=" "+resp;
        
          return resp;
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
