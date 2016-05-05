#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k,m;
	cin>>k>>n>>m;
	int s[m];
	int mi=0;
	for(int i=0;i<m;i++)
	{
		cin>>s[i];
		mi=max(s[i],mi);

	}
	int dp[m+1][n+mi];
	
	memset(dp,-1,sizeof(dp));
	dp[0][k]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n+mi-1;j++)
		{
			if(j==0)
			{
				
				for(int l=1;l<=s[i-1];l++)
				{
					//if(i==4) cout<<dp[i-1][l];
					if(dp[i-1][l]!=-1)
					dp[i][j]=max(dp[i][j],dp[i-1][l]);
				}
				
			}
			else
			{

				if(j>n && j-s[i-1]>=0 && j-s[i-1] < n)
				{
					dp[i][j]=dp[i-1][j-s[i-1]]+1;
				}
				
				if(j-s[i-1]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-s[i-1]]);

				if(j<n && j+s[i-1]<n+mi && j+s[i-1] >n)
				{
					dp[i][j]=dp[i-1][j+s[i-1]]+1;
					
				}

				if(j+s[i-1]<n+mi) dp[i][j]=max(dp[i][j],dp[i-1][j+s[i-1]]);


			}
			
			cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}
	int ans=0;
	for(int j=0;j<=n+mi-1;j++)
		ans=max(ans,dp[m][j]);
	cout<<ans<<endl;
	return 0;
	
	
}