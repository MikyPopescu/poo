// Seminar13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class termo {
private:
	char* eticheta_termostat;
	float temperatura_citita;
	float temperatura_dorita;
public:
	virtual float temperatura_med_citita() {
		return this->temperatura_citita;


	}

	float get_Temperatura_citita() {
		return this->temperatura_citita;
	}

	float get_dorita() {
		return this->temperatura_dorita;
	}

	termo(const char* v_eticheta, float tc, float td)
	{
		if (v_eticheta != NULL)
		{
			this->eticheta_termostat = new char[strlen(v_eticheta) + 1];
			strcpy(this->eticheta_termostat, v_eticheta);

		}

		else
		{
			this->eticheta_termostat = new char[strlen("Anonim") + 1];
			strcpy(this->eticheta_termostat, "Anonim");
		}

		this->temperatura_citita = tc;
		this->temperatura_dorita = td;
	}

	termo(const termo & copie)
	{
		this->eticheta_termostat = new char[strlen(copie.eticheta_termostat) + 1];
		strcpy(this->eticheta_termostat, copie.eticheta_termostat);
		this->temperatura_citita = copie.temperatura_citita;
		this->temperatura_dorita = copie.temperatura_dorita;
	}
	termo& operator=(const termo& copie)
	{
		if (this->eticheta_termostat != NULL)
			delete[] this->eticheta_termostat;
		this->eticheta_termostat = new char[strlen(copie.eticheta_termostat) + 1];
		strcpy(this->eticheta_termostat, copie.eticheta_termostat);
		this->temperatura_citita = copie.temperatura_citita;
		this->temperatura_dorita = copie.temperatura_dorita;
		return *this;
	}
	termo()
	{
		this->eticheta_termostat = new char[strlen("anonim") + 1];
		strcpy(this->eticheta_termostat, "anonim");
		this->temperatura_citita = 0;
		this->temperatura_dorita = 0;
	}
	void set_eticheta(const char* v_eticheta)
	{
		if (v_eticheta != NULL)
		{
			delete[] this->eticheta_termostat;
			this->eticheta_termostat = new char[strlen(v_eticheta) + 1];
			strcpy(this->eticheta_termostat, v_eticheta);
		}
	}
	~termo()
	{
		delete[]this->eticheta_termostat;
	}
};

class BItermo : public termo {
private:
	float temperatura_par_citita;
public:
	virtual float temperatura_med_citita()

	{
		return get_Temperatura_citita() + this->temperatura_par_citita;

	}

};

class UCC {
private:

	string locatie;
	int nr_termostate;
	termo* multime_termostat;

public:
	UCC(string v_locatie, int v_nr_termostate, termo* v_multime_termostat)
	{
		if (v_locatie.length() > 0)
		{
			this->locatie = v_locatie;
		}
		else
		{
			this->locatie = "Anonim";
		}
		this->nr_termostate = 0;
		if (v_multime_termostat != NULL)
		{
			this->multime_termostat = new termo[nr_termostate];
			for (int i = 0; i < this->nr_termostate; i++)
			{
				this->multime_termostat[i] = v_multime_termostat[i];
			}
		}
	}
	UCC(const UCC& copie)
	{
		this->locatie = copie.locatie;
		this->nr_termostate = copie.nr_termostate;
		if (copie.nr_termostate != NULL)
		{
			this->multime_termostat = new termo[copie.nr_termostate];
			for (int i = 0; i < this->nr_termostate; i++)
			{
				this->multime_termostat[i] = copie.multime_termostat[i];
			}
		}

	}
	UCC()
	{
		this->locatie = "Necun";
		this->nr_termostate = 0;
		this->multime_termostat = NULL;
	}
	UCC & operator=(const UCC& copie)
	{
		this->locatie = copie.locatie;
		this->nr_termostate = copie.nr_termostate;
		if (copie.multime_termostat != NULL)
		{
			if (this->multime_termostat != NULL)
			{
				delete[] this->multime_termostat;
			}
			this->multime_termostat = new termo[copie.nr_termostate];

			for (int i = 0; i < this->nr_termostate; i++)
			{
				this->multime_termostat[i] = copie.multime_termostat[i];
			}
		}

		return *this;
	}
	~UCC()
	{
		if (this->multime_termostat != NULL)
		{
			delete[] this->multime_termostat;
		}
	}

};

int main()
{
	termo T1("dormitor", 22.5, 23.5);
	termo T2 = T1;
	termo T3;
	T3 = T1;
	termo T4;
	T3.set_eticheta("bucatarie");
	termo tx1[4] = { T1,T2,T3,T4 };
	termo tx2[3] = { T1,T3,T4 };
	UCC u1("ETAJ 1", 4, tx1);
	UCC u2("ETAJ 2", 3, tx2);
	UCC u3(u2);
	UCC u4;
	u4 = u1;

}

