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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

/*
simplex::solve(A,b,c,x)
	maximize     c' * x
	subject to   A * x' <= b'

	input:
		A -- an m x n matrix
		b -- an m-dimensional vector
		c -- an n-dimensional vector
		x -- a vector where the optimal solution will be stored

	returns:
		value of the optimal solutions,
		or INF if unbounded or infeasible (?)
 */ 

#define INF				1e+10
#define EPS				1e-10
typedef double lf;
typedef vector<lf> Row;
typedef vector<Row> Mat;
typedef vector<int> vi;
inline int sign(lf x){return (x>+EPS)-(x<-EPS);}

namespace simplex
{
	const int MAXN=4;
	const int MAXM=6;
	int n, m;
	lf A[MAXM+1][MAXN+1];
	int basis[MAXM+1],out[MAXN+1];

	void pivot(int a,int b) {
		for(int i=0;i<=m;++i)if(i!=a&&sign(A[i][b]))
		for(int j=0;j<=n;++j)if(j!=b)A[i][j]-=A[a][j]*A[i][b]/A[a][b];
		for(int j=0;j<=n;++j)if(j!=b)A[a][j]/=A[a][b];
		for(int i=0;i<=m;++i)if(i!=a)A[i][b]/=-A[a][b];
		A[a][b]=1/A[a][b];
		swap(basis[a],out[b]);
	}

	lf simplex(Row& x) {
		int i,j,ii,jj;
		for(i=0;i<=m;++i)basis[i]=-i;
		for(j=0;j<=n;++j)out[j]=j;
		while(1) {
			ii=1,jj=0;
			for(i=1;i<=m;++i)
				if(mp(A[i][n],basis[i])<mp(A[ii][n],basis[ii]))ii=i;
			if(A[ii][n]>=0)break;
			for(j=0;j<n;++j)if(A[ii][j]<A[ii][jj])jj=j;
			if(A[ii][jj]>=0)return-INF;
			pivot(ii,jj);
		}
		while(1) {
			ii=1,jj=0;
			for(j=0;j<n;++j)if(mp(A[0][j],out[j])<mp(A[0][jj],out[jj]))jj=j;
			if(A[0][jj]>=0)break;
			for(i=1;i<=m;++i)
				if (A[i][jj]>0&&(A[ii][jj]<=0
					||mp(A[i][n]/A[i][jj],basis[i])
					<mp(A[ii][n]/A[ii][jj],basis[ii]))) ii=i;
			if(A[ii][jj]<=0)return+INF;
			pivot(ii,jj);
		}
		x.resize(n);
		for(j=0;j<n;++j)x[j]=0;
		for(i=1;i<=m;++i)if(basis[i]>=0)x[basis[i]]=A[i][n];
		return A[0][n];
	}

	lf solve ( const Mat& _A, const Row& b, const Row& c, Row& x ) {
		n = c.size();
		m = b.size();
		for ( int i = 0; i < n; ++i )
			A[0][i] = -c[i];
		A[0][n] = 0;
		for ( int i = 0; i < m; ++i ) {
			for ( int j = 0; j < n; ++j )
				A[i+1][j] = _A[i][j];
			A[i+1][n]=b[i];
		}
		return simplex(x);
	}
}

int main(){

	const int m = 6;
	const int n = 4;
	
	Row b( m );
	REP( i , m ) {
		int x;
		sc( x );
		b[ i ] = x;
	}
	
	Mat A ( m, Row ( n , 0 ) );
	
	A[ 0 ][ 0 ] = A[ 0 ][ 3 ] = 1;
	A[ 1 ][ 0 ] = A[ 1 ][ 2 ] = 1;
	A[ 2 ][ 2 ] = A[ 2 ][ 3 ] = 1;
	A[ 3 ][ 1 ] = A[ 3 ][ 2 ] = 1;
	A[ 4 ][ 1 ] = A[ 4 ][ 3 ] = 1;
	A[ 5 ][ 0 ] = A[ 5 ][ 1 ] = 1;

	Row c( n , 1 ) , x;
	simplex::solve( A , b , c , x );
	REP( i , n ) printf( "%.3lf%c" , x[ i ] , (i + 1 == n) ? 10 : 32 );
	
}


