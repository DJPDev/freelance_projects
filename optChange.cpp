#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

/* Optimal Change Calculator - Michael Pina, 2022. A simple exercise program that takes user input for * total price (under $100.00) and payment. The final output is the optimal denominations for change
 * due. */

//Initializing variables

double payment = 0;
double change = 0;
double total = 0;
int numFift;
int numTwen;
int numTens;
int numFive;
int numOnes;
int numQuar;
int numDime;
int numNick;
int numPenn;
string unitFift;
string unitTwen;
string unitTens;
string unitFive;
string unitOnes;
string unitQuar;
string unitDime;
string unitNick;
string unitPenn;
string outputStmt = "\nThe optimal denominations for your change are: \n";
string numFiftStr;
string numTwenStr;
string numTensStr;
string numFiveStr;
string numOnesStr;
string numQuarStr;
string numDimeStr;
string numNickStr;
string numPennStr;
stringstream ss;


//Main Function

int optChange() {	
	system("clear");
	cout << "Optimal Change Calculator - Michael Pina, 2022.\n\n";
	while (total <= 0 || total > 100) {
		cout << "Enter the total cost (more than $0 and less than $100.00): $";
		cin >> total;
	}
	cout << "\n";
	while (payment <= 0 || payment > 100) {
		cout << "Enter the amount paid (more than $0 and no more than $100.00): $";
		cin >> payment;
	}
	cout << "\n";

//Calculate change

	change = payment - total;
	cout << "Your change due is: $" << change << "\n";

//Starting logic to calculate optimal denominations
	
	numFift = (change / 50);
	numFift = round(numFift);
	if (numFift == 0) {
       		//do nothing.
	} else if (numFift == 1) {
		unitFift = " $50 dollar bill \n";
		ss << numFift;
		ss >> numFiftStr;
		outputStmt += numFiftStr + unitFift;
		change -= 50;
	} else if (numFift > 1) {
		unitFift = " $50 dollar bills \n";
		ss << numFift;
	        ss >> numFiftStr;
		outputStmt += numFiftStr + unitFift;
		change -= (numFift * 50);
		ss.clear();
	}
	
//Calculating number of twenties
	
	numTwen = (change / 20);
	numTwen = round(numTwen);
	if (numTwen == 0) {
		// do nothing.
	} else if (numTwen == 1) {
		unitTwen = " $20 dollar bill \n";
		ss << numTwen;
		ss >> numTwenStr;
		outputStmt += "1" + unitTwen;
		change -= 20;
	} else if (numTwen > 1) {
		unitTwen = " $20 dollar bills \n";
		numTwenStr += to_string(numTwen);
		outputStmt += numTwenStr + unitTwen;
		change -= (numTwen * 20);
	}


//Calculating number of Tens
	
	numTens = (change / 10);
	numTens = round(numTens);
	if (numTens == 0) {
		// do nothing.
	} else if (numTens == 1) {
		unitTens = " $10 dollar bill \n";
		numTensStr += to_string(numTens);
		outputStmt += numTensStr + unitTens;
		change -= 10;
	} else if (numTens > 1) {
		unitTens = " $10 dollar bills \n";
		numTensStr += to_string(numTens);
		outputStmt += numTensStr + unitTens;
		change -= (numTens * 10);
	}

//Calculating number of Fives

	numFive = (change / 5);
        numFive = round(numFive);
	if (numFive == 0) {
		// do nothing.
	 } else if (numFive == 1) {
		 unitFive = " $5 dollar bill \n";
		 numFiveStr += to_string(numFive);
		 outputStmt += numFiveStr + unitFive;    
		 change -= 5;
	 } else if (numFive > 1) {
		 unitFive = " $5 dollar bills \n";			
		 numFiveStr += to_string(numFive);
		 outputStmt += numFiveStr + unitFive;
		 change -= (numFive * 5);
	 }

//Calculating number of Ones

	numOnes = (change / 1);
	numOnes = round(numOnes);
	if (numOnes == 0) {
		// do nothing.
	} else if (numOnes == 1) {
		unitOnes = " $1 dollar bill \n";
		numOnesStr += to_string(numOnes);
		outputStmt += numOnesStr + unitOnes;
		change -= 1;
	} else if (numOnes > 1) {
		unitOnes = " $1 dollar bills \n";
		numOnesStr += to_string(numOnes);
		outputStmt += numOnesStr + unitOnes;
		change -= numOnes;
	}


cout << outputStmt << "\n";

return 0;
}

char ans = 'y';
string rtry = "Would you like to calculate the optimal change for another transaction?(y/n): ";

int main() {
	optChange();
	cout << rtry;
	cin >> ans;
	while (ans == 'y') {
		cin.clear();
		cin.ignore(1024, '\n');
		payment = 0;
		total = 0;
		numFiftStr = "";
		numTwenStr = "";
		numTensStr = "";
		numFiveStr = "";
		numOnesStr = "";
		outputStmt = "\nOptimal Change: \n";	
		optChange();
		cout << rtry;
		cin >> ans;
	}

	return 0;
}