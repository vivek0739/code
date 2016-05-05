#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll A[10000005];
ll min(ll a,ll b)
{
	if(a<b)
	return a;
	else
	return b;
}
ll RMQUtil(ll *st,ll ss,ll se,ll qs,ll qe,ll index)
{
	if(qs <= ss && qe >= se)
	{
		return st[index];
	}
	if(se < qs || ss >qe)
	{
		return INT_MAX;
	}
	int mid=(ss+se)/2;
	return min(RMQUtil(st,ss,mid,qs,qe,2*index+1),RMQUtil(st,mid+1,se,qs,qe,2*index+2));
}
ll RMQ(ll *st,ll n,ll qs,ll qe)
{
	return RMQUtil(st,0,n-1,qs,qe,0);
}
ll constructSTUtil(ll ss,ll se,ll *st,ll si)
{
	if(ss == se)
	{
		st[si]=A[ss];
		return A[ss];

	}
	int mid=ss+(se-ss)/2;
	st[si]=min(constructSTUtil(ss,mid,st,si*2+1),constructSTUtil(mid+1,se,st,si*2+2));
	return st[si];
}
ll *constructST(ll n)
{
	ll x=(ll)(ceil(log2(n)));
	ll max_size=2*(ll)pow(2,x)-1;
	ll *st=new ll[max_size];
	constructSTUtil(0,n-1,st,0);
	return st;
}
int main()
{
	ll N,K,Q,a, b, c, d, e, f, r, s, t, m,l1, la, lc, lm, d1, da, dc,dm,i,j;
	scanf("%lld %lld %lld",&N,&K,&Q);
 
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A[1]);
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
	 for(i=0;i<N;i++)
	 {
	 	cout<<A[i]<<endl;
	 }
	 ll *st = constructST(N);  
	 ll L,R,sum=0,product=1;
	 for(i=1;i<=Q;i++)
	 {
	 	l1=(la*l1+lc)%lm;
	 	d1=(da*d1+dc)%dm;
	 	L=l1+1;
	 	R=min(L+K-1+d1,N);
	 	ll ans1;
	 	//cout<<L<<" "<<R<<endl;
	 	ans1=RMQ(st,N,L-1,R-1);
	 	//cout<<ans1;
	 	sum=(sum+ans1);
	 	product=(product*ans1)%mod;
	 }
	 printf("%lld %lld",sum,product);
 
}