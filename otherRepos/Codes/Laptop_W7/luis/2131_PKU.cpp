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

typedef struct node * pnode;

struct node{
	int x, y, cnt;
	pnode L, R;
	node() {}
	node(int x, int y): x(x), y(y), cnt(1), L(NULL), R(NULL) {}
};

pnode T;

inline int cnt(pnode &it){
	return it ? it->cnt : 0;
}

inline void upd_cnt(pnode &it){
	if(it){
		it->cnt = cnt(it->L) + cnt(it->R) + 1;
	}
}


// Split Implicit Treap
void split(pnode t, pnode &L, pnode &R, int key){
	if (!t) L = R = NULL;
	else{
		//push(t);
		int cntL = cnt(t->L);
		if (key <= cntL)
			split (t->L, L, t->L, key), R = t;
		else
			split (t->R, t->R, R, key - cntL - 1), L = t;
		upd_cnt(t);
	}
}

// For Treap & Implicit Treap
void merge(pnode &t, pnode L, pnode R){
	//push(L);
	//push(R);
	if (!L) t = R;
	else if(!R) t = L;
	else if (L->y > R->y)
		merge (L->R, L->R, R), t = L;
	else
		merge (R->L, L, R->L), t = R;
	upd_cnt(t);
}

// Find in Treap
bool find (pnode &t, int x) {
	if(!t) return 0;
	else if (t->x == x) return 1;
	else return find (x < t->x ? t->L: t->R, x);
}

// Erase from Treap
void erase (pnode &t, int x) {
    if(t) {
	   if (t-> x == x)
		  merge (t, t->L, t->R);
	   else
		  erase (x < t->x ? t->L: t->R, x);
	    upd_cnt(t);
    }
}


// Insert into implicit Treap
void insert(pnode &t, int value, int pos){
	pnode t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(value, rand()));
	merge(t, t1, t2);
}


int main()
{
	int n , m , x;
	sc( n ) , sc( m );
	REP( i , m ) insert( T , 0 , 0 );
	REP( i , n )
	{
		sc( x );
		x--;
		pnode t1, t2;
		split( T , t1, t2, x);
		if( t1->x == 0 ) t1->x = 0;
		else merge(t1, t1, new node( i + 1 , rand()) );
		merge( T , t1 , t2);
	}
	
}


