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

const int N = 100000;
int A[N + 5];

int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		if(!n) break;
		REP(i , n) scanf("%d" , &A[i]);
		ll ans = 0 ;
		int sum = 0;
		REP(i , n - 1){
			sum += A[ i ];
			ans += abs(sum);
		}
		printf("%lld\n" , ans);
	}
}





