/*
Course Code: CSC415
Project Name: Electricity Bill System
Author: Aina Nadirah, Nurina Afiqah, Fatin Hazwani, Anis Fariha
Group: RCDCS2401A
*/

#include <iostream>
using namespace std;

//main function
int main()
{
	//declaration and initialisation
	int currentUnit;
	char username [100], choice = 'N';
	float billAmount=0.0, outstandingBalance=0.0, currentCharges=0.0; 
	
	// display menu (unit and rate)
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
	
	do 
	{
		//input
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter outstanding balance from previous month (if any): RM"; 
		cin >> outstandingBalance;
		cout << "Enter current unit:";
		cin >> currentUnit;
		cout << "--------------------------------------------------------------------" << endl;
	
		//calculate bill amount
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
	    
		else  //wrong input for current unit
		{
		cout << "--------------------------------------------------------------------" << endl;
	    	cout << "Error. The current unit can not be calculated. Try again.\n";
	    	cout << "--------------------------------------------------------------------" << endl;
    		}
    
    		//receipt - display back all the input for 1 user
    		cout << "-------------------------------------------------------" << endl;
		cout << "                 ELECTRICITY BILL SYSTEM               " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "  NAME                 | " << username                   << endl;
		cout << "  OUTSTANDING BALANCE  | RM" << outstandingBalance       << endl;
		cout << "  TOTAL UNIT           | " << currentUnit                << endl;
		cout << "  BILL AMOUNT          | RM" << billAmount               << endl;
		cout << "-------------------------------------------------------" << endl;
		
		// prompt to continue or not
		cout << "Exit? (Y: yes / N: no): ";
		cin >> choice;
		cout << "--------------------------------------------------------------------" << endl;
    }
	while (choice == 'N' || choice == 'n');
	
	//remind the user to pay the bill
	cout << "THANK YOU, PLEASE PAY YOUR BILL WITHIN 30 DAYS" << endl;
	
	return 0;
} ABU
