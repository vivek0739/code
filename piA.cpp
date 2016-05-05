#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<n;i++)
	{
		int min1;
		if(i!=0&&i!=n-1)
			min1=min(abs(arr[i]-arr[i-1]),abs(arr[i+1]-arr[i]));
		else if(i==0)
			min1=abs(arr[i+1]-arr[i]);
		else
			min1=abs(arr[i]-arr[i-1]);
		int max1;
		max1=max(abs(arr[i]-arr[0]),abs(arr[n-1]-arr[i]));
		
		

		printf("%d %d\n",min1,max1);
	}
	return 0;	
}