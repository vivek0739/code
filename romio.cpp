#include<bits/stdc++.h>
using namespace std;
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
bool isValid(int i,int j,vector<std::vector<char>> &A)
{
    int n=A.size();
    int  m=A[0].size();
    if(i<n&&j<m&&i>=0&&j>=0&&(A[i][j]=='d'||A[i][j]=='-')&&visited[i][j]==false)
      return true;
    return false;
}
void bfs(int i,int j,vector<std::vector<char>> &A,vector<vector<bool>> &visited,vector<vector<bool>> &dist)
{
    
    int n=A.size();
    int  m=A[0].size();
    if(!isValid(i,j,A)) return;
    visited[i][j]=true;
    
    for(int k=0;k<4;k++)
    {
        int x=i+dir[k][0];
        int y=j+dir[k][1];
        //cout<<x<<y<<endl;
        if(isValid(x,y,A,visited))
        {
            bfs(x,y,A,visited);
        }
    }
    
}
int main()
{
  
   while(1)
   {
        
        scanf("%d",&n);
        if(n==-1) break;
        scanf("%d",&m);
        vector<std::vector<char> > vec(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
          {
            cin>>vec[i][j];
            
            
          }
        }
        
        vector<vector<bool> > visited(n,vector<bool> (m,false));
        vector<vector<int> > dist(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            int j;
          for(j=0;j<m;j++)
          {
            if(vec[i][j]=='s')
            {
                //cout<<i<<j<<endl;
                path =bfs(i,j,vec,visited,dist);
                break;
            }
          }
          if(j!=m) break;
        }
        
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            cout<<vec[i][j]<<" ";
          }
          cout<<endl;
        }
        
   }
    
    
    
    
      return 0; 
}