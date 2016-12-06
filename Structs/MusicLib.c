#include <stdio.h>
#include <string.h>

#define MAX 64



 struct Song{
	char trackName[MAX];
       	char artist[MAX];	
	int timesPlayed;
};



int main()
{
	
	struct Song song1;
	struct Song song2;

	/*Initializing song1*/
	strcpy(song1.trackName, "I wanna fuck you");
	strcpy(song1.artist, "Akon");
	song1.timesPlayed = 100;
	
	strcpy(song2.trackName, "Love Sosa");
	strcpy(song2.artist, "Chief Keef");
	song2.timesPlayed = 50;


	/*Printing songs*/
	printf("%s\n", song1.trackName);
	printf("%s\n", song1.artist);
	printf("%d\n", song1.timesPlayed);
	
	printf("%s\n", song2.trackName);
	printf("%s\n", song2.artist);
	printf("%d\n", song2.timesPlayed);







	return 0;
}
