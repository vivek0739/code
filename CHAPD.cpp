#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a, b;
		int flag=0;
		scanf("%lld%lld",&a,&b);
		while(1)
		{
			long long d=gcd(a,b);
			if(d==b)
			{
				flag=1;
				break;

			}
			b/=d;
			if(d==1)
				break;
		}

		if(flag!=1)
		printf("No\n");
		else
		printf("Yes\n");

	}
	return 0;
}