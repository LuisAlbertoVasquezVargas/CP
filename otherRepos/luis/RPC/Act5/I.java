
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public BigInteger ONE = BigInteger.ONE;
    public BigInteger ZERO = BigInteger.ZERO;
    
    public class Matrix{
        public BigInteger [][]M = new BigInteger[ 2 ][ 2 ];
        Matrix(){
            for( int i = 0 ; i < 2 ; ++i )
                for( int j = 0 ; j < 2 ; ++j )
                    if( i == j ) M[ i ][ j ] = ONE;
                    else M[ i ][ j ] = ZERO;
        }
        Matrix( int x ){
            for( int i = 0 ; i < 2 ; ++i )
                for( int j = 0 ; j < 2 ; ++j )
                    M[ i ][ j ] = ONE;
            M[ 1 ][ 1 ] = ZERO;
        }
    }
    public Matrix multiply( Matrix A , Matrix B ){
        Matrix C = new Matrix();
        for( int i = 0 ; i < 2 ; ++i )
            for( int j = 0 ; j < 2 ; ++j ){
                BigInteger dev = ZERO;
                for( int k = 0 ; k < 2 ; ++k )
                    dev = (dev.add( (A.M[ i ][ k ]).multiply( B.M[ k ][ j ] ) ));
                C.M[ i ][ j ] = dev;
            }
        return C;
    }
    public Matrix []T = new Matrix[ 25 ];
    public Matrix pow( int b ){
	Matrix ans = new Matrix();
	int ct = 0;
	while( b > 0 ){
		if( (b & 1) == 1 ) ans = multiply( ans , T[ ct ] );
		b >>= 1;
		ct ++;
	}
	return ans;
    }
    public void solve(){
        Matrix G = new Matrix( 1 );
        for( int it = 0 ; it <= 17 ; ++it ){
		T[ it ] = G;
                G = multiply( G , G );
	}
        
        Scanner cin = new Scanner( System.in );
        int cases = cin.nextInt();
        for( int tc = 0 ; tc < cases ; ++tc ){
            int a = cin.nextInt();
            int b = cin.nextInt();
            int n = cin.nextInt();
            if( n == 0 ) System.out.println( a );
            else if( n == 1 ) System.out.println( b );
            else{
                Matrix F = pow( n - 1 );
                BigInteger x = (F.M[ 0 ][ 0 ]).multiply( BigInteger.valueOf( b ) );
                BigInteger y = (F.M[ 0 ][ 1 ]).multiply( BigInteger.valueOf( a ) );
                BigInteger ans = x.add( y );
                System.out.println( ans );
            }
        }
    }
    
    public static void main(String[] args) {
        new Main().solve();
    }
        
}

