// Selection Sort

#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter the nos of eles: ");
    scanf("%d",&n);
    int arr[n];
    
    // input user
    printf("Enter the %d integers: \n",n);
    for(i=0;i<n;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    // before sorting 
    printf("Before sorting: \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");

    // calling function
    selectsort(arr,n);
    printf("Sorted array ascending: \n");

    // to print sorted array 
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
 printf("\n");
 return 0;
}

void selectsort(int arr[], int n)
{
    int i,j,min_dx,temp;
    for(i=0;i<n-1;i++)
    {
    // min value 
       min_dx=i;
       for(j=i+1;j<n;j++)
       {
        // compare j=i+1 with last ele and swap i.e. min
        if(arr[j]<arr[min_dx])
        {
            min_dx=j;
        }
        // swapped values
       }
       temp=arr[min_dx];
       arr[min_dx]=arr[i];
       arr[i]=temp;
    }
}