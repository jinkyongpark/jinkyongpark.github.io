//중복 피하기

#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int n;
  scanf("%d",&n);
  
  for(int i=1;i*i<=n;i++){
    if(n%i ==0) printf("%d %d ",i,n/i);
  }
  return 0;
}