#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int get_subset(int* arr_begining, int *arr_end, int target)
{
	int *ptr=arr_end;
	while (*arr_begining < target)
	{
		target=target - (*arr_begining);
		int ret=get_subset(arr_begining+1, arr_end, target);
		if(ret == -1)
		{
			return -1;
		}
		else
		{
			cout<<*arr_begining<<endl;
			return *arr_begining;
		}
	}
	if(*arr_begining ==target)
	{
		cout<<*arr_begining<<endl;
		return *arr_begining;
	}
	else if (*arr_begining > target)
	{
		return -1;
	}
	return 0;

}
int main(int argc, char ** argv)
{

	for(int i=0;i<argc;i++)
		cout<<argv[i]<<endl;
	int element[argc-2];
	int length =argc-1;
	for(int i=0;i<argc-2;i++)
	{
		element[i]=atoi(argv[i+1]);
		cout<<"int =="<<element[i]<<endl;
	}

	sort(element ,element +length-1);

	cout<<"sorted"<<endl;
	for(int i=0;i<length-1;i++)
		cout<<element[i]<<endl;

	int target = atoi(argv[argc-1]);
	cout<<"target is =="<<target<<endl;


	for(int i=0;i<length-1;i++)
	{
		int ret=get_subset(&element[i],&element[length-1],target);
		if(ret == -1)
			continue;
		else
		{
			cout<<ret<<endl;
			cout<<"\n"<<endl;
		}

	}
	return 0;

}
