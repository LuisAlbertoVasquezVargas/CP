#include<vector>
#include<iostream>
#include<utility>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

bool isCurso(string &s){
    for(int i=0;;++i)if(s[i]!=' ')return isupper(s[i]);
}

void f(vector<string> &luis,map<string,int> &m){
    for(int i=0;i<luis.size();++i){
        m[luis[i]]++;
    }
}

void solve(vector<string> &v){
    int n=v.size();
    map<string,int> m;
    vector<string>  luis;
    vector<vector<string> > uni;
    vector<string> cursos(1,v[0]);
    for(int i=1;i<n;++i){
        if(isCurso(v[i])){
            cursos.push_back(v[i]);
            sort(luis.begin(),luis.end());
            int val=unique(luis.begin(),luis.end())-luis.begin();
            luis.resize(val);
            uni.push_back(luis);
            f(luis,m);
            luis.clear();
        }
        else{
            luis.push_back(v[i]);
        }
    }
    f(luis,m);
    uni.push_back(luis);
    vector<pair<int,string> > tru;
    for(int i=0;i<uni.size();++i){
        vector<string> &ref=uni[i];
        int res=ref.size();
        for(int j=0;j<ref.size();++j){
            if(m[ref[j]]>1)res--;
        }
        tru.push_back(make_pair(-res,cursos[i]));
    }
    sort(tru.begin(),tru.end());
    for(int i=0;i<tru.size();++i){
        cout<<tru[i].second<<" "<<-tru[i].first<<"\n";
    }
}

char caso(){
    string s;
    getline(cin,s);
    if(s=="0")return 0;
    if(s=="1")return 1;
    vector<string> v(1,s);
    while(getline(cin,s)&&s!="1"){
        v.push_back(s);
    }
    solve(v);
    return 1;
}

int main(){
    while(caso());
}
