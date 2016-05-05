#include<bits/stdc++.h>
using namespace std;
const int mod = 26;
int hash[26];

void decrypt(string str, int a, int b)
{
        int i=0, x=1;
        int len = str.size();
        while(1)
        {
                if((x*a-1)%(mod-1)==0)
                        break;
                x++;
        }
        for(i=0; i<len; i++)
        {
                int ch = (x*(str[i]-'A'-b))%mod;
                if(ch <0)
                        ch += mod;
                char chr = 'A'+ch;
                cout<<chr;
        }
        cout<<endl;
}

int main()
{
        string cipr;
        cin>>cipr;
        int a, b;
        cin>>a>>b;
        decrypt(cipr, a, b);
        return 0;
}
