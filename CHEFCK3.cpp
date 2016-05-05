#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll A[10000005];
int M[10000009][25];
ll min(ll a,ll b)
{
    if(a<b)
    return a;
    else
    return b;
}
void Compute_ST(ll A[],ll N){
    int i,j;
    for(i=0;i<(int)N;i++)
        M[i][0]=i;
    for(j=1;1<<j <=(int)N ;j++){
        for(i=0;i+(1<<(j-1))<(int)N;i++){
            if(A[M[i][j-1]]<=A[M[i+(1<<(j-1))][j-1]])
                M[i][j]=M[i][j-1];
            else
                M[i][j]=M[i+(1<<(j-1))][j-1];
        }
    }
}
ll RMQ(ll A[],ll s,ll e){
    int k=e-s;
    k=31-__builtin_clz(k+1); // k = log(e-s+1)
    if(A[M[s][k]]<=A[M[e-(1<<k)+1][k]])
        return A[M[s][k]];
    return A[M[e-(1<<k)+1][k]];
}
int main()
{
    ll N,K,Q,a, b, c, d, e, f, r, s, t, m,l1, la, lc, lm, d1, da, dc,dm,i,j;
    scanf("%lld %lld %lld",&N,&K,&Q);
 
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A[0]);
     scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&l1,&la,&lc,&lm,&d1,&da,&dc,&dm);
      ll p=t;
     for(i=1;i<N;i++)
     {
        p=(p*t)%s;
        if(p<=r)
        {
            A[i]=((a*A[i-1]*A[i-1])+(b*A[i-1])+c)%m;
        }
        else
            A[i]=((d*A[i-1]*A[i-1])+(e*A[i-1])+f)%m;
     }   
      
     ll L,R,sum=0,product=1;
     
    Compute_ST(A,N);

     for(i=1;i<=Q;i++)
     {
        l1=(la*l1+lc)%lm;
        d1=(da*d1+dc)%dm;
        L=l1+1;
        R=min(L+K-1+d1,N);
        ll ans1;
        ans1=RMQ(A,L-1,R-1);
        //cout<<L<<" "<<R<<endl;
   
        //cout<<ans1;
        sum=(sum+ans1);
        product=(product*ans1)%mod;
     }
     printf("%lld %lld",sum,product);
 
}
