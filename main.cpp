/* Program name: main.cpp
*  Author: Justin Phillips
*  Date last updated: 6/10/2024
* Purpose: Implement data saves using file I/O
*/

#include "studymor.h"

int main() 
{
	//The code below will get the current date and format it into ISO8601 date format (yyyy-mm-dd) You can use this to get the date to put into the output file for the survey data.
	int n = 1;
	//Keyount is how many lines of text is found in current file to set our new key
	int keycount = 0;
	//Our file names
	string participant = "participant.dat", survey = "survey.dat", fileLine;
	ifstream fin(participant);
	ofstream fout;

	//Date/time conversions for our file output, I wasn't sure where to put it though based on the program setup in codegrade
	char formatDate[80];
	time_t currentDate = time(NULL);
	strftime(formatDate, 80, "%F", localtime(&currentDate)); // for date and time "%F %T"
	string inv_date(formatDate);

	cout << "Welcome to the Westlake Research Hospital StudyMor Study!" << endl;

	//Counts our number of lines in file so we don't lose results by overwriting
	while(getline(fin, fileLine)){
		keycount++;
	}

	fin.close();
	n = keycount + 1;
	
	//Dynamic array of results
	studyMor* participants = new studyMor[100];
	while(true){
		//Sets our menu choice to user selection
		int menuChoice = participants[n].printMenu();

		//Runs our menu choice function depending on the user selection
		participants[n].setMenu(n, menuChoice, participant, survey, participants);

	}
	
	return 0;
}



