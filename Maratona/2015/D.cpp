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
typedef long double ld;
typedef vector< ld > vld;
typedef vector< vld > vvld;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

//typedef tipo ld;
typedef long double tipo;
typedef vector<tipo> Vec;
typedef vector<Vec> Mat;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

typedef vector<tipo> Vec;
typedef vector<Vec> Mat;
#define eps 1e-10
#define feq(a, b) (fabs(a-b)<eps)
bool resolver_ev(Mat a, Vec y, Vec &x, Mat &ev){
	int n = a.size(), m = n?a[0].size():0, rw = min(n, m);
	vector<int> p; forn(i,m) p.push_back(i);
	forn(i, rw){
		int uc=i, uf=i;
		// aca pivotea. lo unico importante es que a[i][i] sea no nulo
		forsn(f, i, n) forsn(c, i, m) if(fabs(a[f][c])>fabs(a[uf][uc])) {uf=f;uc=c;}
		if (feq(a[uf][uc], 0)) { rw = i; break; }
		forn(j, n) swap(a[j][i], a[j][uc]);

		swap(a[i], a[uf]); swap(y[i], y[uf]); swap(p[i], p[uc]);
		// fin pivoteo
		tipo inv = 1 / a[i][i]; //aca divide
		forsn(j, i+1, n) {
			tipo v = a[j][i] * inv;
			forsn(k, i, m) a[j][k]-=v * a[i][k];
			y[j] -= v*y[i];
		}
	} // rw = rango(a), aca la matriz esta triangulada
	forsn(i, rw, n) if (!feq(y[i],0)) return false; // checkeo de compatibilidad
	x = vector<tipo>(m, 0);
	dforn(i, rw){
		tipo s = y[i];
		forsn(j, i+1, rw) s -= a[i][j]*x[p[j]];
		x[p[i]] = s / a[i][i]; //aca divide
	}
	ev = Mat(m-rw, Vec(m, 0)); // Esta parte va SOLO si se necesita el ev
	forn(k, m-rw) {
		ev[k][p[k+rw]] = 1;
		dforn(i, rw){
			tipo s = -a[i][k+rw];
			forsn(j, i+1, rw) s -= a[i][j]*ev[k][p[j]];
			ev[k][p[i]] = s / a[i][i]; //aca divide
		}
	}
	return true;
}
bool diagonalizar(Mat &a){
	// PRE: a.cols > a.filas
	// PRE: las primeras (a.filas) columnas de a son l.i.
	int n = a.size(), m = a[0].size();
	forn(i, n){
		int uf = i;
		forsn(k, i, n) if (fabs(a[k][i]) > fabs(a[uf][i])) uf = k;
		if (feq(a[uf][i], 0)) return false;
		swap(a[i], a[uf]);
		tipo inv = 1 / a[i][i]; // aca divide
		forn(j, n) if (j != i) {
			tipo v = a[j][i] * inv;
			forsn(k, i, m) a[j][k] -= v * a[i][k];
		}
		forsn(k, i, m) a[i][k] *= inv;
	}
	return true;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int R , C;
	while( cin >> R >> C ){
		vi rows( R ) , columns( C );
		vvi T( R , vi( C ) );
		map< string , int > mapa;
		vector< string > inv;
		int it = 0;
		REP( i , R ){
			REP( j , C ){
				string s;
				cin >> s;
				if( !mapa.count( s ) ){
					mapa[ s ] = it;
					inv.pb( s );
					it ++;
				}
				T[ i ][ j ] = mapa[ s ];
			}
			cin >> rows[ i ];
		}
		REP( j , C ) cin >> columns[ j ];
		int n = SZ( mapa );
		vvi EQ;
		REP( i , R ){
			vi eq( n );
			REP( j , C ) eq[ T[ i ][ j ] ]++;
			eq.pb( rows[ i ] );
			EQ.pb( eq );
		}
		REP( j , C ){
			vi eq( n );
			REP( i , R ) eq[ T[ i ][ j ] ]++;
			eq.pb( columns[ j ] );
			EQ.pb( eq );
		}
		Mat A ;
		Vec y;
		for( auto v : EQ ){
			y.pb( v.back() );
			v.pop_back();
			Vec eq;
			for( auto x : v ) eq.pb( x );
			A.pb( eq );
		}
		Vec x;
		bool ok = resolver_ev( A , y , x );
		assert( ok );
		vector< pair< string , int > > solu;
		REP( i , SZ( x ) ) solu.pb( mp( inv[ i ] , round( x[ i ] ) ) );
		sort( all( solu ) );
		for( auto k : solu ) cout << k.fi << " " << k.se << '\n';
	}
}


