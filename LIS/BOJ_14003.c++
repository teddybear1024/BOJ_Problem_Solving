#include <bits/stdc++.h>
using namespace std;
struct str{
    int x,y;
};
vector <str> v;
int n,a,b,t[1000005],u[1000005],m;
str s;
void f(int l,int r){
    if(l>r)return;
    m=(l+r)/2;
    if(v[m].x>=a){
        b=min(b,m);
        f(l,m-1);
    }
    else{
        f(m+1,r);
    }
}
void g(int x){
    if(x!=0){
        g(t[x]);
    }
    else return;
    printf("%d ",u[x]);
}
int main(void){
    scanf("%d",&n);
    s.x=-1111111111;
    s.y=0;
    v.push_back(s);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        u[i]=a;
        b=v.size()+1;
        if(v[v.size()-1].x<a){
            s.x=a;
            s.y=i;
            t[i]=v[v.size()-1].y;
            v.push_back(s);
        }
        else{
            f(0,v.size()-1);
            t[i]=v[b-1].y;
            v[b].x=a;
            v[b].y=i;
        }
    }
    printf("%d\n",v.size()-1);
    g(v[v.size()-1].y);
}
