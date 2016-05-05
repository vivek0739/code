#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007L
long long int arr[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		sort(arr,arr+n);
		long long int prod=1L,sum1=0,sum2=0;
		for(int i=0; i<n;i++)
		{
			(sum1+=(prod*arr[i])%mod)%=mod;
			(sum2+=(prod*arr[n-i-1])%mod)%=mod;
			(prod*=2)%=mod;
		}
		long long int sum=sum1-sum2;
		if(sum<0)
			sum=mod+sum;
		printf("%lld\n",sum);
	}
	return 0;