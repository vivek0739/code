#include<bits/stdc++.h>
#define mod 1000003
using namespace std;
int dp[1000][1000];
#define ll long long 
#define maxx 1000010
ll *fact;
ll power(ll a,ll b)
{
	ll x=1,y=a%mod;
	while(b>0)
	{
		if(b&1)
			(x*=y)%=mod;
		(y*=y)%=mod;
		b>>=1;
	}
	return x%mod;
}
ll C(int N,int r)
{
	ll ncr=fact[N];
	ncr=(ncr*power(fact[r],mod-2))%mod;
	ncr=(ncr*power(fact[N-r],mod-2))%mod;
	return ncr;
}
ll lucas(ll n,ll m)
{
	if(n==0 && m==0) return 1;
	int ni=n%mod;
	int mi=m%mod;
	if(mi>ni) return 0;
	return lucas(n/mod,m/mod)*C(ni,mi);
}
int main()
{
	int t;
	int n,l,r,p;
	fact=(ll*)malloc(maxx*sizeof(ll));
	fact[0]=1;
	for(int i=1;i<maxx;i++)
	fact[i]=(fact[i-1]*i)%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&l,&r);
		p=r-l;
		if(n<=100 && p <= 100 )
		{
			for(int j=0;j<=p;j++)
			dp[0][j]=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=p;j++)
				{
					dp[i][j]=0;
					for(int k=0;k<=j;k++)
					{
						(dp[i][j]+=dp[i-1][k])%=mod;
					}
				}
			}
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				(sum+=dp[i][p])%=mod;
			}
			printf("%d\n",sum);
		}
		else
		{
			p++;
			ll k=lucas(p+n,n);
			printf("%lld\n",(k-1+mod)%mod);
		}
		
	}
	
	return 0;
}
