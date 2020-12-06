#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { Кібербезпека, Програмування, IT, Інженерія, Системи };

string strSpecialty[] = { "Кібербезпека", "Програмування", "IT", "Інженерія" , "Системии" };

struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physics;
	short unsigned math;
	short unsigned informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Sort(Student* s, const int N);
int BinSearch(Student* s, const int N, const string prizv, const Specialty specialty);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Кількість студентів: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);

	cout << "================================================================================" << endl;
	delete[] s;
}

void Create(Student* s, const int N)
{
	int kurs, specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "№ " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kurs;
		cout << "  спеціальність (0- Кібербезпека, 1- Програмування,2- IT,3- Інженерія ,4-Системии ): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  оцінка з фізики: "; cin >> s[i].physics;
		cout << "  оцінка з математики: "; cin >> s[i].math;
		cout << "  оцінка з інформатики: "; cin >> s[i].informatics;
	}
}
void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].informatics > p[i1 + 1].informatics)
				||
				(p[i1].informatics == p[i1 + 1].informatics &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

void Print(Student* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Інформатика |"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "      "
			<< "| " << setw(6) << right << s[i].informatics << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}

int BinSearch(Student* s, const int N, const string prizv, const Specialty specialty)
{
	int L = 0, R = N - 1, m;
	do
	{
		m = (L + R) / 2;
		if (s[m].prizv == prizv && s[m].specialty == specialty)

			return m;
		if ((s[m].specialty < specialty)
			||
			(s[m].specialty == specialty &&
				s[m].prizv < prizv))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;

}




