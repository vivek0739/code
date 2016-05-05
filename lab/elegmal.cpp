#include<bits/stdc++.h>
using namespace std;

int modPower(int a, int p, int n)
{
        int ans = 1;
        while(p)
        {
                if(p&1)
                        ans = (ans*a)%n;
                a = (a*a)%n;
                p = p/2;
        }
        return ans;
}

int primitive(int n)
{
        for(int a=2;a<n; a++)
        {
                int count = 0;
                for(int i=1; i<n; i++)
                {
                        if(modPower(a, i, n)==1)
                                count++;
                }
                if(count==1)
                        return a;
        }
}


int main()
{
        int p;
        cin>>p;
        int e1 = primitive(p);
        srand(time(NULL));
        int d;
        while(1)
        {
                d = rand()%p;
                if(d>0 && d<p-1)
                        break;
        }

        int e2 = modPower(e1, d, p);

        int r = rand()%p;
        int c1 = modPower(e1, r, p);
        int msg;
        cin>>msg;
        int z = modPower(e2, r, p);
        int c2 = (msg*z)%p;
        cout<<"Encrypttion: ";
        cout<<c1<<" "<<c2<<endl;
        cout<<"Decryption: ";
        int cr = modPower(c1, d, p);
        int cz = 1;
        while(1)
        {
                if((cz*cr-1)%p==0)
                        break;
                cz++;
        }
        int msz = c2*cz%p;
        cout<<msz<<endl;
        return 0;
}
