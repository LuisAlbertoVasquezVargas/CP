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

int main(){

     while(1)
     {
          int x;
          cin>>x;
          if(x==0) break;
          int k = (x-1940)/10;     

          double s=0;
          double t=log(2)*(pow(2.0,k));
          int i=0;

          while(s<t){
               s+=log(++i);     
          }          
          cout<<i-1<<endl;
     }
       
          
}
//By Luchin "BOXER"
