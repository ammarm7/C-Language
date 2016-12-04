#include <stdio.h>
#include <string.h>

#define MAX_SIZE 64


struct Book{
	char title[MAX_SIZE];
	char author[MAX_SIZE];
	int bookID;
};




int main()
{
	struct Book book1;
	struct Book book2;

	/*Initializing book1*/
	strcpy(book1.title, "How to win friends and influence people");
	strcpy(book1.author, "Dale Carnegie");
	book1.bookID = 1;	
	




	/*Printing book1*/
	printf("%s\n", book1.title);
	printf("%s\n", book1.author);
	printf("%d\n", book1.bookID);	



	return 0;

}


