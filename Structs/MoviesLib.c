#include <stdio.h>
#include <string.h>

#define MAX_STR 64


typedef struct Movie{
	char tittle[MAX_STR];
	char starActor[MAX_STR];		
	int movieID;
} DVD;


int main()
{
	
/*Creating instances of the Movie structure*/
	DVD film1;
	DVD film2;

	/* Initalizing values for film1 and film2 */
	strcpy(film1.tittle, "I am legend");
	strcpy(film1.starActor, "Will Smith");
	film1.movieID = 1;
	strcpy(film2.tittle, "Nutty Professor");
	strcpy(film2.starActor, "Eddie Murphy");
	film2.movieID = 2;

	/* Printing al values */
	printf("%s\n", film1.tittle);
	printf("%s\n", film1.starActor);
	printf("%d\n", film1.movieID);;

	printf("%s\n", film2.tittle);
	printf("%s\n", film2.starActor);
	printf("%d\n", film2.movieID);


	return 0;
}
