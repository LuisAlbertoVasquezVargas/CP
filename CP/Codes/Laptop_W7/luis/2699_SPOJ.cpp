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

using namespace std;

#define MAXN 20

int mod;

struct Matrix
{
	int X[MAXN][MAXN];
	int SZ;
	Matrix () {}
	Matrix ( int sz )
	{
		SZ = sz;
		clr( X , 0 );
		for( int i = 0 ; i < SZ ; i++ )
			X[i][i] = 1;
	}
	Matrix ( vi &v , int sz )
	{
		SZ = sz;
		clr( X , 0 );
		for( int i = 0 ; i + 1 < SZ ; i++ )
			X[i+1][i] = 1;
		REP( i , SZ ) X[0][i] = v[i];
	}
	void print()
	{

		REP( i , SZ )
			REP( j , SZ )
				cout << setw(12) << X[i][j] << (j+1==SZ?"\n":" ");
	}
};
Matrix operator *(Matrix &A, Matrix &B)
{
	int sz = A.SZ;
	Matrix M( sz );
	for( int i = 0 ; i < sz ; i++ )
		for( int j = 0 ; j < sz ; j++ )
		{
			ll tmp = 0;
			for( int k = 0 ; k < sz ; k++ )
				tmp = ( tmp + ((ll)A.X[i][k] * B.X[k][j])%mod )%mod;
			M.X[i][j] = tmp;
		}
	return M;
}
Matrix pow(Matrix x, long long n)
{
	Matrix P(x.SZ);
	
	while(n)
	{
		//cout << "size:" << x.SZ << endl;
		//cout << "size:" << P.SZ << endl;
		if(n & 1) P = P * x;
		n >>= 1;
		x = x * x;
	}
	return P;
}
// k tamaño
// v vector de constantes
// M(0) matrix inicial ya insertado con constantes
// A vector de valores iniciales
// exponente

/*
int eval( Matrix &M , vi &A , ll t )
{
	int k = M.size;
	Matrix M1 = pow( M , t - k );
	int ans = 0;
	REP( i , k ) ans += (M1.X[0][i]*A[i])%mod , ans%= mod;
	return ans;
}
*/
int eval( vi &v , int k , vi &A , ll t )
{
	if( t <= k )return A[ k - t ];
	Matrix M( v , k );
	
	Matrix M1 = pow( M , t - k );

	//M1.print();
	int ans = 0;
	REP( i , k ) ans = ( ans + (M1.X[0][i]*A[i])%mod )%mod ;
	return ans;
}
int main()
{
	int tc;
	sc( tc );
	REP( t , tc )
	{
		int k;
		sc( k );
		vi v( k ), a( k );
		REP( i , k ) cin >> a[i];
		REP( i , k ) cin >> v[i];
		reverse( all( a ) );
		ll m , n;
		cin >> m >> n >> mod;
		REP( i , 12 )
			cout << i << " " << eval( v , k , a , i ) << endl;
	}
}


