
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static BigInteger C( int i )
    {
        BigInteger n = BigInteger.valueOf(i);
        BigInteger P = BigInteger.ONE;
        for( int k = 2 ; k <= i ; ++k )
        {
            BigInteger K = BigInteger.valueOf(k);
            P = P.multiply(n.add(K));
        }
        for( int k = 2 ; k <= i ; ++k )
        {
            BigInteger K = BigInteger.valueOf(k);
            P = P.divide(K);
        }
        return P;

    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while( cin.hasNext() )
        {
            int i = cin.nextInt();
            System.out.println(C(i));
        }
    }

}
