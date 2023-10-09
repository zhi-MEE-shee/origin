#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>


void printQuantityOfSigns(std::string str)
{
    std::unordered_map<char, int> M;

    /* ������� �� ���� i. 
     * ���� �� ����������� � ����������, �� ��������� ��� �� ��������� 1
     * � ��������� ������: �������������� �������� 
     */
    for (int i = 0; str[i]; i++){
		if (M.find(str[i]) == M.end()){
            M.insert(std::make_pair(str[i], 1));
        }
		else{
            M[str[i]]++;
        }
    }

    /* ���
    *it.first  - ��� ����
    *it.second - ��������
    */
    for (const auto& it : M) {
        std::cout<< it.first << ": " << it.second << '\n';
    }
}


int main() {
	
	std::string s {"Hello world!!"};
    printQuantityOfSigns(s);

	return 0;
}
