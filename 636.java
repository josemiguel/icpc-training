
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class Main {

   static Set<Integer> squares= new TreeSet<Integer>();


   public static void inicializa()
   {
        for(int i=1; i*i<=(1000000000); i++)
            squares.add(i*i);        
   }

    public static void main(String[] args) {
        
        inicializa();
        Scanner buffer=new Scanner(System.in);
        int minBase;
        String num;
        int i;
        BigInteger n;
        boolean done;
        while(buffer.hasNext())
        {
            done=false;
            num=buffer.next();
            if(num.compareTo("0")==0) break;
            minBase=dameMinBase(num);

            for(i=minBase; i<=36; i++)
            {
                n=new BigInteger(num,i);
                if(squares.contains(Integer.parseInt(n.toString())))
                {
                    done=true;
                    System.out.println(i);
                    break;
                }
            }
            if(!done)
            {
                int val=0;
                for(i=37; i<=100; i++)
                {
                    val=0;
                    for(int j=0; j<num.length(); j++)
                    {
                        val*=i;
                        val+=(num.charAt(j)-'0');
                    }
                    if(squares.contains(new Integer(val)))
                    {
                        System.out.println(i);
                        break;
                    }
                }
            }

        }

    }

    private static int dameMinBase(String a) {
        int resp=2;
        for(int i=0; i<a.length();i++)
        {
            if(a.charAt(i)<='9' && a.charAt(i)>='0')
                resp=Math.max(resp, a.charAt(i)-'0'+1);
            
        }
        return resp;
    }

}
