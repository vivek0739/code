#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	string str;
	cin>>str;
	while(m--)
	{
		int a;
		char p[2];
		int count=0;
		scanf("%d%s",&a,p);
		str[a-1]=p[0];
		int prev=-5;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='.')
			{
				if(prev==i-1)
				{
					
					count++;
				}
				
				prev=i;
			}
			
			

		}
		printf("%d\n",count);
	}
	
	return 0;	
}