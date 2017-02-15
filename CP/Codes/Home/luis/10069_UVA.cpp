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

#define N 10005
#define M 1005

using namespace std;

int n , m;
char s[N] , t[M];
string memo[N][M];

string suma(const string &a, const string &b)  
{  
    int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0; 
      
    string x = string(L, '0');  
      
    while(L--) 
    { 
        LA--; LB--; 
          
        if(LA >= 0) carry += a[LA] - '0';  
        if(LB >= 0) carry += b[LB] - '0';  
          
        if(carry < 10) x[L] = '0' + carry, carry = 0; 
        else x[L] = '0' + carry - 10, carry = 1; 
    } 
      
    if(carry) x = '1' + x;  
    return x; 
}  
  
string dp( int i , int j )
{
	if( j == m )return "1";
	if( i == n )return "0";
	string &dev = memo[ i ][ j ];
	if( dev == "-1" )
	{
		dev = "0";
		if( s[i] == t[j] )
			dev = suma( dp( i + 1 , j ) , dp( i + 1 , j + 1 ) );
		else	dev = suma( dp( i + 1 , j ) , dev );
	}
	return dev ;	
}
int main()
{
	int tc;
	scanf( "%d" , &tc );
	while( tc-- )
	{
		scanf( "%s%s" , s ,t );
		n = strlen( s ) , m = strlen( t );
		for( int i = 0 ; i <= n ; ++i )
			for( int j = 0 ; j <= m ; ++j )
				memo[i][j] = "-1";
		cout << dp( 0 , 0 ) << endl;
	}
}
