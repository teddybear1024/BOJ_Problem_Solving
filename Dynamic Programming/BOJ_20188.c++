#include <bits/stdc++.h>
using namespace std;
long long int n,a,b,c[300001],t[300001];
vector <long long int> v[300001];
int f(int x){
    c[x]=1;
    int y=1;
    for(int i=0;i<v[x].size();i++){
        if(c[v[x][i]]==0){
            y+=f(v[x][i]);
        }
    }
    t[x]=y;
    return y;
}
int main(void){
    scanf("%lld",&n);
    for(int i=0;i<n-1;i++){
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    a=f(1);
    a=0;
    for(int i=2;i<=n;i++){
        a+=((n*(n-1)/2)-((n-t[i])*(n-t[i]-1)/2));
    }
    printf("%lld",a);
}
