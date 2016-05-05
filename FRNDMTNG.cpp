#include<bits/stdc++.h>
using namespace std;
int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
			double T1,T2,t1,t2;
			scanf("%lf%lf%lf%lf",&T1,&T2,&t1,&t2);
			double ans1,ans2,ans3,ans4;
			ans1=0.0,ans2=0.0,ans3=0.0,ans4=0.0;
			double temp1=(T2-t1);
			ans1=0.500000*(temp1*temp1);
			if(t1>T2)
			{
				ans2=0.500000*(T2-T1-t1)*(T2-T1-t1);
				
			}
			temp1=(T1-t2);
			ans3=0.500000*(temp1*temp1);
			if(t2>T1)
			{
				ans4=0.500000*(T1-T2-t2)*(T1-T2-t2);
				
			}
			double ans=1-(double)(ans1+ans3-ans2-ans4)/(double)(T1*T2);
			
			
			printf("%.6lf\n",ans);
		}
		return 0;
}