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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<vi> vvi;

void impr(int a,int b,int c){
	printf("%d %d %d\n",a,b,c);
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		vvi F(n+1,vi(n+1));
		for(int i=1;i<=n;++i)
			F[i][i]=n;
		int pos=1;
		F[1][1]--;
		F[1][0]++;
		
		impr(1,1,0);
		while(1){
			int target=-1;
			for(int i=n;i>=1;--i){
				if(F[pos][i]==0){
					if(F[i][i]>=2){
						target=i;
						break;
					}
				}
			}
			if(target==-1)break;
			F[pos][target]++;
			F[pos][0]--;
			
			F[target][target]--;
			F[target][0]++;
			impr(target,target,pos);
			pos=target;
		}
		impr(0,1,pos);
	}
}


