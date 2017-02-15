#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define all( v ) v.begin() , v.end()
#define pb push_back

#define N 1005

typedef long long ll;
typedef vector< ll > vll;
int n , k;
vll target;
vll base( ll num , int b )
{
	vll ans;
	while( num )
	{
		ans.pb( num % b );
		num /= b;
	}
	reverse( all( ans ) );
	return ans;
}
ll memo[ N ][ 2 ];
ll dp( int pos , int menor )
{
	if( pos == n ) return 1;
	ll &dev = memo[ pos ][ menor ];
	if( dev == -1 )
	{
		if( ( n - pos )%2 == 0 ) dev = dp( pos + 1 , target[ pos ] != 0 );
		else
		{
			if( menor ) dev = k*dp( pos + 1 , menor );
			else dev = dp( pos + 1 , 0 ) + target[ pos ]*dp( pos + 1 , 1 );
		}
	}
	return dev; 
}
void impr( vll v ){
	int nv = v.size();
	REP( i , nv ) cout << v[ i ] << char( i + 1 == nv ? 10 : 32 ); 
	cout << endl;
}
int M = 16;
string neg( ll num , ll b )
{
	string ans;
	while( num )
	{
		ll r = num % ( -b );
		ll q = num / ( -b );
		if( r < 0 ) r += b , q++;
		ans += '0' + r;
		num = q;
	}
	reverse( all( ans ) );
	return string( M - (int)ans.size() , '0' ) + ans;
}
string pos( ll num , ll b )
{
	string ans;
	while( num )
	{
		ll r = num % ( b );
		ll q = num / ( b );
		ans += '0' + r;
		num = q;
	}
	reverse( all( ans ) );
	return string( M - (int)ans.size() , '0' ) + ans;
}
int main()
{
	int b = 2;
	for( int i = 0 ; i < 200 ; ++i )
	{
		string s = pos( i , b ) , t = neg( i , b );
		cout << "num " << setw( 3 ) << i << " " << s << " " << t << " " << ( s == t ? "YES" : "NO" ) << endl;
	
	}
	/*
	ll num;
	while( cin >> num >> k )
	{	
		target = base( num , k );
		
		//cout << target << endl;
		//impr( target );
		clr( memo , -1 );
		n = target.size();
		cout << dp( 0 , 0 ) << '\n';
		for( int i = 0 ; i <= num ; ++i )
	}
	*/
}
