#include <iostream>
using namespace std;

struct Account_info {

	int account_num;
	string owner_name;
	double balance;

};

Account_info getNewInfo() {

	Account_info user;

	cout << "������� ����� �����: ";
	cin >> user.account_num;
	cout << "������� ��� ���������: ";
	cin >> user.owner_name;
	cout << "������� ������: ";
	cin >> user.balance;

	return user;
}
void balance_change(Account_info& user) {
	
	cout << "������� ����� ������: ";
	cin >> user.balance;

}

void printAccInfo(Account_info& user) {

	cout << "��� ����: " 
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
