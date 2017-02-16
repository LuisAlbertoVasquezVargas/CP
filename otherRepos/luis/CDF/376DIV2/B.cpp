#include<bits/stdc++.h>
using namespace std;
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
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int n,K;
	while(cin>>n>>K){
		vi a(n);
		REP(i,n)cin>>a[i];
		int ans=0;
		REP(i,n-1){
			int cur=max(0,K-(a[i+1]+a[i]));
			ans+=cur;
			a[i+1]+=cur;
		}
		printf("%d\n",ans);
		REP(i,n)printf("%d%c",a[i],(i+1==n?10:32));
	}
}


