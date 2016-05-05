#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int keyTable[3][3]={{3,5,7},{9,11,15},{17,19,21}};
int main()
{
    int j;
    printf("Enter the plain text\n");
    char plaintext[101];
    char ciphertext[102];
    scanf("%s",plaintext);
    int n=strlen(plaintext);
    int *sol[3];
    int *result[3];
    int m=n/3+(n%3!=0);
    char p,q;
    char a,b;
    int i;
    int temp;
    for(i=0;i<3;i++)
    sol[i]=(int*)malloc(m*sizeof(int));
    for(i=0;i<3;i++)
    result[i]=(int*)malloc(m*sizeof(int));
    int k=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<m;j++)
        {
            if(k<n)
            {
                sol[i][j]=plaintext[k]-'A';
                k++;
            }
            else
            {
                sol[i][j]=2;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<m;j++)
        {
            int ans=0;
            for(k=0;k<3;k++)
            {
                ans+=keyTable[i][k]*sol[k][j];
            }
            ans%=26;
            result[i][j]=ans;
        }
    }
    k=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<m;j++)
        {
            ciphertext[k++]=result[i][j]+'A';
            if(k>=n)
            break;
        }
        if(k>=n)
        break;
    }
    ciphertext[k]='\0';
    printf("Cipher text is %s\n",ciphertext);
}
