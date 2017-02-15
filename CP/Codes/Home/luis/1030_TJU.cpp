#include<iostream>
#include<algorithm>
#include<sstream>
#include<cctype>
#include <assert.h>
 
using namespace std;
long long sz,nv,pequal,n,search_;
long long v[1000];
bool completed ;
string s,t,p,sol;
string parse(string s)
{
    istringstream in(s);
    p = t = "";
    while(in>>p)
        t+=p+" ";    
    int n = t.size();
    t.erase(n-1);
    n--;
    p = "";
    for( int i = 0 ; i < n ; ++i )
        if(t[i] == '(' &&t[i+1] == ' ' && i < n - 1 )
        {
            p+=t[i];
            i++;
        }else p+=t[i];
    t = p;
    p = "";
    n = t.size();
    for( int i = n - 1 ;i >= 0 ; --i )
        if(t[i] == ')' && t[i-1] == ' ' && i > 0 )
        {
            p = t[i] + p;
            i--;
        }else p = t[i] + p; 
    t = p;
    p = "";
    n = t.size();
    for( int i = 0 ; i < n ; ++i )
        if(t[i] == ')' &&(t[i+1] == '(' ||isdigit(t[i+1]))&& i < n - 1 )
        {
            p+=t[i];
            p+=" ";
        }else p+=t[i];      
    t = p;
    p = "";
    n = t.size();
    for( int i = 0 ; i < n ; ++i )
        if( t[i+1] == '(' && isdigit(t[i])&& i < n - 1 )
        {
            p+=t[i];
            p+=" ";
        }else p+=t[i];          
    return p;
}
bool isnumber(int ini,int fin)
{
    bool ok = 1;
    for( int i = ini ; i<= fin ; ++i )    
        if(!isdigit(s[i])&&s[i] != ' ')
            ok = 0;
    return ok;
}
long long value(int ini,int fin)
{
    string t = s.substr(ini,fin-ini+1);  
    istringstream in(t);
    long long x ;
    in>>x;
    return x;
}
long long calc(int ini,int fin){
//    if(ini==fin)return s[ini]-'0';
    if(isnumber(ini,fin))return value(ini,fin);
    int par=0;
    for(int i=fin;i>=ini;--i){
        if(s[i]=='(')++par;
        else if(s[i]==')')--par;
        if(par==0)
        {
            if(s[i]=='*')
                return calc(ini,i-1)*calc(i+1,fin);
            else if(s[i]=='+')
                return calc(ini,i-1)+calc(i+1,fin);
            else if(s[i]=='-')
                return calc(ini,i-1)-calc(i+1,fin);
        }
    }     
/*    par=0;
    for(int i=ini;i<=fin;++i){
        if(s[i]=='(')++par;
        else if(s[i]==')')--par;
        if(par==0)
        {
            if(s[i]=='+')
                return calc(ini,i-1)+calc(i+1,fin);
            else if(s[i]=='-')
                return calc(ini,i-1)-calc(i+1,fin);
        }
    }   */
    return calc(ini+1,fin-1);
}
string present(string s)
{
    string t;
    int n = s.size();
    for( int  i = 0 ; i < n ; ++i )
        if(s[i]!=' ')
            t+=s[i];
    return t;
}
void f( int k )
{
    if(completed)return;
    if( k == nv )
    {
//        cout<<search_<<"="<<calc(0,n-1)<<endl;            
//        cout<<search_<<"="<<s<<endl;                    
        if( search_ == calc(0,n-1) )
        {
            sol = s;
            completed = 1;
        }
        return;
    }else
    {
        s[v[sz++]] = '*';
        f(k+1);
        sz--;
        s[v[sz++]] = '-';
        f(k+1);
        sz--;        
        s[v[sz++]] = '+';
        f(k+1);
        sz--;        
    }
}
int main()
{
    int tc = 0;
    while(getline(cin,s))
    {
        if( present(s) == "0" )break;
        s = parse(s);
        pequal = s.find("=");
        sz = 0;
        nv = 0;
        completed = 0;
        search_ = calc(0,pequal-1);
        s = parse(s.substr(pequal+1));
//        cout<<search_<<"/"<<s<<endl;
        n = s.size();        
        for( int i = 0 ; i < n ; ++i )
            if( s[i] == ' ' )
                v[nv++] = i;
//        cout<<nv<<endl;
//        assert(0);
        sol ="";
        f(0);
        cout<<"Equation #"<<++tc<<":\n";
        if(sol=="")
            cout<<"Impossible\n\n";
        else cout<<search_<<"="<<present(sol)<<endl<<endl;
    }        
}
