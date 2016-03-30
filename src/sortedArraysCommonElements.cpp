/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
int check_dates(char *, char *);
#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
}*result=NULL;

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int temp = 0, i, j = 0, k = 0,count=0;
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
		return NULL;
	else
	{
		result = (struct transaction*)malloc(sizeof(struct transaction) * 10);
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				temp = check_dates(A[i].date, B[j].date);
				if (temp == 1)
				{
					result[k] = B[j];
					k++;
					count++;
				}
			}
		}
		if (count==0)
			return NULL;
		else
		return result;
	}
}
int check_dates(char *date1, char *date2){

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
				else
				{
					return -1;
				}
			}
		}
		return 0;
	}
