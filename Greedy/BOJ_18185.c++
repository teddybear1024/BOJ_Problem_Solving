#include <bits/stdc++.h>
using namespace std;
int n,a,t[3],b;
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(t[1]>a){
            b+=(a*2);
            t[2]=a;
            t[1]=0;
        }
        else{
            b+=(t[1]*2);
            a-=t[1];
            t[0]=t[1];
            b+=(min(a,t[2])*2);
            b+=(max(a-t[2],0)*3);
            t[1]=max(a-t[2],0);
            t[2]=t[0];
        }
    }
    printf("%d",b);
}
