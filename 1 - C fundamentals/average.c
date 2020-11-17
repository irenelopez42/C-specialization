#include <stdio.h>

int main(void)
{
	FILE* file = fopen("elefant_seal_data", "r");  // open file with weights
	if (file == NULL)     // if file doesn't exist exit main()
	{
		printf("No file found with this name.");
		return 0;
	}

	// initialize integers for weight of a seal, sum of weights and number of seals
	int weight;
	int sum = 0;
	int how_many = 0;
	while (fscanf(file, "%d", &weight) == 1)    // scan file looking for integers
	{
		how_many++;    // for each integer, count one seal
		sum = sum + weight; // add weight to total sum
	}

	double average = sum / how_many;     // compute average
	printf("Average weight is %lf\n", average); // print

	return 0;

}
