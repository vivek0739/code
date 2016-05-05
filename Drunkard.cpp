#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int FM,BM,T,FBS,BBS;
	char type[2];
	int ans=0;
	while(t--)
	{	ans=0;
		scanf("%s%d%d%d%d%d",type,&FM,&BM,&T,&FBS,&BBS);
		if(FM==BM)
		{
			if(FM<FBS && BM<BBS)
			{
				printf("Hurray\n");
				continue;
			}
		}
		int count=0;
		int dist=0;;
			if(type[0]=='B')
			{
				if(dist-BM<=-1*BBS)
					{
						count+=abs(dist-BBS);
						if(t!=0)
							printf("%d B\n",count*T );
						else
							printf("%d B",count*T );
						continue;
					}
				int speed=(FM-BM);
				if(speed>0)
				{
					
					count=FBS/speed*(BM+FM);
					if(FBS%speed!=0)
						count+=(BM+BM+FBS%speed);
					if(t!=0)
							printf("%d F\n",count*T );
						else
							printf("%d F",count*T );
						continue;
				}
				else if(speed<0)
				{
					BBS+=(speed);
					count+=BM;
					speed*=-1;
					count=BBS/speed*(BM+FM);
					if(BBS%speed!=0)
						count+=(FM+FM+BBS%speed);
					if(t!=0)
							printf("%d B\n",count*T );
						else
							printf("%d B",count*T );
						continue;
				}
				else
				{
					printf("Hurray\n");
					continue;
				}
				
			}
			else
			{
				if(dist+FM>=FBS)
					{
						count+=abs(dist-FBS);
						if(t!=0)
							printf("%d F\n",count*T );
						else
							printf("%d F",count*T );
						continue;
					}
				int speed=(FM-BM);
				if(speed>0)
				{
					FBS-=speed;
					count+=FM;
					count=FBS/speed*(BM+FM);
					if(FBS%speed!=0)
						count+=(BM+BM+FBS%speed);
					if(t!=0)
							printf("%d F\n",count*T );
						else
							printf("%d F",count*T );
						continue;
				}
				else if(speed<0)
				{
					speed*=-1;
					count=BBS/speed*(BM+FM);
					if(BBS%speed!=0)
						count+=(FM+FM+BBS%speed);
					if(t!=0)
							printf("%d B\n",count*T );
						else
							printf("%d B",count*T );
						continue;
				}
				else
				{
					printf("Hurray\n");
					continue;
				}
				
			}

		
		
	}
	return 0;	
}