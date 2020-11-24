#include <stdio.h>

/// Function that reads integers in file and stores them in array
void read_data(FILE *ptr, int d[])
{
	int i = 0;  // iterator for elements in array
	int num;
	while(fscanf(ptr, "%d", &num)==1)
	{
		d[i] = num;
		i++;
	}
}

/// Function to print array
void print_array(int d[], int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		printf("%d \t", d[i]);
	}
}
	
/// Function that computes average of values in array
double compute_average(int d[], int size)
{
	double average = 0.0;  // initialize to zero
	
	int i;
	for (i=0; i<size; i++)
	{
		average += d[i];  // add all array elements
	}
	average /= size;  // divide by size
	return average;;
}

/// Function that computes maximum value of array
int compute_max(int d[], int size)
{
	int i;
	int max = d[0]; // initialize maximum to first element
	for (i=0; i<size -1; i++)
	{
		if (d[i+1] > d[i])
		{
			max = d[i+1];  // if next element is larger, update max
		}
	}
	return max;
}

int main(void)
{
	FILE *input;
	input = fopen("file.txt", "r");  // open input file

	if(input == NULL)  // if file not found, break
	{
		return 0;
	}

	int size;
       	fscanf(input, "%d", &size);  // first integer of file is array size
	int data[size];
	read_data(input, data);

	// Print array
	print_array(data, size);
	printf("\n");

	// compute average and maximum of data
	double average = compute_average(data, size);
	int max = compute_max(data, size);

	printf("Average is: %f \n", average);
	printf("Maximum is: %d \n", max);

	// Open output file and store average and maximum
	FILE *output;
	output = fopen("answer-hw3", "w");
	putc(average, output);
	putc(' ', output);
	putc(max, output);

	fclose(input);
	fclose(output);

	return 0;
}
