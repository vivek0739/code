#include<bits/stdc++.h>
using namespace std;

int main()
{
	int na,nb,k,m;
	cin>>na>>nb>>k>>m;
	int A[na];
	for(int i=0;i<na;i++)
	{
		cin>>A[i];
	}
	int B[nb];
	for(int i=0;i<nb;i++)
		cin>>B[i];
	int greatest=INT_MIN;
	int smallest=INT_MAX;
	for(int i=0;i<na&&i<k;i++)
		greatest=max(greatest,A[i]);
	for(int i=0;i<nb&&i<m;i++)
		smallest=min(smallest,B[nb-i-1]);
	if(greatest<smallest)
		cout<<"YES"<<endl;
	else
	  cout<<"NO"<<endl;
	return 0;	
}