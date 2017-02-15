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
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int N = 65;
int Find(int x , vi &F){
	int up = -1;
	for(int i = x ; i <= N ; ++i)
		if(F[ i ]){
			up = i;
			break;
		}
	int down = -1;
	for(int i = x ; i >= 1 ; --i)
		if(F[ i ]){
			down = i;
			break;
		}
	if(up == -1) return down;
	if(down == -1) return up;
	if(abs(up - x) <= abs(down - x) ) return up;
	return down;
}
int main(){
	int tc = 0 , n , m;
	while(scanf("%d%d" , &n , &m) == 2){
		if(!n && !m) break;
		vi A(n) , F(N + 5);
		REP(i , n) scanf("%d" , &A[ i ]);
		REP(i , m) {
			int x;
			scanf("%d" , &x);
			F[ x ] ++;
		}
		sort(all(A));
		reverse(all(A));
		int left = n;
		REP(i , n){
			int pos = Find(A[ i ] , F);
			if(pos == -1) break;
			left --;
			F[ pos ] --;
		}
		if(left == 0){
			printf("Case %d: 0\n" , ++tc );
		}else{
			printf("Case %d: %d %d\n" , ++tc , left , A[n - 1] );
		}
	}
}


