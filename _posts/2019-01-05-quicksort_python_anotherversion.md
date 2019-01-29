---
layout: post
title:  "퀵소트"
subtitle: "using python"
date:   2019-01-05 12:36:01
categories: [algorithm]
---
## 퀵정렬

python을 이용하여 구현한 퀵정렬이다.<br>

pivot은 left로 설정하였다.<br>

swap이 필요없고 c++로 구현한 퀵정렬보다 간단하다.<br>



~~~
def quicksort(lst):
    if len(lst)>1:
        pivot=lst[0]
        left,mid,right=[],[],[]
        for i in range(1,len(lst)):
            if lst[i]<pivot:
                left.append(lst[i])
            elif lst[i]>pivot:
                right.append(lst[i])
            else:
                mid.append(lst[i])
        mid.append(pivot)
        return quicksort(left)+mid+quicksort(right)
    else:
        return lst

ans=[]
t = int(input()) #갯수
for i in range(t):
    x=int(input())
    ans.append(x)

ans=quicksort(ans)
for j in range(t):
    print(ans[j])


~~~



