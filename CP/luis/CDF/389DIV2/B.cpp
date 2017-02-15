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
typedef vector<pii> vpii;
typedef vector< int > vi;

int main(){
	ios_base::sync_with_stdio(0);
	string s,t;
	while(cin>>s>>t){
		int n=SZ(s);
		REP(i,n)s[i]-='a',t[i]-='a';
		vi F(26,-1);
		bool ok=1;
		REP(i,n)
			if(s[i]==t[i]){
				if(F[s[i]]==-1||F[s[i]]==s[i]){
					F[s[i]]=s[i];
					continue;
				}
				ok=0;
				break;
			}else{
				if((F[s[i]]==-1&&F[t[i]]==-1)||(F[s[i]]==t[i]&&F[t[i]]==s[i])){
					F[s[i]]=t[i];
					F[t[i]]=s[i];
					continue;
				}
				ok=0;
				break;
			}
		if(!ok){
			cout<<-1<<'\n';
			continue;
		}
		vpii P;
		REP(i,26){
			if(F[i]==-1)continue;
			if(F[i]==i)continue;
			int p=F[i];
			F[i]=F[p]=-1;
			P.pb(mp(i,p));
		}
		cout<<SZ(P)<<'\n';
		for(auto p:P)
			cout<<char('a'+p.fi)<<" "<<char('a'+p.se)<<'\n';
	}
}



