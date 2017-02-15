import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import org.omg.CORBA.BAD_CONTEXT;


public class Main {
    public static int N = 205;
    static private final String input = "derangements.in";
    static private final String output = "derangements.out";

    public static void main(String[] args)throws FileNotFoundException {

       
        Scanner cin = new Scanner(new File(input));
        int n = cin.nextInt();
        cin.close();
        BigInteger []DP = new BigInteger[ N ];
        for( int i = 0 ; i < N ; ++i ) DP[ i ] = BigInteger.ZERO;
        BigInteger []F = new BigInteger[ N ];
        F[ 0 ] = BigInteger.ONE;
        for( int i = 1 ; i < N ; ++i ) F[ i ] = F[ i - 1 ].multiply( BigInteger.valueOf( i ) );
        DP[ 0 ] = BigInteger.ONE;
        DP[ 1 ] = BigInteger.ZERO;
        DP[ 2 ] = BigInteger.ONE;
        for( int i = 3 ; i < N ; ++i )
            DP[ i ] = BigInteger.valueOf( i - 1 ).multiply( DP[ i - 1 ].add( DP[ i - 2 ] ) );
        BigInteger C[][] = new BigInteger[ N ][ N ];
        for( int i = 0 ; i < N ; ++i )
            for( int j = 0 ; j < N ; ++j ) C[ i ][ j ] = BigInteger.ZERO;
        for( int i = 0 ; i < N ; ++i ) C[ i ][ 0 ] = C[ i ][ i ] = BigInteger.ONE;
        for( int i = 2 ; i < N ; ++i )
            for( int j = 1 ; j < i ; ++j ) C[ i ][ j ] = C[ i - 1 ][ j - 1 ].add( C[ i - 1 ][ j ] );
        BigInteger ans = BigInteger.valueOf(2).pow(n).multiply( F[ n ] );
        BigInteger signo = BigInteger.valueOf( -1 );
        for( int i = 1 ; i <= n ; ++i ){
            BigInteger temp = BigInteger.valueOf( 2 ).pow( n - i );
            BigInteger val = ( C[ n ][ i ].multiply( temp ) ).multiply( F[ n - i ] );
            ans = ans.add( signo.multiply( val ) );
            signo = signo.multiply( BigInteger.valueOf( -1 ) );
        }
        PrintWriter s=new PrintWriter(output);

        s.println( ans );
        s.close();
    }

}
