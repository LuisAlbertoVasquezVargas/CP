///AJI gauss
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
