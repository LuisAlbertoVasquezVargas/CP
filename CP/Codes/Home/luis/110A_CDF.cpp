#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int c(string s){
     int cont=0;
     
     for(int i = 0 ; i < s.size() ;++i)
          if(s[i]=='7'||s[i]=='4')
               cont++;
               
     return cont;
}
bool f(string s){
     bool ok=true;
     
     for(int i = 0 ; i < s.size() ;++i)
          if(s[i]!='7'&&s[i]!='4')
               ok=false;
               
     return ok;
}
string atoi(int x){

     ostringstream out;
     out<<x;
     return out.str();
     
}
int toi(string s){
     
     int x;
     istringstream in(s);
     in>>x;
     return x;                
}
int main(){
     
     string s;
     cin>>s;
     
     if(f(atoi(c(s))))
          cout<<"YES";
     else 
          cout<<"NO";          
     
     
}
