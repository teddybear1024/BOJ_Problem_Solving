#include <bits/stdc++.h>
using namespace std;
int n,m,o=1,a[500001]; // n : length of array, m : number of query, o : maximum power of 2 lower than n, a : XOR initial value in index 1 to a
int t[1050000],u[1050000]; // t : segment tree array, u : lazy array
int b,c,d,ans; // (b,c,d) : query input, ans : query output 
void f(int l,int r,int p){ // query 1, f( left index, right index, segment tree index )
    if(u[p]>0){ // lazy array processing
        if(p>=o){
            t[p]=t[p]^u[p];
        }
        else{
            u[p*2]=u[p*2]^u[p];
            u[p*2+1]=u[p*2+1]^u[p];
        }
        u[p]=0;
    }
    if(b<=l&&r<=c){ // when searching array is perfectly included in target array
        if(p>=o){
            t[p]=t[p]^d;
        }
        else{
            u[p*2]=u[p*2]^d;
            u[p*2+1]=u[p*2+1]^d;
        }
        return;
    }
    else if(r<b||c<l){ // when searching array is not included in target array
        return;
    }
    else{
        f(l,(l+r)/2,p*2);
        f((l+r)/2+1,r,p*2+1);
        t[p]=t[p*2]^t[p*2+1];
    }
}
void g(int l,int r,int p){ // query 2
    if(u[p]>0){ // lazy array processing
        if(p>=o){
            t[p]=t[p]^u[p];
        }
        else{
            u[p*2]=u[p*2]^u[p];
            u[p*2+1]=u[p*2+1]^u[p];
        }
        u[p]=0;
    }
    if(b<=l&&r<=c){
        ans=ans^t[p];
        return;
    }
    else if(r<b||c<l){
        return;
    }
    else{
        g(l,(l+r)/2,p*2);
        g((l+r)/2+1,r,p*2+1);
    }
}
int main(void){
    scanf("%d",&n);
    while(o<n)o*=2;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=a[i]^a[i-1]; // setting initial value of a
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b);
        if(b==1){
            scanf("%d%d%d",&b,&c,&d);
            b++;c++;
            f(1,o,1);
        }
        else{
            scanf("%d%d",&b,&c);
            ans=a[b]^a[c+1]; // XOR initial value in index b to c
            b++;c++;
            g(1,o,1);
            printf("%d\n",ans);
        }
    }
}
