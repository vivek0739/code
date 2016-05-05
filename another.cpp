#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int W,int val[],int n)
    {
    int K[n+1][W+1];
    for(int i=0;i<=n;i++)
        {
        for(int j=0;j<=W;j++)
            {
            if(i==0||j==0)
                K[i][j]=0;
            else if(wt[i-1]<=j)
            {
                if(K[i-1][j-wt[i-1]]==0)
                    K[i][j]=val[i-1];
                else
                    K[i][j]=max(K[i-1][j],K[i-1][j-wt[i-1]]+val[i-1]);
            }
                
            else 
                K[i][j]=K[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
        {
        for(int j=0;j<=W;j++)
        {
            cout<<K[i][j];
        }
        cout<<endl;
    }
    return K[n][W];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    scanf("%d%d",&n,&m);
    int wt[n],val[n];
    for(int i=0;i<n;i++)
        {
        wt[i]=i+1;
        val[i]=-1;
    }
    cout<<abs(knapsack(wt,m,val,n))<<endl;
    return 0;
}
