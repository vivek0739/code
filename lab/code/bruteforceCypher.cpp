#include<bits/stdc++.h>
int encrypt(int p,int b)
{
	return ((p-b+26)%26);
}
using namespace std;
int hash[26];
int main()
{
	
	char c[101];
	char p[101];
	cin>>p;
	
	int i=0;
	int n=strlen(p);

	for(i=0;i<n;i++ )
	{
		hash[p[i]-'A']++;
		
	}
	int maxindex=0;
	int max=0;
	for(int i=0;i<26;i++ )
	{
		if(hash[i]>max)
		{
			max=hash[i];
			maxindex=i;
		}
		
	}
	
	int b;
	for(int J=0;J<26;J++)
	{
		b=(maxindex-J)%26;	
		for(i=0;i<n;i++ )
		{
			c[i]=encrypt(p[i]-'A',b)+'A';
		
		
		}
		c[i]='\0';
		cout<<(char)(J+'A')<<" "<<c<<endl;
	}
	
	
	
}
