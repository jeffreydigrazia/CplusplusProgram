/*
SNHU
JEFFREY DIGRAZIA
JEFFREY.DIGRAZIA@SNHU.EDU
07/29/2023
*/

#include "Header.h"
#include <iomanip>
#include <sstream>




// Constructor with three parameters
investmentAccount::investmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit) {
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = monthlyDeposit;
}

// Constructor with two parameters
investmentAccount::investmentAccount(double initialAmount, double annualInterestRate) {
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = 0.0; // no monthly deposit
}

// used to round a value x places
double investmentAccount::round(double value, int x) {
	const int multiplier = pow(10, x);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;

}

// gets ending balance with for loop and rounds using round function
double investmentAccount::getEndingBalance(int numOfYears) {
	double balance = getInitialAmount();
	double monthlyDeposit = getMonthlyDeposit();
	double annualInterestRate = getAnnualInterestRate() / 100;

	for (int i = 1; i <= numOfYears * 12; ++i) {
			double interestAdded = balance * annualInterestRate / 12;
			balance += monthlyDeposit + interestAdded;
		
	}

	return round(balance, 2);
}

// gets ending balance with no deposit added
double investmentAccount::getEndingBalanceNoDeposit(int numOfYears) {
	double balance = getInitialAmount();
	double annualInterestRate = getAnnualInterestRate() / 100;

	for (int i = 1; i <= numOfYears * 12; ++i) {
		double interestAdded = balance * annualInterestRate / 12;
		balance += interestAdded;
	}

	return round(balance, 2);
}

// gets interest earned with for loop and uses round function
double investmentAccount::getInterestEarned(int numOfYears) {
	double interestAdded;
	double annualInterestRate = getAnnualInterestRate() / 100;
	double balance = getInitialAmount() + getMonthlyDeposit();


	for (int i = 0; i < numOfYears * 12; ++i) {
		interestAdded = (balance) * annualInterestRate / 12;
		balance += getMonthlyDeposit() + interestAdded;
	}

	return round(interestAdded, 2);


}

// gets interest earned with no deposit
double investmentAccount::getInterestEarnedNoDeposit(int numOfYears) {
	double interestAdded = 0.0;
	double annualInterestRate = getAnnualInterestRate() / 100;
	double balance = getInitialAmount();

	for (int i = 0; i < numOfYears; ++i) {
		for (int j = 0; j < 12; ++j) {
			double interestEarnedThisMonth = balance * (annualInterestRate / 12);
			balance += interestEarnedThisMonth;
			interestAdded += interestEarnedThisMonth;
		}
	}

	return round(interestAdded, 2);
}

// function to format number into money format
std::string formatNumber(double number) {
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << number;
	return stream.str();
}

// uses formatNumber function to return various balances and interests earn formatted into money format
std::string investmentAccount::getEndingBalanceFormatted(int numOfYears) {
	double endingBalance = getEndingBalance(numOfYears);
	return formatNumber(endingBalance);
}


std::string investmentAccount::getEndingBalanceNoDepositFormatted(int numOfYears) {
	double endingBalanceNoDeposit = getEndingBalanceNoDeposit(numOfYears);
	return formatNumber(endingBalanceNoDeposit);
}


std::string investmentAccount::getInterestEarnedFormatted(int numOfYears) {
	double interestEarned = getInterestEarned(numOfYears);
	return formatNumber(interestEarned);
}


std::string investmentAccount::getInterestEarnedNoDepositFormatted(int numOfYears) {
	double interestEarnedNoDeposit = getInterestEarnedNoDeposit(numOfYears);
	return formatNumber(interestEarnedNoDeposit);
}

// getters

double investmentAccount::getInitialAmount() {
	return initialAmount;
}


double investmentAccount::getMonthlyDeposit() {
	return monthlyDeposit;
}


double investmentAccount::getAnnualInterestRate() {
	return annualInterestRate;
}