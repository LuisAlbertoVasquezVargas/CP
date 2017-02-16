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

#define N 105
#define ALF 256
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-5)

using namespace std;

int a , b , c;
char sa[ N ] , sb[ N ] , sc[ N ];
int memo[ N ][ N ][ N ];

int next[ N ][ ALF ] , node , T[ N ] , term[ N ];
 
void add( char *s ){
    int ac = 0;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        int v = next[ac][s[i]];
        if( v == 0 ) term[node] = 0 , next[ac][s[i]] = node++;
        ac = next[ac][s[i]];
    }
    term[ac] = 1;
}
 
void aho(){
    queue<int> Q;
    for(int i = 0 ; 'A' + i <= 'Z' ; i++){
        int v = next[0][ 'A' + i ];
        if( v ) T[v] = 0 , Q.push( v );
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; 'A' + i <= 'Z' ; i++){
            int v = next[u][ 'A' + i ] , x = next[T[u]][ 'A' + i ];
            if( v == 0 ) next[u][ 'A' + i ] = x;
            else Q.push( v ) , T[v] = x , term[v] |= term[x];
        }
    }
}

int dp( int pos1 , int pos2 , int nodo ){
	if( pos1 == a || pos2 == b ) return 0;
	int &dev = memo[ pos1 ][ pos2 ][ nodo ];
	if( dev == -1 ){
		dev = max( dp( pos1 , pos2 + 1 , nodo ) , dp( pos1 + 1 , pos2 , nodo ) );
		if( sa[ pos1 ] == sb[ pos2 ] ){
			if( !term[ next[ nodo ][ sa[ pos1 ] ] ] )
				dev = max( dev , 1 + dp( pos1 + 1 , pos2 + 1 , next[ nodo ][ sa[ pos1 ] ] ) );
		}
	}
	return dev;
}
string f( int pos1 , int pos2 , int nodo ){
	if( pos1 == a || pos2 == b ) return "";
	int dev = dp( pos1 , pos2 , nodo );

	if( dev == dp( pos1 , pos2 + 1 , nodo ) ) return f( pos1 , pos2 + 1 , nodo );
	if( dev == dp( pos1 + 1 , pos2 , nodo ) ) return f( pos1 + 1 , pos2 , nodo );
	if( sa[ pos1 ] == sb[ pos2 ] ){
		if( !term[ next[ nodo ][ sa[ pos1 ] ] ] )
			if( dev == 1 + dp( pos1 + 1 , pos2 + 1 , next[ nodo ][ sa[ pos1 ] ] ) )
				return string( 1 , sa[ pos1 ] ) + f( pos1 + 1 , pos2 + 1 , next[ nodo ][ sa[ pos1 ] ] );
	}
	return ".";
}
int main()
{
	while( scanf( "%s%s%s" , sa , sb , sc ) == 3 ){
		clr( memo , -1 );
		node = 1;
        clr( next , 0 );
        clr( term , 0 );
		a = strlen( sa );
		b = strlen( sb );
		c = strlen( sc );
		add( sc );
		aho();
		if( !dp( 0 , 0 , 0 ) ) puts( "0" );
		else cout << f( 0 , 0 , 0 ) << '\n';
	}
}


