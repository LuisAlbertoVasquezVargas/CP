#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cout << #x << " " << (x) << endl;
#define N 100000

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

const int base = 1000*1000*1000;
void impr( vi &a ){
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=SZ(a)-2; i>=0; --i)
        printf ("%09d", a[i]);
}
int getLen( vi &a ){
    if( a.empty() ) return 1;
    int r = a.back();
    int ans = 0;
    while( r ){
        r /= 10;
        ans ++;
    }
    ans += 9 *( SZ( a ) - 1 );
    return ans;
}
vi get( string s ){
    vi a;
    for (int i=(int)s.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    return a;
}
vi sum( vi a , vi b ){
    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
    return a;
}
vi rest( vi a , vi b ){
    int carry = 0;
    for (size_t i=0; i<b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry)  a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}
vi mult1( vi a , int b ){
    int carry = 0;
    for (size_t i=0; i<a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}
vi mult2( vi a , vi b ){
    vi c (a.size()+b.size());
    for (size_t i=0; i<a.size(); ++i)
        for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
            long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
            c[i+j] = int (cur % base);
            carry = int (cur / base);
        }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
struct Matrix{
	vi M[ 2 ][ 2 ];
	Matrix(){
		REP( i , 2 ) REP( j , 2 )
			if( i == j ) M[ i ][ i ] = get( "1" );
			else M[ i ][ j ] = get( "0" );
	}
	Matrix( int x ){
		REP( i , 2 ) REP( j , 2 ) M[ i ][ j ] = get( "1" );
		M[ 1 ][ 1 ] = get( "0" );
	}
};

Matrix operator * ( const Matrix &A , const Matrix &B ){
	Matrix C;
	REP( i , 2 )REP( j , 2 ){
		vi dev = get( "0" );
		REP( k , 2 ) dev = sum( dev , mult2( A.M[ i ][ k ] , B.M[ k ][ j ] ) );
		C.M[ i ][ j ] = dev;
	}
	return C;
}
Matrix T[ 25 ];
Matrix pow( Matrix a , int b ){
	Matrix ans;
	int ct = 0;
	while( b ){
		if( b & 1 ) ans = (ans * T[ ct ]);
		b >>= 1;
		ct ++;
	}
	return ans;
}
int main(){
	Matrix G( 1 );
	for( int i = 0 ; i <= 16 ; ++i ){
		T[ i ] = G;
		G = G * G;
	}
	//cout << "GG" << endl;
	int cases;
	sc( cases );
	REP( tc , cases ){
		int a , b , n;
		sc( a ) , sc( b ) , sc( n );
		if( n == 0 ) printf( "%d\n" , a );
		else if( n == 1 ) printf( "%d\n" , b );
		else{
			Matrix F( 1 );
			F = pow( F , n - 1 );
			vi ans = sum( mult1( F.M[ 0 ][ 0 ] , b ) , mult1( F.M[ 0 ][ 1 ] , a ) );
			impr( ans );
			//cout << getLen( ans );
			puts( "" );
		}
	}
}


