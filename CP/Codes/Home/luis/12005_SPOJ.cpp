#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005

int qq[N];

struct stripe {
	vi lazy;
	vi v;
	int len;
	stripe() {}
	stripe(vector<int> &a) : len(a.size()) {
		int off = 1;
		for (; off < len; off<<=1);
		v = vector<int>(off*2);
		lazy = vi(off*2,0);
		make(a, 0, 0, len);
	}
	void relax(int x, int le, int ri) {
		if (lazy[x]!=0) {
			v[x] += lazy[x]*(ri-le);
			int L = x + x + 1, R = L + 1, me = (le + ri)/2;
			if (le+1 < ri) {
				lazy[L] += lazy[x];
				lazy[R] += lazy[x];
			}
			lazy[x] = 0;
		}
	}

	void make(vector<int> &a, int x, int le, int ri) {
		if (le + 1 == ri) v[x] = a[le];
		else {
			int L = x + x + 1, R = L + 1, me = (le + ri)/2;
			make(a, L, le, me); make(a, R, me, ri);
			v[x] = v[L] + v[R];
		}
	}
	void update(int a, int b, int w) { update(a,b,w,0,0,len); }
	void update(int a, int b, int w, int x, int le, int ri) {
		relax(x, le, ri);
		if (b <= le || ri <= a) return;
		if (a <= le && ri <= b) {
			lazy[x] = w;
			relax(x, le, ri);
			return;
		}
		int L = x + x + 1, R = L + 1, me = (le + ri)/2;
		update(a,b,w, L, le, me);
		update(a,b,w, R, me, ri);
		v[x] = v[L] + v[R];
	}
	int get2(int a, int b) { return get2(a,b,0,0,len); }
	int get2(int a, int b, int x, int le, int ri) {
		relax(x, le, ri);
		if (b <= le || ri <= a) return 0;
		if (a <= le && ri <= b) return v[x];
		int L = x + x + 1, R = L + 1, me = (le + ri)/2;
		return get2(a,b,L,le,me) + get2(a,b,R,me,ri);
	}

} st[N];

int chain[N], tam[N], h[N], p[N];

int n,q; 
int peso[N], tot[N];
int csz, cola[N];
vi E[N];
/*
void getnodos(int u, int v) {
	while(chain[u] != chain[v]) {
		if (h[chain[u]] < h[chain[v]]) swap(u,v);
		int c = chain[u], len = st[c].len;
		st[c].get(h[c]+len-1-h[u], len);
		u = p[chain[u]];
	}
	if (u == v) {
		buff[bs++] = peso[u];
		return;
	}
	if (h[u] < h[v]) swap(u,v);
	int c = chain[u], len = st[c].len;
	st[c].get(h[c]+len-1-h[u], h[c]+len-h[v]);
}
*/
void updatenodos(int u, int v, int w) {
	while(chain[u] != chain[v]) {
		if (h[chain[u]] < h[chain[v]]) swap(u,v);
		int c = chain[u], len = st[c].len;
		st[c].update(h[c]+len-1-h[u], len, w);
		u = p[chain[u]];
	}
	if (h[u] < h[v]) swap(u,v);
	int c = chain[u], len = st[c].len;
	st[c].update(h[c]+len-1-h[u], h[c]+len-h[v], w);
}
int query( int u , int v ) {
	int ans = 0;
	while(chain[u] != chain[v]) {
		if( h[ chain[ u ] ] < h[ chain[ v ] ] ) swap( u , v );
		int c = chain[ u ] , len = st[ c ].len;
		ans += st[c].get2( h[ c ] + len - 1 - h[ u ] , len );
		u = p[chain[u]];
	}
	if (h[u] < h[v]) swap(u,v);
	int c = chain[u], len = st[c].len;
	ans += st[ c ].get2( h[ c ] + len - 1 - h[ u ] , h[ c ] + len - h[ v ] );
	return ans;
}

int main(){
	sc( n ) , sc( q );
	REP( i , n ) sc( peso[ i ] );
	REP( i , n - 1 ) {
		int u,v; scanf("%d%d", &u, &v); u--; v--;
		E[u].pb(v);
		E[v].pb(u);
	}
	clr(p, -1);
	csz = 0;
	cola[csz++] = 0;
	p[0] = 0;
	h[0] = 0;
	REP( i , csz ) {
		int u = cola[i];
		FOR(e, E[u]) {
			int v = *e;
			if (~p[v]) continue;
			cola[csz++] = v;
			p[v] = u;
			h[v] = h[u] + 1;
		}
	}
	for(int i = csz-1; i >= 0 ; i--){
		int u = cola[i];
		tam[u] = 1;
		tot[u] = peso[u];
		FOR(e, E[u]) {
			int v = *e;
			if (p[u] == v) continue;
			tam[u] += tam[v];
			tot[u] += tot[v];
		}
	}
	clr(chain, -1);
	REP( i , csz ) {
		int u = cola[i];
		if (~chain[u]) continue;
		chain[u] = u;
		int v = u;
		while(1) { 
			int next = -1;
			FOR(v, E[u]) if (p[*v] == u)
				if (next==-1 || tam[next] < tam[*v]) next = *v;
			if (next == -1) break;
			chain[next] = chain[u];
			u = next;
		}
		int len = h[u]-h[v]+1;
		vector<int> a(len);
		REP( i , len ) {
			a[i] = tot[u];
			u = p[u];
		}
		st[v] = stripe(a);
	}
	while( q-- ) {
		char op; scanf(" %c", &op);
		int u,w;
		scanf("%d%d", &u, &w); u-- , w--;
		int res = query( u , w );
			printf("%d\n", res );
	}
}

