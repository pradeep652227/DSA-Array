#include <iostream>
#include <vector>
#include <climits>

using namespace std;
// /* This function returns median of ar1[] and ar2[].
//Assumption in this function:
//Both ar1[] and ar2[] are sorted arrays */
//int m1{0},m2{0};
//void func_mid(int arr[],int count,int mid)
//{
//  if(count==mid)
//  	m1=arr[mid];
//  else if(count==mid+1)
//    	m2=arr[mid];
//  else
//    return ;
//}
//  
//int getMedian(int arr[], int brr[], int n, int m)
//{
//	int mid=(n+m)/2;
//  	int i=0,j=0; int count=0;
//  	if(n>m){ n^=m;m^=n;n^=m; }
//  	while(i<n && j<m)
//    {
//      if(arr[i]<=brr[j])
//      {
//        i++;func_mid(arr,count,mid);
//        count++;
//      }
//      else{
//        j++;func_mid(brr,count,mid);
//        count++;
//      }
//      if(count>mid+1)
//        	break;
//    }
//  if(n+m&1)
//    return m1;
//  else
//    return ((m1+m2)/2);
//}
/* Driver code */

    double findMedianSortedArrays(int arr[], int brr[],int n,int m) {
        
        if(n==0 && m==0)
            return -1;
        
        if(n>m)
            return findMedianSortedArrays(brr,arr,m,n);
        
        int lo=0,hi=n;// in case if we've to take all the elements from smaller array and remaining from the maximum one.
        while(lo<=hi)
        {   
            int mid=lo+(hi-lo)/2;
            int cut1=mid;
            int cut2=(n+m+1)/2 - cut1;
            
            int lmax1=(cut1==0)?INT_MIN:arr[cut1-1];
            int rmin1=(cut1==n)?INT_MAX:arr[cut1];
            
            int lmax2=(cut2==0)?INT_MIN:brr[cut2-1];
            int rmin2=(cut2==n)?INT_MAX:brr[cut2];
            
            if(lmax1<=rmin2 && lmax2<=rmin1)
            {
                if((n+m)&1)
                    return (double)max(lmax1,lmax2);
                else
                    return (max(lmax1,lmax2)+min(rmin1,rmin2))/2.0;
            }
            else if(lmax1>rmin2)//we're too much on the right side of the smaller array
                hi=mid-1;// move to the left side
            else 
                lo=mid+1;
        }
        
        return -1;
        
    }
    
int main()
{
	int ar1[] = {2};
	int ar2[] = {1,3};
	int n1 = sizeof(ar1)/sizeof(ar1[0]);
	int n2 = sizeof(ar2)/sizeof(ar2[0]);
	cout << findMedianSortedArrays(ar1, ar2, n1, n2)<<endl;
    
    return 0;
}