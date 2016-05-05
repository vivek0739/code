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

bool isVerify(int e1, int e2, int s1, int s2, int msg, int p)
{
        int res = modPower(e2, s1, p);
        int v2 = (res*modPower(s1, s2, p))%p;
        int v1 = modPower(e1, msg, p);
        if(v1==v2)
                return true;
        return false;
}

int main()
{
        int p;
        cin>>p;
        int e1 = primitive(p);
        int msg;
        cin>>msg;
        srand(time(NULL));
        int r = 307; //rand()%p;
        int d = 127;
/*
        while(1)
        {
                d = rand()%p;
                if(d>0 && d<p-1)
                        break;
        }
*/
        int e2 = modPower(e1, d, p);
        int s1 = modPower(e1, r, p);
        cout<<s1<<endl;

        int s2 = (msg-d*s1);
        int inv = 1;
        while(1)
        {
                if((inv*r-1)%(p-1)==0)
                        break;
                inv++;
        }

        s2 = (s2*inv)%(p-1);
        if(s2<0)
                s2+=(p-1);
        cout<<s2<<endl;
        if(isVerify(e1, e2, s1, s2, msg, p))
                cout<<"Verified"<<endl;
        else
                cout<<"Not Verified"<<endl;
        return 0;
}
