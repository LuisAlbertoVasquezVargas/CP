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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;


//Falta agregar factorizacion con la criba
// Comentarios generales :
// p[i] para 0 < i indiva el valor del primo i-esimo 
//	Ejm : p[1] = 2 , p[2] = 3 ....
// A[i] indica que el menor factor primo de i es el primo A[i] - esimo 
//	Ejm: si 15 = 3*5 , entonces A[12] = 2 porque el menor factor primo de 12 es 3 y 3 es el 2do primo

#define MAXN 100000
int A[MAXN + 1], p[MAXN + 1], pc = 0;  
int C[MAXN + 1] , T[ MAXN + 1 ][ 6 ];
void sieve()  
{ 
    for(int i=2; i<=MAXN; i++){ 
        if(!A[i]) p[A[i] = ++pc] = i; 
        for(int j=1; j<=A[i] && i*p[j]<=MAXN; j++) 
            A[i*p[j]] = j; 
    } 
}
void doit()
{
	for( int i = 1 ; i <= MAXN ; ++i )
	{
		int ind = 0;
		for( int j = 1 ; j <= 5 ; ++j )
			if( C[i] == j )
			{
				ind = j;
				T[i][j] =  T[i-1][j] + 1;
			}
		for( int j = 1 ; j <= 5 ; ++j )
			if( j != ind )T[i][j] = T[i-1][j];
	}
}
int main()
{
	sieve();
	for( int i = 2 ; i <= MAXN ; ++i )
	{
		int k = i;
		set< int >S;
		while( k > 1 )
		{
			int P = p[A[k]];
			S.insert( P );
			k /= P;
		}
		C[i] = S.size();
	}
	doit();
	int tc , x , y , k;
	sc( tc );
	while( tc -- )
	{
		sc( x ) , sc( y ) , sc( k );
		cout << T[y][k] - T[x-1][k] << endl;
	}
}
