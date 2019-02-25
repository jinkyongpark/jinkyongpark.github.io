#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int n,arr[46];
  scanf("%d",&n);
  
  arr[0]=0,arr[1]=1;
  for(int i=2;i<=n;i++)
  {
    arr[i] =arr[i-1]+arr[i-2];
  }
  
  printf("%d",arr[n]);
  return 0;
}