#include <iostream>
#include <fstream>

using namespace std;

int* create_array(int size) {
	
	return new int [size] ();
}


int main() {

	ifstream to_read ("in.txt");

	if (!to_read.is_open())
	{
		cout << "Error!" << endl;
		return 0;
	}

	int sizeN{ 0 };
	int sizeM{ 0 };

	to_read >> sizeN;

	int* arrayN{ create_array(sizeN) };

	for (int i = 0; i < sizeN; ++i) {

		to_read >> arrayN[i];
	}

	for (int i = 0; i < sizeN - 1; ++i) {

		if (arrayN[i] < arrayN[i + 1]) {

			int tmp = arrayN[i];
			arrayN[i] = arrayN[i + 1];
			arrayN[i + 1] = tmp;

		}
	}


	to_read >> sizeM;

	int* arrayM{ create_array(sizeM) };

	for (int i = 0; i < sizeM; ++i) {

		to_read >> arrayM[i];
	}



	for (int i = sizeM - 1; i > 0; --i) {

		if (arrayM[i] > arrayM[i - 1]) {

			int tmp = arrayM[i];
			arrayM[i] = arrayM[i - 1];
			arrayM[i - 1] = tmp;

		}
	}


	to_read.close();


	ofstream to_write("out.txt");

	to_write << sizeM << endl;

	for (int i = 0; i < sizeM; ++i) {

		to_write << arrayM[i] << ' ';

	}

	to_write << endl;
	to_write << sizeN << endl;

	for (int i = 0; i < sizeN; ++i) {

		to_write << arrayN[i] << ' ';

	}


	delete[] arrayM;
	delete[] arrayN;
	return 0;
}