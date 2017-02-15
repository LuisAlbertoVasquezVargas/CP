#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define PI acos( -1.0 )
#define EPS (1e-5)
// 6440 

int main()
{
	double s , a , ang ;
	string op;
	while( cin >> s >> a >> op )
	{
		if( op == "deg" )
			ang = 2*PI*a/360;
		else
			ang = 2*PI*a/(21600);
		if( ang > PI ) ang = 2*PI - ang; 
		double r = 6440 + s;
		printf( "%.6lf %.6lf\n" , ang*r , 2*sin( ang/2 )*r );
	}
}

