#include <bits/stdc++.h>
using namespace std;
struct str{
    long long int x,y;
};
str s[200001];
priority_queue <long long int> pq;
long long int n,ans;
int cmp1(str s1,str s2){
    if(s1.y<s2.y)return 1;
    else return 0;
}
int main(void){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i].x);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i].y);
    }
    sort(s,s+n,cmp1);
    ans+=s[0].x;
    for(int i=1;i<n-2;i+=2){
        pq.push(s[i].x);
        pq.push(s[i+1].x);
        ans+=pq.top();
        pq.pop();
    }
    printf("%lld",ans);
}
