#include <bits/stdc++.h>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int good[86401],bad[86401];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void compute()
{
    int moment=86400;
    for(int h=23;h>=0;h--)
    {
        for(int m=59;m>=0;m--)
        {
            for(int s=59;s>=0;s--)
            {
                moment--;
                if(h==0 && m==0 && s!=1||h==0 && m!=1 && s==0||h!=1 && m==0 && s==0)
                {
                    bad[moment]=bad[moment+1]+1;
                    good[moment]=good[moment+1];
                }
                else if(gcd(h,gcd(m,s))==1)
                {
                    bad[moment]=bad[moment+1];
                    good[moment]=good[moment+1]+1;
                }
                else
                {
                     bad[moment]=bad[moment+1]+1;
                     good[moment]=good[moment+1];
                }
            }
        }
    }
}
int main()
{
    compute();
    int t;
    cin>>t;
    while(t--)
    {
        int h,m,s;
        cin>>h>>m>>s;
        
        int moment=h*3600+m*60+s;
        if(good[moment]==0||bad[moment]==0)
             cout<<bad[moment]<<":"<<good[moment]<<endl;
        else
        {
            int g=gcd(good[moment],bad[moment]);
            cout<<bad[moment]/g<<":"<<good[moment]/g<<endl;
        }
    }
    
   
    return 0;
}