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
#define MOD 1000000007

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

using namespace std;

vector< string >S(3);
vector<string> f( vector<string> s )
{
	vector< string >temp( 3 , string(3,' ') );
	for( int i = 0 ; i < 3 ; ++i )
		for( int j = 0 ; j < 3 ; ++j )
			temp[i][j] = s[j][i];
	return temp;	
}
int main()
{
    while( cin >> S[0] )
    {
        cin >> S[1] >> S[2];
        string t = accumulate( all(S), string("") );
        int O = count( all(t) , '0') , X = count( all(t) , 'X' ) , P = count( all(t) , '.' );
		if( O == X || O == X - 1 )
		{	
			int cO = 0 , cX = 0;
			for( int i = 0 ; i < 3 ; ++i )
			{
				cO += S[i] == string(3,'0');
				cX += S[i] == string(3,'X');
			}
			cO += (S[0][0] == '0')*(S[1][1] == '0')*(S[2][2] == '0');
			cX += (S[0][0] == 'X')*(S[1][1] == 'X')*(S[2][2] == 'X');
			cO += (S[0][2] == '0')*(S[1][1] == '0')*(S[2][0] == '0');
			cX += (S[0][2] == 'X')*(S[1][1] == 'X')*(S[2][0] == 'X');
			S = f(S);
			for( int i = 0 ; i < 3 ; ++i )
			{
				cO += S[i] == string(3,'0');
				cX += S[i] == string(3,'X');
			}
			cO += (S[0][0] == '0')*(S[1][1] == '0')*(S[2][2] == '0');
			cX += (S[0][0] == 'X')*(S[1][1] == 'X')*(S[2][2] == 'X');
			cO += (S[0][2] == '0')*(S[1][1] == '0')*(S[2][0] == '0');
			cX += (S[0][2] == 'X')*(S[1][1] == 'X')*(S[2][0] == 'X');
			if( cO && cX )puts("illegal"); 
			else if( cO )puts("the second player won");
			else if( cX )puts("the first player won");
			else if( P )
			{
				if( O == X )
					puts("first");
				else	puts("second");
			}
			else puts("draw ");
		}
		else	puts("illegal");
    }
}
