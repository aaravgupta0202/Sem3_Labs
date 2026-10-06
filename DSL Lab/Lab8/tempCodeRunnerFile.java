class Account {
    int accountNumber;
    double balance;

    // Constructor
    Account(int accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;

        System.out.println("Account Constructor");
    }

    // Method to display account details
    void displayAccountDetails() {
        System.out.println("Account Number : " + accountNumber);
        System.out.println("Balance        : " + balance);
    }
}

// First derived class
class SavingsAccount extends Account {
    double interestRate;

    // Constructor
    SavingsAccount(int accountNumber, double balance, double interestRate) {
        super(accountNumber, balance);
        this.interestRate = interestRate;

        System.out.println("SavingsAccount Constructor");
    }
}

// Second derived class
class PremiumSavingsAccount extends SavingsAccount {
    String extraBenefits;

    // Constructor
    PremiumSavingsAccount(int accountNumber, double balance,
                          double interestRate, String extraBenefits) {

        super(accountNumber, balance, interestRate);
        this.extraBenefits = extraBenefits;

        System.out.println("PremiumSavingsAccount Constructor");
    }

    // Method to calculate total balance
    double calculateTotalBalance() {
        double interest = balance * interestRate / 100;
        return balance + interest;
    }

    // Method to display complete details
    void displayPremiumDetails() {
        displayAccountDetails();
        System.out.println("Interest Rate  : " + interestRate + "%");
        System.out.println("Extra Benefits : " + extraBenefits);
        System.out.println("Total Balance  : " + calculateTotalBalance());
    }
}

// Main class
public class BankingApplication {
    public static void main(String[] args) {

        System.out.println("===== CONSTRUCTOR INVOCATION =====");

        PremiumSavingsAccount account =
            new PremiumSavingsAccount(
                101,
                10000.0,
                5.0,
                "Free ATM Withdrawals"
            );

        System.out.println();

        System.out.println("===== ACCOUNT DETAILS =====");
        account.displayPremiumDetails();
    }
}