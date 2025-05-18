#include <bits/stdc++.h>
using namespace std;
struct str{
    int y,z;
};
str t[10001];
stack <int> s;
vector <int> v[10001];
vector <int> w[10001];
vector <int> x[10001];
int n,m,a,b,c[10001];
void f(int p){
    c[p]=1;
    for(int i=0;i<v[p].size();i++){
        if(c[v[p][i]]==0)f(v[p][i]);
    }
    s.push(p);
}
void g(int p){
    c[p]=2;
    for(int i=0;i<w[p].size();i++){
        if(c[w[p][i]]==1)g(w[p][i]);
    }
    x[b].push_back(p);
}
int cmp(str s1,str s2){
    if(s1.y<s2.y)return 1;
    else return 0;
}
int main(void){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        w[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0)f(i);
    }
    b=0;
    while(!s.empty()){
        a=s.top();
        s.pop();
        if(c[a]==1){
            g(a);
            sort(x[b].begin(),x[b].end());
            t[b].y=x[b][0];
            t[b].z=b;
            b++;
        }
    }
    sort(t,t+b,cmp);
    printf("%d\n",b);
    for(int i=0;i<b;i++){
        for(int j=0;j<x[t[i].z].size();j++){
            printf("%d ",x[t[i].z][j]);
        }
        printf("-1\n");
    }
}
