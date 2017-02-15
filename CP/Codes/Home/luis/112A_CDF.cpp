#include<iostream>
#include<string>
using namespace std;
string f(string s){

     for( int i = 0 ; i < s.size() ; ++i)
          s[i]=toupper(s[i]);     
     return s;
}
int main(){
     
     string s,t;
     
     cin>>s>>t;
     
     s=f(s);
     t=f(t);
     
     int n=s.size();
     int cont=0;
     
     if(s>t)
          cout<<"1";
     if(s<t)
          cout<<"-1";
     if(s==t)
          cout<<"0";                         
     
}
