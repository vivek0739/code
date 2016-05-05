#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	map<int,pair<int,int> > mp;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n][n];
		mp.clear();
		for(int i=0;i<n;i++)
		{
			 for(int j=0;j<n;j++)
			 {
			 	scanf("%d",&arr[i][j]);
			 	mp[arr[i][j]]=make_pair(i,j);
			 }
		}
		int i=2;
		int sum=0;
		pair<int,int> temp=mp[1];
		while(i<=n*n)
		{
			
			pair<int,int> temp2=mp[i];
			sum+=abs(temp.first-temp2.first)+abs(temp.second-temp2.second);
			temp=temp2;
			i++;
		}
		printf("%d\n",sum);

	}
}