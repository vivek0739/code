#include<bits/stdc++.h>
using namespace std;
vector<bool> hash1 (1000000001,false);
int main()
{
	int k;
	long long int n;
	scanf("%lld%d",&n,&k);
	int arr[k];
	for(int i=0;i<k;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<k;i++)
	{
		for(int j=arr[i];j<=n;j+=arr[i])
			hash1[j]=true;
	}
	int count=0;
	for(int i=1;i<=n;i++)
		if(hash1[i]==false)
			count++;
	printf("%d\n",(count*100/(int)n) );
	return 0;	
}