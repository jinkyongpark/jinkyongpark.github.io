#include <stdio.h>

void selection(int *data)
{
 for(int i=0;i<n;i++){
    //i번째부터 맨 끝까지의 값중 최솟값
    int inx=i;
    for(int j=i+1;j<n;j++)
    {
      if(data[inx]>data[j])
      {
        inx =j;
      }
    }
    int tmp =data[i];
    data[i]=data[inx];
    data[inx]=tmp;
  }
  for(int i=0;i<n;i++){
    printf("%d ",data[i]);
  }
}
void insert(int *data)
{
	for(int i=0;i<n;i++)
  {
    for(int j=i; j>=1;j--)
    {
      if(data[j-1] >data[j]){
        int tmp =data[j-1];
        data[j-1]=data[j];
        data[j]=tmp;
      }
      else break;
    }
  }
  for(int i=0;i<n;i++){
    printf("%d ",data[i]);
  }
}
void bubble(int *data)
{
	    
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n-i-1;j++){
     if(data[j]>data[j+1]){
        int tmp =data[j];
        data[j]=data[j+1];
        data[j+1]=tmp;
     }
   }
  }
  for(int i=0;i<n;i++){
    printf("%d ",data[i]);
  }
}
int main() {

  //Please Enter Your Code Here
  int n;
  int data[100];
  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
    scanf("%d",&data[i]);
    
 
  return 0;
}






