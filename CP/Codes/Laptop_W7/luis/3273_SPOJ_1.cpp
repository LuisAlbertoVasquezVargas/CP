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

inline int cnt(treap* it){
	return it ? (it->sons + 1) : 0;
}
inline void rotate_to_right(treap* &t){
    treap* n = t->left;
    t->left = n->right;
    n->right = t;
    t = n;
}
bool find (treap* t, int x) {
	if(!t) return 0;
	else if (t->value == x) return 1;
	return find (x < t->value ? t->left: t->right, x);
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
    
    fix_augment(t->left);
    fix_augment(t->right);
    fix_augment(t);
}

inline long long get_priority(treap* t){
    return t ? t->priority : -1;
}

void erase(treap* &t, treap_type val){
    if(!t) return;

    if(t->value != val) erase(val < t->value ? t->left : t->right, val);
    else{
        if(!t->left && !t->right){
            delete t;
            t = NULL;
        }else{
            if(get_priority(t->left) < get_priority(t->right))
                rotate_to_left(t);
            else
                rotate_to_right(t);
            
            erase(t, val);
        }
    }
    
    if(t){
        fix_augment(t->left);
        fix_augment(t->right);
        fix_augment(t);
    }
}

int Count(treap* T, int bound)
{
    if(T == NULL)
        return 0;

    if(T->value < bound)
        return 1 + cnt( T->left ) + Count(T->right, bound);

    return Count(T->left, bound);
}
    
int getKth(treap* &t, int K){
    int left = (t->left == NULL? 0 : 1 + t->left->sons);
    int right = (t->right == NULL? 0 : 1 + t->right->sons);
    
    if(1+left == K) return t->value;
    else if(left < K) return getKth(t->right,K - 1 - left);
    return getKth(t->left,K);
}
char s[4];
int x;

int main()
{
	treap *T = new treap( INF );
	erase( T , INF );
	int Q;
	sc( Q );
	while( Q-- )
	{
		scanf( "%s", s );
		sc( x );
		if( s[0] == 'D' )
		{
			if( find( T , x ) != 0 )erase( T , x );
		}
		else if( s[0] == 'I' )
		{
			if( find( T , x ) == 0 )insert( T , x );
		}
		else if( s[0] == 'C' )
			printf( "%d\n" , Count( T , x ) );
		else
		{
			int _tam = cnt( T );
			if( x > _tam )
				puts( "invalid" );
			else 
			{
				int val = getKth( T , x );
				printf( "%d\n" , val );
			}
		}
	}
}


