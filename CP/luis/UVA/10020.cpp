#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0; i < n ;++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

typedef pair<int , int> pii;
typedef vector<pii> vpii;

int main(){
	int cases;
	scanf( "%d" , &cases );
	REP(tc , cases){
		int m;
		scanf( "%d" , &m );
		vpii vec;
		while(1){
			int lo , hi;
			scanf("%d%d" , &lo , &hi);
			if(lo == 0 && hi == 0) break;
			vec.pb(mp(lo , hi));
		}
		sort(all( vec ));
		int tope = 0;
		bool possible = 1;
		vpii ans;
		REP(i , SZ(vec)){
			int ind;
			pii best(INT_MIN,INT_MIN);
			for(int j = i ; j < SZ(vec) ; ++j){
				if( vec[ j ].fi <= tope ){
					if(vec[ j ].se > best.se) best = vec[ j ];
					ind = j;
				}else break;
			}
			if(best.fi == INT_MIN){
				possible = 0;
				break;
			}
			ans.pb(best);
			tope = best.se;
			if( tope >= m ) break;
			i = ind;
		}
		if(!possible) ans.clear();
		if(tc)puts( "" );
		printf("%d\n" , SZ(ans));
		REP(i , SZ(ans))printf("%d %d\n" , ans[i].fi , ans[i].se);
	}
}



