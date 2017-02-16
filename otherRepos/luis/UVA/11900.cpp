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
typedef vector< ll > vll;

const int N = 30;
int A[N + 5];
int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n , P , Q;
		scanf("%d%d%d" , &n , &P , &Q);
		REP(i , n)scanf("%d" , &A[ i ]);
		int sum = 0 , ans = 0;	
		REP(i,min(n , P)){
			if(sum + A[i] <= Q){
				sum += A[ i ];
				ans ++;
			}
		}
		printf("Case %d: %d\n" , tc + 1 , ans);
	}
}


