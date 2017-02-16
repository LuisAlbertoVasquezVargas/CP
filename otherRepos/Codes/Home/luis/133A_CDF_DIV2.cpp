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

using namespace std;

int main()
{    
     int a , b, c;
     while( cin >> a >> b >> c )          
     {
          cout<<a*(b-1)+a*c+(b-1)*(c-1)<<endl;
     }
}
