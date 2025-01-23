#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// exceptie personalizata
class NumePersContactException : public exception
{
public:
	string mesaj;
	NumePersContactException() {
		mesaj = "EXCEPTIE! Atributul numePersContact este un string invalid!";
	}
};

class IndexPretExcursieException : public exception
{
public:
	string mesaj;
	IndexPretExcursieException() {
		mesaj = "EXCEPTIE! Index invalid!";
	}
};

class Sejur {
private:
	const unsigned int id; // numar intreg pozitiv constant 
	char* destinatie; // sir de caractere 
	float pretBaza; // numar real 
	int nrExcursiiOptionale; // numar intreg 
	float* pretExcursie; // vector alocat dinamic cu valori reale (pozitive)
	string numePersContact; // sir de caractere 
	static int contor; // numar intreg static 

public:
	
	// constructor implicit (fara parametri)
	Sejur() : id(0) 
	{
		this->destinatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->destinatie, "Necunoscuta");

		this->pretBaza = 0;

		this->nrExcursiiOptionale = 1;

		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = 0;
		}

		this->numePersContact = "Necunoscuta";

		this->contor = contor++;
	}

	// constructor cu parametri 
	Sejur(const char* destinatie,
		  float pretBaza,
		  int nrExcursiiOptionale,
		  float* pretExcursie,
		  string numePersContact) : id(100) 
	{
		this->destinatie = new char[strlen(destinatie) + 1];
		strcpy(this->destinatie, destinatie);

		this->pretBaza = pretBaza;

		this->nrExcursiiOptionale = nrExcursiiOptionale;

		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = pretExcursie[i];
		}

		this->numePersContact = numePersContact;

		this->contor = contor++;
	}

	// constructor de copiere 
	Sejur(const Sejur& sej) : id(101)
	{
		this->destinatie = new char[strlen(sej.destinatie) + 1];
		strcpy(this->destinatie, sej.destinatie);

		this->pretBaza = sej.pretBaza;

		this->nrExcursiiOptionale = sej.nrExcursiiOptionale;

		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = sej.pretExcursie[i];
		}

		this->numePersContact = sej.numePersContact;

		this->contor = contor++;
	}

	// supraincarcare operator de atribuire (=)
	Sejur& operator=(const Sejur& sej) 
	{
		// pas 1 -> dezalocare (tot ce este alocat dinamic)
		if (this->destinatie != NULL) {
			delete[] this->destinatie;
		}

		if (this->pretExcursie != NULL) {
			delete[] this->pretExcursie;
		}

		// pas 2 -> atribuire atribute (constructorul de copiere)
		this->destinatie = new char[strlen(sej.destinatie) + 1];
		strcpy(this->destinatie, sej.destinatie);

		this->pretBaza = sej.pretBaza;

		this->nrExcursiiOptionale = sej.nrExcursiiOptionale;

		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = sej.pretExcursie[i];
		}

		this->numePersContact = sej.numePersContact;

		this->contor = contor++;

		// pas 3 -> returnare valoare 
		return*this;
	}

	// functie de sortare vector
	void sortareVectorCrescator(int n, float* v) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (v[i] > v[j]) {
					swap(v[i], v[j]);
				}
			}
		}
	}

	// supraincarcare operator<< (operatorul de afisare)
	friend ostream& operator<<(ostream& out, Sejur& sej) {
		out << "ID: " << sej.id << " | DESTINATIE: " << sej.destinatie << " | PRET BAZA: " << sej.pretBaza
			<< " | NUMAR EXCURSII OPTIONALE: " << sej.nrExcursiiOptionale << " |";
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			out << " pret excursie " << i + 1 << " = " << sej.pretExcursie[i] << " ";
		}
		out << "| NUME PERS CONTACT: " << sej.numePersContact << " | CONTOR: " << sej.contor;
		out << endl;
		return out;
	}
	
	// metoda afisare cu sortare vector
	void afisare(Sejur& sej){
		sej.sortareVectorCrescator(sej.nrExcursiiOptionale, sej.pretExcursie);
		cout << "ID: " << sej.id << " | DESTINATIE: " << sej.destinatie << " | PRET BAZA: " << sej.pretBaza
			<< " | NUMAR EXCURSII OPTIONALE: " << sej.nrExcursiiOptionale << " |";
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			cout << " pret excursie " << i + 1 << " = " << sej.pretExcursie[i] << " ";
		}
		cout << "| NUME PERS CONTACT: " << sej.numePersContact << " | CONTOR: " << sej.contor;
		cout << endl;
	}

	// supraincarcare operator>> (operatorul de citire)
	friend istream& operator>>(istream& in, Sejur& sej) {
		cout << "Destinatie: ";
		delete[] sej.destinatie;
		char buffer[100];
		in >> buffer;
		sej.destinatie = new char[strlen(buffer) + 1];
		strcpy(sej.destinatie, buffer);

		cout << "Pret baza: ";
		in >> sej.pretBaza;

		cout << "nrExcursiiOptionale: ";
		in >> sej.nrExcursiiOptionale;

		delete[] sej.pretExcursie;
		sej.pretExcursie = new float[sej.nrExcursiiOptionale];
		for (int i = 0; i < sej.nrExcursiiOptionale; i++) {
			cout << "elementul " << i + 1 << " = ";
			in >> sej.pretExcursie[i];
		}

		cout << "nume pers contact: ";
		in >> sej.numePersContact;

		return in;
	}

	// destructor 
	~Sejur() {
		if (this->destinatie != NULL) {
			delete[] this->destinatie;
		}

		if (this->pretExcursie != NULL) {
			delete[] this->pretExcursie;
		}
	}

	// constructor hibrid (constructor cu un singur parametru)
	Sejur(int _id) : id(_id) {
		this->destinatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->destinatie, "Necunoscuta");

		this->pretBaza = 0;

		this->nrExcursiiOptionale = 1;

		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = 0;
		}

		this->numePersContact = "Necunoscuta";

		this->contor = contor++;
	}

	// functii accesor (get + set)

	// numePersContact
	string getNumePersContact() {
		if (this->numePersContact == "Necunoscuta") {
			throw NumePersContactException();
		}
		else {
			return this->numePersContact;
		}
	}
	void setNumePersContact(const string numePersContactNou) {
		numePersContact = numePersContactNou;
	}

	// pretExcursie -> get si set pentru vector 
	float getPretExcursie(int index) {
		if (index < 0 && index > nrExcursiiOptionale)
			throw IndexPretExcursieException();
		else
			return pretExcursie[index];
	}
	void setPretExcursie(int _nrExcursiiOptionale, float* _pretExcursie) {
		if (pretExcursie != NULL) {
			delete[] pretExcursie;
		}
		if (_nrExcursiiOptionale != 0 && _pretExcursie != NULL) {
			this->nrExcursiiOptionale = _nrExcursiiOptionale;

			this->pretExcursie = new float[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = _pretExcursie[i];
			}
		}
		else {
			this->nrExcursiiOptionale = 1;

			this->pretExcursie = new float[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = 0;
			}
		}
	}

	int getNrMaximExcursii(float bugetMaximSejur) {
		int nr = 0;
		float buget = 0; 

		sortareVectorCrescator(nrExcursiiOptionale, pretExcursie);
		
		int i = 0;
		while (buget + pretExcursie[i] <= bugetMaximSejur 
							&& buget + pretExcursie[i] <= pretBaza 
							&& i < nrExcursiiOptionale) 
		{
			nr++;
			buget += pretExcursie[i];
			i++;
		}

		return nr;
	}

	// supraincarcare operator float 
	explicit operator float() {
		float costTotal = 0;
		if (pretExcursie != NULL)
			for (int i = 0; i < nrExcursiiOptionale; i++)
				costTotal += pretExcursie[i];
		else
			costTotal = 0;
		return costTotal;
	}

	// supraincarcare operator-- (varianta postdecrementare)
	Sejur operator--(int x) {
		
		Sejur copie = *this;

		if (this->nrExcursiiOptionale != 0) {
			float pretMinim = this->pretExcursie[0];
			int aparitiiPretMinim = 1;
			for (int i = 1; i < this->nrExcursiiOptionale; i++) {
				if (this->pretExcursie[i] == pretMinim) {
					aparitiiPretMinim++;
				}
				else {
					if(this->pretExcursie[i] < pretMinim)
						pretMinim = this->pretExcursie[i];
				}
			}

			int nrNou = nrExcursiiOptionale - aparitiiPretMinim;
			float* excursiiNoi = new float[nrNou];
			int indexNou = 0;

			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				if (this->pretExcursie[i] != pretMinim) {
					excursiiNoi[indexNou++] = this->pretExcursie[i];
				}
			}

			delete[] this->pretExcursie;
			this->pretExcursie = excursiiNoi;
			this->nrExcursiiOptionale = nrNou;
		}

		return copie;

	}
};

int Sejur::contor = 0;

void main() {
	cout << "--------------- Constructor implicit (fara parametri) ---------------" << endl;
	Sejur sj; 
	cout << "sj -> " << sj;

	cout << endl;

	cout << "--------------- Constructor cu parametri ---------------" << endl;
	Sejur sj1("Maldive", 25000, 3, new float[3] {3600, 4700, 8000}, "Amalia Popescu");
	cout << "sj1 -> " << sj1;

	Sejur sj2("Bali", 35000, 2, new float[2] {1600, 3700}, "Ionel Deaconu");
	cout << "sj2 -> " << sj2; 

	Sejur sj3("Italia", 9000, 4, new float[4] {7600, 1700, 3400, 2500}, "Stefania Savu");
	cout << "sj3 -> " << sj3;

	cout << endl;

	cout << "--------------- Constructor de copiere ---------------" << endl;
	Sejur sj4(sj1);
	cout << "sj4 = sj1 -> " << sj4;

	cout << endl;

	cout << "--------------- Operator =  ---------------" << endl;
	Sejur sj5;
	sj5 = sj2; 
	cout << "sj5 = sj2 -> " << sj5;

	cout << endl;

	cout << "--------------- Constructor hibrid  ---------------" << endl;
	Sejur sj6(102);
	cout << "sj6 -> " << sj6;

	cout << endl;
	
	cout << "--------------- Getter (functie accesor) pentru atributul numePersContact ---------------" << endl;
	try {
		cout << sj3.getNumePersContact() << endl;
	}
	catch (NumePersContactException& e) {
		cerr << e.mesaj << endl;
	}
	catch (...) {
		cerr << "orice eroare :)" << endl;
	}

	try {
		cout << sj.getNumePersContact() << endl;
	}
	catch (NumePersContactException& e) {
		cerr << e.mesaj << endl;
	}
	catch (...) {
		cerr << "orice eroare :)" << endl;
	}

	cout << endl;

	cout << "--------------- Setter (functie accesor) pentru atributul numePersContact ---------------" << endl;
	try {
		cout << "numePersContact inainte de setter: ";
		cout << sj1.getNumePersContact() << endl;
	}
	catch (NumePersContactException& e) {
		cerr << e.mesaj << endl;
	}
	catch (...) {
		cerr << "orice eroare :)" << endl;
	}
	sj1.setNumePersContact("Ioana Radoi");
	try {
		cout << "numePersContact dupa setter: ";
		cout << sj1.getNumePersContact() << endl;
	}
	catch (NumePersContactException& e) {
		cerr << e.mesaj << endl;
	}
	catch (...) {
		cerr << "orice eroare :)" << endl;
	}

	cout << endl;

	cout << "--------------- Getter (functie accesor) pentru atributul pretExcursie ---------------" << endl;
	try {
		cout << "" << sj3.getPretExcursie(2) << endl;
	}
	catch (IndexPretExcursieException& e) {
		cerr << e.mesaj << endl;
	}
	catch (...) {
		cerr << "orice eroare :)" << endl;
	}

	try {
		cout << "" << sj3.getPretExcursie(10) << endl;
	}
	catch (IndexPretExcursieException& e) {
		cerr << e.mesaj << endl; // nu merge -> nu se afiseaza mesajul din clasa 
	}
	catch (...) {
		cerr << "orice eroare :)" << endl;
	}

	cout << endl;

	cout << "--------------- Setter (functie accesor) pentru atributul pretExcursie ---------------" << endl;
	sj3.setPretExcursie(5, new float[5] {2500, 6700, 5560, 6700, 1900});
	cout << "sj3 -> " << sj3;

	cout << endl;
	
	/*
	cout << "--------------- Operator >> (operator de citire) ---------------" << endl;
	Sejur sj7; 
	cin >> sj7;
	cout << "sj7 -> " << sj7;
	*/

	cout << endl;

	cout << "--------------- Operator float (supraincarcare operator de cast - varainata explicita) ---------------" << endl;
	cout << (float)sj3 << endl;

	cout << endl;

	cout << endl;

	cout << "--------------- Metoda getNrMaximExcursii(float bugetMaximSejur) ---------------" << endl;
	cout << sj3.getNrMaximExcursii(31000);
	cout << endl;
	cout << "sj3 (vector sortat crescator) -> " << sj3;

	cout << endl;

	cout << "--------------- Operator-- (varianta postdecrementare) ---------------" << endl;
	int x = 1;
	sj3.setPretExcursie(7, new float[7] {1900, 2500, 6700, 1900, 5560, 6700, 1900});
	cout << "sj3 -> ";
	sj3.afisare(sj3);
	sj3.operator--(x);
	cout << "sj3 -> " << sj3;
}