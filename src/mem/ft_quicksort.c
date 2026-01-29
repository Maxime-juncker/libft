#include "libft/memory.h"
#include <stdio.h>

static void swap(int* a, int* b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}
/*
partitionner(tableau T, entier premier, entier dernier, entier pivot)
    échanger T[pivot] et T[dernier]  // échange le pivot avec le dernier du tableau , le pivot devient le dernier du tableau
    j := premier
    pour i de premier à dernier - 1 // la boucle se termine quand i = (dernier élément du tableau).
        si T[i] <= T[dernier] alors
            échanger T[i] et T[j]
            j := j + 1
    échanger T[dernier] et T[j]
    renvoyer j

tri_rapide(tableau T, entier premier, entier dernier)
        si premier < dernier alors
            pivot := choix_pivot(T, premier, dernier)
            pivot := partitionner(T, premier, dernier, pivot)
            tri_rapide(T, premier, pivot-1)
            tri_rapide(T, pivot+1, dernier)

* */

static int partition(int* arr, int beginIdx, int endIdx, int pivotIdx)
{
	swap(&arr[endIdx], &arr[pivotIdx]);

	int j = beginIdx;
	for (int i = beginIdx; i < endIdx - 1; i++)
	{
		if (arr[i] <= arr[endIdx])
		{
			swap(&arr[i], &arr[j]);
			j++;
		}
	}
	swap(&arr[endIdx], &arr[j]);
	return j;
}

static int choosePivot(int beginIdx, int endIdx)
{
	int size = endIdx - beginIdx;
	return beginIdx + (size / 2);
}

static void print(int* arr, int begin, int end)
{
	for (int i = begin; i <= end; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

static void qsort_step(int* arr, int beginIdx, int endIdx)
{
	int pivotIdx;

	if (beginIdx < endIdx)
	{
		pivotIdx = choosePivot(beginIdx, endIdx);
		pivotIdx = partition(arr, beginIdx, endIdx, pivotIdx);
		qsort_step(arr, beginIdx, pivotIdx - 1);
		qsort_step(arr, pivotIdx + 1, endIdx);
		print(arr, beginIdx, endIdx);
	}
}

void	ft_qsort(int* arr, size_t size)
{
	qsort_step(arr, 0, size - 1);
}
