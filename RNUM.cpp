#include<bits/stdc++.h>
using namespace std;
int hash[1000005];
int hashm[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a;
		
		memset(hash,0,sizeof(hash));
		memset(hashm,0,sizeof(hash));
		int mx_a=0,mn_a=INT_MAX;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			hash[a]++;
			hashm[a]++;
			mx_a=max(a,mx_a);
			mn_a=min(a,mn_a);
		}
		//cout<<mn_a<<mx_a<<endl;
		int mx=0,mn=0;
		int count=0;
		for(int i=mn_a;i<=mx_a;i++)
		{
			if(hash[i]==1 && hash[i+1]==1 && hash[i+2] == 1)
			{
				count++;
				hash[i]=0;
				hash[i+1]=0;
				hash[i+2]=0;
			}
		}
		for(int i=mn_a;i<=mx_a;i++)
		{
			if(hash[i]==1 && hash[i+1]==1)
			{
				count++;
				hash[i]=0;
				hash[i+1]=0;
				
			}
		}
		for(int i=mn_a;i<=mx_a;i++)
		{
			if(hash[i]==1)
			{
				count++;
				hash[i]=0;
				
				
			}
		}
		//cout<<mn_midl<<mn_midr;
			for(int i=mn_a;i<=mx_a;i++)
		{
			if(hashm[i]==1 && hashm[i+1]==1)
			{
				mx++;
				hashm[i]=0;
				hashm[i+1]=0;
				
			}
		}
		for(int i=mn_a;i<=mx_a;i++)
		{
			if(hashm[i]==1)
			{
				mx++;
				hashm[i]=0;
				
				
			}
		}
		printf("%d %d\n",count,mx);
	}
	return 0;
}