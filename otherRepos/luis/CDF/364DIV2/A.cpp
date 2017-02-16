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
typedef vector<int> vi;
typedef pair<int , int> pii;
typedef vector<pii> vpii;

int main(){
	int n;
	while( cin >> n ){
		vpii A(n);
		REP(i , n) A[i].se = i + 1;
		REP(i , n) cin >> A[i].fi;
		sort(all(A));
		REP(i , n/2){
			cout << A[i].se << " " << A[n - 1 - i].se << '\n';
		}
	}
}
