#include <bits/stdc++.h>
using namespace std;
stack <int> s1;
stack <int> s2;
vector <int> v;
char c[30],d[300005];
int n,m,a,b,t,t1[300005],t2[300005],k,cnt;
int main(void){
	scanf("%s %s",c,d);
	n=strlen(c);m=strlen(d);
	for(int i=0;i<m-1;i++){
        t1[i]=i+1;
	}
	t1[m-1]=1234567;
	for(int i=m-1;i>=0;i--){
        t2[i]=i-1;
	}
	a=0;b=m-1;
	while(1){
        for(int i=0;i<n;i++){
            if(s1.empty())break;
            else if(d[s1.top()]==0){
                s1.pop();
                i--;
            }
            else{
                a=s1.top();
                s1.pop();
            }
        }
        cnt=0;
        for(int i=a;i<m;i=t1[i]){
            k=i;
            for(int j=0;j<n;j++){
                if(k==1234567)break;
                if(d[k]==c[j]){
                    v.push_back(k);
                    k=t1[k];
                    if(j==n-1){
                        a=k;
                        for(int p=0;p<v.size();p++){
                            d[v[p]]=0;
                        }
                        v.clear();
                        if(s1.empty())i=-1;
                        else i=s1.top();
                        if(i==-1&&k==1234567){
                            return 0;
                        }
                        else if(i==-1){
                            t2[k]=-1;
                        }
                        else if(k==1234567){
                            t1[i]=1234567;
                        }
                        else{
                            t2[k]=i;
                            t1[i]=k;
                        }
                        cnt=1;
                    }
                }
                else{
                    v.clear();
                    break;
                }
            }
            if(cnt==1){
                break;
            }
            else{
                s1.push(i);
            }
        }
        if(cnt==0)break;
        for(int i=0;i<n;i++){
            if(s2.empty())break;
            else if(d[s2.top()]==0){
                s2.pop();
                i--;
            }
            else{
                b=s2.top();
                s2.pop();
            }
        }
        cnt=0;
        for(int i=b;i>=0;i=t2[i]){
            k=i;
            for(int j=n-1;j>=0;j--){
                if(k==-1)break;
                if(d[k]==c[j]){
                    v.push_back(k);
                    k=t2[k];
                    if(j==0){
                        b=k;
                        for(int p=0;p<v.size();p++){
                            d[v[p]]=0;
                        }
                        v.clear();
                        if(s2.empty())i=1234567;
                        else i=s2.top();
                        if(i==1234567&&k==-1){
                            return 0;
                        }
                        else if(i==1234567){
                            t1[k]=1234567;
                        }
                        else if(k==-1){
                            t2[i]=-1;
                        }
                        else{
                            t2[i]=k;
                            t1[k]=i;
                        }
                        cnt=1;
                    }
                }
                else{
                    v.clear();
                    break;
                }
            }
            if(cnt==1){
                break;
            }
            else{
                s2.push(i);
            }
        }
        if(cnt==0)break;
	}
	for(int i=0;i<m;i++){
        if(d[i]!=0)printf("%c",d[i]);
	}
}
