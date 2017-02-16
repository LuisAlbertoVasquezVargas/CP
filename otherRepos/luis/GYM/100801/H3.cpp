#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)v.size())
#define all(v) v.begin(),v.end()

vector<string> T = {"aaaaaaaaaaa","aaaaaaaaabB","aaaaaaaabBa","aaaaaaaabCB","aaaaaaabBaa","aaaaaaabBbB","aaaaaaabCBa","aaaaaaabCCB","aaaaaabBaaa","aaaaaabBabB","aaaaaabBbBa","aaaaaabBbCB","aaaaaabCBaa","aaaaaabCBbB","aaaaaabCCBa","aaaaaabCCCB","aaaaabBaaaa","aaaaabBaabB","aaaaabBabBa","aaaaabBabCB","aaaaabBbBaa","aaaaabBbBbB","aaaaabBbCBa","aaaaabBbCCB","aaaaabCBaaa","aaaaabCBabB","aaaaabCBbBa","aaaaabCBbCB","aaaaabCCBaa","aaaaabCCBbB","aaaaabCCCBa","aaaaabCCCCB","aaaabBaaaaa","aaaabBaaabB","aaaabBaabBa","aaaabBaabCB","aaaabBabBaa","aaaabBabBbB","aaaabBabCBa","aaaabBabCCB","aaaabBbBaaa","aaaabBbBabB","aaaabBbBbBa","aaaabBbBbCB","aaaabBbCBaa","aaaabBbCBbB","aaaabBbCCBa","aaaabBbCCCB","aaaabCBaaaa","aaaabCBaabB","aaaabCBabBa","aaaabCBabCB","aaaabCBbBaa","aaaabCBbBbB","aaaabCBbCBa","aaaabCBbCCB","aaaabCCBaaa","aaaabCCBabB","aaaabCCBbBa","aaaabCCBbCB","aaaabCCCBaa","aaaabCCCBbB","aaaabCCCCBa","aaaabCCCCCB","aaabBaaaaaa","aaabBaaaabB","aaabBaaabBa","aaabBaaabCB","aaabBaabBaa","aaabBaabBbB","aaabBaabCBa","aaabBaabCCB","aaabBabBaaa","aaabBabBabB","aaabBabBbBa","aaabBabBbCB","aaabBabCBaa","aaabBabCBbB","aaabBabCCBa","aaabBabCCCB","aaabBbBaaaa","aaabBbBaabB","aaabBbBabBa","aaabBbBabCB","aaabBbBbBaa","aaabBbBbBbB","aaabBbBbCBa","aaabBbBbCCB","aaabBbCBaaa","aaabBbCBabB","aaabBbCBbBa","aaabBbCBbCB","aaabBbCCBaa","aaabBbCCBbB","aaabBbCCCBa","aaabBbCCCCB","aaabCBaaaaa","aaabCBaaabB","aaabCBaabBa","aaabCBaabCB","aaabCBabBaa","aaabCBabBbB","aaabCBabCBa","aaabCBabCCB","aaabCBbBaaa","aaabCBbBabB","aaabCBbBbBa","aaabCBbBbCB","aaabCBbCBaa","aaabCBbCBbB","aaabCBbCCBa","aaabCBbCCCB","aaabCCBaaaa","aaabCCBaabB","aaabCCBabBa","aaabCCBabCB","aaabCCBbBaa","aaabCCBbBbB","aaabCCBbCBa","aaabCCBbCCB","aaabCCCBaaa","aaabCCCBabB","aaabCCCBbBa","aaabCCCBbCB","aaabCCCCBaa","aaabCCCCBbB","aaabCCCCCBa","aaabCCCCCCB","aabBaaaaaaa","aabBaaaaabB","aabBaaaabBa","aabBaaaabCB","aabBaaabBaa","aabBaaabBbB","aabBaaabCBa","aabBaaabCCB","aabBaabBaaa","aabBaabBabB","aabBaabBbBa","aabBaabBbCB","aabBaabCBaa","aabBaabCBbB","aabBaabCCBa","aabBaabCCCB","aabBabBaaaa","aabBabBaabB","aabBabBabBa","aabBabBabCB","aabBabBbBaa","aabBabBbBbB","aabBabBbCBa","aabBabBbCCB","aabBabCBaaa","aabBabCBabB","aabBabCBbBa","aabBabCBbCB","aabBabCCBaa","aabBabCCBbB","aabBabCCCBa","aabBabCCCCB","aabBbBaaaaa","aabBbBaaabB","aabBbBaabBa","aabBbBaabCB","aabBbBabBaa","aabBbBabBbB","aabBbBabCBa","aabBbBabCCB","aabBbBbBaaa","aabBbBbBabB","aabBbBbBbBa","aabBbBbBbCB","aabBbBbCBaa","aabBbBbCBbB","aabBbBbCCBa","aabBbBbCCCB","aabBbCBaaaa","aabBbCBaabB","aabBbCBabBa","aabBbCBabCB","aabBbCBbBaa","aabBbCBbBbB","aabBbCBbCBa","aabBbCBbCCB","aabBbCCBaaa","aabBbCCBabB","aabBbCCBbBa","aabBbCCBbCB","aabBbCCCBaa","aabBbCCCBbB","aabBbCCCCBa","aabBbCCCCCB","aabCBaaaaaa","aabCBaaaabB","aabCBaaabBa","aabCBaaabCB","aabCBaabBaa","aabCBaabBbB","aabCBaabCBa","aabCBaabCCB","aabCBabBaaa","aabCBabBabB","aabCBabBbBa","aabCBabBbCB","aabCBabCBaa","aabCBabCBbB","aabCBabCCBa","aabCBabCCCB","aabCBbBaaaa","aabCBbBaabB","aabCBbBabBa","aabCBbBabCB","aabCBbBbBaa","aabCBbBbBbB","aabCBbBbCBa","aabCBbBbCCB","aabCBbCBaaa","aabCBbCBabB","aabCBbCBbBa","aabCBbCBbCB","aabCBbCCBaa","aabCBbCCBbB","aabCBbCCCBa","aabCBbCCCCB","aabCCBaaaaa","aabCCBaaabB","aabCCBaabBa","aabCCBaabCB","aabCCBabBaa","aabCCBabBbB","aabCCBabCBa","aabCCBabCCB","aabCCBbBaaa","aabCCBbBabB","aabCCBbBbBa","aabCCBbBbCB","aabCCBbCBaa","aabCCBbCBbB","aabCCBbCCBa","aabCCBbCCCB","aabCCCBaaaa","aabCCCBaabB","aabCCCBabBa","aabCCCBabCB","aabCCCBbBaa","aabCCCBbBbB","aabCCCBbCBa","aabCCCBbCCB","aabCCCCBaaa","aabCCCCBabB","aabCCCCBbBa","aabCCCCBbCB","aabCCCCCBaa","aabCCCCCBbB","aabCCCCCCBa","aabCCCCCCCB","abBaaaaaaaa","abBaaaaaabB","abBaaaaabBa","abBaaaaabCB","abBaaaabBaa","abBaaaabBbB","abBaaaabCBa","abBaaaabCCB","abBaaabBaaa","abBaaabBabB","abBaaabBbBa","abBaaabBbCB","abBaaabCBaa","abBaaabCBbB","abBaaabCCBa","abBaaabCCCB","abBaabBaaaa","abBaabBaabB","abBaabBabBa","abBaabBabCB","abBaabBbBaa","abBaabBbBbB","abBaabBbCBa","abBaabBbCCB","abBaabCBaaa","abBaabCBabB","abBaabCBbBa","abBaabCBbCB","abBaabCCBaa","abBaabCCBbB","abBaabCCCBa","abBaabCCCCB","abBabBaaaaa","abBabBaaabB","abBabBaabBa","abBabBaabCB","abBabBabBaa","abBabBabBbB","abBabBabCBa","abBabBabCCB","abBabBbBaaa","abBabBbBabB","abBabBbBbBa","abBabBbBbCB","abBabBbCBaa","abBabBbCBbB","abBabBbCCBa","abBabBbCCCB","abBabCBaaaa","abBabCBaabB","abBabCBabBa","abBabCBabCB","abBabCBbBaa","abBabCBbBbB","abBabCBbCBa","abBabCBbCCB","abBabCCBaaa","abBabCCBabB","abBabCCBbBa","abBabCCBbCB","abBabCCCBaa","abBabCCCBbB","abBabCCCCBa","abBabCCCCCB","abBbBaaaaaa","abBbBaaaabB","abBbBaaabBa","abBbBaaabCB","abBbBaabBaa","abBbBaabBbB","abBbBaabCBa","abBbBaabCCB","abBbBabBaaa","abBbBabBabB","abBbBabBbBa","abBbBabBbCB","abBbBabCBaa","abBbBabCBbB","abBbBabCCBa","abBbBabCCCB","abBbBbBaaaa","abBbBbBaabB","abBbBbBabBa","abBbBbBabCB","abBbBbBbBaa","abBbBbBbBbB","abBbBbBbCBa","abBbBbBbCCB","abBbBbCBaaa","abBbBbCBabB","abBbBbCBbBa","abBbBbCBbCB","abBbBbCCBaa","abBbBbCCBbB","abBbBbCCCBa","abBbBbCCCCB","abBbCBaaaaa","abBbCBaaabB","abBbCBaabBa","abBbCBaabCB","abBbCBabBaa","abBbCBabBbB","abBbCBabCBa","abBbCBabCCB","abBbCBbBaaa","abBbCBbBabB","abBbCBbBbBa","abBbCBbBbCB","abBbCBbCBaa","abBbCBbCBbB","abBbCBbCCBa","abBbCBbCCCB","abBbCCBaaaa","abBbCCBaabB","abBbCCBabBa","abBbCCBabCB","abBbCCBbBaa","abBbCCBbBbB","abBbCCBbCBa","abBbCCBbCCB","abBbCCCBaaa","abBbCCCBabB","abBbCCCBbBa","abBbCCCBbCB","abBbCCCCBaa","abBbCCCCBbB","abBbCCCCCBa","abBbCCCCCCB","abCBaaaaaaa","abCBaaaaabB","abCBaaaabBa","abCBaaaabCB","abCBaaabBaa","abCBaaabBbB","abCBaaabCBa","abCBaaabCCB","abCBaabBaaa","abCBaabBabB","abCBaabBbBa","abCBaabBbCB","abCBaabCBaa","abCBaabCBbB","abCBaabCCBa","abCBaabCCCB","abCBabBaaaa","abCBabBaabB","abCBabBabBa","abCBabBabCB","abCBabBbBaa","abCBabBbBbB","abCBabBbCBa","abCBabBbCCB","abCBabCBaaa","abCBabCBabB","abCBabCBbBa","abCBabCBbCB","abCBabCCBaa","abCBabCCBbB","abCBabCCCBa","abCBabCCCCB","abCBbBaaaaa","abCBbBaaabB","abCBbBaabBa","abCBbBaabCB","abCBbBabBaa","abCBbBabBbB","abCBbBabCBa","abCBbBabCCB","abCBbBbBaaa","abCBbBbBabB","abCBbBbBbBa","abCBbBbBbCB","abCBbBbCBaa","abCBbBbCBbB","abCBbBbCCBa","abCBbBbCCCB","abCBbCBaaaa","abCBbCBaabB","abCBbCBabBa","abCBbCBabCB","abCBbCBbBaa","abCBbCBbBbB","abCBbCBbCBa","abCBbCBbCCB","abCBbCCBaaa","abCBbCCBabB","abCBbCCBbBa","abCBbCCBbCB","abCBbCCCBaa","abCBbCCCBbB","abCBbCCCCBa","abCBbCCCCCB","abCCBaaaaaa","abCCBaaaabB","abCCBaaabBa","abCCBaaabCB","abCCBaabBaa","abCCBaabBbB","abCCBaabCBa","abCCBaabCCB","abCCBabBaaa","abCCBabBabB","abCCBabBbBa","abCCBabBbCB","abCCBabCBaa","abCCBabCBbB","abCCBabCCBa","abCCBabCCCB","abCCBbBaaaa","abCCBbBaabB","abCCBbBabBa","abCCBbBabCB","abCCBbBbBaa","abCCBbBbBbB","abCCBbBbCBa","abCCBbBbCCB","abCCBbCBaaa","abCCBbCBabB","abCCBbCBbBa","abCCBbCBbCB","abCCBbCCBaa","abCCBbCCBbB","abCCBbCCCBa","abCCBbCCCCB","abCCCBaaaaa","abCCCBaaabB","abCCCBaabBa","abCCCBaabCB","abCCCBabBaa","abCCCBabBbB","abCCCBabCBa","abCCCBabCCB","abCCCBbBaaa","abCCCBbBabB","abCCCBbBbBa","abCCCBbBbCB","abCCCBbCBaa","abCCCBbCBbB","abCCCBbCCBa","abCCCBbCCCB","abCCCCBaaaa","abCCCCBaabB","abCCCCBabBa","abCCCCBabCB","abCCCCBbBaa","abCCCCBbBbB","abCCCCBbCBa","abCCCCBbCCB","abCCCCCBaaa","abCCCCCBabB","abCCCCCBbBa","abCCCCCBbCB","abCCCCCCBaa","abCCCCCCBbB","abCCCCCCCBa","abCCCCCCCCB","bBaaaaaaaaa","bBaaaaaaabB","bBaaaaaabBa","bBaaaaaabCB","bBaaaaabBaa","bBaaaaabBbB","bBaaaaabCBa","bBaaaaabCCB","bBaaaabBaaa","bBaaaabBabB","bBaaaabBbBa","bBaaaabBbCB","bBaaaabCBaa","bBaaaabCBbB","bBaaaabCCBa","bBaaaabCCCB","bBaaabBaaaa","bBaaabBaabB","bBaaabBabBa","bBaaabBabCB","bBaaabBbBaa","bBaaabBbBbB","bBaaabBbCBa","bBaaabBbCCB","bBaaabCBaaa","bBaaabCBabB","bBaaabCBbBa","bBaaabCBbCB","bBaaabCCBaa","bBaaabCCBbB","bBaaabCCCBa","bBaaabCCCCB","bBaabBaaaaa","bBaabBaaabB","bBaabBaabBa","bBaabBaabCB","bBaabBabBaa","bBaabBabBbB","bBaabBabCBa","bBaabBabCCB","bBaabBbBaaa","bBaabBbBabB","bBaabBbBbBa","bBaabBbBbCB","bBaabBbCBaa","bBaabBbCBbB","bBaabBbCCBa","bBaabBbCCCB","bBaabCBaaaa","bBaabCBaabB","bBaabCBabBa","bBaabCBabCB","bBaabCBbBaa","bBaabCBbBbB","bBaabCBbCBa","bBaabCBbCCB","bBaabCCBaaa","bBaabCCBabB","bBaabCCBbBa","bBaabCCBbCB","bBaabCCCBaa","bBaabCCCBbB","bBaabCCCCBa","bBaabCCCCCB","bBabBaaaaaa","bBabBaaaabB","bBabBaaabBa","bBabBaaabCB","bBabBaabBaa","bBabBaabBbB","bBabBaabCBa","bBabBaabCCB","bBabBabBaaa","bBabBabBabB","bBabBabBbBa","bBabBabBbCB","bBabBabCBaa","bBabBabCBbB","bBabBabCCBa","bBabBabCCCB","bBabBbBaaaa","bBabBbBaabB","bBabBbBabBa","bBabBbBabCB","bBabBbBbBaa","bBabBbBbBbB","bBabBbBbCBa","bBabBbBbCCB","bBabBbCBaaa","bBabBbCBabB","bBabBbCBbBa","bBabBbCBbCB","bBabBbCCBaa","bBabBbCCBbB","bBabBbCCCBa","bBabBbCCCCB","bBabCBaaaaa","bBabCBaaabB","bBabCBaabBa","bBabCBaabCB","bBabCBabBaa","bBabCBabBbB","bBabCBabCBa","bBabCBabCCB","bBabCBbBaaa","bBabCBbBabB","bBabCBbBbBa","bBabCBbBbCB","bBabCBbCBaa","bBabCBbCBbB","bBabCBbCCBa","bBabCBbCCCB","bBabCCBaaaa","bBabCCBaabB","bBabCCBabBa","bBabCCBabCB","bBabCCBbBaa","bBabCCBbBbB","bBabCCBbCBa","bBabCCBbCCB","bBabCCCBaaa","bBabCCCBabB","bBabCCCBbBa","bBabCCCBbCB","bBabCCCCBaa","bBabCCCCBbB","bBabCCCCCBa","bBabCCCCCCB","bBbBaaaaaaa","bBbBaaaaabB","bBbBaaaabBa","bBbBaaaabCB","bBbBaaabBaa","bBbBaaabBbB","bBbBaaabCBa","bBbBaaabCCB","bBbBaabBaaa","bBbBaabBabB","bBbBaabBbBa","bBbBaabBbCB","bBbBaabCBaa","bBbBaabCBbB","bBbBaabCCBa","bBbBaabCCCB","bBbBabBaaaa","bBbBabBaabB","bBbBabBabBa","bBbBabBabCB","bBbBabBbBaa","bBbBabBbBbB","bBbBabBbCBa","bBbBabBbCCB","bBbBabCBaaa","bBbBabCBabB","bBbBabCBbBa","bBbBabCBbCB","bBbBabCCBaa","bBbBabCCBbB","bBbBabCCCBa","bBbBabCCCCB","bBbBbBaaaaa","bBbBbBaaabB","bBbBbBaabBa","bBbBbBaabCB","bBbBbBabBaa","bBbBbBabBbB","bBbBbBabCBa","bBbBbBabCCB","bBbBbBbBaaa","bBbBbBbBabB","bBbBbBbBbBa","bBbBbBbBbCB","bBbBbBbCBaa","bBbBbBbCBbB","bBbBbBbCCBa","bBbBbBbCCCB","bBbBbCBaaaa","bBbBbCBaabB","bBbBbCBabBa","bBbBbCBabCB","bBbBbCBbBaa","bBbBbCBbBbB","bBbBbCBbCBa","bBbBbCBbCCB","bBbBbCCBaaa","bBbBbCCBabB","bBbBbCCBbBa","bBbBbCCBbCB","bBbBbCCCBaa","bBbBbCCCBbB","bBbBbCCCCBa","bBbBbCCCCCB","bBbCBaaaaaa","bBbCBaaaabB","bBbCBaaabBa","bBbCBaaabCB","bBbCBaabBaa","bBbCBaabBbB","bBbCBaabCBa","bBbCBaabCCB","bBbCBabBaaa","bBbCBabBabB","bBbCBabBbBa","bBbCBabBbCB","bBbCBabCBaa","bBbCBabCBbB","bBbCBabCCBa","bBbCBabCCCB","bBbCBbBaaaa","bBbCBbBaabB","bBbCBbBabBa","bBbCBbBabCB","bBbCBbBbBaa","bBbCBbBbBbB","bBbCBbBbCBa","bBbCBbBbCCB","bBbCBbCBaaa","bBbCBbCBabB","bBbCBbCBbBa","bBbCBbCBbCB","bBbCBbCCBaa","bBbCBbCCBbB","bBbCBbCCCBa","bBbCBbCCCCB","bBbCCBaaaaa","bBbCCBaaabB","bBbCCBaabBa","bBbCCBaabCB","bBbCCBabBaa","bBbCCBabBbB","bBbCCBabCBa","bBbCCBabCCB","bBbCCBbBaaa","bBbCCBbBabB","bBbCCBbBbBa","bBbCCBbBbCB","bBbCCBbCBaa","bBbCCBbCBbB","bBbCCBbCCBa","bBbCCBbCCCB","bBbCCCBaaaa","bBbCCCBaabB","bBbCCCBabBa","bBbCCCBabCB","bBbCCCBbBaa","bBbCCCBbBbB","bBbCCCBbCBa","bBbCCCBbCCB","bBbCCCCBaaa","bBbCCCCBabB","bBbCCCCBbBa","bBbCCCCBbCB","bBbCCCCCBaa","bBbCCCCCBbB","bBbCCCCCCBa","bBbCCCCCCCB","bCBaaaaaaaa","bCBaaaaaabB","bCBaaaaabBa","bCBaaaaabCB","bCBaaaabBaa","bCBaaaabBbB","bCBaaaabCBa","bCBaaaabCCB","bCBaaabBaaa","bCBaaabBabB","bCBaaabBbBa","bCBaaabBbCB","bCBaaabCBaa","bCBaaabCBbB","bCBaaabCCBa","bCBaaabCCCB","bCBaabBaaaa","bCBaabBaabB","bCBaabBabBa","bCBaabBabCB","bCBaabBbBaa","bCBaabBbBbB","bCBaabBbCBa","bCBaabBbCCB","bCBaabCBaaa","bCBaabCBabB","bCBaabCBbBa","bCBaabCBbCB","bCBaabCCBaa","bCBaabCCBbB","bCBaabCCCBa","bCBaabCCCCB","bCBabBaaaaa","bCBabBaaabB","bCBabBaabBa","bCBabBaabCB","bCBabBabBaa","bCBabBabBbB","bCBabBabCBa","bCBabBabCCB","bCBabBbBaaa","bCBabBbBabB","bCBabBbBbBa","bCBabBbBbCB","bCBabBbCBaa","bCBabBbCBbB","bCBabBbCCBa","bCBabBbCCCB","bCBabCBaaaa","bCBabCBaabB","bCBabCBabBa","bCBabCBabCB","bCBabCBbBaa","bCBabCBbBbB","bCBabCBbCBa","bCBabCBbCCB","bCBabCCBaaa","bCBabCCBabB","bCBabCCBbBa","bCBabCCBbCB","bCBabCCCBaa","bCBabCCCBbB","bCBabCCCCBa","bCBabCCCCCB","bCBbBaaaaaa","bCBbBaaaabB","bCBbBaaabBa","bCBbBaaabCB","bCBbBaabBaa","bCBbBaabBbB","bCBbBaabCBa","bCBbBaabCCB","bCBbBabBaaa","bCBbBabBabB","bCBbBabBbBa","bCBbBabBbCB","bCBbBabCBaa","bCBbBabCBbB","bCBbBabCCBa","bCBbBabCCCB","bCBbBbBaaaa","bCBbBbBaabB","bCBbBbBabBa","bCBbBbBabCB","bCBbBbBbBaa","bCBbBbBbBbB","bCBbBbBbCBa","bCBbBbBbCCB","bCBbBbCBaaa","bCBbBbCBabB","bCBbBbCBbBa","bCBbBbCBbCB","bCBbBbCCBaa","bCBbBbCCBbB","bCBbBbCCCBa","bCBbBbCCCCB","bCBbCBaaaaa","bCBbCBaaabB","bCBbCBaabBa","bCBbCBaabCB","bCBbCBabBaa","bCBbCBabBbB","bCBbCBabCBa","bCBbCBabCCB","bCBbCBbBaaa","bCBbCBbBabB","bCBbCBbBbBa","bCBbCBbBbCB","bCBbCBbCBaa","bCBbCBbCBbB","bCBbCBbCCBa","bCBbCBbCCCB","bCBbCCBaaaa","bCBbCCBaabB","bCBbCCBabBa","bCBbCCBabCB","bCBbCCBbBaa","bCBbCCBbBbB","bCBbCCBbCBa","bCBbCCBbCCB","bCBbCCCBaaa","bCBbCCCBabB","bCBbCCCBbBa","bCBbCCCBbCB","bCBbCCCCBaa","bCBbCCCCBbB","bCBbCCCCCBa","bCBbCCCCCCB","bCCBaaaaaaa","bCCBaaaaabB","bCCBaaaabBa","bCCBaaaabCB","bCCBaaabBaa","bCCBaaabBbB","bCCBaaabCBa","bCCBaaabCCB","bCCBaabBaaa","bCCBaabBabB","bCCBaabBbBa","bCCBaabBbCB","bCCBaabCBaa","bCCBaabCBbB","bCCBaabCCBa","bCCBaabCCCB","bCCBabBaaaa","bCCBabBaabB","bCCBabBabBa","bCCBabBabCB","bCCBabBbBaa","bCCBabBbBbB","bCCBabBbCBa","bCCBabBbCCB","bCCBabCBaaa","bCCBabCBabB","bCCBabCBbBa","bCCBabCBbCB","bCCBabCCBaa","bCCBabCCBbB","bCCBabCCCBa","bCCBabCCCCB","bCCBbBaaaaa","bCCBbBaaabB","bCCBbBaabBa","bCCBbBaabCB","bCCBbBabBaa","bCCBbBabBbB","bCCBbBabCBa","bCCBbBabCCB","bCCBbBbBaaa","bCCBbBbBabB","bCCBbBbBbBa","bCCBbBbBbCB","bCCBbBbCBaa","bCCBbBbCBbB","bCCBbBbCCBa","bCCBbBbCCCB","bCCBbCBaaaa","bCCBbCBaabB","bCCBbCBabBa","bCCBbCBabCB","bCCBbCBbBaa","bCCBbCBbBbB","bCCBbCBbCBa","bCCBbCBbCCB","bCCBbCCBaaa","bCCBbCCBabB","bCCBbCCBbBa","bCCBbCCBbCB","bCCBbCCCBaa","bCCBbCCCBbB","bCCBbCCCCBa","bCCBbCCCCCB","bCCCBaaaaaa","bCCCBaaaabB","bCCCBaaabBa","bCCCBaaabCB","bCCCBaabBaa","bCCCBaabBbB","bCCCBaabCBa","bCCCBaabCCB","bCCCBabBaaa","bCCCBabBabB","bCCCBabBbBa","bCCCBabBbCB","bCCCBabCBaa","bCCCBabCBbB","bCCCBabCCBa","bCCCBabCCCB","bCCCBbBaaaa","bCCCBbBaabB","bCCCBbBabBa","bCCCBbBabCB","bCCCBbBbBaa","bCCCBbBbBbB","bCCCBbBbCBa","bCCCBbBbCCB","bCCCBbCBaaa","bCCCBbCBabB","bCCCBbCBbBa","bCCCBbCBbCB","bCCCBbCCBaa","bCCCBbCCBbB","bCCCBbCCCBa","bCCCBbCCCCB","bCCCCBaaaaa","bCCCCBaaabB","bCCCCBaabBa","bCCCCBaabCB","bCCCCBabBaa","bCCCCBabBbB","bCCCCBabCBa","bCCCCBabCCB","bCCCCBbBaaa","bCCCCBbBabB","bCCCCBbBbBa","bCCCCBbBbCB","bCCCCBbCBaa","bCCCCBbCBbB","bCCCCBbCCBa","bCCCCBbCCCB","bCCCCCBaaaa","bCCCCCBaabB","bCCCCCBabBa","bCCCCCBabCB","bCCCCCBbBaa","bCCCCCBbBbB","bCCCCCBbCBa","bCCCCCBbCCB","bCCCCCCBaaa","bCCCCCCBabB","bCCCCCCBbBa","bCCCCCCBbCB","bCCCCCCCBaa","bCCCCCCCBbB","bCCCCCCCCBa","bCCCCCCCCCB"};
int Hash(string s){
	int pot = 1;
	int ans = 0;
	for(int i = SZ(s) - 1; i >= 0; --i){
		pot *= 31;
		ans = ans + pot * s[i];
	}
	return ans;
}
int main(){
	//REP(i,SZ(T)) assert(Hash(T[0]) == Hash(T[i]));
	//hash.in
	
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
	
	int n;
	while(scanf("%d",&n)==1){
		REP(i,n) printf("%s\n",T[i].c_str());
	}
}


