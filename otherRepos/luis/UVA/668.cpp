#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;
typedef long double ld;

const int N = 80;
int A[ N + 5 ] , AC[ N + 5 ];
ld B[ N + 5 ] , AC2[ N + 5 ];
int get1(int lo , int hi){
	return AC[ hi ] - AC[ lo - 1 ];
}
ld get2(int lo , int hi){
	return AC2[ hi ] - AC2[ lo - 1 ];
}
int main(){
	for(int i = 1 ; i <= N ; ++i){
		A[ i ] = i;
		AC[ i ] = AC[ i - 1 ] + A[ i ];
		B[ i ] = log( i );
		AC2[ i ] = AC2[ i - 1 ] + B[ i ];
	}
	
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n;
		scanf("%d" , &n);
		ld best = -1;
		vi ans;
		for(int a = 1 ; a <= N ; ++a)
			for(int b = a ; b <= N && get1(a , b) <= n; ++b)
				for(int c = b + 1 ; c <= N ; ++c)
					for(int d = c ; d <= N && get1(a,b) + get1(c,d) <= n ; ++d){
						if( get1(a,b) + get1(c,d) == n){
							ld cur = get2(a,b) + get2(c,d);
							if(best < cur){
								best = cur;
								ans = {a , b, c , d};
							}
						}
					}
		vi vec;
		REP( k , 2 )
			for(int a = ans[ 2 * k ] ; a <= ans[ 2 * k + 1 ] ; ++a) vec.pb(a);
		if(tc) puts("");
		REP(i , SZ(vec)) printf("%d%c" , vec[ i ] , (i + 1 == SZ(vec)?10:32));
	}
}


