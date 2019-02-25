#include <stdio.h>
void merging(int arr[],int s1, int e1, int s2, int e2 ){
  //둘을 합쳐서 arr의 s1~e2를 정렬된 결과로 만드는 함수
  //2개의 포인터p는 왼쪽절반의 포인터 q는 오른쪽절반의 포인터
  //답을 arr에 바로 넣으면 안됨. 
  //temp라는 배열을 만들어두고 집어놓고 정렬후 arr에 다시 복사
  int p,q; //현재 최솟값을 가리키는 변수들
  int tmp[100]; //합쳐진 결과를 저장하는 임시 변수
  int tmp_idx=0;
  p =s1, q=s2;
  
  while(p<=e1 && q<=e2){
    if(arr[p]<=arr[q]) {
      tmp[tmp_idx++]= arr[p];
      p++;
    }
    else {
      tmp[tmp_idx++] = arr[q];
      q++;
    }
  }
  if(p>e1){
    for (int i=q;i<=e2;i++)
      tmp[tmp_idx++] = arr[i];
  }
  else{
    for (int i=p;i<=e1;i++)
      tmp[tmp_idx++] = arr[i];
  }

  //tmp 완성, arr[s1~e2]까지 tmp 값 복사
  for (int i=s1;i<=e2;i++)
    arr[i] = tmp[i-s1]; 
}
void mergeSort(int arr[],int start,int end){
  //start부터 end까지 합병정렬하는 함수
  if(start>=end) return;
  else{
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    //이미 위에꺼는 정렬이되어있다 가정
    merging(arr,start,mid,mid+1,end);
  }
}
int main() {

  //Please Enter Your Code Here
  int n;
  int numbers[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&numbers[i]);
    
  mergeSort(numbers,0,n-1);
  for(int i=0;i<n;i++){
    printf("%d ",numbers[i]);
  }
  return 0;
}


#include <stdio.h>
int getLeft(int arr[],int start, int end, int pivot, int result[]){
  //pivot보다 작거나같은 값
  //작거나 같은 원소의 갯수를 반환
  int res_idx=0;
  for(int i=start;i<=end;i++){
    if(arr[i]<=pivot)
      result[res_idx++]=arr[i];
  }
  return res_idx;
}
int getRight(int arr[],int start, int end, int pivot, int result[]){
  int res_idx=0;
  for(int i=start;i<=end;i++){
    if(arr[i]>pivot)
      result[res_idx++]=arr[i];
  }
  return res_idx;
}

void quickSort(int arr[], int start, int end){
  //arr을 start부터 end까지 퀵정렬하는 함수
  if(start>=end) return ;
  
  int pivot =arr[start];
  int left[100],right[100];
  int left_cnt=getLeft(arr,start+1,end,pivot,left);  //pivot보다 작거나같은 값
  int right_cnt=getRight(arr,start+1,end,pivot,right);//pivot보다 큰값
  
  
  for(int i=0;i<left_cnt;i++){
    arr[i+start] = left[i];
  }
  arr[start+left_cnt]= pivot;
  for(int i=0;i<right_cnt;i++){
    arr[start+left_cnt+1+i] = right[i];
  }
  
  quickSort(arr, start, start+left_cnt-1);
  quickSort(arr, start+left_cnt+1,end);
}

int main() {

  //Please Enter Your Code Here
  int n;
  int numbers[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&numbers[i]);
  
  quickSort(numbers,0,n-1);
  
  for(int i=0;i<n;i++) printf("%d ",numbers[i]);
  return 0;
}