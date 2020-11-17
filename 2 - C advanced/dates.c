#include <stdio.h>

// First of all initialize structs for month and date 
typedef enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{ month month; int day;} date;

// Function that prints string corresponding to month
void print_month(month m)
{
	switch(m)
	{
		case jan: printf("January"); break;
		case feb: printf("February"); break;
		case mar: printf("March"); break;
		case apr: printf("April"); break;
		case may: printf("May"); break;
		case jun: printf("June"); break;
		case jul: printf("July"); break;
		case aug: printf("August"); break;
		case sep: printf("September"); break;
		case oct: printf("October"); break;
		case nov: printf("November"); break;
		case dec: printf("December"); break;
		default: printf("%d is not a month", m);

	}
}

// Function that print date as a combination of string and integer
void print_date(date d)
{
	print_month(d.month);
	printf(" %d", d.day);
}

// Function that computes next date
date next_date(date d)
{
	int total_days;
	total_days = 31;  // most months have 31 days, so this is default
	if (d.month == apr || d.month == jun || d.month == sep || d.month ==nov)
	{
		total_days = 30;  // april, june, september or november have 30 days
	}
	if (d.month == feb)
	{
		total_days = 28;  // february has 28 days
	}

	date next;  // initialize next date
	next.day = d.day + 1;  // add one to current day
	// if new day is beyond days in month, reset day to 1 and go to next month
	if (next.day > total_days)
	{
		next.day = 1;
		next.month = (d.month + 1) % 12;
	}
	else
	{
		next.month = d.month; // if new day < than maximum, keep previous month
	}
	return next;
}

int main(void)
{
	// initialize array for test dates
	date test[5];
	test[0].day = 1;
	test[0].month = jan;
	test[1].day = 28;
	test[1].month = feb;
	test[2].day = 14;
	test[2].month = mar;
	test[3].day = 31;
	test[3].month = oct;
	test[4].day = 31;
	test[4].month = dec;

	// go over test dates and print their next
	int i;
	for (i = 0; i<5; i++)
	{
		printf("The day after ");
		print_date(test[i]);
		printf(" is: ");
		print_date(next_date(test[i]));
		printf("\n");
	}

	return 0;
}
