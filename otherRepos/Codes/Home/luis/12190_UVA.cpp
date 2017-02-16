#include<bits/stdc++.h>
using namespace std;

#define INF (1LL<<32)

typedef long long ll;


ll f( ll x ){
	if( x <= 100LL ) return x*2LL;
	if( x <= 10000LL ) return 100LL*2LL + (x - 100LL)*3LL ;
	if( x <= 1000000LL ) return 100LL*2LL + (10000LL-100LL)*3LL + ( x - 10000LL )*5LL;
	return 100LL*2LL + (10000LL-100LL)*3LL + (1000000LL-10000LL)*5LL + ( x - 1000000LL )*7LL;
}
ll findAB( ll X )
{
	ll lo = 0 , hi = INF;
	if( f( lo ) >= X ) return lo;
	while( hi - lo > 1 )
	{
		ll med = ( lo + hi )/2;
		if( f( med ) >= X ) hi = med;
		else lo = med;
	}
	return hi;
}
void solve( ll &A , ll &B , ll AB , ll Y )
{
	ll lo = 0 , hi = AB;
	if( f( lo ) - f( AB - lo ) >= Y )
	{
		B = 0 , A = AB;
		return;
	}
	while( hi - lo > 1 )
	{
		ll med = ( lo + hi )/2;
		if( f( med ) - f( AB - med ) >= Y ) hi = med;
		else lo = med;
	}
	B = hi , A = AB - B;
}
int main()
{
	ll X , Y;
	while( cin >> X >> Y )
	{
		if( X == 0 && Y == 0 ) break;
		ll AB = findAB( X );
		ll A , B;
		solve( A , B , AB , Y );
		cout << f( A ) << '\n';
	}
}
