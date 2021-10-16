#include<bits/stdc++.h>
using namespace std;
void CountSort(vector<int>& arr,int exp){
    int range=10;   //decimal system
    vector<int> Count(range,0),Output(arr.size());

    for(int i=0;i<arr.size();i++){
        Count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<range;i++){
        Count[i]+=Count[i-1];
    }
    for(int i=arr.size()-1;i>=0;i--){
        Output[Count[(arr[i]/exp%10)]-1]=arr[i];
        Count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=Output[i];
    }

}

//using conting sort for every digit of the numbers 
//startion from least significant digit to most significant digit
void RadixSort(vector<int>& arr){
    int m=*max_element(arr.begin(),arr.end());
    for(int exp=1;m/exp>0;exp*=10){
        CountSort(arr,exp);
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    vector<int> arr={170, 45, 75, 90, 802, 24, 2, 66};
    RadixSort(arr);
    return 0;
}