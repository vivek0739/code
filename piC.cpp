#include<bits/stdc++.h>
using namespace std;
map< int,int > mp;
int main()
{
	int n,k;
	
	scanf("%d%d",&n,&k);
	int arr[n];
	for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			
		}
	std::vector<int> vivek (n,0);
	long long int result=0;
	int pr1,pr2;
	
	for(int i=n-1;i>=2;i--)
	{
		pr1=arr[i]/k;
		if(arr[i]%k==0)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(arr[j]==pr1 && arr[j]%k==0)
				{
					pr2=pr1/k;
					for(int k=j-1;k>=0;k--)
					{
						if(arr[k]==pr2)
						{
							vivek[k]++;
						}
					}
				}
			
			}
		}
		
	}
	for(int i=0;i<n;i++)
		result+=vivek[i];
	
	
	cout<<result<<endl;
	return 0;	
}