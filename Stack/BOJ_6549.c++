#include <bits/stdc++.h>
using namespace std;
struct str{
    long long int x,y;
};
stack <str> s;
long long int n,a,mx;
str v;
int main(void){
    while(1){
        mx=a=n=0;
        scanf("%lld",&n);
        if(n==0)break;
        v.x=0;v.y=0;
        s.push(v);
        for(long long int i=1;i<=n;i++){
            scanf("%lld",&a);
            v.x=a;v.y=i;
            while(!s.empty()){
                if(s.top().x>a){
                    mx=max(mx,s.top().x*(i-s.top().y));
                    v.y=s.top().y;
                    s.pop();
                }
                else break;
            }
            s.push(v);
        }
        while(!s.empty()){
            mx=max(mx,s.top().x*(n+1-s.top().y));
            s.pop();
        }
        printf("%lld\n",mx);
    }
}
