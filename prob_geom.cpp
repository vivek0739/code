#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b) swap(a,b);
    //cout<<a<<b<<endl;
    int ans=0;
    if(a+b<=c)
    {
        ans=2*a*b;
    }
    else if(a<c && b<c)
    {
        ans=a*b*2;
        ans-=(b+a-c)*(b+a-c);
    }
    
    else if(a<c && b>c)
    {
    	ans=c*c;
        cout<<ans<<endl;
    	ans-=(c-a)*(c-a);
    }
    else 
    {
    	ans=c*c;
    }
    
    int total_area=2*a*b;
    int d=gcd(ans,total_area);
	cout<<ans/d<<"/"<<total_area/d<<endl;
    return 0;
}
