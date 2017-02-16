#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
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


typedef int treap_type;

class treap{
    public:
    
    treap_type value;
    long long priority;
    treap *left, *right;
    int sons;
    
    treap(treap_type value) : left(NULL), right(NULL), value(value), sons(0){
        priority = rand();
    }
    
    ~treap(){
        if(left) delete left;
        if(right) delete right;
    }
};

inline void rotate_to_right(treap* &t){
    treap* n = t->left;
    t->left = n->right;
    n->right = t;
    t = n;
}

inline void rotate_to_left(treap* &t){
    treap* n = t->right;
    t->right = n->left;
    n->left = t;
    t = n;
}

void fix_augment(treap* t){
    if(!t) return;
    t->sons = (t->left ? t->left->sons + 1 : 0) +
        (t->right ? t->right->sons + 1 : 0);
}

void insert(treap* &t, treap_type val){
    if(!t) t = new treap(val);
    else insert(val <= t->value ? t->left : t->right, val);
    
    if(t->left && t->left->priority > t->priority)
        rotate_to_right(t);
    else if(t->right && t->right->priority > t->priority)
        rotate_to_left(t);
    
    fix_augment(t->left); fix_augment(t->right); fix_augment(t);
}

int getKth(treap* &t, int K){
    int left = (t->left==NULL? 0 : 1+t->left->sons);
    int right = (t->right==NULL? 0 : 1+t->right->sons);
    
    if(1+left==K) return t->value;
    else if(left<K) return getKth(t->right,K-1-left);
    return getKth(t->left,K);
}

int main()
{
	int m , n;
	sc( m ) , sc( n );
	int V[N] , W[N];
	REP( i , m )sc( V[i] );
	REP( i , n )sc( W[i] );
	treap *T= new treap( 2000000005 );
	for( int i = 0 , j = 0 ; i < m && j < n ; ++i )
	{
		insert( T , V[i] );
		while( j < n && W[j] == i + 1 )
			printf( "%d\n" , getKth( T , ++j) );
	}
}


