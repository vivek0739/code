#include<bits/stdc++.h>
using namespace std;
char l1[1000005],l2[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	bool t1,t2,t3,t4;
	t1=t2=t3=t4=true;
	int ans=0;
	while(t--)
	{	ans=0;
		scanf("%s%s",l1,l2);
		int n=strlen(l1);
		int dp[n+1][2];
		for(int i=0;i<=n;i++)
		{
			dp[i][0]=INT_MAX-5;
			dp[i][1]=INT_MAX-5;
		}
		dp[n][0]=0;
		dp[n][1]=0;
		if(l1[n-1]!='#') dp[n-1][0]=0;
		if(l2[n-1]!='#') dp[n-1][1]=0;
		//
		for(int i=n-2;i>=0;i--)
		{

			if(l1[i]!='#')
			{
				dp[i][0]=min(dp[i+1][0],dp[i+1][1]+1);
			}
			if(l2[i]!='#')
			{
				dp[i][1]=min(dp[i+1][1],dp[i+1][0]+1);
			}
			//printf("Yes\n %d\n",dp[i][0]);
		}

		ans=min(dp[0][0],dp[0][1]);
		
		if(dp[0][0]!=INT_MAX-5||dp[0][1]!=INT_MAX-5)
			printf("Yes\n %d\n",ans);
		else
			printf("No\n");
	}
	return 0;	
}