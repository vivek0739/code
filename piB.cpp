#include<bits/stdc++.h>
using namespace std;
map< int,int > mp;
int main()
{
	int n;
	
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		
	
	mp.clear();
	int leaving=0,entering=0,maxnumber=0;;
	char op[2];
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",&op,&arr[i]);
		if(op[0]=='+')
		{
			entering++;
			mp[arr[i]]++;
			if((entering)>maxnumber)
				maxnumber=entering;
		}
		else
		{
			if(mp[arr[i]]!=1)
			{
				maxnumber++;
			}
			else
			{
				entering--;
				mp[arr[i]]--;
			}
		}
		
	}
	printf("%d\n",maxnumber);
	return 0;	
}