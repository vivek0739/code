#include<bits/stdc++.h>
using namespace std;
char b[55][55];
int n,m;
int ans=0;
map<char,int> ms;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%s",b[i]);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			ms[b[i][j]]=1;
			if(ms['f']==1 && ms['a']==1 && ms['c']==1 && ms['e']==1 )
				ans++;
			cout<<i<<j<<ans<<endl;
		}
	
	printf("%d\n",ans);
	return 0;
}