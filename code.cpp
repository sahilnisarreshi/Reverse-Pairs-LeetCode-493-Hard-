#include<iostream>
#include<vector>
using namespace std ;
int count = 0;
int inversion(vector<int>& arr1,vector<int>& arr2){
        int i=0; //arr1
        int j=0; //arr2
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]>2*arr2[j]){
                count+=(arr1.size()-i);
                j++;
            }
            else i++;
        }
        return count;
    }
void merge(vector<int>& arr1,vector<int>& arr2,vector<int>& res){
    int i=0; // arr1
    int j=0;// arr2
    int k=0;// res 
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            res[k]=arr1[i];
            i++;
            k++;
        }
        else{
            res[k]=arr2[j];
            j++;
            k++;
        }
    }
    if(i==arr1.size()){
        while(j<arr2.size()){
            res[k]=arr2[j];
            k++;
            j++;
        }
    }
    else{
        while(i<arr1.size()){
            res[k]=arr1[i];
            k++;
            i++;
        }
    }
}
void mergesort(vector<int>& v){
    int n = v.size();
    if(n==1) return; // base case the size of array is 1
    int n1 = n/2; // size arr1
    int n2 = n-n/2; // size of arr2
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i=0;i<n1;i++){
        arr1[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=v[n1+i];
    }

    // sorting these arrays by using recursion 
    mergesort(arr1);
    mergesort(arr2);

    // count the inversion
    count = inversion(arr1,arr2);

    // merging these arrays
    merge(arr1,arr2,v);
    arr1.clear(); // to save space complexity
    arr2.clear();
}
int main (){
    int a1[]={1,3,2,3,1};
    int n = sizeof(a1)/sizeof(a1[0]);
    vector<int> v(a1,a1+n); //  same as array
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
    cout<<"no of inversion = "<<count;
}