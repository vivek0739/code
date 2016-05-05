#include<stdio.h>
#include<string.h>
int key[5]={15,0,18,2,11};
int main()
{
    int j;
    printf("Enter the cypher text!n");
    char plaintext[102];
    char ciphertext[102];
    scanf("%s",ciphertext);
    int n=strlen(ciphertext);
    char p,q;
    char a,b;
    int i;
    int temp;
    for(i=0;i<n;)
    {
        for(j=0;j<5;j++)
        {
            temp=ciphertext[i]-'A'-key[j]+26;
            temp%=26;
            plaintext[i]=temp+'A';
            i++;
            if(i>=n) break;
        }
    }
    plaintext[i]='';
    printf("Plain text is %sn",plaintext);
}
