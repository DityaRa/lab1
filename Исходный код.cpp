#include "windows.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
clock_t t1; void Rtime(); int ns = 0;

class MainTime
{

private:
	int ssek = ns;
public:
	bool setTime(int h, int m, int s){
		if (h < 24 && h >= 0 && m < 60 && m >= 0 && s < 60 && s >= 0){
			ns = h * 3600 + m * 60 + s;
			return false;
		}
		cout << "Error: Неверный фотрмат времени" << endl;
		return true;
	}
	void getHoarTime(){
		int dsek = (clock() - t1) / 1000 + ns;
		per(dsek, 1);

	}
	void getMinTime(){
		int dsek = (clock() - t1) / 1000 + ns;
		per(dsek, 2);

	}
	void  getSekTime(){
		int dsek = (clock() - t1) / 1000 + ns;
		per(dsek, 3);

	}
	void  getTimeS(){
		int dsek = (clock() - t1) / 1000 + ns;
		per(dsek, 4);

	}
	void  getTimeM() {
		;
		int dsek = (clock() - t1) / 1000 + ns;
		per(dsek, 5);

	}
	string per(int sek, int id) {
		int hp = 0, mp = 0, sp = 0;
		if (sek >= 3600)
		{
			hp = sek / 3600;
			sek = sek - hp * 3600;
		}
		else hp = 0;

		if (sek >= 60)
		{
			mp = sek / 60;
			sek = sek - mp * 60;
		}
		else mp = 0;
		sp = sek;
		if (id == 1) {
			cout << hp << endl;
			goto a;
			return "";
		}

		if (id == 2) {
			cout << mp << endl;
			goto a;
			return "";
		}
		if (id == 3){
			cout << sp << endl;
			goto a;
			return "";
		}
		if (id == 4) {
			cout << hp << ":" << mp << ":" << sp << endl;
			goto a;
			return 0;
		}
		if (id == 5) {
			cout << hp << " часов " << mp << " минут " << sp << " секунд" << endl;
			goto a;
			return "";
		}
	a:Rtime();
		return "";
	}
};
MainTime t;
void Init(MainTime t);
void Menu(MainTime t)
{
	int vb;
	cout << "Время меню (v1.0 RA)" << endl;
	cout << "1.Установить время" << endl << "2.Получить время" << endl << "3.Выход" << endl;
	cin >> vb;
	switch (vb)
	{
	case 1: {Init(t); break; }
	case 2: {Rtime(); break; }
	case 3: {exit(0); }
	default: {cout << "Error: Неверное значение" << endl; }
	}
}

void Rtime()
{
	int vb;
a:cout << "Выберите тип:" << endl;
	cout << "1.Через строку" << endl << "2.Через систему" << endl << "3.Получить часы" << endl << "4.Получить минуты" << endl << "5.Получить секунды" << endl << "6.Назад" << endl;
	cin >> vb;
	switch (vb)
	{
	case 1:t.getTimeM(); break;
	case 2:t.getTimeS(); break;
	case 3: t.getHoarTime(); break;
	case 4: t.getMinTime(); break;
	case 5:t.getSekTime(); break;
	case 6:Menu(t);
	default:cout << "Error: Неверное значение" << endl; break;
	}
	goto a;
}

void Init(MainTime t)
{
	int h, m, s;
	do {
		cout << "Введите часы:" << endl;
		cin >> h;
		cout << "Введите минуты:" << endl;
		cin >> m;
		cout << "Введите секунды:" << endl;
		cin >> s;
	} while (t.setTime(h, m, s));
	t1 = clock();
	Menu(t);
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	t1 = clock();
	Menu(t);
}
