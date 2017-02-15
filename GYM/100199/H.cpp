#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; i++ )
#define f(i,a,b) for( int i = (a) ; i < (b) ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 10000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int Rank(vector<vector<int> > A){
	if (A.size() == 0) return 0;
	int n = A.size(), m = A[0].size();
	int row = 0;
	f(c, 0, m)
	{
		if (row == n) return n;
		f(j, row + 1, n) if (A[j][c] == 1)
		{
			swap(A[row], A[j]);
			break;
		}
		if (A[row][c] == 0)
			continue;

		f(j, row + 1, n) if (A[j][c])
		{
			f(k, c, m) 
				A[j][k] ^= A[row][k];
		}
		row ++;
	}
	return row;
}


int getLower( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
bool P[ N + 5 ];
void primefact( int n , vi &Pr , vi &E , vi &primes ){
	REP( i , SZ( primes ) ){
		int p = primes[ i ];
		if( p * p > n ) break;
		if( n % p == 0 ){
			int e = 0;
			while( n % p == 0 ) n /= p , e ++;
			Pr.pb( i );
			E.pb( e );
		}
	}
	if( n > 1 ){
		Pr.pb( getLower(primes,n) );
		E.pb( 1 );
	}
}
/*
void impr( vi &v ){
	for( auto x : v ) cout << x << " "; cout << endl;
}
*/
const int base = 1000*1000*1000;
void impr( vi &a ){
	printf ("%d", a.empty() ? 0 : a.back());
	for (int i=SZ(a)-2; i>=0; --i)
		printf ("%09d", a[i]);
	puts( "" );
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
int main(){
	
	freopen( "rsa.in" , "r" , stdin );
	freopen( "rsa.out" , "w" , stdout );
	
	int T , m;
	while( sc( T ) == 1 ){
		sc( m );
		clr( P , 1 );
		P[ 0 ] = P[ 1 ] = 0;
		for( int i = 2 ; i * i <= N ; ++i )
			if( P[ i ] )
				for( int j = i * i ; j <= N ; j += i )
					P[ j ] = 0;
		vi primes;
		REP( i , N )
			if( P[ i ] ) primes.pb( i );
		primes.resize( T );
		
		vvi A( T , vi( m ) );
		REP( j , m ){
			int x;
			sc( x );
			vi Pr , E;
			primefact( x , Pr , E , primes );
			REP( i , SZ( Pr ) ){
				int p = Pr[ i ] , e = E[ i ];
				if( e & 1 ) A[ p ][ j ] = 1;
			}
		}
		int free = m - Rank( A );
		vi num = get( "1" );
		REP( k , free ) num = mult1( num , 2 );
		num = rest( num , get( "1" ) );
		impr( num );
	}
}



