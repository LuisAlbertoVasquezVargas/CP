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
#define MAXN 100001

using namespace std;

int n;
int a[MAXN],b[MAXN];
int main()
{
     while( cin >> n )
     {
          for( int i = 1 ; i <= n ; ++i )
               cin >> a[i];    
          for( int i = 1 ; i <= n ; ++i )
               b[i] = a[i];
          sort(b+1,b+n+1);               
          int cont = 0;
          for( int i  = 1 ; i <= n ; ++i )
               if(a[i]!=b[i])
                    cont++;
          if( cont == 0 || cont == 2 )
               cout<<"YES\n";
          else cout<<"NO\n";      
     }
}
