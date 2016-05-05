#include<bits/stdc++.h>
using namespace std;
int compare(const void *a ,const void *b)
{
	return (*(long long int*)a-*(long long int *)b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long int area[n][2];
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);

			long long int dist,x,y;
			scanf("%lld%lld",&x,&y);
			dist=y;
			for(int j=0;j<m-1;j++)
			{
				scanf("%lld%lld",&x,&y);
				
				long long int temp=y;
				if(temp>=dist)
					dist=temp;
			}
			
			area[i][0]=dist;
			area[i][1]=i+1;
		}
		
		qsort(area,n,2*sizeof(long long int),compare);
		int no_of_polygon[n+1];
		for(int i=0;i<n;i++)
		{
			if(area[i][0]== area[i-1][0])
			{
				no_of_polygon[(int)area[i][1]]=no_of_polygon[(int)area[i-1][1]];
			}
			else
			no_of_polygon[(int)area[i][1]]=i;
		}
		
		for(int i=1;i<=n;i++)
			printf("%d ",no_of_polygon[i]);
			printf("\n");
	}
	return 0;
}
