#include <bits/stdc++.h>
using namespace std;
struct str{
    long long int a,b;
};
str s[1000001];
long long int n,m=1,t[4000001],ans;
int srt(str s1,str s2){
    if(s1.a>s2.a)return 0;
    else return 1;
}
void f(long long int l,long long int r,long long int x,long long int p){
    if(l<=x&&x<=r){
        t[p]++;
        if(l!=r){
            f(l,(l+r)/2,x,p*2);
            f((l+r)/2+1,r,x,p*2+1);
        }
    }
}
void g(long long int l1,long long int r1,long long int l2,long long int r2,long long int p){
    if(l2<=l1&&r1<=r2){
        ans+=t[p];
    }
    else if(r2<l1||r1<l2)return;
    else{
        g(l1,(l1+r1)/2,l2,r2,p*2);
        g((l1+r1)/2+1,r1,l2,r2,p*2+1);
    }
}
int main(void){
    scanf("%lld",&n);
    while(n>m)m*=2;
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i].a);
        s[i].b=i+1;
    }
    sort(s,s+n,srt);
    for(int i=0;i<n;i++){
        f(1,m,s[i].b,1);
        g(1,m,s[i].b+1,m,1);
    }
    printf("%lld",ans);
}
