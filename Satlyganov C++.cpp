#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <Windows.h>

using namespace std;


void first(int ch) {
	if (ch > 7) {
		cout << "Привет \n";
	}
}
void second(char const* name) {
	int i;
	char const* valid_value = "Вячеслав";
	i = strcmp(valid_value, name);
	if (i == 0) {
		cout << "Привет, Вячеслав\n";
	}
	else {
		cout << "Нет такого имени \n";
	}
}
void third(string m) {
	vector<int> v;
	while (1)
	{
		m += cin.get();
		if (m.find("\n") != -1)
			break;
	}
	auto ptr = m.c_str();
	char* endptr = nullptr;
	while (ptr != m.c_str() + m.size()) {
		auto value = strtol(ptr, &endptr, 10);
		if (ptr == endptr) {
			ptr++;
		}
		else {
			ptr = endptr;
			v.push_back(value);
		}
	}
	if (v.empty())
		cout << "Массив пустой \n";
	for (size_t count = 0; count < v.size(); count++) {
		if ((v[count] % 3) == 0)
			cout << v[count] << " ";;
	}
	cout << "\n";
}
int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int choise, n;
	string in, str, mass;
	char const* inName;
	//vector <int> v;
	bool repeat = true;
	while (repeat) {
		cout << "Выберите задание, 1-первое, 2-второе, 3-третье, 4 выход \n";
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "Введите число \n";
			cin >> n;
			first(n);
			break;
		case 2:
			cout << "Введите имя \n";
			cin >> in;
			inName = in.c_str();
			second(inName);
			break;
		case 3:
			cout << "Введите массив через пробел, до нажатия Enter \n";
			cin >> mass;
			third(mass);
			break;
		case 4:
			repeat = false;
			break;
		}

	}

}
