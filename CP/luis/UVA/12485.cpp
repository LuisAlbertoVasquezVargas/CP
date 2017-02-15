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

typedef vector<string> vs;
typedef vector<int> vi;
const int N = (int)1e4;
int A[N + 5];

int main(){
	int n;
	while(scanf("%d",&n) == 1){
		REP(i,n) scanf("%d",&A[i]);
		int S = accumulate(A,A+n,0);
		if(S % n){
			puts("-1");
			continue;
		}
		int target = S/n , ans = 0;
		REP(i,n)
			if(A[i] > target) ans += A[i] - target;
		printf("%d\n" , ans + 1);
	}
}


