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

#define test() cerr<<"hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool isVowel(int c){
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')return 1;
	return 0;
}
int main(){
	string s;
	while(cin>>s){
		int ans=0;
		REP(i,SZ(s)){
			if(isVowel(s[i]))continue;
			int ind;
			for(int j=i;j<SZ(s);++j)
				if(!isVowel(s[j]))
					ind=j;
				else break;
			ans=max(ans,ind-i+1);
			i=ind;
		}
		ans++;
		cout<<ans<<'\n';
	}
}


