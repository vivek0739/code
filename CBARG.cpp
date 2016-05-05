#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,sum=0,prev=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&a);
			
			sum+=((a-prev)>0)?(a-prev):0;
			prev=a;
			//cout<<sum;
		}
		printf("%lld\n",sum);
	}
	return 0;
}