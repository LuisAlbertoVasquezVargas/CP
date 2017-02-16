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

vector<ll> sum(vector<ll>::iterator a, vector<ll>::iterator b, int na, int nb) {
  vector<ll> res(max(na, nb));
  REP(i, SZ(res) ) {
    if (i < na) res[i] += a[i];
    if (i < nb) res[i] += b[i];
  }
  return res;
}

void karatsuba(vector<ll>::iterator a, vector<ll>::iterator b, int na, int nb, vector<ll> &res) {
  int m = max(na, nb);
  res.resize(m * 2 , 0);
  if (m <= 30) {
    REP(i, na) REP(j, nb) res[i + j] += a[i] * b[j];
  } else {
    int m2 = m / 2;
    int 
      sl1 = min(na, m2),
      sh1 = max(na - m2, 0),
      sl2 = min(nb, m2),
      sh2 = max(nb - m2, 0);
    vector<ll>::iterator
      l1 = a,
      h1 = a + sl1,
      l2 = b,
      h2 = b + sl2;
 
    vector<ll> z0, z1, z2;
    karatsuba(l1, l2, sl1, sl2, z0);
    karatsuba(sum(l1, h1, sl1, sh1).begin(), sum(l2, h2, sl2, sh2).begin(), max(sl1, sh1), max(sl2, sh2), z1);
    karatsuba(h1, h2, sh1, sh2, z2);
 
    REP(i, SZ(z2) ) res[i + 2 * m2] += z2[i], res[i + m2] += -z2[i];
    REP(i, SZ(z1) ) res[i + m2] += z1[i];
    REP(i, SZ(z0) ) res[i] += z0[i], res[i + m2] += -z0[i];
  }
  int last = 0;
  REP(i, 2 * m)
    if (res[i] != 0) last = i;
  res.resize(last + 1);
}
int main(){
	int n ,  m;
	while( sc( n ) == 1 ){
		vi a( n );
		REP(i , n ) sc( a[ i ] );
		
		sc( m );
		vi b( m );
		REP( i , m ) sc( b[ i ] );
		
		int len = 200000 + 1;
		vll P( len );
		P[ 0 ] = 1;
		REP( i , n ) P[ a[ i ] ] = 1;
		vll Q = P;
		vll ans;
		karatsuba( P.begin() , Q.begin() , SZ( P ) , SZ( Q ) , ans );

		int cnt = 0;
		REP( i , m )
 			if( ans[ b[ i ] ] >= 1 ) cnt ++;
		
		printf( "%d\n" , cnt );
	}	
}



