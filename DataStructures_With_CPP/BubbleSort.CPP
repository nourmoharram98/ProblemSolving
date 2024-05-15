#include<iostream.h>
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
		static void merger(int *A, int *L, int leftCount, int* R, int rightcount);
};

void IntCollections::swap(int &a, int &b)
{
	int temp= a;
	a=b;
	b=temp;
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

int main(void)
{
	clrscr();
	int arr[N]={1,12,8,17,28,15,18,11,55,6};
	IntCollections::bubbleSort(arr,N);
	for(int i=0;i<N;i++)
	{
		cout<<"element "<<i+1<<" = "<<arr[i]<<endl;
	}
	getch();
	return 0;
}