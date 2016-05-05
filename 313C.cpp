#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	

	int x=2*a1+1;
	int sum=0;
	int p=x;
	for(int i=0;i<a2;i++)
	{
		sum+=(p);
		p+=2;
	}
		
	for(int i=a3;i>0;i--)
	{
		p-=2;	
		sum+=(p);
		
	}
	cout<<sum<<endl;
	return 0;
}