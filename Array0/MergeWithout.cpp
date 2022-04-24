/* Mege two arrays without extra space */
 /* Two methods :- Swap then sort the 2nd array instaneously  -> O(n*m)
  *                 Using gap method */
#include <iostream>
#include <cmath>

using namespace std;

void swap(int *c,int *d)
{
    int a=*c; int b=*d;
    
    a=a+b;
    b=a-b;
    a=a-b;
    
    *c=a; *d=b;
}

void swap(int a,int *b)
{
    int c=*b;
    a=a+c;
    c=a-c;
    a=a-c;
    
    *b=c;
}

/*Gap method*/
int newGap(int gap)
{
    if(gap <=1)
        return 0;
    else
        return ( gap/2 + gap%2 );
}

void merge(int arr1[],int arr2[],int n,int m);
int main()
{
    int arr1[]={1,3,5,7}; int arr2[]={0,2,6,8,9,43,53,211,3444,29999};
 int n=sizeof(arr1)/sizeof(arr1[0]); int m=sizeof(arr2)/sizeof(arr2[0]);
 
 merge(arr1,arr2,n,m);
 
 cout<<"Merged array :- "; for(auto i:arr1) cout<<i<<" "; for(auto i:arr2) cout<<i<<" "; cout<<endl;
 
 return 0;
}

void merge(int arr1[],int arr2[],int n,int m)
{
    
  /*  int i, j, gap = n + m;
    for (gap = newGap(gap);
         gap > 0; gap = newGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }*/
   int i=0,j=0;
    int gap=newGap( (n+m) );
    
    while(gap>0)
    {
        for(i=0;i+gap<n;i++){
            if(arr1[i]>arr1[i+gap])
            swap(arr1[i],arr1[i+gap]);
        }
        
        for(j=(gap>n)? gap-n:0; j<m && i<n ; i++, j++)
        {   if(arr1[i] > arr2[j])
            swap(arr1[i],arr2[j]);
        }
        
        if(j<m)
        {
            for(j=0;j+gap<m;j++)
            {
                if(arr2[j] > arr2[j+gap])
                    swap(arr2[j],arr2[j+gap]);
            }
        }
            gap=newGap(gap);
    }
}

/*void merge(int arr1[],int arr2[],int n,int m);


int main()
{
int arr1[]={1,3,5,7}; int arr2[]={0,2,6,8,9};
 int n=sizeof(arr1)/sizeof(arr1[0]); int m=sizeof(arr2)/sizeof(arr2[0]);
 
 merge(arr1,arr2,n,m);
 
 cout<<"Merged array :- "; for( auto i:arr1) cout<<i<<" "; for(auto i:arr2) cout<<i<<" "; cout<<endl;
 
 return 0;

}

void merge(int arr1[],int arr2[],int n,int m)
{ int i=0;
    while(i<n)
    {
        if(arr1[i]>arr2[0])
         {   swap(arr1[i],arr2[0]);
             int temp=arr2[0];
             int j;
             for(j=1;j<m && arr2[j]< temp; j++)
                 arr2[j-1]=arr2[j];
            arr2[j-1]=temp;
         }
         
         i++;
    }

}*/



// void ins_sort(int arr[],int n)
//    {   int i=1,j=0;
//        int temp;
//        for(i;i<n;i++)
//        {
//            temp=arr[i];
//            for(j=i-1;arr[j]>arr[i] && j>=0;j--)
//                arr[j+1]=arr[j];
//            arr[j+1]=temp;
//        }
//    }
//    
//    	void merge(int arr1[], int arr2[], int n, int m) {
//	    int i=0;
//    while(i<n)
//    {
//        if(arr1[i]>arr2[0])
//        {
//           swap(arr1[i],arr2[0]);
//           ins_sort(arr2,m);
//        }
//        i++;
//    }
//        }
//
//int main(){
////{   int n,m; cout<<"Enter how many arr1 and arr2 elements "; cin>>n>>m;
////    int arr1[n]; int arr2[m]; 
////    cout<<"Enter arr1 elements:- ";
////    for(int i=0;i<n;i++)
////        cin>>arr1[i];
////    cout<<"Enter arr2 elements:- ";
////       for(int i=0;i<m;i++)
////           cin>>arr2[i];
//int arr1[]={1,3,5,7}; int n=4;
//int arr2[]={0,2 ,6, 8,9}; int m=5;           
//           merge(arr1,arr2,n,m);
//           
////    int i=0, j=0;
////    while(i<n && j<m)
////    {
////        if(arr1[i]>arr2[j])
////        {
////            swap(&arr1[i],&arr2[j]);
////            j++;
////        }
////        else j++;
////        if(i<n && j==m)
////        {
////            j=0;i++;
////        }
////    }
////    
////    i=0, j=m-1;
////    while(i<m && j>0)
////    {
////        if(arr2[j]<arr2[i])
////        {
////            swap(&arr2[i],&arr2[j]);
////            i++;
////        }else 
////            i++;
////        if(i==j && j>0)
////        {j--;i=0;}
////    }
//        cout<<"The sorted merged array is:- ";
//        
//        for(int i=0;i<n;i++)
//        cout<<arr1[i]<<" ";
//       for(int i=0;i<m;i++)
//           cout<<arr2[i]<<" ";
//           
//           cout<<endl;
//    return 0;
//}