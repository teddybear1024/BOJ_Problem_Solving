/*
How to solve the problem
1. Check all the possible value made with only 'dividing by 2' operation from a until 1
( add 1 operation if value is odd because can't divide by 2 when number is odd )
2. Save the value and number of operation in c
3. Do the same thing to b ( save the value and number of operation in d )
4. Check all pairs drawn from c and d, then find the answer
{ number of operation = c.y + d.y + abs ( c.x - d.x ) }
*/
#include <bits/stdc++.h>
using namespace std;
struct str{
    long long int x,y; // x : value after operation, y : number of operation
};
struct str c[100],d[100]; // c : str of a, d : str of b
long long int n,a,b; // inputs
long long int a1,b1; // number of operation
long long int x[100],y[100],m,t;
int main(void){
    scanf("%lld",&n);
    for(int p=0;p<n;p++){
        scanf("%lld%lld",&a,&b);
        // reseting values
        a1=b1=0; 
        m=0;
        c[0].x=a; // setting c
        c[0].y=0;
        for(int i=1;;i++){ 
            a1++;
            if(a==1)break;
            if(a%2==0){
                m++;a/=2;
            }
            else{
                m+=2;a++;a/=2;
            }
            c[i].x=a;
            c[i].y=m;
        }
        m=0;
        d[0].x=b; // setting d
        d[0].y=0;
        for(int i=1;;i++){
            b1++;
            if(b==1)break;
            if(b%2==0){
                m++;b/=2;
            }
            else{
                m+=2;b--;b/=2;
            }
            d[i].x=b;
            d[i].y=m;
        }
        t=10000000000001;
        for(int i=0;i<a1;i++){
            for(int j=0;j<b1;j++){
                if(c[i].x>d[j].x)break; // ignore the pair that never can be answer
                if(t>c[i].y+d[j].y+d[j].x-c[i].x){
                    t=c[i].y+d[j].y+d[j].x-c[i].x;
                }
            }
        }
        printf("%lld\n",t);
    }
}
