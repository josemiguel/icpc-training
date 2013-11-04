import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

class Main {
static BigInteger F []=new BigInteger[10005];
public static BigInteger fact(int n)
{
	if(F[n]!=null)
	{
		return F[n];
	}
	else
		return F[n]=(new BigInteger(n+"")).multiply(fact(n-1));
}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		String st="";
		F[0]=new BigInteger("1");
		F[1]=new BigInteger("1");
		F[2]=new BigInteger("2");
		
		
		int x=Integer.parseInt(reader.readLine());
		int t=1;
		while(x!=0)
		{
			st=fact(x).toString();
			int ss[]=new int[10];
			for(int i=0;i<st.length();i++)
			{
				int f=(int)(st.charAt(i)-'0');

				ss[f]++;
			}

			System.out.println(x+"! --");
			System.out.printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",ss[0],ss[1],ss[2],ss[3],ss[4]);
			System.out.printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",ss[5],ss[6],ss[7],ss[8],ss[9]);	

			x=Integer.parseInt(reader.readLine());

		}

	}

}

