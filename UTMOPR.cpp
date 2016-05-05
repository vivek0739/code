#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long long int sum=0;
		for(int i=0;i<n;i++)
		{
			long long int a;
			scanf("%lld",&a);
			sum+=a;

		}
		if(k==1 && sum%2==0)
		{
			printf("odd\n");
		}
		else
		{
			printf("even\n");
		}
	}
	return 0;
}