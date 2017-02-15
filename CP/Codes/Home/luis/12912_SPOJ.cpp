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

#define N 100005
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

using namespace std;

#define MOD 1000000007
#define MAXN 10

int size = 10;

struct Matrix
{
	ll X[MAXN][MAXN];
	
	Matrix () {}
	Matrix (int k)
	{
		memset(X, 0, sizeof(X));
		
		for(int i=0; i<size; i++)
			X[i][i] = k;
	}
};

Matrix operator *(Matrix &A, Matrix &B)
{
	Matrix M;
	
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			long long tmp = 0;
			for(int k=0; k<size; k++)
				tmp += (long long)A.X[i][k] * B.X[k][j],tmp%=MOD;
			M.X[i][j] = tmp % MOD;
		}
	}
	
	return M;
}

Matrix pow(Matrix x, long long n)
{
	Matrix P(1);
	
	while(n)
	{
		if(n & 1) P = P * x;
		
		n >>= 1;
		x = x * x;
	}
	
	return P;
}
int main()
{
    int tc;
    sc( tc );
    while( tc -- )
    {
        int n , k;
        sc( n ) , sc( k );
        Matrix M ;
        me( M.X , 0  );
        for( int i = 0 ; i < size ; ++i )
            for( int j = 0 ; j < size ; ++j )
                if( abs( i - j ) >= k )
                    M.X[i][j] = 1;
        M = pow( M , n - 1 );
        ll cnt = 0 ;
        for( int i = 1 ; i < size ; ++i )
            for( int j = 0 ; j < size ; ++j )        
                cnt += M.X[i][j] , cnt %= MOD;
        cout << cnt << endl;
    }
}

