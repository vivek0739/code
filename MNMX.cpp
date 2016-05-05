#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int dp[205];
	scanf("%d",&t);
	
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		int min1=INT_MAX;
		for(int i=0;i<n;i++)
		{
			min1=min(min1,arr[i]);
		}
		long long int ans=(long long int)(min1)*(long long int)(n-1);
		printf("%lld\n",ans);
	}
	return 0;
}