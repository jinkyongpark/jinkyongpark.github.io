//재귀

#include <stdio.h>
int binarySearch(int arr[],int start,int end, int value){
  //arr의 start부터 end까지 값들 중에서 value가존재하면 위치반환
  //없으면 -1반환
  if(start>end) return -1;
  else if(start==end){
    if(value==arr[start]) return start;
    else return -1;
  }
  else{
    int mid =(start+end)/2;
    if (arr[mid]==value) return mid;
    else if(arr[mid]>value) return binarySearch(arr, start,mid-1,value);
    else return binarySearch(arr,mid+1,end,value);
  }
}
int main() {

  //Please Enter Your Code Here
  int n, m;
  int arr[100];
  scanf("%d",&n);
  for (int i=0;i<n;i++) scanf("%d",&arr[i]);
  //arr은 정렬이 되어있어야함
  scanf("%d",&m);
  
  int idx= binarySearch(arr, 0,n-1,m);
  if(idx == -1) printf("수 없음");
  else printf("%d번째에 있다.",idx);
  return 0;
}


//비재귀
#include <stdio.h>
int binarySearch(int arr[],int myStart, int myEnd, int value){
  int start,end;
  int mid;
  //start는 value보다 항상작은값
  //end는 value보다 항상 큰 값
  if(arr[myStart]>value) return -1;
  if(arr[myStart]==value) return myStart;
  
  if(arr[myEnd]<value) return -1;
  if(arr[myEnd]==value) return myEnd;
  start = myStart;
  end = myEnd;
  
  while(start+1 <end){
    mid = (start+end)/2;
    
    if(arr[mid]==value) return mid;
    else if(arr[mid]>value) end = mid;
    else start = mid;
  }
  
  //start ? end 이렇게 붙을때까지 돔.
  //다돌아도 없음
  return -1;
}
int main() {

  //Please Enter Your Code Here
  //Please Enter Your Code Here
  int n, m;
  int arr[100];
  scanf("%d",&n);
  for (int i=0;i<n;i++) scanf("%d",&arr[i]);
  //arr은 정렬이 되어있어야함
  scanf("%d",&m);
  
  int idx= binarySearch(arr, 0,n-1,m);
  if(idx == -1) printf("수 없음");
  else printf("%d번째에 있다.",idx);
  return 0;
}