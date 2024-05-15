#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

#define N 10



class IntCollections{
	public:
		static int SeqSearch(int *data, int size, int key);

		static int binarySearch(int *data, int size, int key);
		static int RbinarySearch(int *data,int Low, int high, int key);

		static void selectionSort(int *data, int size);
		static void bubbleSort(int *data, int size);
		static void mergeSort(int *data, int size);
		static void swap(int &a, int &b);
		static void merge(int *A, int *L, int leftCount, int* R, int rightcount);
};

void IntCollections::swap(int &a, int &b)
{
	int temp= a;
	a=b;
	b=temp;
}


void IntCollections::merge(int *A, int *L, int leftCount, int* R, int rightcount)
{
	int i=0,j=0,k=0;
	static int counter=0;
	static int index=0;
	while(i<leftCount && j<rightcount)
	{
		if(L[i] < R[j])
		{
			A[k++]=L[i++];
		}
		else
		{
			A[k++]=R[j++];
		}
	}
	while(i<leftCount)
	{
		A[k++]=L[i++];
	}
	while(j<rightcount)
	{
		A[k++]=R[j++];
	}
	counter++;
	index += k;
	/*
	cout<<"array no"<<counter<<" "<<endl;
	for(i=0;i<k;i++)
	{
		cout<<" "<<A[i];
	}
    cout<<" "<<endl;
	*/
	cout<<"array no"<<counter<<" "<<endl;
	for(i=0;i<index;i++)
	{
		cout<<" "<<A[i];
	}
    cout<<" "<<endl;

}


void IntCollections::selectionSort(int *data, int size)
{
	int i, j, index=0;
	for(i=0;i<size-1;i++,index=i)
	{
		for(j=i+1;j<size;j++)
		{
			if(data[index]>data[j])
			{
				index=j;
			}
		}
		IntCollections::swap(data[i],data[index]);
	}
}

void IntCollections::bubbleSort(int *data, int size)
{
	int i=0,sorted=0,j=1;
	for(j=0;j<size-1&&!sorted;j++)
	{
		sorted =1;
		for(i=0;i<size-j;i++)
		{
			if(data[i]>data[i+1])
			{
				IntCollections::swap(data[i],data[i+1]);
				sorted=0;
			}
		}
	}
}

void IntCollections::mergeSort(int *A, int size)
{
	int mid, i, *L, *R;
	if(size<2)
	{
		return;
	}
	mid = size/2;
	L=(int *)malloc(mid*sizeof(int));
	R=(int *)malloc((size-mid)*sizeof(int));
	for(i=0;i<mid;i++)
	{
		L[i]=A[i];
	}
	for(i=mid;i<size;i++)
	{
		R[i-mid]=A[i];
	}
	IntCollections::mergeSort(L,mid);
	IntCollections::mergeSort(R,size-mid);
	IntCollections::merge(A,L,mid,R,size-mid);
	free(L);
	free(R);
}

int main(void)
{
	clrscr();
	int arr[N]={1,12,8,17,28,15,18,11,55,6};
	IntCollections::mergeSort(arr,N);
	for(int i=0;i<N;i++)
	{
	   //	cout<<"element "<<i+1<<" = "<<arr[i]<<endl;
	}
	getch();
    return 0;
}