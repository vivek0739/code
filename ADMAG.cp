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
		long long int half=n/2;
		if(half*2==n)
		{
			ans=half+1;
		}
		else
		{
			ans=n-half;
		}
		
			printf("%d\n",ans );
		
	}
	return 0;	
}