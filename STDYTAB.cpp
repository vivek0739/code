#include<bits/stdc++.h>
using namespace std;
#define mod 1000000000
long long int dp[2005][2005];
long long int comb[4010][4010];
void combination()
{
	comb[0][0]=1;
	for(int i=1;i<4010;i++)
	{
		comb[i][0]=1;
		
	}
	for(int i=1;i<4010;i++)
	{
		comb[i][1]=i;
		
	}
	for(int i=1;i<4010;i++)
		comb[i][i]=1;
	for(int n=1;n<4010;n++)
	{
		for(int r=2;r<=n;r++)
		{
		 comb[n][r]=(comb[n-1][r-1]+comb[n-1][r])%mod;
		}
	}
}
void sol(int n,int m)
{
	int result=0;
	for(int i=1;i<=n;i++)
	dp[0][i]=1;
	
	for(int i=1;i<=m;i++)
	{
		dp[i][1]=(comb[i+m-1][m-1]+dp[i-1][1])%mod;
		
	}
	
	
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		{
			dp[i][j]=((dp[i][j-1]*comb[i+m-1][m-1])%mod+dp[i-1][j])%mod;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	combination();
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		sol(n,m);
		printf("%lld\n",dp[m][n]);

	}
}