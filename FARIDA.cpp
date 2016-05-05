#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	int k=1;
	while(k<=t)
	{
		int n;
		scanf("%d",&n);
		long long int arr[n+1];
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		arr[0]=0;
		for(int i=2;i<=n;i++)
		{
			arr[i]=max(arr[i-1],arr[i-2]+arr[i]);
		}
		printf("Case %d: %lld\n",k,arr[n]);
		k++;
	}


	return 0;
}