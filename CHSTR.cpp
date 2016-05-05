#include<bits/stdc++.h>
using namespace std;
map<string,int> ms;
map<char*,int> counta;
char str1[500005];
int arr[10000005];
int bin[1000005][]
void findAllSubstrings2(const char *s)
{
    while(*s)
    {
        int x=0;
        while(*(s + x))
        {
            int k=0;
            for(int y = 0; y <= x; y++)
                str1[k++]=*(s+y);
            str1[k]='\0';
            ms[str1]++;
            x++;
        }
        s++;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ms.clear();
        counta.clear();
        char str[50005];
        scanf("%s",str);
        int q;
        scanf("%d",&q);
        findAllSubstrings2(str);
        
        memset(arr,0,sizeof(arr));
        map<string,int>::iterator it;
        for(it=ms.begin();it!=ms.end();it++)
           arr[it->second]++;
       for(int i=1000005;i>0;i--)

       while(q--)
       {
            int k;
            scanf("%d",&k);
            printf("%d\n",arr[k]);
       }

    }
    return 0;
}