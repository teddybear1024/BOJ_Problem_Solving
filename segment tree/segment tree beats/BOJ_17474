#include <bits/stdc++.h>
using namespace std;
long long int n,m,o=1; // n : length of array, m : number of query, o = maximum power of 2 that smaller than n
long long int t[4][2500001]; // t : segment tree
/*
t[0][x] : maximum value in the sub array
t[1][x] : sum of sub array
t[2][x] : second maximum value in the sub array
t[3][x] = number of maximum value in the sub array
*/
long long int u[2500001]; // u : lazy array of array t
long long a,b,c,mx=1000000000000000,ans; (a,b,c) : query input, ans : query output
void f(long long int l,long long int r,long long int p){ // a=1 query, f ( left index, right index, segment tree index )
    if(u[p]!=mx){ // lazy array processing
        if(t[0][p]>u[p]){
            t[1][p]-=((t[0][p]-u[p])*t[3][p]);
            t[0][p]=u[p];
            if(p<o){
                u[p*2]=min(u[p*2],u[p]);
                u[p*2+1]=min(u[p*2+1],u[p]);
            }
        }
        u[p]=mx;
    }
    if(c<l||r<b)return; // when searching array is not included in the target array
    else if(b<=l&&r<=c){ // when searching array is perfectly included in the target array
        if(t[0][p]<=a)return;
        if(t[2][p]<a){
            t[1][p]-=((t[0][p]-a)*t[3][p]);
            t[0][p]=a;
            if(p<o){
                u[p*2]=min(u[p*2],a);
                u[p*2+1]=min(u[p*2+1],a);
            }
            return;
        }
    }
    else{
        f(l,(l+r)/2,p*2);
        f((l+r)/2+1,r,p*2+1);
    }
    // update value
    t[0][p]=max(t[0][p*2],t[0][p*2+1]);
    t[1][p]=t[1][p*2]+t[1][p*2+1];
    if(t[0][p*2]>t[0][p*2+1]){
        t[2][p]=max(t[0][p*2+1],t[2][p*2]);
        t[3][p]=t[3][p*2];
    }
    else if(t[0][p*2]<t[0][p*2+1]){
        t[2][p]=max(t[0][p*2],t[2][p*2+1]);
        t[3][p]=t[3][p*2+1];
    }
    else{
        t[2][p]=max(t[2][p*2],t[2][p*2+1]);
        t[3][p]=t[3][p*2]+t[3][p*2+1];
    }
}
void g(long long int l,long long int r,long long int p){ // a=2 query
    if(u[p]!=mx){
        if(t[0][p]>u[p]){
            t[1][p]-=((t[0][p]-u[p])*t[3][p]);
            t[0][p]=u[p];
            if(p<o){
                u[p*2]=min(u[p*2],u[p]);
                u[p*2+1]=min(u[p*2+1],u[p]);
            }
        }
        u[p]=mx;
    }
    if(r<b||c<l)return;
    if(b<=l&&r<=c)ans=max(ans,t[0][p]);
    else{
        g(l,(l+r)/2,p*2);
        g((l+r)/2+1,r,p*2+1);
    }
}
void h(long long int l,long long int r,long long int p){ // a=3 query
    if(u[p]!=mx){
        if(t[0][p]>u[p]){
            t[1][p]-=((t[0][p]-u[p])*t[3][p]);
            t[0][p]=u[p];
            if(p<o){
                u[p*2]=min(u[p*2],u[p]);
                u[p*2+1]=min(u[p*2+1],u[p]);
            }
        }
        u[p]=mx;
    }
    if(r<b||c<l)return;
    if(b<=l&&r<=c)ans+=t[1][p];
    else{
        h(l,(l+r)/2,p*2);
        h((l+r)/2+1,r,p*2+1);
    }
}
int main(void) {
    scanf("%lld",&n);
    while(o<n)o*=2;
    for(int i=1;i<=o*2;i++)u[i]=mx;
    for(int i=0;i<n;i++){
        scanf("%lld",&t[0][o+i]);
        t[1][o+i]=t[0][o+i];
        t[2][o+i]=-1;
        t[3][o+i]=1;
    }
    for(int i=o-1;i>=1;i--){ // insert initial value in array t
        t[0][i]=max(t[0][i*2],t[0][i*2+1]);
        t[1][i]=t[1][i*2]+t[1][i*2+1];
        if(t[0][i*2]>t[0][i*2+1]){
            t[2][i]=max(t[0][i*2+1],t[2][i*2]);
            t[3][i]=t[3][i*2];
        }
        else if(t[0][i*2]<t[0][i*2+1]){
            t[2][i]=max(t[0][i*2],t[2][i*2+1]);
            t[3][i]=t[3][i*2+1];
        }
        else{
            t[2][i]=max(t[2][i*2],t[2][i*2+1]);
            t[3][i]=t[3][i*2]+t[3][i*2+1];
        }
    }
    scanf("%lld",&m);
    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a==1){
            scanf("%lld",&a); // overwrite a with fourth value in the query 1
            f(1,o,1);
        }
        else if(a==2){
            ans=0;
            g(1,o,1);
            printf("%lld\n",ans);
        }
        else{
            ans=0;
            h(1,o,1);
            printf("%lld\n",ans);
        }
    }
}
