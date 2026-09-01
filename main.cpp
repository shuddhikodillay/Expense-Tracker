#include <iostream>
#include <vector>
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
    cout << "Enter category:" <<endl;
    cin >> exp.category;
    cout << "Enter small description:" <<endl;
    cin >> exp.desc;

    expenses.push_back(exp);

}

int main() {
    cout << "Expense Tracker" <<endl;


    return 0;
}