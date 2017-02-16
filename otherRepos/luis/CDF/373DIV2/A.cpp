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
typedef vector<ll> vll;

vi A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vi vec;
int main(){
	REP(k,100)REP(i,SZ(A))vec.pb(A[i]);
	A = vec;
	int n;
	while(cin >> n){
		vi a(n);
		REP(i,n) cin >> a[i];
		if(n == 1){
			if(a[0] == 0){
				cout << "UP\n";
				continue;
			}
			if(a[0] == 15){
				cout << "DOWN\n";
				continue;
			}
			cout << -1 << '\n';
			continue;
		}
		int pos = -1;
		REP(i,SZ(A)-SZ(a)+1){
			bool ok = 1;
			REP(k,SZ(a))
				if(a[k] != A[i + k]) ok = 0;
			if(ok){
				pos = i + SZ(a);
				break;
			}
		}
		assert(pos != -1);
		if(A[pos] < a.back()) cout << "DOWN\n";
		else cout << "UP\n";
	}
}


