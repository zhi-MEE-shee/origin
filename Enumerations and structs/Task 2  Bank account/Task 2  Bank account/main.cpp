#include <iostream>
using namespace std;

struct Account_info {

	int account_num;
	string owner_name;
	double balance;

};

Account_info getNewInfo() {

	Account_info user;

	cout << "¬ведите номер счета: ";
	cin >> user.account_num;
	cout << "¬ведите им€ владельца: ";
	cin >> user.owner_name;
	cout << "¬ведите баланс: ";
	cin >> user.balance;

	return user;
}
void balance_change(Account_info& user) {
	
	cout << "¬ведите новый баланс: ";
	cin >> user.balance;

}

void printAccInfo(Account_info& user) {

	cout << "¬аш счет: " 
		<< user.account_num << ", "
		<< user.owner_name << ", "
		<< user.balance << endl;

}



int main() {

	setlocale(LC_ALL, "Russian");

	Account_info new_client{ getNewInfo() };
	balance_change(new_client);
	printAccInfo(new_client);


	return 0;
}
