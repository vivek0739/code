#include<bits/stdc++.h>
int encrypt(int p)
{
	return (2*p+3)%26;
}
using namespace std;
int main()
{
	
	char c[101];
	char p[101];
	cin>>p;
	int i=0;
	for(i=0;p[i]!='\0';i++ )
	{
		c[i]=encrypt(p[i]-'A');
		c[i]+='A';
		
	}
	c[i]='\0';
	cout<<c<<endl;
	
	
}
