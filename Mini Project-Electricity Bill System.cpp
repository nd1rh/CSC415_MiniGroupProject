/*
Course Code: CSC415
Project Name: Electricity Bill System
Author: Aina Nadirah, Nurina Afiqah, Fatin Hazwani, Anis Fariha
Group: RCDCS2401A
*/

#include <iostream>
using namespace std;

// main function
int main()
{
	// variable declaration and initialisation
	int currentUnit;
	char username [100], choice = 'N';
	float billAmount=0.0, outstandingBalance=0.0, currentCharges=0.0; 
	
	// displays the electricity rate menu, which shows the unit ranges and rates
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|                    ELECTRICITY BILL SYSTEM                       |" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|                       UNIT                      |   RATE (cent)  |" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "| For the first 100 kWh (1 - 100 kWh) per month   |      21.8      |" << endl;
	cout << "| For the next 100 kWh (101 - 200 kWh) per month  |      33.4      |" << endl;
	cout << "| For the next 100 kWh (201 - 300 kWh) per month  |      51.6      |" << endl;
	cout << "| For the next kWh (301 kWh onwards) per month    |      54.6      |" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	
	// main loop allows the program to process multiple users
	do 
	{
		// input for username, outstanding balance, and current unit
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter outstanding balance from previous month (if any): RM"; 
		cin >> outstandingBalance;
		cout << "Enter current unit:";
		cin >> currentUnit;
		cout << "--------------------------------------------------------------------" << endl;
	
		// calculates the bill amount based on the provided unit using different rates for different unit ranges
		if (currentUnit >= 1 && currentUnit <= 100)  //for 1 - 100kWh
		{
			currentCharges=currentUnit*0.218;
			billAmount=currentCharges+outstandingBalance;
    		}
    
		else if (currentUnit >= 101 && currentUnit <= 200)  //for 101 - 200kWh
		{
			currentCharges=(100*0.218)+(currentUnit-100)*0.334;
			billAmount=currentCharges+outstandingBalance;
    		}
	    
		else if (currentUnit >= 201 && currentUnit <= 300)  //for 201 - 300kWh
		{
			currentCharges=(100*0.218)+(100*0.334)+(currentUnit-200)*0.516;
			billAmount=currentCharges+outstandingBalance;
		}
	    
		else if (currentUnit >= 301)  //for 301kWh onwards
		{
			currentCharges=(100*0.218)+(100*0.334)+(100*0.516)+(currentUnit-300)*0.546;
			billAmount=currentCharges+outstandingBalance;
    		}
	    
		else // if the input unit is invalid, it displays an error message
		{
		cout << "--------------------------------------------------------------------" << endl;
	    	cout << "Error. The current unit can not be calculated. Try again.\n";
	    	cout << "--------------------------------------------------------------------" << endl;
    		}
    
    		// displays a receipt containing the user's name, outstanding balance, total units, and the calculated bill amount
    		cout << "-------------------------------------------------------" << endl;
		cout << "                 ELECTRICITY BILL SYSTEM               " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "  NAME                 | " << username                   << endl;
		cout << "  OUTSTANDING BALANCE  | RM" << outstandingBalance       << endl;
		cout << "  TOTAL UNIT           | " << currentUnit                << endl;
		cout << "  BILL AMOUNT          | RM" << billAmount               << endl;
		cout << "-------------------------------------------------------" << endl;
		
		// the program prompts the user to decide whether to continue entering data for another user or to exit the program
		cout << "Exit? (Y: yes / N: no): ";
		cin >> choice;
		cout << "--------------------------------------------------------------------" << endl;
    }
	while (choice == 'N' || choice == 'n');
	
	// this message is displayed at the end to remind users to pay their bills within 30 days
	cout << "THANK YOU, PLEASE PAY YOUR BILL WITHIN 30 DAYS" << endl;
	
	return 0;
} 
