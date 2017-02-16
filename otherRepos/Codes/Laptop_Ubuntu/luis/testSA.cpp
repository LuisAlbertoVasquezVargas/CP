#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 250001
#define ALPH_SIZE 26
 
using namespace std;
 
struct state{
    int len, link, next[ALPH_SIZE];
};
 
state st[N*2];
int sz, last;
 
void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}
 
void sa_extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next[c]; p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, ALPH_SIZE * sizeof(int));
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
 

int main(){
	char s[N],t[N];
	scanf("%s%s",s,t);
	sa_init();
	for(int i=0;s[i]!='\0';++i){
		sa_extend(s[i]-'a');
	}
	int v=0,ct=0,best=0;
	for(int i=0;t[i]!='\0';++i){
		int aux=st[v].next[t[i]-'a'];
		if(aux==0){
			best=max(best,ct);
			while(aux==0 && v!=0){
				v=st[v].link;
				ct=st[v].len;
				aux=st[v].next[t[i]-'a'];
			}
			if(aux!=0)ct++;
		}
		else {
			ct++;
		}
		v=aux;
	}
	best=max(best,ct);
	printf("%d\n",best);
}


