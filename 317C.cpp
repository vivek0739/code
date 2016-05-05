#include<bits/stdc++.h>
using namespace std;
int isValid(int a,int b,int c)
{

	if(a<b+c && b<a+c && c<a+b)
	{
		cout<<a<<b<<c<<endl;
		return 1;
	}
		 
    return 0;

}

void bruteforcer(int a,int b,int c,int n,int& count)
{
	if(n==-1)
		return;
	count+=isValid(a,b,c);
	bruteforcer(a,b+1,c,n-1,count);
	bruteforcer(a+1,b,c,n-1,count);
	
	
	bruteforcer(a,b,c+1,n-1,count);
}
int main()
{
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	int count=0;
	bruteforcer(a,b,c,n,count);
	cout<<count<<endl;
	return 0;
}