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
char cad[ N + 5 ];

int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n;
		scanf("%d" , &n);
		scanf("%s" , cad);
		int ans = 0;
		REP(i , n){
			if(cad[ i ] == '#')continue;
			ans ++;
			i += 2;
		}
		printf( "Case %d: %d\n" , tc + 1 , ans );
	}
}


