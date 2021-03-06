// Seminar13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

enum tip_repetitie
{
	ZILNICA,
	SAPTAMANALA,
	LUNARA
};

class Activitate
{
private:
	const int id;
	static int nr_activitati;
	char* denumire;
	int durata;
	tip_repetitie periodicitate;
public:
	Activitate()  : id(nr_activitati++)
	{
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->durata = 0;
		this->periodicitate = ZILNICA;
	}
	Activitate(char* v_denumire, int v_durata, tip_repetitie v_periodicitate) :id(nr_activitati++)
	{
		if (v_denumire != NULL)
		{
			this->denumire = new char[strlen(v_denumire) + 1];
			strcpy(this->denumire, v_denumire);
		}
		else
		{

			this->denumire = new char[strlen("Anonim") + 1];
			strcpy(this->denumire, "Anonim");
		}
		if (v_durata > 0)
		{
			this->durata = v_durata;
		}
		else
		{
			this->durata = 0;
		}
		this->periodicitate = v_periodicitate;
	}

	~Activitate() {
		if (denumire != NULL)
			delete[]denumire;
	}

	Activitate(Activitate& copie):id(copie.id) {
		denumire = new char[strlen(copie.denumire) + 1];
		strcpy(denumire, copie.denumire);
		durata = copie.durata;
		periodicitate = copie.periodicitate;
	}

	Activitate& operator=(Activitate& copie) {
		if (this->denumire != NULL)
		{
			delete[] this->denumire;
		}
		this->denumire = new char[strlen(copie.denumire) + 1];
		strcpy(denumire, copie.denumire);
		durata = copie.durata;
		periodicitate = copie.periodicitate;
		return *this;
	}
    string getTipasString()
	{
		switch (this->periodicitate)
		{
		case ZILNICA:
			return "Zilnica";
		case LUNARA:
			return "Lunara";
		 default:
			 return "Saptamnala";

		}
			
	}
	friend ostream& operator << (ostream& out, Activitate& a)
	{
		out << "Id: " << a.id << endl;
		out << "Denumire: " << a.denumire << endl;
		out << "Tip repetitie: " << a.getTipasString()<<endl;
		out << "Duarata: " << a.durata << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Activitate& a)
	{
		cout << "Denumire:";
		char buff[50];
		in.getline(buff, 50);
		if (a.denumire != NULL)
		{
			delete[] a.denumire;
		}
		a.denumire = new char[strlen(buff) + 1];
		strcpy(a.denumire, buff);
		cout << "Durata: ";
		in >> a.durata;
		cout << "Periodicitate: Zilnica, Saptamanala, Orice";
		in.ignore();
		in.getline(buff, 50);
		if (strcmp(buff, "Zilnica") == 0)
		{
			a.periodicitate = ZILNICA;

		}
		else
			if (strcmp(buff, "Saptamanala") == 0)
			{
				a.periodicitate = SAPTAMANALA;
			}
			else
			{
				a.periodicitate = LUNARA;
			}
		return in;
	}

	Activitate& operator+=(int x) {
		if (this->durata + x < 24 * 365) {
			this->durata += x;
		}
		return*this;
	}

	bool operator!() {
		if (periodicitate == LUNARA)return true;
		else return false;
	}

	friend bool operator==(Activitate a1, Activitate a2) {
		if (a1.id == a2.id&&a1.durata == a2.durata)return true;
		else return false;

	}
	


};
int Activitate::nr_activitati = 0;

class Persoana
{
	char nume[50];
};

class Etapa
{
	Persoana* persoane;
	int numarPersoane;
	Activitate activitate();
	Etapa(Activitate a)
	{
		this->activitate = a;
	}
};







int main()
{
	char* nume = new char[strlen("Definire echipa") + 1];
	strcpy(nume, "Definire echipa");
	Activitate a1(nume, 10, ZILNICA);
	Activitate a2 = a1;
	cin >> a2;
	cout << a2;
	cout << a1;
	a1 += 4;
	cout << a1;
	cout << !a2;
	cout << (a1 == a2);
	Etapa etapa(a1);
	return 0;
}