#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int n;
  scanf("%d",&n);
  
  for(int i=2;n!=1;)
  {
    if(n%i==0)
    {
      printf("%d ",i);
      n=n/i;
    }
    else 
      i++;
  }
  return 0;
}