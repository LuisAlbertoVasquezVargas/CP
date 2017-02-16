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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;


int shift( string s ,int n){
	int i = 0, j = 1, k = 0;
	char a,b;
	while( j<n && i+k+1<n ){
		a = s[i+k]; b = s[(j+k)%n];
		if( a==b ) k++;
		else if( a<b ) j=j+k+1, k = 0;
		else i = max(i+k+1,j), j = i+1, k = 0;
	}
	return i;
}
string f( string a , string b )
{
	reverse( all( b ) );
	string t = a + b;
	int k = shift( t , 4 );
	return t.substr( k ) + t.substr( 0 , k );
}
int main()
{
	int n;
	while( cin >> n )
	{
		string a , b , c;
		set< string >S;
		REP( i , n )
		{
			cin >> a >> b ;
			if( i != n - 1 ) cin>> c;
			//cout << f( a , b ) << endl;
			S.insert( f( a , b ) );
		}
		cout << S.size() << '\n';
	}
}


