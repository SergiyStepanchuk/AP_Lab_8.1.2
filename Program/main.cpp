// Lab_8_1_2
// скануванням рядка рекурсивним способом

#include <iostream>
#include <string>
using namespace std;

int count_strs(const char* str, int i = 0) {
	bool y = 0;
	if (str[i - 1] == ',' && str[i + 1] == '-')
		y++;
	i++;
	return str[i + 1] != '\0' ? y + count_strs(str, i) : y;
}

char* change_str(char* str, char* tmp, int i = 0, int m = 0)
{
	if (str[i + 2] != '\0') {
		if (str[i] == ',' && str[i + 2] == '-') {
			*(tmp + m++) = '*';
			*(tmp + m) = '*';
			i += 2;
		}
		else tmp[m] = str[i];
		i++; m++;
		change_str(str, tmp, i, m);
	}
	else {
		tmp[m++] = str[i++];
		tmp[m++] = str[i];
		tmp[m] = '\0';
		str[0] = '\0';
		strcpy(str, tmp);
	}
	return tmp;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << (strlen(str) < 3 ? 0 : count_strs(str)) << " groups of ', -'" << endl;
	if (strlen(str) > 2)
		delete[] change_str(str, new char[strlen(str) + 1]);
	cout << "Modified string (param) : " << str << endl;
	return 0;
}