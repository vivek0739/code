#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int time1;
		double p;
		scanf("%d%lf",&time1,&p);
		int tm=0;
		double pd=1;
		while(pd>0.5 && tm<time1-1)
		{
			pd*=p;
			tm++;
		}
		double p1=(double)(1000000000.0)*pd;
		double p2=(double)(1000000000.0)-p1;
		printf("%.1lf %.1lf\n",p1,p2);
	}
}