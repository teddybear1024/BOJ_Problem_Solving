#include <bits/stdc++.h>
using namespace std;
long long int n,m=1,a,t[12][400000],x=1000000007,ans;
void f(int p,long long int q,long long int r){
    t[p][q]+=r;
    t[p][q]%=x;
    if(q>1)f(p,q/2,r);
}
void g(long long int l,long long int r,long long int p,int q){
    if(a-1<l)return;
    if(r<=a-1){
        ans+=t[q][p];
        ans%=x;
    }
    else{
        g(l,(l+r)/2,p*2,q);
        g((l+r)/2+1,r,p*2+1,q);
    }
}
int main(void) {
    scanf("%d",&n);
    while(m<n)m*=2;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        f(1,m+a-1,1);
        for(int j=1;j<11;j++){
            ans=0;
            g(1,m,1,j);
            f(j+1,m+a-1,ans);
        }
    }
    ans=0;
    a=n+1;
    g(1,m,1,11);
    printf("%lld",ans);
}
