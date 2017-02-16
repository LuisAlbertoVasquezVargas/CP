#include<iostream>
#define EPS 1E-8
using namespace std;

int vp,vd,t,f,c,cont;
double T,cte;
int main()
{
     while( cin >> vp >> vd >> t>> f >> c )
     {
          if( vd <= vp )
          {
               cout<<0<<endl;
               continue;     
          }
          double pos = vp*t;
          cte = (1.0*vd/vp - 1.0);
          cont = 0;
          while( pos < c - EPS )
          {
               pos+=pos/cte;
               T = pos/vd + f;
               if( pos < c - EPS )cont++;
               pos+=vp*T;
          }
          cout<<cont<<endl;
     }     
}
