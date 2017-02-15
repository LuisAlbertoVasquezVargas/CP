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
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-8)

using namespace std;

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
  
int main()
{
	vector< string > v(3,"1");
	int it = 3;
	while(1)
	{
		string temp = suma(v[it-1] , v[it-2] );
		if( temp.size() > 1000 )break;
		v.push_back(temp);
		it++;
	}
	int n ;
	cin >> n;
	cout << v[n] << endl;
}
