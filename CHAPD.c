#include<stdio.h>
#define ll long long 


ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(a%b,a);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a, ll b;
		scanf("%lld%lld",&a,&b);
		ll d=gcd(a,b);
		a=b/d;
		ll e=gcd(a,d);
		if(e==1)
		printf("No\n");
		else
		printf("Yes\n");

	}
	return 0;
}