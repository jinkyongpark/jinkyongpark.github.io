#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int n;
  scanf("%d",&n);
  bool flag=false;
  for(int i=2;i<=n-1;i++){  //n-1보다 루트 n이 더효율적?
    if(n%i==0){
      flag = true;
      break;
    }
  }
  if(flag) printf("No");
  else printf("Yes");
  return 0;
}



//에라토스테네스의체 a~b사이의 모든 걸 물어보는거면
// 특정 숫자를 물어보는건 위의 방법이빠름
//O(nlogn) -소수구하기치고 빠름

#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  bool prime[51];
  for(int i=2;i<51;i++)
  {
    prime[i]=true;
  }
  for(int i=2;i<51;i++)
  {
    if(!prime) continue;
    for(int j=2;i*j<51;j++)
      prime[i*j]=false;
	 //if(!prime[i*j]) continue; -중복피하기
  }
  
  for(int i=2;i<51;i++){
    if(prime[i]) 
    printf("%d ", i);
  }
  return 0;
}