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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 300005
#define MOD 1000000009
#define INF (1<<30)
#define EPS (1e-5)
using namespace std;

int n;

ll pow( ll a , ll b , ll c ){
    ll ans = 1;	
    while( b ){
        if( b&1 ) ans = ( ans * a )%c;
        a = ( a*a )%c;
        b >>= 1;
    }	
    return ans;
}
ll mod_inv( ll a , ll p ){ return pow( a , p - 2 , p );}
ll F[N] , FP[N];
void init(){
	F[ 0 ] = 1;
	for( int i = 1 ; i < N ; ++i ) 
		F[ i ] = i*F[ i - 1 ] , F[ i ] %= MOD;
	FP[ N - 1 ] = mod_inv( F[ N - 1 ] , MOD ) ;
	for( int i = N - 2 ; i >= 0 ; --i ) 
		FP[ i ] = FP[ i + 1 ]*( i + 1 ) , FP[ i ] %= MOD;
}
// Lucas Teorem 
// Cuando n y m son grandes y se pide comb(n,m)%MOD, donde MOD es un numero primo, se puede usar el Teorema de Lucas.
ll comb( ll n, ll k ){
	ll ans = 1;
    while( n > 0 ){
        ll ni = n%MOD,ki = k%MOD;
        n /= MOD; k /= MOD;
        if( ni - ki < 0 )return 0;
        ll temp = (FP[ki]*FP[ni-ki])%MOD;
        temp = (temp*F[ni])%MOD;
        ans = (ans*temp)%MOD;
    }
    return ans;
}

int main()
{
	init();
	while( scanf("%d",&n) == 1 ) {
		long long res=0;
		for(int i=2;i<=n;i++){
			res=(res+((pow(2,i,MOD)-2+MOD)%MOD)*comb(n,n-i))%MOD;
			
		}
		cout<<res<<endl;
	}
}


