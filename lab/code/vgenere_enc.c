#include<stdio.h>
#include<string.h>
int key[5]={15,0,18,2,11};
int main()
{
    int j;
    printf("Enter the plain text\n");
    char plaintext[101];
    char ciphertext[102];
    scanf("%s",plaintext);
    int n=strlen(plaintext);
    char p,q;
    char a,b;
    int i;
    int temp;
    for(i=0;i<n;)
    {
        
        for(j=0;j<5;j++)
        {
            temp=plaintext[i]-'A'+key[j];
            temp%=26;
            ciphertext[i]=temp+'A';
            i++;
            if(i>=n) break;
        }
    }
    ciphertext[i]='\0';
    printf("Cipher text is %s\n",ciphertext);
}
