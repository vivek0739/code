#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<long long int> vec;
	for(int i=0;i<n;i++)
	{
		long long int x;
		scanf("%lld",&x);
		vec.push_back(x);
	}
	sort(vec.rbegin(),vec.rend());
	long long int max=vec[0];

	long long sig=1;
	while(sig<=max)
	{
	 sig<<=1;
	}
	sig>>=1;
	for(int t=0;sig>=1;sig>>=1)
	{
		int i=t;
		while(i<n && (vec[i]&sig)==0)
		{
			i++;
		}
		if(i>=n) continue;
		swap(vec[t],vec[i]);
		for(int j=0;j<n;j++)
		{
			if(j!=t && (vec[j]&sig)!=0)
			{
				vec[j]=vec[j]^vec[t];
			}
		}
		t++;
	}
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		ans^=vec[i];
	}
	printf("%lld\n",ans);
}