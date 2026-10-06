class Account {
    int accountNumber;
    double balance;

   
    Account(int accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;

        System.out.println("Account Constructor");
    }

    
    void displayAccountDetails() {
        System.out.println("Account Number : " + accountNumber);
        System.out.println("Balance        : " + balance);
    }
}

class SavingsAccount extends Account {
    double interestRate;

    
    SavingsAccount(int accountNumber, double balance, double interestRate) {
        super(accountNumber, balance);
        this.interestRate = interestRate;

        System.out.println("SavingsAccount Constructor");
    }
}


class PremiumSavingsAccount extends SavingsAccount {
    String extraBenefits;

    PremiumSavingsAccount(int accountNumber, double balance,
                          double interestRate, String extraBenefits) {

        super(accountNumber, balance, interestRate);
        this.extraBenefits = extraBenefits;

        System.out.println("PremiumSavingsAccount Constructor");
    }

    
    double calculateTotalBalance() {
        double interest = balance * interestRate / 100;
        return balance + interest;
    }

    
    void displayPremiumDetails() {
        displayAccountDetails();
        System.out.println("Interest Rate  : " + interestRate + "%");
        System.out.println("Extra Benefits : " + extraBenefits);
        System.out.println("Total Balance  : " + calculateTotalBalance());
    }
}


public class q1 {
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