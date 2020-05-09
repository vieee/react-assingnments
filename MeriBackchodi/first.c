#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);
    while(n--){
        int a,x=0,y=0;
        scanf("%d",&a);
        int i;
        char s[a];
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++){
            if(s[i]=='L'&&s[i-1]!='L'&&s[i-1]!='R'){
                x--;
            }
            else if(s[i]=='R'&&s[i-1]!='R'&&s[i-1]!='L'){
                x++;
            }
            else if(s[i]=='U'&&s[i-1]!='U'&&s[i-1]!='D'){
                y++;
            }
            else if(s[i]=='D'&&s[i-1]!='D'&&s[i-1]!='U'){
                y--;
            }
            else{
                continue;
            }
        }
        printf("%d %d\n",x,y);
    }
	// your code goes here
	return 0;
}
