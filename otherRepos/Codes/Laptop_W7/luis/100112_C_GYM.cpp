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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
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
#define N 600005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;
int toi(string s){istringstream is(s);int x;is>>x;return x;}
string s;

typedef struct node * pnode;

struct node{
	ll x, y, cnt;
	pnode L, R;
	node() {}
	node(int x, int y): x(x), y(y), cnt(1), L(NULL), R(NULL) {}
};

pnode T;

inline ll cnt(pnode &it){
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

pnode query(pnode t, int i, int j)
{
    int cntL = cnt(t->L);
   
    if(j < cntL) return query(t->L, i, j);
    if(cntL + 1 <= i) return query(t->R, i-cntL-1, j-cntL-1);
    else
    {
        if(j - i + 1 == cnt(t)) return t;
       
        pnode L = (i < cntL ? query(t->L, i, cntL-1) : NULL);
        pnode R = (cntL + 1 <= j ? query(t->R, 0, j-cntL-1) : NULL);
        pnode ans = new node(t->x, 0);
        ans->L = L;
        ans->R = R;
        upd_cnt(ans);
        return ans;
    }
}
int main()
{
	sync;
	int n = 0;
	insert( T , INF , 0 );
	while( cin >> s )
	{
		if( s[0] == '#' )
		{
			int temp;
			if( n%2 == 0 )
			{
				temp = query( T , n/2+1 , n/2 + 1 )->x;
				erase( T , n/2 + 1 );
			}
			else 
			{
				temp = query( T , ( n + 1 )/2 , ( n + 1 )/2 )->x;
				erase( T , ( n + 1 )/2 );
			}
			n--;
			cout << temp << endl;
		}
		else
		{
			int num = toi( s );
			insert( T , num , ++n );
		}
	}
}
