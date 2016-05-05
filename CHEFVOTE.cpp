#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n+1];
		int flag=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]>(n-1))
			flag=1;
			sum+=arr[i];
			//printf("%d",sum);
		}

		if(sum!=n)
		flag=1;
		if(flag==1)
		{
			printf("-1\n");
			continue;
		}
		int sol[n+1];
		int k=0,p,i;
		memset(sol,0,sizeof(sol));
		for(int i=1;i<=n;i++)
		{
			k=0;
			for(int j=1;j<=n;j++)
			{
				
					if( j != i && sol[j] == 0)
					{
						sol[j]=i;
						k++;
					}
					if(k==arr[i])
					{
						break;
					}

					
					
				
			}
		}
		//printf("%d",p);
		
		for(int i=1;i<=n;i++)
		printf("%d ",sol[i]);
		printf("\n");

	}
}