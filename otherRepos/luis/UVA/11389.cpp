#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0; i < n ;++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

const int N = 100;
int A[N + 5] , B[N + 5];
int main(){
	int n , d , R;
	while(scanf("%d%d%d" , &n , &d , &R) == 3){
		if(n == 0 && d == 0 && R == 0) break;
		REP(i , n) scanf("%d" , &A[ i ]);
		REP(i , n) scanf("%d" , &B[ i ]);
		sort(A , A + n);
		sort(B , B + n);
		int ans = 0;
		REP(i , n) ans += max( 0 , A[ i ] + B[ n - 1 - i ] - d );
		printf( "%d\n" , ans * R );
	}
}


