/*
SNHU
JEFFREY DIGRAZIA
JEFFREY.DIGRAZIA@SNHU.EDU
07/29/2023
*/

#pragma once
#include <string>

// class 
class investmentAccount 
{      // two constructors declared
public:
	investmentAccount(double initialAmount, double annualInterestRate);
	investmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);
	//gets ending balance and interest earned with/without deposits
	double getEndingBalance(int numOfYears);
	double getInterestEarned(int numOfYears);
	double getInterestEarnedNoDeposit(int numOfYears);
	double getEndingBalanceNoDeposit(int numOfYears);

	// gets ending balances and interest earned formatted with/without deposits
	std::string getEndingBalanceFormatted(int numOfYears);
	std::string getEndingBalanceNoDepositFormatted(int numOfYears);
	std::string getInterestEarnedFormatted(int numOfYears);
	std::string getInterestEarnedNoDepositFormatted(int numOfYears);
	
	// getter methods
	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();

	// round function used to round number 2 places
	double round(double num, int places);
	




	// private variables // variables always stays the same
private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;
};
