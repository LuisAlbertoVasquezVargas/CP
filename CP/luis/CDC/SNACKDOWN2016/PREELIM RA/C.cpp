#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

typedef long long ll;

int main(){
	int cases;
	scanf( "%d" , &cases );
	REP(tc , cases){
		ll A , B , C , D;
		scanf( "%lld%lld%lld%lld" , &A , &B , &C , &D );
		ll g = __gcd(C , D);
		ll Z = (B - A)/ g;
		ll ans = LLONG_MAX;
		for( ll dx = -3 ; dx <= 3 ; ++dx ){
			ll curZ = Z + dx;
			ans = min( ans , abs(A - B + g * curZ) );
		}
		printf( "%lld\n" , ans );
	}
}


