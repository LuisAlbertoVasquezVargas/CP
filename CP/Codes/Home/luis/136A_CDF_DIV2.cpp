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
#define MAXN 1001

using namespace std;

int n;
int a[MAXN];
void f(int i)
{
     if(i == 1)return;
     f(i-1);     
     swap(a[i-1],a[i]);
}
int main()
{
     while( cin >> n )
     {
          a[1] = n;
          for( int i = 2 ; i <= n ; ++i )
               a[i] = i - 1 ;
//          f(n); 
          for( int i = 1 ; i <= n ; ++i )
               cout<<a[i]<<" ";
          cout<<endl;
     }
}
