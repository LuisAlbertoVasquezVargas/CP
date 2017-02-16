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

ll pow( ll numa, ll  numb, ll numc ){
    ll numx = 1, numy = numa;	
    while( numb > 0 ){
        if( numb&1 ) numx = ( numx * numy )%numc;
        numy = ( numy*numy)%numc;
        numb >>= 1;
    }	
    return numx;
}
ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream st; st<<t;return st.str();}

int main()
{
	int tc;
	cin >> tc;
	while( tc-- )
	{
		ll n , k ;
		cin >> n >> k;
		int least = pow(n, k, 1000), most;
		long double z = log10l(n);z *= k;
		long double m = (3) - 1 - floor(z);
		if(m >= 0.0) most = least;
		else most = (ll)powl(10.0l, z + m);
		printf( "%03d..." , most);
		printf( "%03d\n" , least );
	}
}


