#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

// Insertion Sort
void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key = a[i], j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

// Merge Sort helpers
void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
        a[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Quick Sort helpers
int partition(int a[], int low, int high){
    int pivot=a[high], i=low-1;
    for(int j=low;j<high;j++)
        if(a[j]<pivot) swap(a[++i],a[j]);
    swap(a[i+1],a[high]);
    return i+1;
}
void quickSort(int a[], int low, int high){
    if(low<high){
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

// Print array
void print(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n, ch;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<"\n1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Quick Sort\nEnter choice: ";
    cin>>ch;

    switch(ch){
        case 1: bubbleSort(a,n); break;
        case 2: insertionSort(a,n); break;
        case 3: mergeSort(a,0,n-1); break;
        case 4: quickSort(a,0,n-1); break;
        default: cout<<"Invalid choice"; return 0;
    }

    cout<<"Sorted array: ";
    print(a,n);
    return 0;
}
