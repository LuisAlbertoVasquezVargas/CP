#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <queue>
#define f(i,x,y) for(int i=x;i<y;i++)
#define fd(i,y,x) for(int i=y;i>=x;i--)
#define FOR(it,A) for( typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define impr(A) for( typeof A.begin() chen = A.begin(); chen !=A.end(); chen++ ) cout<<*chen<<" "; cout<<endl
#define ll long long
#define vint vector<int>
#define clr(A,x) memset(A,x,sizeof(A))
#define CLR(v) f(i,0,n) v[i].clear()
#define oo (1<<30)
#define ones(x) __builtin_popcount(x)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define eps (1e-9)
#define cua(x) (x)*(x)
#define MAX 30005
#define L(x) 2*x+1
#define R(x) 2*x+2
#define pii pair<int,int>
#define fst first
#define snd second
using namespace std;

struct node{
   int on, area;
   node (int x = 0, int y = 0) : on(x), area(y){}
};
int tam;
struct segmentTree{
   node *seg;
   int off;
   segmentTree(int x){
		off = 1;
		while (off<x) off*=2;
		seg = new node[off*2];
   };
   int area(){ return seg[0].area;}
   void add (int a, int b, int x = 0, int le = 0, int ri = tam){
   	if (b<=le || ri<=a) return;
      if (a<=le && ri<=b){ seg[x].on++; seg[x].area = ri - le; return; }
      int me = (le + ri) / 2;
      add (a, b, L(x), le, me);
      add (a, b, R(x), me, ri);
      if(seg[x].on==0) seg[x].area = seg[L(x)].area + seg[R(x)].area;
   }
   void take (int a, int b, int x = 0, int le = 0, int ri = tam){
      if (b<=le || ri<=a) return;
      if (a<=le && ri<=b){
         seg[x].on--;
         if (seg[x].on==0) seg[x].area = x<off? seg[L(x)].area + seg[R(x)].area : 0;
         return;
      }
      int me = (le + ri) / 2;
      take (a, b, L(x), le, me);
      take (a, b, R(x), me, ri);
      if(seg[x].on==0) seg[x].area = seg[L(x)].area + seg[R(x)].area;
   }
};
vector<pii> abre[MAX], cierra[MAX];
int main()
{
    int n;
    cin >> n;
    int a1,b1,a2,b2;
    f(i,0,n){
        scanf ("%d%d%d%d", &a1, &b1, &a2, &b2);
        abre[a1].pb (pii(b1,b2));
        cierra[a2].pb (pii(b1,b2));
    }
    segmentTree st(MAX);
    tam = st.off; 
    int res = 0;
    f(i,0,MAX){
        f(j,0,abre[i].size()) st.add (abre[i][j].fst, abre[i][j].snd);
        f(j,0,cierra[i].size()) st.take (cierra[i][j].fst, cierra[i][j].snd);
        res += st.area();
    }
    cout << res << endl;
    return 0;
}
