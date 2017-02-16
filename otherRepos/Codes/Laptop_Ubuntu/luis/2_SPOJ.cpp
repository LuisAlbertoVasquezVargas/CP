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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;


int pow( int a , int b , int c ){
    int ans = 1;	
    while( b ){
        if( b&1 ) ans = ( 1LL*ans * a )%c;
        a = ( 1LL*a*a )%c;
        b >>= 1;
    }	
    return ans;
}
bool miller(ll p, int it = 8){
	if(p < 2) return 0;
	if(p != 2 && (p & 1) == 0) return 0;
	int s = p - 1;
	while( (s & 1) == 0) s >>= 1;
	while( it-- ){
		int a = rand() % (p - 1) + 1, temp = s;
		int mod = pow(a, temp, p);
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = ( 1LL* mod*mod)%p;
			temp <<= 1;
		}
		if(mod != p - 1 && (temp & 1) == 0) return 0;
	}
	return 1;
}


int main()
{
	int tc;
	sc( tc );
	bool ok = 0;
	while( tc-- )
	{
		if( !ok ) ok = 1;
		else puts( "" );
		int n , m;
		sc( n ) , sc( m );
		for( int i = n ; i <= m ; ++i )
			if( miller( i ) )
				printf( "%d\n" , i );
	}
}


