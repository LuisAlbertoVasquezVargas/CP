#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test puts("************test************");
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define PI acos( -1.0 )
#define MAXN 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;


typedef complex<double> base;
 
int rev[MAXN + 5];
base wlen_pw[MAXN + 5];


void fft (base a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			base t,
				*pu = a+i,
				*pv = a+i+len2, 
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu += t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}

base fa[ MAXN + 5 ] , fb[ MAXN + 5 ];
void multiply ( int a[] , int &na , int b[] , int &nb ,  int res[] , int &nr ){
	
	REP( i , na ) fa[ i ] = a[ i ];
	REP( i , nb ) fb[ i ] = b[ i ];
	
	int n = 1 , ct = 0;
	while (n < max (na , nb))  n <<= 1 , ct ++;
	n <<= 1;
	ct ++;
	
	for( int i = na ; i < n ; ++i ) fa[ i ] = 0;
	for( int i = nb ; i < n ; ++i ) fb[ i ] = 0;
	
	na = nb = n;
 	calc_rev( n , ct );
 	
	fft (fa, na, false);
	fft (fb, nb, false);
	
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	
	fft (fa, na, true);

	nr = n;
	for (size_t i=0; i<n; ++i)
		res[ i ] = round( fa[i].real() );
	/*
	REP( i , n) cout << res[ i ] << " ";
	cout << endl;
	*/

	//en caso de multiplicar numeros , se garantiza que no hay rte por que el tamaño de 
	//multiplicar dos numeros es <= 2 * n :) por ejm  99 * 99 = 0198
	int carry = 0;
	REP( i , n ){
		res[ i ] += carry;
		carry = res[ i ] / 10;
		res[ i ] %= 10;
	}
	while( nr > 1 && res[ nr - 1 ] == 0 ) nr --;
}


void impr( vi &x ){
	REP( i , SZ(x) ) printf( "%d%c" , x[ i ] , (i + 1 == SZ(x)) ? 10 : 32 );
}

int X[ MAXN + 5 ] , Y[ MAXN + 5 ] , XY[ MAXN + 5 ];
char S[ MAXN + 5 ] , T[ MAXN + 5 ];
int main(){
	double timer = clock();
	int cases;
	sc( cases );
	REP( tc , cases ){
		scanf( "%s%s" , S , T );
		int nX = strlen( S ) , nY = strlen( T );
		
		REP( i , nX ) X[ i ] = S[ i ] - '0';
		REP( i , nY ) Y[ i ] = T[ i ] - '0';
		
		reverse( X , X + nX );
		reverse( Y , Y + nY );

		int nXY = 0;
		multiply( X , nX ,  Y , nY , XY , nXY );
		reverse( XY , XY + nXY );
		REP( i , nXY ) printf( "%d" , XY[ i ] );
		puts( "" );
		
	}
	timer = (clock() - timer) / CLOCKS_PER_SEC;
	//DEBUG( timer );
}




