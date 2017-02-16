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

typedef pair<int , int> pii;
typedef vector<pii> vpii;
typedef vector< int > vi;
typedef vector<vi> vvi;
typedef vector< string > vs;

void update( vi &x , int tam , int cant ){
	x[ tam ] = max( 0 , x[ tam ] - cant );
}
int main(){
	vi x(7);
	while( scanf("%d" , &x[ 1 ]) == 1){
		for(int i = 2 ; i <= 6 ; ++i)
			scanf("%d" , &x[ i ]);
		if(x == vi(7)) break;
		//solving 6
		int ans = x[ 6 ];
		x[ 6 ] = 0;
		//solving 5
		ans += x[ 5 ];
		int cur = x[ 5 ] * (36 - 25);
		update( x , 1 , cur );
		//solving 4
		ans += x[ 4 ];
		int space = x[ 4 ] * (36 - 16);
		int used = min( space / 4 , x[ 2 ] );
		space -= used * 4;
		update( x , 2 , used );
		update( x , 1 , space );
		//solving 3
		ans += x[ 3 ]/4;
		x[ 3 ] %= 4;
		vi array = { -1 , 5 , 3 , 1 };
		if( x[ 3 ] == 0 ){
			//nothing LOL
		}else{
			ans ++;
			int cant = array[ x[ 3 ] ];
			space = 36 - x[ 3 ] * 9; 
			used = min(cant , x[ 2 ]);
			space -= used * 4;
			update( x , 2 , used );
			update( x , 1 , space );
		}
		//solving 2
		ans += x[ 2 ] / 9;
		x[ 2 ] %= 9;
		if(x[ 2 ]) {
			ans ++;
			space = 36 - x[ 2 ] * 4;
			update( x , 1 , space );
		}
		//solving 1
		ans += x[ 1 ] / 36;
		x[ 1 ] %= 36;
		if( x[ 1 ] ) ans ++;
		printf("%d\n" , ans);
	}
}




