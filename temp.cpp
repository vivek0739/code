#include<bits/stdc++.h>
using namespace std;
char binary[100005];
int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
			int n,k;
			scanf("%d%d",&n,&k);
			
			scanf("%s",binary);
			
			if(k==1)
			{
				
				int no_of_flip=0;
				char str1[n+1];
				strcpy(str1,binary);
				//cout<<binary[0]<<endl;
				for(int i=0;i<n;i+=2)
				{
					//cout<<flag<<endl;
					if(str1[i]=='0')
					{
						
							str1[i]='1'+'0'-str1[i];
							no_of_flip++;
							
					}
					if(str1[i+1]=='1')
					{
						str1[i+1]='1'+'0'-str1[i+1];
						no_of_flip++;
							
					}
					
				}
				char str2[n+1];
				strcpy(str2,binary);
				int no_of_flipr=0;
				for(int i=0;i<n;i+=2)
				{
					if(str2[i]=='1')
					{
						
							str2[i]='1'+'0'-str2[i];
							no_of_flipr++;
							
					}
					if(str2[i+1]=='0')
					{
						str2[i+1]='1'+'0'-str2[i+1];
						no_of_flipr++;
							
					}
					
				}
				if(no_of_flipr>=no_of_flip)
					printf("%d\n%s\n",no_of_flip,str1);
				else
					printf("%d\n%s\n",no_of_flipr,str2);
			}
			else
			{
				char str1[n+1];
				strcpy(str1,binary);
				
				int no_of_flip=0;
				for(int i=0; i<n; i++)
				{
					//cout<<str1<<endl<<i<<endl;
					int flag=0,j;
					for(j=1;j<=k && i+j<n; j++)
					{
						if(str1[i]==str1[i+j])
						{
							flag++;
							
						}
						else
						{
							
							break;
						}
					}
					if(flag==k)
					{
						flag=0;
						for(j=1;j<=k && i+j+k<n;j++)
						{
							if(str1[i+k]==str1[i+k+j])
							{
								flag++;
								
							}
							else
							{
								
								break;
							}
						}
						no_of_flip++;
						
						if(flag==k)
						{
							str1[i+k]='1'+'0'-str1[i+k];
							
						}
						else
						{
							str1[i+k-1]='1'+'0'-str1[i+k-1];
						}
						i+=(k-1);
					}
				}
				//cout<<no_of_flip<<endl;
				
				
					printf("%d\n%s\n",no_of_flip,str1);
				
			}
		}
		return 0;
}