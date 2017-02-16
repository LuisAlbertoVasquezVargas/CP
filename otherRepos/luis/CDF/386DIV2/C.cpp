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

int get(int x1,int x2,int p,int d,int s){
	bool visX1=0,visX2=0;
	int cnt=0;
	while(1){
		//DEBUG(p);
		if(p==x1)visX1=1;
		else if(p==x2){
			if(visX1)return cnt;
		}
		if(p+d>=0&&p+d<=s)p+=d,cnt++;
		else d*=-1;
	}
}
int main(){
	int s,x1,x2;
	int t1,t2;
	int p,d;
	while(cin>>s>>x1>>x2>>t1>>t2>>p>>d){
		int ans=abs(x2-x1)*t2;
		int timer=get(x1,x2,p,d,s);
		ans=min(ans,timer*t1);
		cout<<ans<<'\n';
	}
}



