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

const int MAX_N=200000;
set<int>POS[2];
bool erased[MAX_N];
string s,t;
int main(){
	int n;
	while(cin>>n>>s){
		REP(i,n)s[i]=(s[i]=='D');
		while(1){
			n=SZ(s);
			REP(k,2)POS[k].clear();
			REP(i,n)POS[s[i]].insert(i);
			if(!SZ(POS[0]))break;
			if(!SZ(POS[1]))break;
			REP(k,n)erased[k]=0;
			REP(i,n)
				if(!erased[i]){
					if(POS[s[i]^1].empty())continue;
					auto p=POS[s[i]^1].upper_bound(i);
					if(p==POS[s[i]^1].end())p=POS[s[i]^1].begin();
					int pos=*p;
					POS[s[i]^1].erase(p);
					erased[pos]=1;
				}
			t.clear();
			REP(i,n)
				if(!erased[i])t.pb(s[i]);
			s=t;
		}
		if(s.empty())assert(0);
		else cout<<(s[0]==1?'D':'R')<<'\n';
	}
}



