#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int dif = abs(n-m);
		if(dif >= k)
			printf("%d\n",dif-k);
		else
			printf("0\n");
	}
	return 0;
}