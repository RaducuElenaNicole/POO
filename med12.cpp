#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// INTERFATA = clasa abstracta fara atribute, contine doar metode virtuale pure 
class Interfata { 
	virtual void afisare() = 0;
};

// clasa abstracta = contine o metoda virtuala pura (are virtual si nu are return, este egala cu 0)
class Abstracta {
	virtual float claculVenit() = 0; // se pot adauga si alte atribute si/sau metode, etc.
};

// clasa Persoana -> ABSTRACTIZARE 
class Persoana : public Interfata {
public:
	int varsta;
	string nume;

	virtual void metodaVirtualaPura() = 0;

	Persoana() {
		this->varsta = 0;
		this->nume = "Necunoscut/a";
	}

	Persoana(int varsta, string nume) {
		this->varsta = varsta;
		this->nume = nume;
	}

	friend ostream& operator<< (ostream& out, Persoana& pers) {
		out << "Persoana -> VARSTA: " << pers.varsta << " | NUME: " << pers.nume;
		return out;
	}

	virtual void afisareNume() {
		cout << this->nume;
	}

	// Inherited via Interfata
	void afisare() override
	{
		cout << nume << " Interfata";
	}
};

class Student : public Persoana, Abstracta{
public:
	float bursa;

	Student() : Persoana() {
		this->bursa = 0;
	}

	Student(int varsta, string nume, float bursa) : Persoana(varsta, nume) {
		this->bursa = bursa;
	}

	friend ostream& operator<< (ostream& out, Student& stud) {
		out << "Student -> ";
		out << (Persoana&)stud;
		out << " | BURSA: " << stud.bursa;
		return out;
	}

	void afisareNume() {
		cout << this->nume << " + " << this->bursa; 
	}

	// Inherited via Persoana
	void metodaVirtualaPura() override
	{
		cout << "bursa: " << this->bursa << " | bursa marita: " << this->bursa * 1.3;
	}

	// Inherited via Abstracta
	float claculVenit() override
	{
		this->bursa = this->bursa * 1.6;
		return this->bursa;
	}
};

class Angajat : public Persoana, Abstracta, Interfata {
public:
	int salariu;

	Angajat(int varsta, string nume, int salariu) : Persoana(varsta, nume) {
		this->salariu = salariu;
	}
	
	friend ostream& operator<<(ostream& out, Angajat& ang) {
		out << "Angajat -> " << (Persoana&)ang << " | SALARIU: " << ang.salariu;
		return out;
	}


	// Inherited via Persoana
	void metodaVirtualaPura() override
	{
		cout << "salariu marit: " << this->salariu * 2.5;
	}


	// Inherited via Abstracta
	float claculVenit() override
	{
		this->salariu = this->salariu * 1.2;
		return this->salariu;
	}


	// Inherited via Interfata
	void afisare() override
	{
		cout << nume << " | " << salariu;
	}

};

void main() {
	//Persoana* p;
	//cout << "p - " << p << endl;

	//Persoana* p1(25, "Ana Popescu");
	//cout << "p1 - " << p1 << endl;

	Student s;
	cout << "s - " << s << endl;

	Student s1(20, "Maria Matei", 350);
	cout << "s1 - " << s1 << endl;

	//p->afisareNume(); 
	//cout << " | ";
	s1.afisareNume();
	cout << endl;

	s1.metodaVirtualaPura();
	cout << endl;

	Angajat a1(39, "Victoria Miroiu", 2600);
	cout << "a1 -> " << a1;
	cout << endl;
	a1.metodaVirtualaPura();
	cout << endl;

	cout << s1.claculVenit() << endl;
	cout << a1.claculVenit() << endl;

	s1.afisare();
	cout << endl;
	a1.afisare();
	cout << endl;

	Persoana* p= new Angajat(39, "Victoria Miroiu", 2600);//upcasting  & downcasting
	p->afisare();
	// late binding 
}