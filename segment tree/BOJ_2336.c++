#include <bits/stdc++.h>
using namespace std;
struct str{
    int x,y,z;
};
str s[500001]; // ranking of three tests
int n,m=1,t[1050000],a,b;
int cmp(str s1,str s2){
    if(s1.x>s2.x)return 0;
    else return 1;
}
void f(int p,int q){
    t[p]=min(t[p],q);
    if(p!=1)f(p/2,q);
}
void g(int l,int r,int p,int q){
    if(p<l)return;
    else if(r<=p){
        b=min(t[q],b);
    }
    else{
        g(l,(l+r)/2,p,q*2);
        g((l+r)/2+1,r,p,q*2+1);
    }
}
int main(void){
    scanf("%d",&n);
    while(m<n)m*=2;
    for(int i=1;i<m*2;i++)t[i]=10000000;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        s[a-1].x=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        s[a-1].y=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        s[a-1].z=i;
    }
    a=0;
    sort(s,s+n,cmp); // sort input by x
    for(int i=0;i<n;i++){
        t[m+s[i].y-1]=s[i].z;
        f(m+s[i].y-1,s[i].z);
        b=10000000; // max value
        g(1,m,s[i].y-1,1);
        if(b>s[i].z)a++;
    }
    printf("%d",a);
}
