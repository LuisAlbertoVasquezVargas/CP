#include <bits/stdc++.h>
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
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

double frec[50];

int main(){
	
	int n, x, y;
	bool flag = false;
	
	while(scanf("%d%d", &x, &y) == 2){
		
		if(flag)puts("");
		flag = true;
		
		for(int i = 0; i <= x + y; i++)frec[i] = 0;
		
		for(int i = 1; i <= x; i++)
			for(int j = 1; j <= y; j++)frec[i + j] = frec[i + j] + 1.0/(x * y * 1.0);	
		
		double maxi = -1;
		int res;
		for(int i = 1; i <= x + y; i++)maxi = max(maxi, frec[i]);
		
		for(int i = 1; i <= x + y; i++)if(maxi == frec[i])printf("%d\n", i);	

		
	}
}


