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
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-50)
#define PI acos( -1.0 )

typedef long double ld;
typedef vector< ld > poly;

void solve_cuadratic( ld A , ld B , ld C , ld &re1 , ld &im1 , ld &re2 , ld &im2 )
{
	ld disc = B*B - 4*A*C;
	ld Disc = abs( disc );
	ld x = -B/( 2*A ) , y = sqrt( Disc )/( 2*A );
	if( Disc < EPS || disc < EPS ) re1 = x , im1 = y , re2 = x , im2 = -y;
	else re1 = x + y , im1 = 0 , re2 = x - y , im2 = 0;
}

void bairstow( poly a , int n , poly &B , ld re[] , ld im[] , int &sz )
{
	ld b[ n + 1 ] , f[ n + 1 ];
	ld c , d , g , h;
	b[ n ] = b[ n - 1 ] = 0;
	f[ n ] = f[ n - 1 ] = 0;
	ld u = -1 , v = -1;
	REP( t , 100 )
	{
		for( int i = n - 2 ; i >= 0 ; --i )
		{
			f[ i ] = b[ i + 2 ] - u*f[ i + 1 ] - v*f[ i + 2 ];
			b[ i ] = a[ i + 2 ] - u*b[ i + 1 ] - v*b[ i + 2 ];
		}
		c = a[ 1 ] - u*b[ 0 ] - v*b[ 1 ];
		d = a[ 0 ] - v*b[ 0 ];
		g = b[ 1 ] - u*f[ 0 ] - v*f[ 1 ];
		h = b[ 0 ] - v*f[ 0 ];
		u = u -( -h*c + g*d )/( v*g*g + h*(h-u*g) );
		v = v -( -g*v*c + ( g*u - h )*d)/( v*g*g + h*(h-u*g) );
	}
	B = poly( b , b + n - 1 );
	solve_cuadratic( 1 , u , v , re[ sz ] , im[ sz ] , re[ sz + 1 ] , im[ sz + 1 ] );
	sz += 2;
}

void solve( poly a , int n , ld re[] , ld im[] , int &sz , bool &solvable )
{
	if( n == 0 )
	{
		if( abs( a[ 0 ] ) <= EPS ) re[ sz ] = im[ sz ] = 0 , sz++ ;
		else solvable = 0;
		return;
	}
	if( abs( a[ n ] ) < EPS )
	{
		re[ sz ] = im[ sz ] = 0;
		sz++;
		a.pop_back();
		solve( a , n - 1 , re , im , sz , solvable );
		return ;
	}
	if( n == 1 )
	{
		re[ sz ] = -a[ 0 ]/a[ 1 ];
		im[ sz ] = 0;
		sz++;
		return;
	}
	if( n == 2 )
	{
		ld A = a[ 2 ] , B = a[ 1 ] , C = a[ 0 ];
		solve_cuadratic( A , B , C , re[ sz ] , im[ sz ] , re[ sz + 1 ] , im[ sz + 1 ] );
		sz += 2;
		return;
	}
	poly F;
	bairstow( a , n , F , re , im , sz );
	solve( F , n - 2 , re , im , sz , solvable );
}
poly fix( poly V )
{
	int nV = V.size();
	while( nV > 1 && abs( V[ nV - 1 ] ) < EPS )
		V.pop_back() , nV--;
	return V;
}
poly sum( poly A , poly B )
{
	int nA = A.size() , nB = B.size() , nV = max( nA , nB );
	poly V( nV );
	REP( i , nA ) V[ i ] += A[ i ];
	REP( i , nB ) V[ i ] += B[ i ];
	return fix( V );
}
poly prod( poly A , poly B )
{
	int nA = A.size() , nB = B.size() , nV = nA + nB;
	poly V( nV );
	REP( i , nA )REP( j , nB ) V[ i + j ] += A[ i ]*B[ j ];
	return fix( V );
}

poly Integral( poly P )
{
	int nP = P.size();
	poly V( nP + 1 );
	REP( i , nP ) V[ i + 1 ] = P[ i ]/( i + 1 );
	return V;
}
ld eval( poly &P , ld x )
{
	int nP = P.size();
	ld ans = 0;
	for( int i = nP - 1 ; i >= 0 ;--i )
		ans = ans*x + P[ i ];
	return ans;
}
int main()
{
	int n;
	int tc = 0;
	while( cin >> n )
	{
		poly P( n + 1 );
		REP( i , n + 1 ) cin >> P[ i ];
		ld xlo , xhi , inc , XLO;
		cin >> xlo >> xhi >> inc;
		XLO = xlo;
		P = prod( P , P );
		P = Integral( P );
		ld Volume = PI *( eval( P , xhi ) - eval( P , xlo ) );
		//cout << Volume << endl;
		printf( "Case %d: %.2lf\n" , ++tc , double( Volume ) );
		if( abs( Volume - inc ) < EPS || Volume > inc )
		{
			vector< ld > sol;
			int sz = 0;
			while( 1 )
			{
				if( sz == 8 )break;
				if( Volume + EPS < ( sz + 1 )*inc )break;
				ld lo = xlo , hi = 200;
				REP( it , 100 )
				{
					ld med = ( lo + hi )/2;
					ld Vol = PI *( eval( P , med ) - eval( P , xlo ) );
					if( Vol >= inc + EPS ) hi = med;
					else lo = med;
				}
				sol.pb( hi - XLO );
				xlo = hi;
				sz++;
			}
			int ns = sol.size();
			REP( i , ns )printf( "%.2lf%s" , double( sol[ i ] ) , i + 1 == ns ? "\n": " " );
		}
		else puts( "insufficient volume" );
	}
}

