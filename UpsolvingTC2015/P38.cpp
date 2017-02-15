#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef double ld;
typedef vector< ld > vld;
typedef long long ll;
typedef vector< ll > vll; 
typedef pair< int , int > pii;
typedef vector< int > vi;

ld PI = acos( (ld)(-1.0) );

typedef complex<ld> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		ld ang = 2.0 * PI /len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
void multiply (const vector<ld> & a, const vector<ld> & b, vll & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = (ll)round( fa[i].real() );
}
int main(){
	int n ,  m;
	while( sc( n ) == 1 ){
		vi a( n );
		REP( i , n ) sc( a[ i ] );
		
		sc( m );
		vi b( m );
		REP( i , m ) sc( b[ i ] );
		
		int len = 200000 + 1;
		vld P( len );
		P[ 0 ] = 1;
		REP( i , n ) P[ a[ i ] ] = 1;
		vld Q = P;
		vll ans;
		multiply( P , Q , ans );

		int cnt = 0;
		REP( i , m )
 			if( ans[ b[ i ] ] >= 1 ) cnt ++;
		
		printf( "%d\n" , cnt );
	}	
}



