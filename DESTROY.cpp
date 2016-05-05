#include<bits/stdc++.h>
using namespace std;
int arr[50002];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);

		int sum = 1, count = 1, first = arr[0];
		for(int i=1;i<n;i++)
		{
			if(arr[i]==first)
			{
				count++;
				sum++;
			}
			else
			{
				if(count == 0)
				{
					count = 1;
					sum++;
					first = arr[i];
				}
				else
				{
					count--;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}