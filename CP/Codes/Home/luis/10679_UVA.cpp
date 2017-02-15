#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXNODES 1005*1005
#define ALPH_SIZE 256
using namespace std;
 
int nodes, trie[MAXNODES][ALPH_SIZE];
char s[100001];
char p[1001];  
void init()
{
    nodes = 1;
    memset(trie, -1, sizeof(trie));
}
  
inline int enc(char ch)
{
    if(ch == '-') return 26;
    else return ch - 'A';
}
  
void insert(char s[])
{
    int p = 0;
    int n = strlen(s);
    for(int i=0; i<n; i++)
    {
        if(trie[p][enc(s[i])] == -1) trie[p][enc(s[i])] = nodes++;
        p = trie[p][enc(s[i])];
    }
}
  
bool find(char s[])
{
    int p = 0;
    int n = strlen(s);
    for(int i=0; i<n; i++)
    {
        if(trie[p][enc(s[i])] == -1) return 0;
        p = trie[p][enc(s[i])];
    }
    return 1;
}
 
int main()
{
    int n,k;
    scanf("%d",&n);
    gets(s);
    for( int i = 0 ; i < n ; ++i )
    {
        init();
        gets(s);
        insert(s);
        scanf("%d",&k);
        gets(p);
        bool ok = 1;
        for( int j = 0 ; j < k ; ++j )
        {
            gets(p);
            cout<<j<<" "<<p<<endl;
            if(find(p))
                puts("y");
            else puts("n");
        }
    }    
    
} 
 
