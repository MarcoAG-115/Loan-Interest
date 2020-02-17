//  Marco Gonzalez
//  mag0089
//  project1_mag0089.cpp
//  Project_1
//
//  I used Dr. Li's Lecture 2 slides for number formatting.
//  I had to look through the notes on Canvas to learn some C++ syntax / rules.
//  I used stackoverflow.com to learn how to left align my output.
//  I used stackoverflow.com to learn some C++ syntax & shortcuts.
//  I spoke with William Baldwin in class about how "setw()" and "left" works.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    //Variables
    double loanAmount;
    double yearlyInterest;
    double monthlyPayment;
    int month = 0;
    double balance;
    double rate;
    double interestPaid = 0;
    double principal;
    double totalInterest = 0;
    
    //User inputs
    std::cout << "Loan Amount: ";
    std::cin >> loanAmount;
    std::cout << "Interest Rate (% per year): ";
    std::cin >> yearlyInterest;
    std::cout << "Monthly Payments: ";
    std::cin >> monthlyPayment;
    
    //Setting balance
    balance = loanAmount;
    
    //Calculating rate
    rate = yearlyInterest/12;
    
    //Checks for monthlyPayment < interestPaid
    if (monthlyPayment < ((rate / 100) * balance))
    {
        std::cout << "\nError: The interest paid in the first month is higher than"
            << " the submited monthly payment value.\n\n";
    }
    else
    {
        //Table header & starting values
        std::cout << "\n********************************************************\n";
        std::cout << "\tAmortization Table\n";
        std::cout << "********************************************************\n";
        std::cout << "Month   Balance   Payment   Rate   Interest   Principal\n";
        std::cout << month;
        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(2);
        std::cout << "       $" << balance;
        std::cout << "  N/A";
        std::cout << "       N/A";
        std::cout << "    N/A";
        std::cout << "        N/A\n";
    }
    
    //Calculates & displays each row of information
    while (balance > 0)
    {
        //Calculating values
        month++;
        interestPaid = (rate / 100) * balance;
        totalInterest = totalInterest + interestPaid;
        principal = monthlyPayment - interestPaid;
        monthlyPayment = principal + interestPaid;
        balance = balance - principal;
        
        //Checks for monthlyPayment < interestPaid
        if (monthlyPayment < interestPaid)
        {
            break;
        }
        
        //Checks for final payment
        if (balance <= 0)
        {
            monthlyPayment = balance + monthlyPayment;
            principal = monthlyPayment - interestPaid;
            balance = 0;
        }
        
        //Displaying values
        
        std::cout << setw(8) << left << month;
        std::cout << "$" << setw(9) << left << balance;
        std::cout << "$" << setw(9) << left << monthlyPayment;
        std::cout << setw(7) << left << rate;
        std::cout << "$" << setw(10) << left << interestPaid;
        
        //Checks if principal is negative
        if (principal < 0)
        {
            double principalPositive;
            principalPositive = principal * (-1);
            std::cout << "-$" << principalPositive;
        }
        else
        {
            std::cout << "$" << principal;
        }
        
        std::cout << "\n";
        
    }
    
    //Final output
    if (monthlyPayment > interestPaid)
    {
        std::cout << "********************************************************\n\n";
        std::cout << "It takes " << month << " months to pay off the loan.\n";
        std::cout << "Total interest paid is: $" << totalInterest << "\n\n";
    }
    
    return 0;
}
