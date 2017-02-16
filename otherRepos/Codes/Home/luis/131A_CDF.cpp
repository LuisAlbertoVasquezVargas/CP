#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(){
     
     string s;
     cin>>s;
     
     bool ok=true;
     
     for(int i = 1 ;i < s.size() ; ++i){
          
          if(s[i]!=toupper(s[i])){
               
               ok=false;
               break;
          }
     }     
     
     if(ok&&s[0]!=toupper(s[0])){
     
          cout<<(char)toupper(s[0]);
          
          for(int i = 1 ; i < s.size() ; ++i)
               cout<<(char)tolower(s[i]);    
               
          return 0;                     
     }
     
     if(ok&&s[0]==toupper(s[0])){
          
          for(int i = 0 ; i < s.size() ; ++i)
               cout<<(char)tolower(s[i]);    
          
          return 0;          
     }

     for(int i = 0 ; i < s.size() ; ++i)
          cout<<s[i];
     
}
