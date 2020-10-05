#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define SIZE 10000

int myArray[SIZE - 1];

void copyarray(int array[],int copy[],int n)
{
    int i;
    for(i=0;i<n;i++)
    copy[i]=array[i];
}

void printSorted()
{
    int i;
    for( i = 0; i < SIZE - 1; i++)
    {
        printf("%d\n", myArray[i]);
    }
}


void init()
{
    int i;
    for( i = 0; i < SIZE - 1; i++)
    {
        myArray[i] = rand()%1000000;
    }
}

//Bubble sort
void bubblesort(int array[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(array[j]>array[j+1])
                swap(array[j],array[j+1],temp);

        }
    }
}

//Insertion sort
void insertionsort(int array[],int n)
{
    int i,j,key;
    for(j=1;j<n;j++)
    {
        key=array[j];
        i=j-1;
        while(i>=0 && array[i]>key)
        {
            array[i+1]=array[i];
            i=i-1;
        }
        array[i+1]=key;
     }
}

//selection sort
void selectionsort(int array[],int n)
{
    int i,j,minpos,temp;
    for(i=0;i<n;i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++){
            if(array[j]<array[minpos])
                minpos=j;

        }
        swap(array[i],array[minpos],temp);
    }
}


//Shell sort
void shellsort(int array[],int n)
{
    int gap,i,key,j,temp;
    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            key=array[i];
            for(j=i;j>=gap&&array[j-gap]>key;j-=gap)
                array[j]=array[j-gap];
            array[j]=key;
        }
    }

}

//Heap sort

int parent(int i) {
    return(i/2);
}
int left(int i) {
    return(2*i+1);
}
int right(int i) {
    return(2*i+2);
}

void heapify(int a[],int i,int n)
{
    int l,r,large,temp;
    l=left(i);
    r=right(i);
    if((l<=n-1)&&(a[l]>a[i]))
        large=l;
    else
        large=i;
    if((r<=n-1)&&(a[r]>a[large]))
        large=r;
    if(large!=i)
    {
        temp=a[i];
        a[i]=a[large];
        a[large]=temp;
        heapify(a,large,n);
    }
}

void buildheap(int a[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
        heapify(a,i,n);
}

void heapsort1(int a[],int n)
{
    int i,m,temp;
    buildheap(a,n);
    m=n;
    for(i=n-1;i>=1;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        m=m-1;
        heapify(a,0,m);
    }
}

//Main 
int main()
{
    init();
    double elapsed_T;
    time_t begin,end;

    int bubble[SIZE - 1];
    copyarray(myArray,bubble,SIZE);
    begin=clock();
    bubblesort(bubble,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    printf("\nTime taken by bubble sort is");
    printf(" %0.4lf secs\n",elapsed_T);


    int insertion[SIZE - 1];
    copyarray(myArray,insertion,SIZE);
    begin=clock();
    insertionsort(insertion,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    printf("\nTime taken by insertion sort is");
    printf(" %0.4lf secs\n",elapsed_T);


    int selection[SIZE - 1];
    copyarray(myArray,selection,SIZE);
    begin=clock();
    selectionsort(insertion,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    printf("\nTime taken by selection sort is");
    printf(" %0.4lf secs\n",elapsed_T);


    int shell[SIZE - 1];
    copyarray(myArray,shell,SIZE);
    begin=clock();
    shellsort(shell,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    printf("\nTime taken by shell sort is");
    printf(" %0.4lf secs\n",elapsed_T);

    int heap[SIZE - 1];
    copyarray(myArray,heap,SIZE);
    begin=clock();
    heapsort1(heap,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    printf("\nTime taken by heap sort is");
    printf(" %0.4lf secs\n",elapsed_T);
    return 0;
}