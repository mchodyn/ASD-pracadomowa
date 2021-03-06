// sortowanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cstdio>

using namespace std;
void heapify(int *tab, int rozmiar, int i)
{
	int largest = 0;
	int temp=0;
	int l = 2 * i;
	int r = (2 * i) + 1;
	if (l <= rozmiar && tab[l] > tab[i])
		largest = l;
	else largest = i;
	if (r <= rozmiar && tab[r] > tab[largest])
		largest = r;
	if (largest != i)
	{
		temp = tab[largest];
		tab[largest] = tab[i];
		tab[i] = temp;
		heapify(tab, rozmiar, largest);
	}
}
void buildHeap(int *tab, int rozmiar)
{
	for (int i = rozmiar / 2; i > 0; i--)
		heapify(tab, rozmiar, i);
}

void heapsort(int *tab, int rozmiar)
{
	int temp;
	buildHeap(tab, rozmiar);
	for (int i = rozmiar; i > 1; i--)
	{
		temp = tab[i];
		tab[i] = tab[1];
		tab[1] = temp;
		rozmiar--;
		heapify(tab, rozmiar, 1);
	}
}

int partition(int tab[], int p, int r)
{
	int x = tab[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (tab[j] <= x)
		{
			i++;
			int temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}
	int temp = tab[i + 1];
	tab[i + 1] = tab[r];
	tab[r] = temp;
	return i+1;
}
void quicksort(int tab[], int p, int r)
{
	if (p < r)
	{
		int q = partition(tab, p, r);
		quicksort(tab, p, q - 1);
		quicksort(tab, q + 1, r);

	}
}
void bubblesort(int tab[], int r)
{
	for (int i = 1; i < r; i++)
	{
		for (int j = 1; j < r - i; j++)
		{
			if (tab[j] > tab[j+1])
			{
				int temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int const rozmiar = 30000;// przyjmuje indeksowanie od 1 w ponizszych tablicach
	int *randBubble=new int[rozmiar+1];
	int *randQS = new int[rozmiar + 1];
	int *randHS = new int[rozmiar + 1];
	int *rosBubble = new int[rozmiar + 1];
	int *rosQS = new int[rozmiar + 1];// ros - posortowana tablica rosnaco
	int *rosHS = new int[rozmiar + 1];
	int *malBubble = new int[rozmiar + 1];//posortowana tablica malejaco*/
	int *malQS = new int[rozmiar + 1];
	int *malHS = new int[rozmiar + 1];

	for (int i = 1; i <= rozmiar; i++)//wypelnienie losowymi wartosciami
	{
		randBubble[i] = rand() % 100 + 1;
		randQS[i] = randBubble[i];
		randHS[i] = randBubble[i];	
	}
	for (int i = 1; i <= rozmiar; i++)//wypelnienie rosnacymi wartosciami
	{
		rosBubble[i] = i;
		rosHS[i] = i;
		rosQS[i] = i;

	}
	for (int i = rozmiar; i >=1 ; i--)//wypelnienie malejacymi wartosciami
	{
		malBubble[i] = i;
		malHS[i] = i;
		malQS[i] = i;
	}
	clock_t start = clock();
	bubblesort(randBubble, rozmiar);
	clock_t stop = clock();
	double randBubbleTime = (stop - start) / (double)CLOCKS_PER_SEC;
	clock_t start1 = clock();
	quicksort(randQS, 1,rozmiar);
	clock_t stop1 = clock();
	double randQSTime = (stop1 - start1) / (double)CLOCKS_PER_SEC;
	clock_t start2 = clock();
	heapsort(randHS, rozmiar);
	clock_t stop2 = clock();
	double randHSTime = (stop2 - start2) / (double)CLOCKS_PER_SEC;
	

	clock_t start3 = clock();
	bubblesort(rosBubble, rozmiar);
	clock_t stop3 = clock();
	double rosBubbleTime = (stop3 - start3) / (double)CLOCKS_PER_SEC;
	clock_t start4 = clock();
	quicksort(rosQS, 1, rozmiar);
	clock_t stop4 = clock();
	double rosQSTime = (stop4 - start4) / (double)CLOCKS_PER_SEC;
	clock_t start5 = clock();
	heapsort(rosHS, rozmiar);
	clock_t stop5 = clock();
	double rosHSTime = (stop5 - start5) / (double)CLOCKS_PER_SEC;
	
	
	clock_t start7 = clock();
	bubblesort(malBubble, rozmiar);
	clock_t stop7 = clock();
	double malBubbleTime = (stop7 - start7) / (double)CLOCKS_PER_SEC;
	clock_t start8 = clock();
	quicksort(malQS, 1, rozmiar);
	clock_t stop8 = clock();
	double malQSTime = (stop8 - start8) / (double)CLOCKS_PER_SEC;
	clock_t start9 = clock();
	heapsort(malHS, rozmiar);
	clock_t stop9 = clock();
	double malHSTime = (stop9 - start9) / (double)CLOCKS_PER_SEC;
	cout << "Wyniki czasu sortowan losowych tablic 100000 elementowych: " <<"BubbleSort: " << randBubbleTime<<" QuickSort: "<<randQSTime<<" HeapSort: "<<randHSTime<<endl;
	cout << "Wyniki czasu sortowan posortowanych tablic 100000 elementowych: " << "BubbleSort: " << rosBubbleTime << " QuickSort: " << rosQSTime << " HeapSort: " << rosHSTime << endl;
	cout << "Wyniki czasu sortowan odwrotnie posortowanych tablic 100000 elementowych: " << "BubbleSort: " << malBubbleTime << " QuickSort: " << malQSTime << " HeapSort: " << malHSTime << endl;
	
	return 0;
}

