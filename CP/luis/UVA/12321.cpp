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
	int L , n;
	while(scanf("%d%d" , &L , &n) == 2){
		if(L == 0 && n == 0) break;
		vpii vec;
		REP(i , n){
			int x , d;
			scanf( "%d%d" , &x , &d );
			vec.pb(mp(x - d , x + d));
		}
		sort(all(vec));
		int tope = 0;
		bool possible = 1;
		int ans = 0;
		REP(i , SZ(vec)){
			int ind;
			int best = INT_MIN;
			for(int j = i ; j < SZ(vec) ; ++j){
				if(vec[ j ].fi <= tope){
					ind = j;
					if(vec[ j ].se > best) best = vec[ j ].se;
				}else break;
			}
			if(best > tope){
				tope = best;
				ans ++;
			}else{
				possible = 0;
				break;
			}
			if(tope >= L) break;
			i = ind;
		}
		if(tope < L) possible = 0;
		if(!possible)ans = -1;
		else ans = n - ans;
		printf("%d\n" , ans);
	}
}


