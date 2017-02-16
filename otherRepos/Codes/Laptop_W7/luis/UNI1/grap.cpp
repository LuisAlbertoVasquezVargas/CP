#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);


#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int t;
char c;
int uf[40];

int FIND(int x){ return uf[x]==x? x:uf[x] = FIND(uf[x]); }
void UNION(int x,int y){ uf[FIND(x)] = FIND(y); }

string s;
bool ok;
int a,b;

int main()
{
	scanf("%d\n",&t);
	ok=1;
	while(t--){
		cin>>c;
		if(!ok)puts("");
		ok=0;
		getline(cin,s);
		int N=int(c)-'A';
		for(int i=0;i<=N;i++)uf[i]=i;	
		
		while(getline(cin,s)){
			if(s=="")break;	
			a=s[0]-'A';
			b=s[1]-'A';
			
			UNION(a,b);
		}
		int ans=0;
		for(int i=0;i<=N;i++)
			if(FIND(i)==i)ans++;
		cout<<ans<<endl;
	}
}



