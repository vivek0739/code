#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int arr[m];
		int min1=INT_MAX;
		for(int i=0;i<m;i++)
		{
			 
			 	scanf("%d",&arr[i]);
		}
		sort(arr,arr+m);
		int sum=0;
		int i=0;
		for(i=0;i<m;i++)
		{
			if(sum+arr[i]<=m-2)
			{
				sum+=arr[i];
				m--;
			}
			else
			{
				break;
			}
		}
		printf("%d\n",m-1);
		

	}
}