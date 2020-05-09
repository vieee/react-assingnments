#include<stdio.h>
#include<string.h>
 
int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];
 
void printLCS(int i,int j)
{
                if(i==0 || j==0)
                                return;
                if(b[i][j]=='d')
                {
                                printLCS(i-1,j-1);
                                printf("%c",x[i-1]);
                }
                else if(b[i][j]=='u')
                                printLCS(i-1,j);
                else
                                printLCS(i,j-1);
}
 
void lcs()
{
                m=strlen(x);
                n=strlen(y);
                for(i=0;i<=m;i++)
                                c[i][0]=0;
                for(i=0;i<=n;i++)
                                c[0][i]=0;
                                
                //d -> diagonal entry
                //u -> upside entry
                //l -> leftside entry
                
                for(i=1;i<=m;i++)
                                for(j=1;j<=n;j++)
                                {
                                                if(x[i-1]==y[j-1])
                                                {
                                                                c[i][j]=c[i-1][j-1]+1;
                                                                b[i][j]='d';
                                                }
                                                else if(c[i-1][j]>=c[i][j-1])
                                                {
                                                                c[i][j]=c[i-1][j];
                                                                b[i][j]='u';
                                                }
                                                else
                                                {
                                                                c[i][j]=c[i][j-1];
                                                                b[i][j]='l';
                                                }
                                }
                                printf("The length of the Longest Common Subsequence is %d", c[m][n]);
                                
}
 
int main()
{
		printf("Implementing the LCS problem..\n");
                printf("Enter 1st sequence:");
                scanf("%s",x);
                printf("Enter 2nd sequence:");
                scanf("%s",y);
                lcs();
                printf("\nThe Longest Common Subsequence is ");
                printLCS(m,n);
		return 0;
}
