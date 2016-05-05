#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
void sum1(int s1,int s2,int s3,int i,int arr[],int n)
{
	//cout<<arr[i]<<endl;
	if(i>=n)
	{
		
		ans=min(ans,max(s1,max(s2,s3)));

		return;
	}
	sum1(s1+arr[i],s2,s3,i+1,arr,n);
	sum1(s1,s2+arr[i],s3,i+1,arr,n);
	sum1(s1,s2,s3+arr[i],i+1,arr,n);
	
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
  
    ans=INT_MAX;
    sum1(0,0,0,0,arr,n);
    cout<<ans<<endl;
    return 0;
}