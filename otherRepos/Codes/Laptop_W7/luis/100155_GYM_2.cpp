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

#define N 1000005

typedef struct node * pnode;

struct node{
	int y, cnt;
	char x;
	pnode L, R;
	node() {}
	node(char X, int Y){
	    x = X, y = Y, cnt = 1;
	    L = NULL , R = NULL;
    }
};

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
	if (!L) t = R;
	else if(!R) t = L;
	else if (L->y > R->y)
		merge (L->R, L->R, R), t = L;
	else
		merge (R->L, L, R->L), t = R;
	upd_cnt(t);
}

// Insert into implicit Treap
void insert(pnode &t, char value, int pos){
	pnode t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(value, rand()));
	merge(t, t1, t2);
}

char s[N];
pnode T;

pnode get()
{
	pnode t = new node( s[ 0 ] , rand() );
	int n = strlen( s );
	REP( i , n )
		if( i ) merge( t , t , new node( s[ i ] , rand() ) );
    return t;
}

void print(pnode t){
    if( t ){
        print( t->L );
        printf("%c",t->x);
        print( t->R );
    }
}

int main()
{
    int tc = 1;
    //sc(tc);
    while( tc-- )
	{
        scanf( "%s" , s );
        T = get();
        char op[5];
        int a , b , pos;
        while( scanf( "%s", op ) == 1 )
		{
            if( op[0] == 'E' ) break;
            else if( op[0] == 'I' )
			{
                scanf( "%s%d" , s , &pos );
                int n = strlen( s );
                pnode t = get();
                pnode L , R;
                split( T , L , R , pos );
                merge( T , L , t );
                merge( T , T , R );
                
            }
            else{
                sc( a ) , sc( b );
                pnode L , R;
                split( T , T , L , a );
                split( L , L , R , b - a + 1 );
                print(L);
                puts( "" );
                merge( L , L , R );
                merge( T , T , L );
            }
        }
    }
    return 0;
}

