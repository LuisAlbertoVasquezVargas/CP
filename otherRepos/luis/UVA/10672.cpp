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

const int N = 10000;
vi G[N + 5];
int ind[N + 5] , W[N + 5] , SW[N + 5] , T[N + 5];
void clear(int n){
	REP(i,n) G[i].clear();
	REP(i,n) ind[i] = 0;
}
int ans = 0;
void dfs(int u){
	SW[ u ] = W[ u ];
	T[ u ] = 1;
	for(auto v : G[u]){
		dfs(v);
		SW[ u ] += SW[ v ];
		T[ u ] += T[ v ];
	}
	ans += abs(SW[ u ] - T[ u ]);
}
int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		if(!n) break;
		clear(n);
		REP(i , n){
			int u , w , len;
			scanf("%d%d%d" , &u , &w , &len);
			u --;
			W[ u ] = w;
			REP(j , len){
				int v;
				scanf("%d" , &v);
				v --;
				G[ u ].pb(v);
				ind[ v ] ++;
			}
		}
		int root = find(ind , ind + n , 0) - ind;
		ans = 0;
		dfs(root);
		printf("%d\n" , ans);
	}
}


