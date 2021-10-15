//Time complexity : O(n+k) ; k: range of elements is from 0-k
#include<bits/stdc++.h>
using namespace std;
void CountSort(vector<int>& arr){

    int maximum=*max_element(arr.begin(),arr.end());
    int minimum=*min_element(arr.begin(),arr.end());
    int range=maximum-minimum+1;

    vector<int> Count(range,0),Output(arr.size());

    for(int i=0;i<arr.size();i++){
        Count[arr[i]-minimum]++;
    }

    for(int i=1;i<range;i++){
        Count[i]+=Count[i-1];
    }
    
    for(int i=0;i<arr.size();i++){
        Output[Count[arr[i]-minimum]-1]=arr[i];
        Count[arr[i]-minimum]--;
    }

    for(int i=0;i<arr.size();i++){
        arr[i]=Output[i];
    }
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    vector<int> arr={-5,-10,0,-3,8,5,-1,10};
    CountSort(arr);
    return 0;
}