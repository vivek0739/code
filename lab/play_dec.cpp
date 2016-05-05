#include<stdio.h>
#include<string.h>
char Table[5][5]={{'L','G','D','B','A'},{'Q','M','H','E','C'},{'U','R','N','I','F'},{'X','V','S','O','K'},{'Z','Y','W','T','P'}};
void findTable(char p,int *a ,int *b)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(Table[i][j]==p)
            {
                *(a)=i;
                *(b)=j;
                return;
            }
        }
    }
}
void findcord(char *p,char *q,char a,char b)
{
    int i,j,r,s;
    findTable(a,&i,&j);
    findTable(b,&r,&s);
    int x,y,k,l;
    if(i==r)
    {
        x=i;
        y=j-1+5;
        y%=5;
        k=r;
        l=s-1+5;
        l%=5;
    }
    else if(j==s)
    {
        x=i-1+5;
        x%=5;
        y=j;
        k=r-1+5;
        k%=5;
        l=s;
    }
    else
    {
        x=i;
        y=s;
        k=r;
        l=j;
    }
    *(p)=Table[x][y];
    *(q)=Table[k][l];
}
int main()
{
    printf("Enter the plain text!n");
    char plaintext[1013];
    char ciphertext[102];
    scanf("%s",ciphertext);
    int n=strlen(ciphertext);
    char p,q;
    char a,b;
    int i;
    for(i=0;i<n;i++)
    {
        a=ciphertext[i++];
        if(i==n)
        {
            b='A';
        }
        else
        b=ciphertext[i];
        findcord(&p,&q,a,b);
        plaintext[i-1]=p;
        plaintext[i]=q;
    }
    plaintext[i]='';
    printf("Cipher text is %sn",plaintext);
}
