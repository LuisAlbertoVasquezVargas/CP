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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define PI acos( -1.0 )

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;


typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;
 
	vector<base> a0 (n/2),  a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft (a0, invert);
	fft (a1, invert);
 
	double ang = 2*PI/n * (invert ? -1 : 1);
	base w (1),  wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i+n/2] /= 2;
		w *= wn;
	}
}
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
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
	
	//en caso de multiplicar numeros , se garantiza que no hay rte por que el tamaño de 
	//multiplicar dos numeros es <= 2 * n :) por ejm  99 * 99 = 0198
	int carry = 0;
	REP( i , n ){
		res[ i ] += carry;
		carry = res[ i ] / 10;
		res[ i ] %= 10;
	}
	while( SZ( res ) > 1 && res.back() == 0 ) res.pop_back();
}



void fix( string &s ){
	for( auto &x : s ) x -= '0';
}
void defix( string &s ){
	for( auto &x : s ) x += '0';
}
void impr( vi &x ){
	REP( i , SZ(x) ) printf( "%d%c" , x[ i ] , (i + 1 == SZ(x)) ? 10 : 32 );
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	double timer = clock();
	int cases;
	cin >> cases ;
	REP( tc , cases ){
		string a , b;
		cin >> a >> b;
		fix( a ) , fix( b );

		vi x( rall( a ) ) , y( rall( b ) ) , xy;
		
		multiply( x , y , xy );
		
		string s( rall( xy ) );
		defix( s );
		cout << s << '\n';
	}
	timer = (clock() - timer) / CLOCKS_PER_SEC;
	DEBUG( timer );
}




