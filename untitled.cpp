#include<bits/stdc++.h>
using namespace std;
int dx[8] = {1, -1, 0, 0,1,1,-1,-1};
int dy[8] = {0, 0, 1, -1,1,-1,1,-1};
int n,m;
bool is_valid(int x, int y) {
        if(x < 0 || x >= n|| y < 0 || y >= m)
                return false;
        return true;
    }
list<pair<int,int> > bfs(int i, int j, vector<std::vector<char> >Vec) {
        queue<pair<int, int> > Que;
        map<pair<int,int>, list<pair<int,int> > > path;
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        Que.push(make_pair(i, j));
        path[make_pair(i,j)].push_back(make_pair(i,j));
        visited[i][j]=true;
        while(!Que.empty()) {
            pair<int, int> P = Que.front();
            Que.pop();
            visited[P.first][P.second]=true;
            //cout<<P.first<<P.second<<endl;
            for(int i = 0; i < 8; ++i) {
                int x = P.first + dx[i];
                int y = P.second + dy[i];
                
                if(is_valid(x, y) && (Vec[x][y] == '-' || Vec[x][y] == 'd') && !visited[x][y]) 
                {
                    pair<int,int> temp=make_pair(x,y);
                    if( path.find(temp)==path.end())
                    {
                        path[temp]=path[P];
                        path[temp].push_back(temp);
                    }
                    if(Vec[x][y]=='d')
                    {
                        //cout<<"vivek"<<endl;
                        return path[temp];
                    }
                    else
                    Que.push(make_pair(x, y));

                }
            }
        }
        return path[make_pair(i,j)];    
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
        for(int i=0;i<n;i++)
        {
          
        }
        list<pair<int,int> > path;
        for(int i=0;i<n;i++)
        {
            int j;
          for(j=0;j<m;j++)
          {
            if(vec[i][j]=='s')
            {
                //cout<<i<<j<<endl;
                path =bfs(i,j,vec);
                break;
            }
          }
          if(j!=m) break;
        }
        list<pair<int,int> > ::iterator it;
        for(it=path.begin();it!=path.end();++it)
        {
            //cout<<"check"<<endl;
            if(vec[it->first][it->second]!='d')
            vec[it->first][it->second]='a';
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