/*
SNHU
JEFFREY DIGRAZIA
JEFFREY.DIGRAZIA@SNHU.EDU
07/29/2023
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <tuple>
#include "Header.h"



// Prints menu
void printMenu(double initialAmount, double monthlyDeposit, double annualInterestRate, int numOfYears) {

	std::cout << "----------------------------------------------------------------------------\n";
	std::cout << "          Balance and Interest Without Additional Monthly Deposits\n";
	std::cout << "----------------------------------------------------------------------------\n";
	std::cout << "Year             Year End Balance                 Year End Interest\n";
	std::cout << "----------------------------------------------------------------------------\n";
    // creates a account object with the parameters
	investmentAccount account1(initialAmount, annualInterestRate, monthlyDeposit);
    // for loop used print multiple ending balances and interest earned based on number of years entered
	for (int year = 1; year <= numOfYears; ++year) {
		std::string endBalance = account1.getEndingBalanceNoDepositFormatted(year);
		std::string interestEarned = account1.getInterestEarnedNoDepositFormatted(year);

		std::cout << year << "\t\t$" << std::setw(20) << std::right << endBalance;
		std::cout << "\t\t$" << std::setw(15) << std::right << interestEarned << std::endl;
	}

	std::cout << "----------------------------------------------------------------------------\n";
	std::cout << "          Balance and Interest With Additional Monthly Deposits\n";
	std::cout << "----------------------------------------------------------------------------\n";
	std::cout << "Year             Year End Balance                 Year End Interest\n";
	std::cout << "----------------------------------------------------------------------------\n";
    // creates account object with parameters
	investmentAccount account(initialAmount, annualInterestRate, monthlyDeposit);
    // for loop used to print multiple ending balances and interest earned based on number of years entered.
	for (int year = 1; year <= numOfYears; ++year) {
		std::string endBalance = account.getEndingBalanceFormatted(year);
		std::string interestEarned = account.getInterestEarnedFormatted(year);

		std::cout << year << "\t\t$" << std::setw(20) << std::right << endBalance;
		std::cout << "\t\t$" << std::setw(15) << std::right << interestEarned << std::endl;
	}
}

// Function that gets input, stores it in a tuple, then I unpack it in main function into each variable
std::tuple<double, double, double, int> getInput() {
	std::cout << "\x1B[32m  ___   _   _  _ _  __\n"
		" | _ ) /_\\ | \\| | |/ /\n"
		" | _ \\/ _ \\| .` | ' < \n"                 // ASCII Art :D
		" |___/_/ \\_\\_|\\_|_|\\_\\\n";
    // Variables declared
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numberOfYears;

    std::cout << "+--------------------------------+\n";
    // Input validation for Initial Investment
    while (true) {
        std::cout << std::left << std::setw(25) << "| Initial Investment Amount: $";
        if (std::cin >> initialInvestment && initialInvestment >= 0) {
            break;
        }
        std::cout << "| Invalid input! Only positive real numbers allowed!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Input validation for Monthly Deposit
    while (true) {
        std::cout << std::left << std::setw(25) << "| Monthly Deposit:           $";
        if (std::cin >> monthlyDeposit && monthlyDeposit >= 0) {
            break;
        }
        std::cout << "| Invalid input. Only positive real numbers allowed!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Input validation for Annual Interest
    while (true) {
        std::cout << std::left << std::setw(25) << "| Annual Interest:           %";
        if (std::cin >> annualInterest && annualInterest >= 0) {
            break;
        }
        std::cout << "| Invalid input. Only positive real numbers allowed!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Input validation for Number of Years
    while (true) {
        std::cout << std::left << std::setw(25) << "| Number of Years:           ";
        if (std::cin >> numberOfYears && numberOfYears >= 0) {
            break;
        }
        std::cout << "| Invalid input. Only positive real numbers allowed!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "+--------------------------------+\n";

    std::cout << "Press any key to view reports...";
    std::cin.ignore();
    std::cin.get();

    // Return the values as a tuple
    return std::make_tuple(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
}


int main() {
    // declare four variables
	double a, m, i, y; 
    // unpacks tuple from getInput function and stores input into four variables declared
	std::tie(a, m, i, y) = getInput();
    // this function prints the menu of reports with the inputted information as arguments
	printMenu(a,m,i,y);
    

    return 0;
}
