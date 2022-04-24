#include <bits/stdc++.h>
using namespace std;

int median(int arr[],int s,int e)
{
  return (arr[(s+e)/2] + arr[(s+e+1)/2])/2;
}

int findMedian(int arr[],int brr[],int sa,int ea,int sb,int eb)
{
  int m1=median(arr,sa,ea);
  int m2=median(brr,sb,eb);
  if(m1==m2)
    return m1;
  if(ea-sa<=1)
    return (min(arr[ea],brr[eb])+max(arr[sa],brr[sb]))/2;
  else if(m1>m2)
    return findMedian(arr,brr,sa,(sa+ea+1)/2,(sb+eb+1)/2,eb);
  else
    return findMedian(arr,brr,(sa+ea+1)/2,ea,sb,(sb+eb+1)/2);
}

//int median(int num[],int n)
//{
//    if(n&1)
//        return num[n/2];
//    else
//    return (num[n/2-1]+num[n/2])/2;
//}

//int getMedian(int num1[],int num2[],int size)
//{
//    
//     if (size <= 0)
//      return -1;
//   if (size == 1)
//      return (num1[0] + num2[0]) / 2;
//   if (size == 2)
//      return (max(num1[0], num2[0]) + min(num1[1], num2[1])) / 2;
//   int med1 = median(num1, size);
//   int med2 = median(num2, size);
//   // compare the medians
//   if (med1 == med2)
//      return med1 ;
//   if (med1 < med2) {
//      // recurse for the subarray num1[m1 to size] and num2[0 to m2]
//      if (size % 2 == 0)
//         return getMedian(num1 + size/2 - 1, num2, size - size/2 + 1);
//      else
//         return getMedian(num1 + size / 2, num2, size - size / 2);
//   } else {
//      // recurse for the subarray num1[0 to m1] and num2[m2 to n]
//      if (size % 2 == 0)
//         return getMedian(num2 + size / 2 - 1, num1, size - size / 2 + 1) ;
//      else
//         return getMedian(num2 + size / 2, num1, size - size / 2) ;
//}

int getMedian(int arr[],int brr[],int n)
{
    return findMedian(arr,brr,0,n-1,0,n-1);

//    int i=0,j=0;
//    int count=0;
//    int m1=0,m2=0;
//    while(count<n)
//    {
//        if(arr[i]<=brr[j])
//        {
//            m2=brr[j];m1=arr[i];
//            i++;
//        }
//        else
//        {
//            m2=arr[i];m1=brr[j];
//            j++;
//        }
//        
//        count++;
//    }
//    
//    return (m1+m2)/2;
}


int main()
{
	int ar1[] = {1, 12, 15, 26, 38};
	int ar2[] = {2, 13, 17, 30, 45};
//int ar1[]{1,2,3,6,8};
//int ar2[]{4,6,8,10,12};
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	if (n1 == n2)
		cout << "Median is "
			<< getMedian(ar1, ar2, n1) ;
	else
		cout << "Doesn't work for arrays"
			<< " of unequal size" ;
	return 0;
}