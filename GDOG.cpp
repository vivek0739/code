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
		int maximum_profit=0;
		for(int i=1;i<=k;i++)
		{
			int temp=n%i;
			if(temp>maximum_profit)
				maximum_profit=temp;
		}
		printf("%d\n",maximum_profit );
	}
	return 0;
}