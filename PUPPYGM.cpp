#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int ans;
		if(n%2==1 && k%2==1)
			ans=1;
		else
			ans=0;
		if(ans==0)
		printf("Tuzik\n");
		else
		printf("Vanka\n");	
	}
	return 0;
}