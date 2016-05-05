#include<bits/stdc++.h>
int encrypt(int p,int ainv,int b)
{
	return (((ainv*(p-b+26)))%26);
}
using namespace std;
int hash[26];
int main()
{
	
	char c[101];
	char p[101];
	cin>>c;
	int a,b;
	cout<<"Enter the decription key";
	cin>>a>>b;
	int ainv;
	for(int i=0;i<26;i++)
	{
		if((i*a)%26==1)
		{
			ainv=i;
			break;
		}
	}
	
	int i=0;
	int n=strlen(c);


	
		for(i=0;i<n;i++ )
		{
			p[i]=encrypt(c[i]-'A',ainv,b)+'A';
		
		
		}
		p[i]='\0';
		cout<<p<<endl;

	
	
	
}
