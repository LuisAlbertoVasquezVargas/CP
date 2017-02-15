#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0; i < n ;++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

typedef long double ld;
typedef pair<ld , ld> pld;
typedef vector<pld> vpld;
const ld EPS = 1e-8;

int main(){
	int n , L , W;
	while(scanf("%d%d%d" , &n , &L , &W) == 3){
		vpld vec;
		REP(i , n){
			int x , r;
			scanf("%d%d" , &x , &r);
			if( r * 2 < W ) continue;
			assert( ((ld)r * r - (ld)W * W /4.0) >= 0 );
			ld d = sqrt( (ld)r * r - (ld)W * W /4.0 );
			//cout << x - d << " " << x + d << endl;
			vec.pb(mp(x - d , x + d));
		}
		sort(all( vec ));
		ld tope = 0;
		bool possible = 1;
		int ans = 0;
		REP(i , SZ(vec)){
			int ind;
			ld best = -1e5;
			for(int j = i ; j < SZ(vec) ; ++j){
				if(vec[ j ].fi < tope + EPS){
					if(vec[ j ].se > best + EPS) best = vec[ j ].se;
					ind = j;
				}else break;
			}
			if(best == -1e5){
				possible = 0;
				break;
			}
			ans ++;
			tope = best;
			if( tope > L - EPS ) break;
			i = ind;
		}
		if( tope < L - EPS )possible = 0;
		if(!possible) ans = -1;
		printf("%d\n" , ans);
	}
}



