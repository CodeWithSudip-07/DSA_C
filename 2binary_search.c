#include <stdio.h>

int binarysearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;
    
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low= mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[]={10,20,30,40,50,60,70};
    int size= sizeof(arr)/sizeof(int);
    int element=50;
    int searchelement=binarysearch(arr,size,element);
    printf("The element %d is found in index %d\n",element,searchelement);
    return 0;
}