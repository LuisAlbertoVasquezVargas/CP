#include<iostream>

using namespace std;
long long n,k;
long long  f(long long x)
{
     long long sum = x;
     long long l = k;
     while(x/l!=0)
     {
          sum += x/l;
          l*=k;
     }
     return sum;
}
int main()
{
     while( cin >> n >> k )
     {
          long long lo = 1;
          long long hi = n;
          while( hi - lo > 1)
          {
               long long med = lo + ( hi - lo )/ 2;
               if(f(med)>=n) 
                    hi = med;
               else lo = med;
          }
          cout<<hi<<endl;
     }
}
