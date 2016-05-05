#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[m];
	int a;
	for(int i=0;i<m;i++)
	{
		int max=0,index=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a);
			if(a>max)
			{
				max=a;
				index=j;
			}
		}
		arr[i]=index;
	}
	int count[n];
	memset(count,0,sizeof(count));
	for(int i=0;i<m;i++)
	{
		count[arr[i]]++;
	}
	int max=0;
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			index=i;
		}
			
	}

	printf("%d\n",index+1);
	return 0;	
}