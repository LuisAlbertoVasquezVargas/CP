#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef long long ll;

const ll INF = LLONG_MAX/2;
const int N = 3000;
const int R = 45;
int A[N + 5];
vi MAPA;
int n , m;
ll DP[2][3 * N * R + 6 * N + 5];
set<int> SET;
void getMed(){
	vi v(A , A + n);
	sort(all(v));
	int med;
	if(n & 1) med = v[n >> 1];
	else med = (v[n >> 1] + v[(n >> 1) - 1]) >> 1;
	for(int k = -n ; k <= n ; ++k)
		SET.insert(med + k);
}
int main(){
	ios_base :: sync_with_stdio(0);
	while(cin >> n){
		REP(i , n) cin >> A[i];
		SET.clear();
		int mini = *min_element(A , A + n);
		int maxi = *max_element(A , A + n);
		getMed();
		REP(i,n) SET.insert(mini - (i + 1));
		REP(i,n) SET.insert(mini + (i + 1));
		REP(i,n) SET.insert(maxi + (i + 1));
		REP(i,n) SET.insert(maxi - (i + 1));
		REP(i , n)for(int k = -R ; k <= R ; ++k) SET.insert(A[i] + k);
		
		MAPA = vi(all(SET));
		m = SZ(MAPA);
		
		REP(last,m + 1) DP[n&1][last] = (last == m ? INF : 0);
		for(int pos = n - 1 ; pos >= 0 ; --pos){
			DP[pos&1][m] = INF;
			for(int last = m - 1; last >= 0 ; --last){
				DP[pos&1][last] = DP[pos&1][last + 1];
				DP[pos&1][last] = min(DP[pos&1][last] , abs(MAPA[last] - A[pos]) + DP[(pos + 1)&1][last + 1]);
			}
		}
		cout << DP[0][0] << '\n';
	}
}


