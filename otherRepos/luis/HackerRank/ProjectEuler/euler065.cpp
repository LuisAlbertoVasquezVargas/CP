
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static BigInteger ONE = BigInteger.ONE;
    public static BigInteger ZERO = BigInteger.ZERO;
    public static BigInteger TWO = BigInteger.valueOf(2);
    public static int N = 30000;

    public static void main(String[] args) {
        Scanner cin = new Scanner( System.in );
        int n = cin.nextInt();
        BigInteger F[] = new BigInteger[ N + 5 ];
        F[ 0 ] = ZERO;
        F[ 1 ] = ONE;
        for( int i = 0 ; i < n ; ++i ){
            int cur = ( (i == 0) ? 2 : ( (i % 3 == 2) ? ( 2 * (i/3 + 1) ) : 1 ) );
            //System.out.print(cur + " ");
            F[ i + 2 ] = (F[ i + 1 ].multiply( BigInteger.valueOf( cur ) )).add( F[ i ] );
            //System.out.println( F[ i + 2 ] );
        }
        String s = F[ n + 1 ].toString();
        int ans = 0;
        for( int i = 0 ; i < s.length() ; ++i ){
            char c = s.charAt( i );
            ans += c - '0';
        }        
        System.out.println( ans );
    }
    
}

