#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ;i < n; ++i)

#define mp make_pair
#define fi first
#define se second

#define pb push_back

typedef long long ll;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll;

const ll INF = (ll)(1e9) + 5;

void f( ll t , bool flag){
	vpll ans;
	pll mini(INF , 1LL);
	vector< string > name(5);
	REP(it , 5){
		ll K , D;
		cin >> name[ it ] >> K >> D;
		pll temp;
		if(D == 0) temp = mp( INF , 1 );
		else{
			ll g = __gcd(K , D); 
			K /= g , D /= g;
			temp = mp( K , D );
		}
		if( mini.fi * temp.se > temp.fi * mini.se )
			mini = temp;
		ans.pb( temp );
	}
	REP(k , 5){
		//if( ans[ k ] == mp(INF,1LL) ) continue;
		if( (mini == ans[ k ] && flag) || ans[ k ].fi * t < ans[ k ].se ){
			cout << name[ k ] << " plz uninstall\n";
		}
	}
}

int main(){
	int cases;
	cin >> cases;
	REP(tc , cases){
		f( 3 , 0 );
		f( 2 , 1 );
	}
}


