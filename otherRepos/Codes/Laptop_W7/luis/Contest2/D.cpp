#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define N 4500005

typedef long long ll;
typedef vector< char > vi;

//map< ll , ll > memo;
ll memo[ N ];
bool done[ N ];
char n;
vi target;
char dx[] = { 18 , 2 , 2 , 3 , 3, 3, 3, 3, 3,3,3,3,3,3,3,3,3,3,3 };
inline int hash( vi &v ){
	int ans = 0;
	int nv = v.size();
	REP( i , nv ) ans = ans * dx[ i ] + v[ i ];
	return ans;
}
ll dp( vi &v ){
	char pos = v[ 0 ] ;
	bool menor = v[ 1 ] , taked = v[ 2 ];
	if( pos == n ){
		//cout << "concha" << endl;
		return taked;
	}
	ll HASH = hash( v );
	//if( memo[ hash( v ) ] == -1 ) return memo[ HASH ];
	/*cout << "pos : " << v[ 0 ] << endl;
	cout << "menor : " << v[ 1 ] << endl;
	cout << "taked : " << v[ 2 ] << endl;*/
	ll &dev = memo[ HASH ];
	char i;
	if( !done[ HASH ] ){
		done[ HASH ] = 1;
		dev = 0;
		if( taked == 0 ){
			vi ww = v;
			ww[ 0 ]++;ww[ 1 ] = 1;
			dev += dp( ww );
			if( menor == 0 )
			{
				
				for( i = 1 ; i <= target[ pos ] ; ++i )
				{
					vi w = v;
					w[ 0 ]++;
					if( target[ pos ] == i ) w[ 1 ] = 0;
					else w[ 1 ] = 1;
					w[ 2 ] = 1;
					w[ 3 + i ] ++;
					dev += dp( w );
				}
			}
			else
			{
				for( i = 1 ; i <= 9 ; ++i )
				{
					vi w = v;
					w[ 0 ]++;
					w[ 1 ] = 1;
					w[ 2 ] = 1;
					w[ 3 + i ] ++;
					dev += dp( w );
				}
			}
		}
		else
		{
			if( menor == 0 )
			{
				for( i = 0 ; i <= target[ pos ] ; ++i )
					if( v[ i + 3 ] <= 1 ){
						vi w = v;
						w[ 0 ] ++;
						if( target[ pos ] == i ) w[ 1 ] = 0;
						else w[ 1 ] = 1;
						w[ i + 3 ]++;
						dev += dp( w );
					}
			}
			else
			{
				for( i = 0 ; i <= 9 ; ++i )
					if( v[ i + 3 ] <= 1 )
					{
						vi w = v;
						w[ 0 ] ++;
						w[ i + 3 ] ++;
						dev += dp( w );
					}
			}
		}
	}
	return dev;
}
bool ok;
ll f( ll X ){
	if( X == 0 ) return 0;
	n = 0;
	target.clear();
	while( X )
	{
		target.push_back( X%10 );
		X /= 10;
		n++;	
	}
	reverse( target.begin() , target.end() );
	//REP( i , n ) cout << (int)target[ i ] << char(i + 1 == n ? 10 : 32 );
	//cout << int(n) << endl;
	if( ok ) clr( done , 0 );
	else ok = 1;
	//REP( i , n ) cout << target[ i ] << char( i + 1 == n ? 10 : 32 );
	vi v = vi( 13 );
	return dp( v );
}
int main()
{
	freopen("exchange.in", "r", stdin);freopen("exchange.out", "w", stdout);
	ll L , R; 
	ok = 0;
	//cout << f( 1000 ) << endl;
	while( cin >> L >> R ){
		ll A = f( L - 1 ) , B = f( R );
		//cout << A << " " << B << endl;
		cout << B - A << '\n';
	}
}



