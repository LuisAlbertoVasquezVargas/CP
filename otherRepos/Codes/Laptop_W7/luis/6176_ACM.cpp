
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

  
    BigInteger a , b;
    public Main( BigInteger x , BigInteger y ){
        BigInteger g = x.gcd(y);
        //a = x/g , b = y/g;
	//if( y/g < 0 ) b = -b , a = -a;
        a = x.divide(g) ; 
        b = y.divide(g);
        if( b.compareTo( BigInteger.ZERO ) == -1 ) {
               b = BigInteger.ZERO.subtract(b) ;
               a = BigInteger.ZERO.subtract(a);
        }
    }

    
    ///Fraction operator *( const Fraction &u , const Fraction &v ){ return Fraction( u.a*v.a , u.b*v.b ); }
    //Fraction operator +( const Fraction &u , const Fraction &v ){ return Fraction( u.a*v.b + v.a*u.b , u.b*v.b ); }
    //Fraction operator -( const Fraction &u , const Fraction &v ){ return Fraction( u.a*v.b - v.a*u.b , u.b*v.b ); }
    public static Main prod( Main u , Main v ){
        return new Main( u.a.multiply(v.a) , u.b.multiply(v.b) );
    }
    public static Main sum( Main u , Main v ){
    //Fraction operator +( const Fraction &u , const Fraction &v ){ return Fraction( u.a*v.b + v.a*u.b , u.b*v.b );
        return new Main( u.a.multiply(v.b).add( v.a.multiply(u.b) )  , u.b.multiply(v.b) );
    }
    public static Main rest( Main u , Main v ){
    //Fraction operator +( const Fraction &u , const Fraction &v ){ return Fraction( u.a*v.b + v.a*u.b , u.b*v.b );
        return new Main( u.a.multiply(v.b).subtract(v.a.multiply(u.b) )  , u.b.multiply(v.b) );
    }
    public static void main(String[] args) {
        Main [][]F = new Main[ 405 ][ 405 ];
        for( int i = 0 ; i < 405 ; ++i )
            for( int j = 0 ; j < 405 ; ++j )
                    F[ i ][ j ] = new Main(BigInteger.ONE, BigInteger.ONE );
        F[ 0 ][ 1 ] = new Main( BigInteger.ONE, BigInteger.ONE );
        for( int i = 1 ; i <= 400 ; ++i ){
		for( int j = 2 ; j <= i + 1; ++j )
			F[ i ][ j ] = prod ( new Main( BigInteger.valueOf(i) , BigInteger.valueOf(j) )
                                       , F[ i - 1 ][ j - 1 ] );
		Main S = new Main( BigInteger.ZERO , BigInteger.ONE );
		for( int j = 2 ; j <= i + 1 ; ++j )
			S = sum( S , F[ i ][ j ] );
		F[ i ][ 1 ] = rest( new Main( BigInteger.ONE , BigInteger.ONE ) , S ); 
	}
        Scanner cin = new Scanner( System.in );
	int cases = cin.nextInt();
	for( int tc = 0 ; tc < cases ; ++tc ){
		int id  , i , j ;
                id = cin.nextInt();
                i = cin.nextInt();
                j = cin.nextInt();
		if( F[ i ][ j ].b.equals( BigInteger.ONE ) ) 
                        System.out.println( id + " " + F[ i ][ j ].a );
                else System.out.println( id + " " + F[ i ][ j ].a + "/" + F[ i ][ j ].b );
	}
        
    }
}

