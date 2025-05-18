#include <bits/stdc++.h>
using namespace std;
struct str{
    long long int x,y;
};
map <long long int,long long int> mp;
str s[100001],t[100001],u[100001];
long long int n,m,a,b,c,d,check,mx,mn,ans;
int f(str s1,str s2){
    if(s1.x<s2.x)return 1;
    else if(s1.x>s2.x)return 0;
    else if(s1.y>s2.y)return 1;
    else return 0;
}
int main(void){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&s[i].x,&s[i].y);
    }
    sort(s,s+n,f);
    a=b=0;
    t[0].x=u[0].x=s[0].x;
    t[0].y=u[0].y=s[0].y;
    for(int i=1;i<n;i++){
        if(t[a].x==s[i].x){
            if(t[a].y<s[i].y){
                t[a].y=s[i].y;
                for(int j=0;j<a;j++){
                    if((t[j+1].x-t[j].x)*(s[i].y-t[j].y)>=(s[i].x-t[j].x)*(t[j+1].y-t[j].y)){
                        t[j+1].x=s[i].x;
                        t[j+1].y=s[i].y;
                        a=j+1;
                        check=1;
                        break;
                    }
                }
            }
        }
        else if(a==0){
            a++;
            t[a].x=s[i].x;
            t[a].y=s[i].y;
        }
        else{
            check=0;
            for(int j=0;j<a;j++){
                if((t[j+1].x-t[j].x)*(s[i].y-t[j].y)>=(s[i].x-t[j].x)*(t[j+1].y-t[j].y)){
                    t[j+1].x=s[i].x;
                    t[j+1].y=s[i].y;
                    a=j+1;
                    check=1;
                    break;
                }
            }
            if(check==0){
                a++;
                t[a].x=s[i].x;
                t[a].y=s[i].y;
            }
        }

        if(u[b].x==s[i].x){
            if(u[b].y>s[i].y){
                u[b].y=s[i].y;
                for(int j=0;j<b;j++){
                    if((u[j+1].x-u[j].x)*(s[i].y-u[j].y)<=(s[i].x-u[j].x)*(u[j+1].y-u[j].y)){
                        u[j+1].x=s[i].x;
                        u[j+1].y=s[i].y;
                        b=j+1;
                        break;
                    }
                }
            }
        }
        else if(b==0){
            b++;
            u[b].x=s[i].x;
            u[b].y=s[i].y;
        }
        else{
            check=0;
            for(int j=0;j<b;j++){
                if((u[j+1].x-u[j].x)*(s[i].y-u[j].y)<=(s[i].x-u[j].x)*(u[j+1].y-u[j].y)){
                    u[j+1].x=s[i].x;
                    u[j+1].y=s[i].y;
                    b=j+1;
                    check=1;
                    break;
                }
            }
            if(check==0){
                b++;
                u[b].x=s[i].x;
                u[b].y=s[i].y;
            }
        }
    }
    for(int i=0;i<=a;i++){
        mp[t[i].x*100000+t[i].y]++;
        if(mp[t[i].x*100000+t[i].y]==1)ans++;
    }
    for(int i=0;i<=b;i++){
        mp[u[i].x*100000+u[i].y]++;
        if(mp[u[i].x*100000+u[i].y]==1)ans++;
    }
    printf("%lld",ans);
}
