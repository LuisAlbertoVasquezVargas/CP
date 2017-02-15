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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

#define MAX_SIZE 10005

int A[MAX_SIZE],C[MAX_SIZE],pos1,pos2,sz;

int countInversions(int a, int b){
    if(a==b) return 0;
    
    int c = ((a+b)>>1);
    int aux = countInversions(a,c)+countInversions(c+1,b);
    pos1 = a; pos2 = c+1; sz = 0;
    
    while(pos1<=c && pos2<=b){
        if(A[pos1]<A[pos2]) C[sz] = A[pos1++];
        else{
            C[sz] = A[pos2++];
            aux += c-pos1+1;
        }
        ++sz;
    }
    
    if(pos1>c) memcpy(C+sz,A+pos2,(b-pos2+1)*sizeof(int));
    else memcpy(C+sz,A+pos1,(c-pos1+1)*sizeof(int));
    
    sz = b-a+1; 
    memcpy(A+a,C,sz*sizeof(int));
    
    return aux;
}

int main()
{
	int n , k;
	scanf( "%d%d", &n , &k );
	int maxi = -1,  ind = -1;
	REP( t , k )
	{
		REP( x , n ) sc( A[x] );
		int temp = countInversions( 0 , n - 1 );
		if( maxi < temp )
			maxi = temp , ind = t;
	}
	printf( "%d\n" , ind + 1 );
}


