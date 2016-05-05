#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char s[105];
	while(t--)
	{
		
		scanf("%s",s);
		int n=strlen(s);
		int i;
		int chef,opps;
		chef=0;
		opps=0;
		for(i=0;i<n;i++)
		{
		 	if(s[i]=='0')
		 	opps++;
		 	else
		 	chef++;
		 	if(chef==10 && opps==10)
		 	{
		 		break;
		 	}
		 	else if(chef==11||opps==11)
		 	{
		 		break;
		 	}
		}
		if(chef==10 && opps==10)
		{
		
				chef=0;
				opps=0;
				for(;i<n;i++)
				{
					if(s[i]=='0')
		 				opps++;
		 			else
		 				chef++;
		 			if(chef==2 && opps==1 || chef==1 && opps==2 )
		 			{
		 				chef=0;
						opps=0;
		 			}
		 			else if(chef==2 &&  opps==0 ||chef==0 &&  opps==2 )
		 			{
		 				break;
		 			}
				}
				if(chef==2 &&  opps==0)
				{
					printf("WIN\n");
					continue;
				}
				else if(chef==0 &&  opps==2)
				{
					printf("LOSE\n");
					continue;
				}
			
		}
		else if(chef == 11)
				{
					printf("WIN\n");
					continue;
				}
		else if(opps== 11)
				{
					printf("LOSE\n");
					continue;
				}
	}
}
