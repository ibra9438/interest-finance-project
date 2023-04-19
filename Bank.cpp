#include <iostream>
#include <cmath>
#include <iomanip>


class Investment {
private:
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterestRate;
    int numYears;
public:
    Investment(double initialInvestmentAmount, double monthlyDeposit, double annualInterestRate, int numYears) {
        this->initialInvestmentAmount = initialInvestmentAmount;
        this->monthlyDeposit = monthlyDeposit;
        this->annualInterestRate = annualInterestRate;
        this->numYears = numYears;
    }
    void displayInvestmentData() {
        // Display investment data entered by user
        std::cout << "Initial Investment Amount: $" << initialInvestmentAmount << std::endl;
        std::cout << "Monthly Deposit: $" << monthlyDeposit << std::endl;
        std::cout << "Annual Interest (Compounded): " << annualInterestRate << "%" << std::endl;
        std::cout << "Number of Years: " << numYears << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();
        
        // Display year-end balances and interest earned without monthly deposits
        double balance = initialInvestmentAmount;
        double earnedInterest = 0;
        std::cout << std::endl << "Year-End Balances and Interest Earned (No Monthly Deposits):" << std::endl;
        std::cout << "Year\t\tBalance\t\tInterest Earned" << std::endl;
        for (int year = 1; year <= numYears; year++) {
            earnedInterest = balance * annualInterestRate / 100;
            balance += earnedInterest;
            std::cout << year << "\t\t$" << balance << "\t\t$" << earnedInterest << std::endl;
        }
        
        // Display year-end balances and interest earned with monthly deposits
        balance = initialInvestmentAmount;
        earnedInterest = 0;
        std::cout << std::endl << "Year-End Balances and Interest Earned (With Monthly Deposits):" << std::endl;
        std::cout << "Year\t\tBalance\t\tInterest Earned" << std::endl;
        for (int year = 1; year <= numYears; year++) {
            earnedInterest = (balance + monthlyDeposit) * annualInterestRate / 1200;
            balance += monthlyDeposit + earnedInterest;
            std::cout << year << "\t\t$" << balance << "\t\t$" << earnedInterest << std::endl;
        }
    }
};

int main() {
    // Get investment data from user
    double initialInvestmentAmount, monthlyDeposit, annualInterestRate;
    int numYears;
    std::cout << "Enter initial investment amount: ";
    std::cin >> initialInvestmentAmount;
    std::cout << "Enter monthly deposit: ";
    std::cin >> monthlyDeposit;
    std::cout << "Enter annual interest rate: ";
    std::cin >> annualInterestRate;
    std::cout << "Enter number of years: ";
    std::cin >> numYears;
    
    // Create Investment object and display data
    Investment investment(initialInvestmentAmount, monthlyDeposit, annualInterestRate, numYears);
    investment.displayInvestmentData();
    
    return 0;
}
