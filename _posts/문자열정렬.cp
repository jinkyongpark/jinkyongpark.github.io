#include <stdio.h>
#include <string.h>
int main() {

  //Please Enter Your Code Here
  int n;
  char str[101][101];
  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
    scanf("%s",str[i]);
  
  for(int i=0;i<n;i++)
  {
    for(int j=i;j>=1;j--)
    {
      if(strcmp(str[j],str[j-1])<0)
      {
        char tmp[101];
        strcpy(tmp,str[j]);
        strcpy(str[j],str[j-1]);
        strcpy(str[j-1],tmp);
        
      }
      else 
        break;
    }
  }
  
  for(int i=0;i<n;i++)
    printf("%s\n",str[i]);
  
  return 0;
}