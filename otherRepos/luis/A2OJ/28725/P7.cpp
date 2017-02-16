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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=(int)1e5;
int DP[MAX_N+1];
int main(){
	int myN;
	while(scanf("%d",&myN)==1){
		DP[0]=0;
		int move=-1;
		for(int n=1;n<=myN;++n){
			set<int>mySet;
			map<int,int>myMap;
			for(int r=1;(r*(r+1))/2<=n;++r){
				if((2*n)%(r+1))continue;
				int ak=(2*n)/(r+1)-r;
				if(ak&1)continue;
				ak/=2;
				if(ak>0){
					int xorSum=0;
					REP(s,r+1)xorSum^=DP[ak+s];
					mySet.insert(xorSum);
					if(n==myN){
						if(!myMap.count(xorSum))
							myMap[xorSum]=r+1;
					}
				}
			}
			int ans=0;
			while(mySet.count(ans))ans++;
			DP[n]=ans;
			if(n==myN){
				move=myMap[0];
			}
		}
		if(!DP[myN]){
			puts("-1");
			continue;
		}
		printf("%d\n",move);
	}
}


