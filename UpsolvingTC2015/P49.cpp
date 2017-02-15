#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<complex>

using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define SZ(v) ((int)(v).size())

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define MAXVAL 1000

typedef long long ll;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;
typedef complex< ld > base;
  
ld PI = acos( -1.0 );
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
void multiply (const vector<ld> & a, const vector<ld> & b, vi & res) {
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
        res[i] = round( fa[i].real() );
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi F( MAXVAL + 1 );
		vld P( MAXVAL + 1 );
		REP( i , n ){
			int x;
			sc( x );
			F[ x ] ++;
			P[ x ] ++;
		}
		vld Q = P;
		vi vec;
		multiply( P , Q , vec );
		int K;
		sc( K );
		REP( it , K ){
			int C;
			sc( C );
			int ans = 0;
			if( C >= SZ( vec ) ){
				puts( "0" );
			}else{
				ans += vec[ C ];
				//DEBUG( vec[ C ] );
				if( C % 2 == 0 && (C / 2 <= MAXVAL) ){
					ans -= F[ C / 2 ];
					//DEBUG( F[ C / 2 ] );
				}
				//test();
				printf( "%d\n" , ans );
			}
		}
	}
}


