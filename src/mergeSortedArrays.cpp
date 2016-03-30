/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
int check_date(char *, char *);
#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
}*res;

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int temp,i=0,j=0,k=0;
	if (BLen<0 ||ALen<0 || A==NULL || B==NULL)
	return NULL;
	else
	{
		res = (struct transaction*)malloc(sizeof(struct transaction)*10);
		while (i<ALen && k<BLen)
		{ 
		   temp = check_date(A[i].date,B[k].date);
		   if (temp == 1 || temp==3)
		   {
			   res[j] = A[i];
			   j++;
			   i++;
		   }
		   if (temp == 2)
		   {
			   res[j] = B[k];
			   j++;
			   k++;
		   }
		}
		if ((i == ALen) && k < BLen)
		{
			while (k < BLen)
			{
				res[j] = B[k];
				j++;
				k++;
			}
		}
		if ((k==BLen) && i < ALen)
		{
			while (i < ALen)
			{
				res[j] = A[i];
				j++;
				i++;
			}
		}
		return res;
	}
}
int check_date(char *date1, char *date2)
{
	int d1 = 0, d2 = 0, y1 = 0, y2 = 0, m1 = 0, m2 = 0;
	y1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
	y2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
	m1 = (date1[3] - '0') * 10 + (date1[4] - '0');
	m2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	d1 = (date1[0] - '0') * 10 + (date1[1] - '0');
	d2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	if (y1 == y2)
	{
		if (m1 == m2)
		{
			if (d1 == d2)
			{
				return 1;
			}
			else if (d1 > d2)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
		else if (m1 > m2)
			return 2;
		else
			return 3;
	}
	else if (y1 > y2)
		return 2;
	else
		return 3;
	}