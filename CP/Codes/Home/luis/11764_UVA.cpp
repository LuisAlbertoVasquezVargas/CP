#include<iostream>

using namespace std;
int a[50];

int main()
{
     int t,it=0;
     cin>>t;
     
     for(int  i = 0 ;i < t ; ++i)
     {
          int n;
          cin>>n;     
          for(int j = 0 ; j < n ; ++j)
               cin>>a[j];
          
          int pos = 0, neg = 0;                         
          for(int j = 1 ; j < n ; ++j)
               if(a[j]>a[j-1])     pos++;
               else if (a[j]<a[j-1])    neg++;
          
          cout<<"Case "<<++it<<": "<<pos<<" "<<neg<<endl;          
     }     
     
     
}
