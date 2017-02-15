#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 10005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int ns , nt ;
char S1[ N ] , S2[ N ];

int next[N][30] , node , T[N] , term[N];

char can[] = "abcdefghijklmnopqrstuvwxyz";
int n = 26 ;

void add(char *s){
    int ac = 0;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        int v = next[ac][s[i]-'a'];
        if( v == 0 ) term[node] = 0 , next[ac][s[i]-'a'] = node++;
        ac = next[ac][s[i]-'a'];
    }
    term[ac] = 1;
}
void aho(){
    queue<int> Q;
    for(int i = 0 ; i < n ; i++){
        int v = next[0][ can[i] - 'a' ];
        if( v ) T[v] = 0 , Q.push( v );
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < n ; i++){
            int v = next[u][can[i] - 'a' ] , x = next[T[u]][can[i] - 'a'];
            if( v == 0 ) next[u][can[i] - 'a'] = x;
            else Q.push( v ) , T[v] = x , term[v] |= term[x];
        }
    }
}
/*
int memo[10005][N];
int dp( int pos , int nodo )
{
	if( pos == ns )return (term[nodo]?INF:0);
	int &dev = memo[ pos ][ nodo ];
	if( dev == -1 )
	{
		dev = 1 + dp( pos +  1 , nodo );
		if( !term[next[nodo][s[pos]-'a']] )
			dev = min( dev , dp( pos + 1 , next[nodo][s[pos]-'a'] ) );
	}
	return dev;
}
*/
int DP[2][N];

int main()
{
	int tc;
	sc( tc );
	while( tc -- )
	{
		scanf( "%s%s" , S1 , S2 );
		ns = strlen( S1 ) , nt = strlen( S2 );
		node = 1;
		clr( next , 0 );
		clr( term , 0 );
		add( S2 );
		aho();
		//clr( memo , -1 );
		for( int nodo = 0 ; nodo < node ; ++nodo )
			DP[ns&1][nodo] = (term[nodo]?INF:0);
		for( int pos = ns - 1 ; pos >= 0 ; pos -- )
			for( int nodo = node - 1 ; nodo >= 0 ; --nodo )
			{
				int &dev = DP[ pos&1 ][ nodo ] = 1 + DP[ (pos +  1)&1 ][ nodo ];
				if( !term[next[nodo][S1[pos]-'a']] )
					dev = min( dev , DP[ (pos + 1)&1 ][ next[nodo][ S1[pos] - 'a' ] ] );
			}
		printf( "%d\n" , DP[0][0] );
	}
}
