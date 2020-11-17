#include <stdio.h>    // for printf
#include <stdlib.h>   // for malloc

struct list{int data; struct list *next;};   // create list struct
typedef struct list list;

void print_list(list *h)  // define function for printing list in rows of five
{
	int i = 0;
	while (h != NULL)
	{
		printf("%d\t ", h -> data);
		h = h -> next;
		if (i % 5 == 4)         // after 5 elements go to new line
		{
			printf("\n");
		}
		i++;
	}
}

list* create_list(int d)   // function that initializes list with one element
{
	list* head = malloc(sizeof(list));  // memory allocation
	head -> data = d;                   // fist element
	head -> next = NULL;                // no next

	return head;
}

list* add_to_front(int d, list* h)  // function for adding elements to list
{
	list* head = create_list(d);
	head -> next = h;
	return head;
}

void bubblesort(list* h, int last)           // one pass of bubblesort
{
        while(last > 0)
        {
                if (h -> data > h -> next -> data)   // if out of order swap
                {
			int temp_value = h -> data;  // keep for reference
                        h -> data = h -> next -> data;
                        h -> next -> data = temp_value;
                }
                h = h -> next;		// make function recursive
	        last--;                 // take one from iterator	
        }

}

int main(void)
{
	list* head = NULL;
	head = malloc(sizeof(list));          // allocate memory

	head -> data = rand() % 100;	      // assign first element
	head -> next = NULL;

	int i;
	for(i=0; i <99; i++)   // add 99 (pseudo-)random numbers (between 1 and 100)
	{
		head = add_to_front(rand() % 100 , head);
	}
	printf("Initial list: \n");
	print_list(head);
	printf("\n\n");

	///  Bubblesort
	int j;
	for (j=99; j>0; j--)        // do bubblesort 99 times for first j elements
	{
		bubblesort(head, j);
	}
	printf("Sorted list: \n");
	print_list(head);
	printf("\n");

	return 0;
}

