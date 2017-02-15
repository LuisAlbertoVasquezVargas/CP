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

int main(){
	ios_base :: sync_with_stdio(0);
	int cases;
	cin >> cases;
	REP(tc , cases){
		int n;
		cin >> n;
		vs S(n);
		REP(i , n) cin >> S[ i ];
		vi dx = {0,0,1,-1};
		vi dy = {1,-1,0,0};
		REP(i , n) REP(j , n){
			if(S[i][j] != '.') continue;
			vi vis(5);
			REP(k , 4){
				int ni = i + dx[ k ];
				int nj = j + dy[ k ];
				if(ni >= 0 && ni < n && nj >= 0 && nj < n && isalpha(S[ni][nj]) && S[ni][nj] <= 'E')
					vis[S[ni][nj] - 'A'] = 1;
			}
			REP(k , 5){
				if(!vis[k]){
					S[i][j] = 'A' + k;
					break;
				}
			}
		}
		cout << "Case " << tc + 1 << ":\n";
		REP(i , n) cout << S[ i ] << '\n';
	}
}



