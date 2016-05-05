#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int A[105][105];
	scanf("%d",&t);
	
	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<n;j++)
			{	
				scanf("%d",&A[i][j]);	
			}
		}
		int maxi=0,sum=0;
		int l=1;
		
			for(int x1=0;x1<n;x1++)
			{
				for(int x2=x1;x2<n;x2++)
				{
					for(int y1=0;y1<n;y1++)
					{
						for(int y2=y1;y2<n;y2++)
						{	
							int xori=0;
							for(int i=x1;i<=x2;i++)
							{	
								for(int j=y1;j<=y2;j++)
								{	
								  xori=xori^A[i][j];
								}
							}
							if(xori>maxi) maxi=xori;
						}
					}
				}
				
			}
		
		
		printf("%d\n",maxi);
	}
	return 0;
} 