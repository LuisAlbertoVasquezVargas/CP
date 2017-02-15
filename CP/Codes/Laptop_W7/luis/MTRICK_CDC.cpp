#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

typedef long long ll;

ll A , B , C;
ll mul(ll a, ll b, ll c){
	ll x = 0, y = a % c;
	while(b > 0){
		if(b & 1){
			x += y;
			if(x >= c) x -= c;
		}
		y = y + y;
		if(y >= c) y -= c;
		b >>= 1;
	}
	return x % c;
}
int main()
{
	int cases;
	cin >> cases;
	while( cases -- )
	{
		int n;
		cin >> n;
		ll Array[ n ];
		REP( i , n ) cin >> Array[ i ];
		cin >> A >> B >> C;
		string s;
		cin >> s;
		int lo = 0 , hi = n - 1 , rev = 0;
		ll X = 1 , Y = 0;
		REP( i , n ){
			if( s[ i ] == 'A' ) Y = ( Y + A )%C;
			else if( s[ i ] == 'M' ) Y = mul( Y , B , C ) , X = mul( X , B , C );
			else rev ^= 1;
			cout << ( mul( X , Array[ !rev ? lo : hi ] , C ) + Y )%C << char( i + 1 == n ? 10 : 32 );
			if( !rev ) lo ++;
			else hi --;
		}
	}
}
