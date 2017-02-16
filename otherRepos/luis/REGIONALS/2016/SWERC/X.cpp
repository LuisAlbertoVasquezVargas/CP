#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define N 102

vector<int>pila[N];
int memo[N][1002], k;

int DP(int id, int pos){
	
	if(pos < 0)return 0;
	int &ret = memo[id][pos];
	
	if(ret != -1)return ret;
	set<int>s;
	
	for(int i = 0; i <= k; i++){
		
		if(pos - i < 0)continue;
		if(pila[id][pos - i] <= pos - i + 1)s.insert(DP(id, pos - i - pila[id][pos - i]));
	}
	
	int top = 0;
	while(s.count(top))top++;
	return ret = top;
}

int main(){
	
	int p;
	while(scanf("%d%d", &p, &k) == 2){
		
		for(int i = 0; i < p ; i++){
			pila[i].clear();
			for(int j = 0; j <= 1000; j++)memo[i][j] = -1;
		}
		
		for(int i = 0; i < p; i++){
			
			int n, x;
			scanf("%d", &n);
			
			for(int j = 0; j < n; j++)
				scanf("%d", &x), pila[i].pb(x);
		}
		
		int ans = 0;
		for(int i = 0; i < p; i++)ans ^= DP(i, pila[i].size() - 1);
		
		if(ans == 0)puts("Bob will win.");
		else puts("Alice can win.");
		
	}
}
