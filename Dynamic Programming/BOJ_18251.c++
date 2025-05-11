#include <bits/stdc++.h>
using namespace std;
struct str{
    long long int x,y,z;
};
long long int n,a,b,c,t[30],mx;
struct str s[300001];
int f(str s1,str s2){
    if(s1.z<s2.z)return 1;
    else return 0;
}
int main(void){
    scanf("%lld",&n);
    b=2;
    while(b<n){
        b*=2;
    }
    a=2;c=b/2;
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i].x);
        s[i].z=c;
        if(i==a-1){
            a*=2;
            b/=2;
            c=b/2;
        }
        else{
            c+=b;
        }
    }
    sort(s,s+(n+1),f);
    for(int i=1;i<=n;i++){
        a=i;
        while(a%2==0){
            a/=2;
            s[i].y++;
        }
    }
    a=1;b=2;
    while(b<n){
        a++;
        b*=2;
    }
    mx=-100000000000;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)t[j]=0;
        t[i]=1;
        for(int j=i;j<a;j++){
            b=-100000000000;
            c=0;
            t[j]=1;
            for(int k=1;k<=n;k++){
                if(t[s[k].y]==1){
                    if(c>0){
                        c+=s[k].x;
                    }
                    else{
                        c=s[k].x;
                    }
                    b=max(b,c);
                }
            }
            mx=max(mx,b);
        }
    }
    printf("%lld",mx);
}
