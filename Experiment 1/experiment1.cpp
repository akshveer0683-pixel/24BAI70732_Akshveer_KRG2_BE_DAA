#include<iostream>
using namespace std;
 int main()
 {
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    double value[n], taken=0, weight[n], capacity, profit=0;
    cout<<"Enter capacity of container: ";
    cin>>capacity;
    cout<<"Enter the values and weights of items:\n";
    for(int i=0;i<n;i++)
    {
        cin>>value[i]>>weight[i];
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(value[i]/weight[i]<value[i+1]/weight[i+1])
            {
                double tempv=value[i];
                double tempw=weight[i];
                value[i]=value[i+1];
                weight[i]=weight[i+1];
                value[i+1]=tempv;
                weight[i+1]=tempw;
            }
        }
}
for(int i=0;i<n;i++)
{
    if(capacity >= weight[i])
    {
        taken = taken + weight[i];
        profit = profit + value[i];
        capacity = capacity - weight[i];
    }
    else
    {
        profit = profit + (value[i]/weight[i]) * capacity;
        break;
    }
}
cout<<"Maximum profit is: "<<profit;
 }
