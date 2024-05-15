#include<iostream.h>
#include<string.h>
#include<conio.h>



class employee{
	public:
		int ID;
		char Name[51];
};




class IntCollections{
	public:
		static void selectionSort(char **data, int size);
		static void bubbleSort(int *data, int size);
		static void mergeSort(int *data, int size);
		static void swap(char **a, char **b);
		static void merge(int *A, int *L, int leftCount, int* R, int rightcount);
};

/*swap function take double pointer to swap two pointers to characters*/

void IntCollections::swap(char **a, char **b)
{
	char *temp= *a;
	*a=*b;
	*b=temp;
}


/*selection sort function take double pointer that point to
  the address of array of pointers to characters*/

void IntCollections::selectionSort(char **data, int size)
{
	int i, j, index=0;
	char *min;
	for(i=0;i<size-1;i++,index=i)
	{
		for(j=i+1;j<size;j++)
		{
			if(strcmp(data[j],data[index])<0)
			{
				index=j;
			   //	cout<<"index = "<<index<<endl; //for debug
			}
		}
		IntCollections::swap(&data[i],&data[index]);
	}
}


int main(void)
{
	clrscr();

	char *array_of_strings[5]={"nourrr","momenn","alaaaa","eldeen","eanafy"};
	cout<<"###################"<<endl;
	cout<<"names before sort:"<<endl;
	cout<<"###################"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<i+1<<" - "<<array_of_strings[i]<<endl;
	}
	IntCollections::selectionSort(array_of_strings,5);
	cout<<"####################"<<endl;
	cout<<"names after sort:"<<endl;
	cout<<"####################"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<i+1<<" - "<<array_of_strings[i]<<endl;
	}
	getch();
	return 0;
}