#include <iostream>     //boilerplate shortcut     cppmain + tab
#include<iomanip>    
using namespace std;

struct Expense{
    float amount;
    string category;
};

Expense expense[50];
int expenseCount = 0;
float totalAmountOfExpense;

void enterExpense(){
   do{            // // Outermost loop: keep adding expenses until user says No
     if(expenseCount >= 50) {
        cout << "You have reached maximum number of Expenses!!!";
        return;
    }
    while (true){    // This inner loop is to make assure the user enters the correct option alphabet.
        cout << "\n\n"                            
             << "(a) Food" << endl
             << "(b) Transport" << endl
             << "(c) Shopping" << endl
             << "(d) Health" << endl
             << "(e) Billing" << endl
             << "(f) Education" << endl
             << "Enter category (a/b/c): ";
    char categoryChoice;
    cin >> categoryChoice;
    if (categoryChoice == 'a') { expense[expenseCount].category = "Food"; break; }
    else if(categoryChoice == 'b'){ expense[expenseCount].category = "Transport"; break; }   
    else if(categoryChoice == 'c'){ expense[expenseCount].category = "Shopping"; break; }
    else if(categoryChoice == 'd'){ expense[expenseCount].category = "Health"; break; }
    else if(categoryChoice == 'e'){ expense[expenseCount].category = "Billing"; break; }
    else if(categoryChoice == 'f'){ expense[expenseCount].category = "Education"; break; }
    else cout << endl << "Invalid category choice!! Please enter a valid option." << endl << endl;
}  //End of category choice loop

    //  ===== AMOUNT =====
    do{   // loop assures input is positive and more than 0.
    cout << "Enter your expense : Rs ";          
    cin >> expense[expenseCount].amount;      
    }while(expense[expenseCount].amount <= 0);

    expenseCount++;    // This is the main counter to keep track of number of expense entries

    //  ===== LOOP THAT ASK TO CONTINUE =====
    string choiceToAddMoreExpenses;
    while(true) {
    cout << "\nDo you want to add more expenses (Y/N): ";
    cin >> choiceToAddMoreExpenses;
    choiceToAddMoreExpenses[0] = toupper(choiceToAddMoreExpenses[0]);  //converts to uppercase letter

    if(choiceToAddMoreExpenses == "Y") {
        break;  // exit Y/N loop, outer loop runs again
    }
    else if(choiceToAddMoreExpenses == "N"){
        return;  // exit function completely → back to main menu 
    }
    else {
    cout << "Oops!! Choose b/w Y or N." << endl;
    }
}

   }while(true); //Outermpost loop ends here
}

void viewExpense() {
    totalAmountOfExpense = 0;  // Without this reset, this var keeps summing the previous values too. Total Expense is storing the previous total   and when the loop runs it adds all the array values
    for(int j = 0; j < expenseCount; j++) {
        totalAmountOfExpense += expense[j].amount;
        cout << "================================" << endl
             << "|  Category :" << setw(18) << left << expense[j].category << "|" << endl
             << "|  Amount : Rs " << setw(16) << left << expense[j].amount << "|" << endl
             << "================================\n\n";
             
    }
    cout << "Your total expense is : Rs " << totalAmountOfExpense << "/-" << endl;
}
void viewExpenseByCategory(){
    string choice, category = "";       //It inputs the category to compare with categories in the list of expenses
    float subTotal = 0.0;     //For Subtotal of all the expenses within the required category
    while(true) {
    cout << "\n\n" 
             << "(a) Food" << endl
             << "(b) Transport" << endl
             << "(c) Shopping" << endl
             << "(d) Health" << endl
             << "(e) Billing" << endl
             << "(f) Education" << endl;
    cout << "\nSelect the category to view relevant expenses (a/b/c...): ";
    cin >> choice;
    if (choice == "a") { category = "Food"; break; }
    else if (choice == "b") { category = "Transport"; break; }   
    else if (choice == "c") { category = "Shopping"; break; }
    else if (choice == "d") { category = "Health"; break; }
    else if (choice == "e") { category = "Billing"; break; }
    else if (choice == "f") { category = "Education"; break; }
    else cout << endl << "Invalid category choice!! Please enter a valid option." << endl << endl;
    }  //End_Of_While_Loop

    
    for(int i = 0; i < expenseCount; i++){
        if(expense[i].category == category){
            subTotal += expense[i].amount;
            cout << "---Amount : Rs " << expense[i].amount << endl;
        }
    }
    cout << "===================================" << endl;
    cout << "|" << setw(25) << left <<"Total spent on " << category << ": Rs " << subTotal << " |" << endl;
    cout << "===================================" << endl;

}

void clearScreen() { 

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

}

int main() {
    int choice;
    while (true) {
    clearScreen();
    cout << "\n==============================\n"
         << "        Expense Tracker\n"
         << "==============================\n"    
         << "1: Enter expense" << endl
         << "2: View expense" << endl
         << "3: View expense by category" << endl
         << "4: Exit program" << endl
         << "Your Choice: " ;

    cin >> choice;

    if (cin.fail()) {           // if wrong type entered
    cin.clear();               // reset error state
    cin.ignore(1000, '\n');   // discard bad input
    cout << "Invalid input! Please enter a number." << endl;
    continue;               // skip the rest of loop and re-show menu
}

    switch (choice) {
        case 1:
        enterExpense();
        break;
        case 2:
        viewExpense();
        break;
        case 3:
        viewExpenseByCategory();
        break;
        case 4: {
        cout << "Exiting..." << endl;
        return 0;
        break;
        }
        default:
        cout << "Invalid option! Please try again :)" << endl;
        }
        cout << "_______________________________________________________________________________________________________________" << endl;
    }
}
