#include<bits/stdc++.h>
using namespace std;
# define M_PI    3.14159265358979323846
int main()
{
	int t;
	scanf("%d",&t);
	double x,m;
	int ans=0;
	while(t--)
	{	ans=0;
		scanf("%lf%lf",&x,&m);
		double r=x*0.5;
		r=(r*r+m*m);
		if(m==0)
		{

			printf("%lf\n",0.5*r*M_PI);
			continue;
		}
		

		double areasector=atan(x/(2.0*m))*r;
			
		double remain=areasector-0.5*(double)(x*m);
	
			printf("%lf\n",remain );
		
	}
	return 0;	
}