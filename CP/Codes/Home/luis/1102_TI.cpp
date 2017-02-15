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

#define N 10000005
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

using namespace std;

int sz;
int PP[N];
int F(int x) {return x == PP[x] ? x : (PP[x] = F(PP[x]));}
void U(int x, int y) {PP[F(x)] = F(y);}

void init()
{
	for( int i = 0 ; i < sz ; ++i )
		PP[i] = i ;	
}
int* getPre(char* s){
	int n=strlen(s);
	int* p=new int[n+1];
	p[1]=0;
	int w=0;
	for(int i=2;i<=n;++i){
		while(w&&s[w]!=s[i-1])w=p[w];
		if(s[w]==s[i-1])w++;
		p[i]=w;
	}
	return p;
}
void match(char* S,char *s,int* p){
	int m=strlen(S);
	int n=strlen(s);
	int w=0;
	for(int i=0;i<m;++i){
		while(w&&s[w]!=S[i])w=p[w];
		if(s[w]==S[i])w++;
		if(w==n){
			//cout << i+1 << " " << i-w+1 << endl;
			if( F(i+1) != F(i-w+1) )
				U( i + 1 , i - w + 1 ); //cout << i+1 << " * " << i-w+1 << endl;
			w=p[w];
		}
	}
}
char cad[N];
char t[6][10] = { "puton" , "out" , "output", "in" , "input" , "one" };
void doit()
{
	scanf( "%s" , cad );
	int* p = getPre( cad );
	sz = 1 + strlen( cad );
	init();
	for( int k = 0 ; k < 6 ; ++k )
		match( cad , t[k] , p );
	if( F(0) == F(sz - 1) )
		puts("YES");
	else	puts("NO");
}
int main()
{
	int m;
	sc( m );
	while( m-- )
		doit();
}
