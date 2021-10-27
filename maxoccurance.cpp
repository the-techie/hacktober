#include<bits/stdc++.h>

using namespce std;

int main(){

  int n;
  cin>>n;
  
  int arr[n];
  
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  
  int mx=-1,cnt=0;
  
  for(int i=0;i<n;i++){
    if(mx==arr[i]) cnt++;
    else if(cnt==0){
      mx=arr[i];
      cnt=1;
    }else cnt--;
    
    cout<<"The mode of array is :- "<<mx<<endl;
  
}
