#include <stdio.h>
#include <string.h>

#define MAX 64

struct University{
	int worldRank;
	char UniName[MAX];
};

struct Student{
	int stuID;
	char stuName[MAX];
	char stuMajor[MAX];
	char stuMinor[MAX];
	struct University stuUni;	//Adding a structure in a structure
};


int main()
{
	
	/* Initalizing an arbitray stu structure  */
	struct Student stu = {100851469, "Ammar", "Psyc", "CompSci", 100000, "Carleton"};

	/* Printing the members of the stu structure */
	printf("%d\n", stu.stuID);
	printf("%s\n", stu.stuName);
	printf("%s\n", stu.stuMajor);
	printf("%s\n", stu.stuMinor);
	printf("%d\n", stu.stuUni.worldRank);
	printf("%s\n", stu.stuUni.UniName);

	return 0;
}




