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

typedef long long ll;
typedef pair<int,int>pii;
typedef vector<pii> vpii;

int main(){
	int n , tc = 0;
	while(scanf("%d" , &n) == 1){
		if(!n) break;
		vpii vec;
		REP(i , n){
			int B , J;
			scanf("%d%d" , &B , &J);
			vec.pb(mp(J , B));
		}
		sort(all(vec) , greater<pii>() );
		int sum = 0 , best = 0;
		for(auto p : vec){
			sum += p.se;
			best = max(best , sum + p.fi);
		}
		printf("Case %d: %d\n" , ++tc , best);
	}
}



