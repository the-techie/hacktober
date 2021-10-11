#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[],int s,int m,int e){

    int Left_size=m-s+1;
    int Right_size=e-m;

    int *LeftSubarray= new int[Left_size];
    int *RightSubarray=new int[Right_size];

    for(int i=0;i<Left_size;i++){
        LeftSubarray[i]=arr[s+i];
    }
    for(int i=0;i<Right_size;i++){
        RightSubarray[i]=arr[m+1+i];
    }

    int i=0,j=0,k=s;
    while(i<Left_size && j<Right_size)
    {
        if(LeftSubarray[i]<RightSubarray[j])
        {
            arr[k]=LeftSubarray[i];
            k++;
            i++;
        }
        else if(LeftSubarray[i]>RightSubarray[j])
        {
            arr[k]=RightSubarray[j];
            k++;
            j++;
        }
    }
    while(i<Left_size)
    {
        arr[k]=LeftSubarray[i];
        k++;
        i++;
    }
    while(j<Right_size)
    {
        arr[k]=RightSubarray[j];
        k++;
        j++;
    }

}
void MergeSort(int arr[], int s, int e){
    if(s<e){
        int m=(s+e)/2;
        MergeSort(arr,s,m);
        MergeSort(arr,m+1,e);
        Merge(arr,s,m,e);
    }
    else{
        return;
    }
}

void PrintArray(int A[],int s)
{
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main(){    
    int Arr[]={12,11,13,5,6,7};
    int size=sizeof(Arr)/sizeof(Arr[0]);

    cout<<"Initial Array :"<<endl;
    PrintArray(Arr,size);

    MergeSort(Arr,0,size-1);
    cout<<"Sorted Array :"<<endl;
    PrintArray(Arr,size);

    return 0;
}