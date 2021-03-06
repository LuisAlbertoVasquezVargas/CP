#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
ll pow( ll numa, ll  numb, ll numc ){
    ll numx = 1, numy = numa;	
    while( numb > 0 ){
        if( numb&1 ) numx = ( numx * numy )%numc;
        numy = ( numy*numy)%numc;
        numb >>= 1;
    }	
    return numx;
}
ll mod_inv( ll numa , ll mod ){	return pow( numa , mod - 2 , mod );	}

char s[ N ] ;
int k;

int main()
{
	while( scanf( "%s%d" , s , &k ) == 2 )
	{
		int ns = strlen( s );
		ll two = (pow( 2 , 1LL*ns*k , MOD ) - 1 + MOD)%MOD;
		ll ans = 0 , t = (pow( 2 , 1LL*ns , MOD ) - 1 + MOD)%MOD , inv = mod_inv( t , MOD );
		vi V; 
		REP( i , ns )
			if( (s[i] == '0' || s[i] == '5' ) )V.pb(i);
		int nV = V.size();
		REP( i , nV )ans = ( ans + (((pow( 2 , V[i] , MOD )*two)%MOD)*inv)%MOD )%MOD;
		cout << ans << endl;
	}
}


