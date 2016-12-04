#include <stdio.h>

int main()
{

	char movie1[] = "I am legend";	//This is a constant... It is one way to create strings. However it is hard to edit these later on (without something like strcpy for example...

	printf("%s\n", movie1);

	/* movie1 = "American Pie 2"; */ 

	char* movie2 = "American Pie 1";
	printf("%s\n", movie2);	

	printf("Renaming to AP1 to AP2\n");
	
	movie2 = "American Pie 2";	
	printf("%s\n", movie2);	
	

	return 0;
}
