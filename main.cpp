#include<bits/stdc++.h>
using namespace std;
struct item
{
    int value,weight;
};
bool cmp(item a,item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return(r1>r2);
}
double fractionalknapsack(item arr[],int w,int n)
{
    sort(arr,arr+n,cmp);
    int cur_weight=0;
    double final_val=0.0;
    for(int i=0;i<n;i++)
    {
        if(cur_weight+arr[i].weight<=w)
        {
            cur_weight+=arr[i].weight;
            final_val+=arr[i].value;
        }
        else
        {
            int remain=w-cur_weight;
            final_val+=arr[i].value*((double)remain/arr[i].weight);
        }
    }
    return final_val;
}
int main()
{
    int n;
    cout<<"Enter the number of items:"<<endl;
    cin>>n;
    int w;
    cout<<"enter the maximum weight:"<<endl;
    cin>>w;
    item arr[n];
    cout<<"enter the value and weights:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value>>arr[i].weight;
    }
    double ans=fractionalknapsack(arr,w,n);
    cout<<ans;
    return 0;
}
