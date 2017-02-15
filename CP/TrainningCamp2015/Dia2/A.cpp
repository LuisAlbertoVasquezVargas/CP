#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 55

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

double P[N];
int n;

double DP(int cur, int l, int r, int h){
	
	//printf("%d %d %d %d\n", cur, l, r, h);
	if(h == n)return 0;
	if(l == 1 || r == n + 1)return (r - l + 1 == n );
	
	double ans = P[cur] * DP(cur + 1, l, max(r, cur + 1), h + 1);
	ans += (1 - P[cur]) * DP(cur - 1, min(l, cur - 1), r, h + 1);
	
	return ans;
}

int main(){
	
	int k;
	while(scanf("%d%d", &n, &k) == 2){
		
		for(int i = 0; i < n; i++)
			scanf("%lf", &P[i]);
		
		double ans = DP(k, k, k, 1);
		printf("%.6lf\n", ans);
			
	}
	 
}



