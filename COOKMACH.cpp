#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int n,m,k;
	while(t--)
	{
		
		scanf("%d%d",&n,&m);
		int count=0;
		if(!(n&(n-1)))
		{
			if(n>m)
			{
				while(n!=m)
				{
					n>>=1;
					count++;
				}
			}
			else
			{
				while(n!=m)
				{
					n<<=1;
					count++;
				}
			}
		}
		else
		{
			while(n&(n-1))
				{
					n>>=1;
					count++;
				}
			if(n>m)
			{
				while(n!=m)
				{
					n>>=1;
					count++;
				}
			}
			else
			{
				while(n!=m)
				{
					n<<=1;
					count++;
				}
			}
		}
		
		printf("%d\n",count);
	}
	return 0;	
}