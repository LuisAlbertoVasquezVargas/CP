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

#define ld long double

using namespace std;
ld a , r3 = sqrt( 3.0 ) , pi = acos( -1.0 );

int main()
{
	while( cin >> a )
	{
		ld A1 = a*a , A2 = pi*a*a/4 , A3 = (pi*a*a/3) - (a*a*r3/4);
		ld AB = A2 - A3;
		ld C = A1 - 4*AB;
		ld B = (A3 - AB) - C;
		ld A = AB - B;
		printf( "%.3lf %.3lf %.3lf\n" , double( C ) , double( 4*B ) , double( 4*A ) );
	}
}


