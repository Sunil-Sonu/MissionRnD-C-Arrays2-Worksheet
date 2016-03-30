/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
int year(struct transaction *, char *,int);
int month(struct transaction *, char *, int);
int day(struct transaction *, char *, int);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int x,i=0,count=0;
	if (len < 0)
	return 0;
	else
	{
		for (i = 0; i < len; i++)
		{
			x = year(Arr, date, i);
			if (x == 0)
			{
				x = month(Arr, date,i);
				if (x == 0)
				{
					x = day(Arr, date, i);
				}
			}
			if (x > 0)
				count++;
		}
		return count;
	}
}
int year(struct transaction *Arr, char *date,int var)
{
	int i = 6,x,y;
	while (i <= 9)
	{
		x = (int)(Arr[var].date[i] - 48);
		y = (int)(date[i] - 48);
		if (x > y)
			return 2;
		else if (x < y)
			return -1;
		else
			i++;
	}
	return 0;
}
int month(struct transaction *Arr, char *date,int var)
{
	int m1, m2;
	m1 = (Arr[var].date[3] - 48) * 10 + (Arr[var].date[4] - 48);
	m2 = (date[3] - 48) * 10 + (date[4] - 48);
	if (m1>m2)
		return 2;
	else if (m1 < m2)
		return -1;
	else
		return 0;
}
int day(struct transaction *Arr,char *date,int var)
{
	int d1, d2;
	d1 = (Arr[var].date[0] - 48) * 10 + (Arr[var].date[1] - 48);
	d2 = (date[0] - 48) * 10 + (date[1] - 48);
	if (d1 > d2)
		return 2;
	else if (d1 < d2)
		return -1;
	else
		return 0;
}