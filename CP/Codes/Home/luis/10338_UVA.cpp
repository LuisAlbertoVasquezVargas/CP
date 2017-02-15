
import java.math.BigInteger;
import java.util.Scanner;


public class Main {


    public static void main(String[] args) {
       Scanner cin = new Scanner(System.in);
       int n = cin.nextInt();
       BigInteger []F = new BigInteger[30];
       F[0] = BigInteger.ONE;
       for( int i = 1 ; i < 30 ; ++i )
       {
           F[i] = BigInteger.ONE;
           F[i] = F[i-1].multiply(BigInteger.valueOf(i));
       }
       for( int i = 0 ;  i < n ; ++i )
       {
           String S = cin.next();
           int []A = new int[ 30 ];
           for( int j = 0 ; j < 30 ; ++j )A[j] = 0;
           int nS = S.length();
           for( int j = 0 ; j < nS ; ++j )
               A[ S.charAt(j)-'A']++;
           BigInteger ans = F[nS];
           for( int j = 0 ; j < 30 ; ++j )
               if( A[j]>0 )ans = ans.divide(F[A[j]]);
           System.out.println( "Data set " + (i+1) + ": " + ans);
       }
    }
}

