#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
	
	
		int n,k;
		scanf("%d%d",&n,&k);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		long long int prod=arr[n-1];
		while(n>k)
		{
			
			n-=k;
			(prod*=arr[n-1])%=mod;
			
		}
		printf("%lld\n",prod);
		return 0;
	
} 