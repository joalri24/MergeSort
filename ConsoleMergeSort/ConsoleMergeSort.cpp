// ConsoleMergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// ------------ function declarations ------------

void printHeader();
void printFooter();
vector<int> buildArray();
void printArray(vector<int> array);
vector<int> mergeSort(vector<int> vectorIn);
vector<int> merge(vector<int> vector1, vector<int> vector2);


// ------------ Main program -------------
const int arraySize = 2;

int main()
{
	
	int array[arraySize];
	printHeader();

	vector<int> vectorIn = buildArray();
	cout << "\n";
	cout << "original:" << setw(2);
	printArray(vectorIn);
	cout << "\n";
	cout << "sorted:" << setw(4);
	printArray(mergeSort(vectorIn));

	printFooter();
	return 0;
}


// ------------ Function definitions -------------
void printHeader()
{
	cout << "*** Merge sort example ***" << "\n"; 
	cout << "Type a number and press 'enter' to add it to the array.\n";
	cout << "When finished, type 's' and press enter to execute the algorithm.\n";
}

void printFooter()
{
	int a;
	cout << "\nType any key and press 'enter' to exit.\n";
	cin >> a;
}

vector<int> buildArray()
{
	string input;
	vector<int> vector;
	while (true)
	{
		cin >> input;
		if (input == "s")
			break;
		try
		{		
			vector.push_back(stoi(input));
		}
		catch (invalid_argument& ia)
		{
			cout << "Invalid value. Type an integer number.\n";
		}
		catch (out_of_range& ia)
		{
			cout << "The number is too big. Try a smaller one.\n";
		}		
	}
	return vector;
}

void printArray(vector<int> array)
{
	cout << "[";
	vector<int>::iterator it;
	for (it = array.begin(); it != array.end(); it++)
	{		
		cout << *it ;
		if (it == array.begin() + array.size()-1)
			cout << "]";
		else
			cout << ", ";
	}
		
}

vector<int> mergeSort(vector<int> vectorIn)
{
	// base case
	if (vectorIn.size() == 1)
		return vectorIn;

	// Break the array in two
	int middlePoint = vectorIn.size() / 2; // The integer part of the division.
	vector<int> left(vectorIn.begin(), vectorIn.begin() + middlePoint);
	vector<int> right(vectorIn.begin()+ middlePoint, vectorIn.end());
	left = mergeSort(left);
	right = mergeSort(right);
 	
	return merge(left, right);
}

vector<int> merge(vector<int> vector1, vector<int> vector2)
{
	vector<int> merge;
	int j = 0; 
	int i = 0;
	while ( i < vector1.size() || j < vector2.size())
	{
		if (j >= vector2.size())
		{
			merge.push_back(vector1[i]);
			i++;
			continue;
		}

		if (i >= vector1.size())
		{
			merge.push_back(vector2[j]);
			j++;
			continue;
		}

		if (vector1[i] <= vector2[j])
		{
			merge.push_back(vector1[i]);
			i++;
		}
		else
		{
			merge.push_back(vector2[j]);
			j++;
		}
	}

	return merge;
}


