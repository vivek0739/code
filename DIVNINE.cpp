#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		
		scanf("%s",s);
		long long int sum=0;
		for(int i=0;s[i]!='\0';i++)
		{
			sum+=s[i]-'0';
		}
		sum=sum%9;
		int sum1,sum2;
		sum1=sum2=sum;
		int n=strlen(s);
		int ans1=0;
		int ans2=0;
		for(int i=n-1;i>0;i--)
		{
			if(s[i]!='9')
			{
				sum1-=(9-s[i]);
			}
			if(sum1<0) break;

		}
		if(s[0]=='9' && sum1>0 )
		{
			for(int i=n-1;i>0;i--)
			{
				if(s[i]!='9')
				{
					sum2-=(s[i]);
				}
				if(sum2<0) break;

			}
		}
		if(sum<9-sum)
			printf("%lld\n",sum );
		else
			printf("%lld\n",9-sum);
	}
}
