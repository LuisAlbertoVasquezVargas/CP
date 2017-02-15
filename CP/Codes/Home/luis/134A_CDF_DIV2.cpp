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
#define MAXN 300

using namespace std;

int n,k;
int a[MAXN];
int b[MAXN];
int main()
{
     while( cin >> n >> k )
     {
          for( int i = 0 ; i < 2*n + 1 ; ++i )
               cin >> a[i];          
          for( int i = 1 ; i < 2*n + 1 && k ; i+=2 )
          {
               if(a[i-1]<a[i]-1&&a[i]-1>a[i+1])
                    k--,a[i]--;     
          }
          for( int i = 0 ; i < 2*n + 1 ; ++i )          
               cout<<a[i]<<" ";
          cout<<endl;
     }
}
