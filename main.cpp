#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// holds each expense values
struct Expense {
    double amt;
    string category;
    string desc;
};

//adding a function to create expense and add it to a vector
void addExpense(vector<Expense>& expenses){
    Expense exp;

    cout << "Enter amount:" <<endl;
    cin >> exp.amt;
    while (exp.amt <= 0) {
        cout << "Enter a valid positive amount: ";
        cin >> exp.amt;}
    cout << "Enter category:" <<endl;
    cin >> exp.category;
    cout << "Enter short description:" <<endl;
    cin.ignore();
    getline(cin,exp.desc);

    expenses.push_back(exp);

}

//function to view all expenses
void viewExpenses(const vector<Expense>& expenses){
    int count = 1;
    for (const Expense& exp : expenses){
        cout << count << ")" <<endl;
        cout << "Amount: " << exp.amt << endl;
        cout << "Category: " << exp.category << endl;
        cout << "Description: " << exp.desc << endl;
        count++;
    }
}

//function to show summary 
void showSummary(const vector<Expense>& expenses){
    cout << "------ Summary ------" <<endl;
    // total amount of all expenses
    double total = 0;

    for (const Expense& exp : expenses){
        total+= exp.amt;
    }
    cout << "Total amount spent: " << total << endl;

    //to calculate total amt spent in each category
    map<string, double> categoryTotal;

    for (const Expense& exp : expenses) {
    categoryTotal[exp.category] += exp.amt;
    }

    for (const auto& item : categoryTotal) {
    cout << item.first << ": " << item.second << endl;
    }

    //to find category where user spent most
    double highest = 0;
    string highestCategory;

    for (const auto& item : categoryTotal) {
        if (item.second > highest) {
            highest = item.second;
            highestCategory = item.first;
        }
    }
    cout << "User spent the highest on: " << highestCategory <<endl;
        
}


int main() {
    cout << "------Expense Tracker------" <<endl;

    vector<Expense> expenses;
    int n = 0;

    // menu of choices
    while (n != 4) {
    cout << "\n1. Add Expense" << endl;
    cout << "2. View Expenses" << endl;
    cout << "3. Show Summary" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter choice: ";
    cin >> n;
    

    // using switch 
    switch(n){
        case 1:
        addExpense(expenses);
        break;

    case 2:
        viewExpenses(expenses);
        break;

    case 3:
        showSummary(expenses);
        break;

    case 4:
        cout << "Exiting....." << endl;
        break;

    default:
        cout << "Invalid choice" << endl;

    }
}


    return 0;
}