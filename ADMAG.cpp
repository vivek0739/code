#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	
	long long int ans=0;
	while(t--)
	{	long long int n;
		scanf("%lld",&n);
		long long int half=1L;
		long long int i=1;
		if(n==1)
		{
			printf("%lld\n",i );
			continue;
		}
		
		for(i=2;i<=n;i++)
		{
			half=half+i;
			if(half>=n)
				break;
		}
		printf("%lld\n",i );
		
		
	}
	return 0;	
}