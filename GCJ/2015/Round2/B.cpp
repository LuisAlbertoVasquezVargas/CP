#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 2
#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;
typedef long double ld;

double R[ N + 5 ] , C[ N + 5 ];

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		double V, X;
		scanf("%d%lf%lf", &n, &V, &X);
		
		REP( i , n ) scanf("%lf%lf", &R[i], &C[i]);
			
		bool ok = true;
		ld ans = 0;
		
		if(n == 1){
			if(C[0] != X)ok = false;
			else ans = V/R[0];
		}
		else{
			ld a1 = R[0] * (C[0] - X);
			ld a2 = R[1] * (C[1] - X);

			ld b1 = R[0];
			ld b2 = R[1];
			ld d = R[1] * a1 - R[0] * a2;
	
			if(d == 0)ok = false;
			else{
				
				ld t2 = (V * a1)/d;
				ld t1 = (V - R[1]*t2)/R[0];
				
				ans = max(t1, t2);
				if(a1 * d < 0 || (V - R[1]*t2) < 0)ok = false;
			}
			
			
		}
		
		if(!ok)printf("Case #%d: IMPOSSIBLE\n", tc + 1 );
		else printf("Case #%d: %.10lf\n", tc + 1 , (double) ans);
	}
	
}


