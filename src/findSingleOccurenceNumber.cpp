/*
OVERVIEW: 
Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
void merge(int *, int, int);
void merging(int *, int, int, int);
int findSingleOccurenceNumber(int *A, int len) {
	int i,count=0,j=0;
	if (len<0 || A=='\0')
	return -1;
	else
	{
		merge(A, 0, len-1);
	}
	for (i = 0; i < len; i++)
	{
		if (A[i] == A[i + 1])
		{
			count++;
			if (count == 2)
			{
				count = 0;
				i++; j = i+1;
			}
		}
		else
		{
			return A[j];
		}
	}
	return A[j];
}
void merge(int *A, int min, int max)
{
	int mid;
	if (min<max)
	{ 
	mid = (min + max) / 2;
	merge(A, min, mid);
	merge(A, mid + 1, max);
	merging(A, min, mid, max);
	}
}
void merging(int *A, int min, int mid, int max)
{
	int i, j, k, m;
	int t[20];
	j = min; m = mid + 1;
	for (i = min; j <= mid && m <= max; i++)
	{
		if (A[j] <= A[m])
		{
			t[i] = A[j];
			j++;
		}
		else
		{
			t[i] = A[m];
			m++;
		}
	}
	if (j > mid)
	{
		for (k = m; k <= max; k++)
		{
			t[i] = A[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			t[i] = A[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
		A[k] = t[k];

}