#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std; 

class Sejur {
private:
	const unsigned int id;
	char* destinatie; // sir de caractere 
	float pretBaza;
	string numePersContact;
	int nrExcursiiOptionale; 
	float* pretExcursie; 
	string* destinatiiExcursii;
	static int contor; // numar sejururi legat de atribut const - id

public: 
	Sejur() : id(contor++) 
	{
		this->destinatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->destinatie, "Necunoscuta");

		this->pretBaza = 0; 

		this->numePersContact = "Necunoscut";

		this->nrExcursiiOptionale = 1; // !!!! ATENTIE !!!!
		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = 0;
		}
		this->destinatiiExcursii = new string[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->destinatiiExcursii[i] = "Necunoscut";
		}
	}

	Sejur(const char* destinatie, float pretBaza, string numePersContact,
			int nrExcursiiOptionale, float* pretExcursie, string* destinatiiExcursii) 
			: id(contor++) 
	{
		this->destinatie = new char[strlen(destinatie) + 1];
		strcpy(this->destinatie, destinatie);

		this->pretBaza = pretBaza;

		this->numePersContact = numePersContact;

		this->nrExcursiiOptionale = nrExcursiiOptionale;

		this->pretExcursie = new float[this->nrExcursiiOptionale];

		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = pretExcursie[i];
		}

		this->destinatiiExcursii = new string[this->nrExcursiiOptionale];

		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->destinatiiExcursii[i] = destinatiiExcursii[i];
		}
	}

	Sejur(const Sejur& sej) : id(contor++)
	{
		this->destinatie = new char[strlen(sej.destinatie) + 1];
		strcpy(this->destinatie, sej.destinatie);

		this->pretBaza = sej.pretBaza;

		this->numePersContact = sej.numePersContact;

		this->nrExcursiiOptionale = sej.nrExcursiiOptionale;

		this->pretExcursie = new float[this->nrExcursiiOptionale];

		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = sej.pretExcursie[i];
		}

		this->destinatiiExcursii = new string[this->nrExcursiiOptionale];

		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->destinatiiExcursii[i] = sej.destinatiiExcursii[i];
		}
	}

	// constructor hibrid -> constructorul cu un parametru (id)
	Sejur(int _id) : id(_id)
	{
		this->destinatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->destinatie, "Necunoscuta");

		this->pretBaza = 0;

		this->numePersContact = "Necunoscut";

		this->nrExcursiiOptionale = 1; // !!!! ATENTIE !!!!
		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = 0;
		}
		this->destinatiiExcursii = new string[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->destinatiiExcursii[i] = "Necunoscut";
		}
	}

	Sejur& operator=(Sejur& sej) {
		if (this->destinatie != NULL) {
			delete[] this->destinatie;
		}

		if (this->pretExcursie != NULL) {
			delete[] this->pretExcursie;
		}

		if (this->destinatiiExcursii != NULL) {
			delete[] this->destinatiiExcursii;
		}

		this->destinatie = new char[strlen(sej.destinatie) + 1];
		strcpy(this->destinatie, sej.destinatie);

		this->pretBaza = sej.pretBaza;

		this->numePersContact = sej.numePersContact;

		this->nrExcursiiOptionale = sej.nrExcursiiOptionale;

		this->pretExcursie = new float[this->nrExcursiiOptionale];

		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = sej.pretExcursie[i];
		}

		this->destinatiiExcursii = new string[this->nrExcursiiOptionale];

		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->destinatiiExcursii[i] = sej.destinatiiExcursii[i];
		}

		return*this;
	}

	friend ostream& operator<<(ostream& out, Sejur& sej) 
	{
		out << "ID: " << sej.id << " | PRET BAZA: " << sej.pretBaza <<
			" | NUME PERS CONTACT: " << sej.numePersContact <<
			" | NUMAR EXCURSII OPTIONALE: " << sej.nrExcursiiOptionale <<
			" | PRET EXCURSIE: "; 
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			out << sej.pretExcursie[i] << " "; 
		}
		out << endl; 
		
		out << " | DESTINATII EXCURSII: " << endl;
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			out << sej.destinatiiExcursii[i] << " ";
		}
		out << endl;
		out << " | CONTOR: " << sej.contor;
		out << endl;

		return out;
	}

	friend istream& operator>>(istream& in, Sejur& sej) {
		// const si static nu se modifica aici 

		cout << "Destinatie: ";
		delete[] sej.destinatie;
		char buffer[100];
		in >> buffer;
		sej.destinatie = new char[strlen(buffer) + 1];
		strcpy(sej.destinatie, buffer);

		cout << "Pret baza: "; 
		in >> sej.pretBaza;

		cout << "nume pers contact: ";
		in >> sej.numePersContact;

		cout << "nrExcursiiOptionale: ";
		in >> sej.nrExcursiiOptionale;

		cout << "vector pret excursie: ";
		delete[] sej.pretExcursie;
		sej.pretExcursie = new float[sej.nrExcursiiOptionale];
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			cout << "elementul " << i + 1 << " = ";
			in >> sej.pretExcursie[i];
		}

		cout << "vector destinatii: ";
		delete[] sej.destinatiiExcursii;
		sej.destinatiiExcursii = new string[sej.nrExcursiiOptionale];
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			cout << "elementul " << i + 1 << " = ";
			in >> sej.destinatiiExcursii[i];
		}

		return in; 
	}

	~Sejur() {
		if (this->destinatie != NULL) {
			delete[] this->destinatie;
		}

		if (this->pretExcursie != NULL) {
			delete[] this->pretExcursie;
		}

		if (this->destinatiiExcursii != NULL) {
			delete[] this->destinatiiExcursii;
		}
	}

	// functii accesor (get + set)

	/*
	const unsigned int id;
	char* destinatie; 
	float pretBaza;
	string numePersContact;
	int nrExcursiiOptionale; 
	float* pretExcursie; 
	string* destinatiiExcursii;
	static int contor; 
	*/

	char* getDestinatie() {
		return this->destinatie;
	}
	void setDestinatie(const char* destinatieNoua) 
	{
		if (this->destinatie != NULL) {
			delete[] this->destinatie;
		}

		this->destinatie = new char[strlen(destinatieNoua) + 1];
		strcpy(this->destinatie, destinatieNoua);
	}

	float getPretExcursie(int index) 
	{
		if (index < 0 && index >= nrExcursiiOptionale) {
			throw  new out_of_range("indexul este invalid");
		}
		else {
			return this->pretExcursie[index];
		}
		
	}

};

int Sejur::contor = 0;

void main() {
	Sejur sj; 
	cout << "sj -> " << sj;

	Sejur sj1("Maldive", 2500, "Andrei Popescu", 3, 
				new float[3] {2800, 4500, 3600}, 
				new string[3]{ "Paris", "Roma", "Atena" });
	cout << "sj1 -> " << sj1;

	Sejur sj2(sj1);
	cout << "sj2 -> " << sj2;

	Sejur sj3; 
	cout << "sj3 -> " << sj3;
	sj3 = sj1; 
	cout << "sj3 = sj1 -> " << sj3;

	Sejur sj4(10);
	cout << "sj4 -> " << sj4;

	cout << "Destinatie sj1 " << sj1.getDestinatie() << endl;
	sj1.setDestinatie("Bali");
	cout << "Destinatie sj1 " << sj1.getDestinatie() << endl;

	try {
		cout << "Pret excursie cu index 5 -> " << sj1.getPretExcursie(5) << endl;
	}
	catch (out_of_range& e) {
		cout << e.what();
	}

	Sejur sj5;
	cin >> sj5;
	cout << "sj5 -> " << sj5;
}