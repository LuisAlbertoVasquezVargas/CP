#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0; i < n ;++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

const int N = 1000;
int A[ N + 5 ];

int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n;
		scanf("%d" , &n);
		REP(i , n) scanf("%d" , &A[ i ]);
		int ans = 0 ;
		long long sum = 0;
		REP(i , n){
			if(A[ i ] > sum){
				sum += A[ i ];
				ans ++;
			}
		}
		printf("%d\n" , ans);
	}
}




