/*
This problem also use Dynamic Programming technique.
*/
#include <bits/stdc++.h>
using namespace std;
long long int n,n1,m,t[400001],a[200001],mx;
long long int maxi(long long int num1,long long int num2){
    if(num1>num2)return num1;
    else return num2;
}
long long int f(long long int pos,long long int l1,long long int r1,long long int l2,long long int r2){
    if(l2<=l1&&r1<=r2){
        return t[pos];
    }
    else if(r1<l2||r2<l1){
        return -1000000000000;
    }
    else{
        return maxi(f(pos*2,l1,(l1+r1)/2,l2,r2),f(pos*2+1,(l1+r1)/2+1,r1,l2,r2));
    }
}
void g(long long int pos,long long int num){
    t[pos]=maxi(t[pos],num);
    if(pos!=1)g(pos/2,num);
}
long long int h(long long int pos){
    if(pos>=n1){
        t[pos]=a[pos-n1];
    }
    else{
        t[pos]=maxi(h(pos*2),h(pos*2+1));
    }
    return t[pos];
}
int main(void){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<200000;i++)a[i]=-1000000000000;
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    n1=1;
    while(n1<n)n1*=2;
    mx=h(1);
    mx=0;
    for(long long int i=1;i<n;i++){
        if(i<m){
            mx=maxi(f(1,1,n1,1,i)+a[i],a[i]);
            g(n1+i,mx);
        }
        else{
            mx=maxi(f(1,1,n1,i-m+1,i)+a[i],a[i]);
            g(n1+i,mx);
        }
    }
    printf("%lld",t[1]);
}
