#include<bits/stdc++.h>
using namespace std;
int Partition(int arr[],int s,int e){
    int pivot=arr[e];
    int Pivot_Index=s;
    for(int i=s;i<e;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[Pivot_Index]);
            Pivot_Index++;
        }
    }
    swap(arr[e],arr[Pivot_Index]);
    return Pivot_Index;
}
void QuickSort(int arr[],int s, int e){
    if(s<e){
        int p=Partition(arr,s,e);
        QuickSort(arr,s,p-1);
        QuickSort(arr,p+1,e);
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

    QuickSort(Arr,0,size-1);
    cout<<"Sorted Array :"<<endl;
    PrintArray(Arr,size);

    return 0;
}