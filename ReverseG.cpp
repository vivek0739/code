#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int f,b,T,d;
	int ans=0;
	while(t--)
	{	ans=0;
		scanf("%d%d%d%d",&f,&b,&T,&d);
		while(d>b)
		{
			d-=(b-f);
			ans+=(b+f);
		}
		ans+=d;
		ans*=T;
		
		if(t!=0)
			printf("%d\n",ans );
		else
			printf("%d",ans );
	}
	return 0;	
}