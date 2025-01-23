// POO - seminar 13 - 13.01.2025
// STL
#include<iostream>
#include<map>
using namespace std;

// nume + varsta + marca 
// op<<
// regula celor 5 
// STL pt a gestiona obiecte de tip Persoana
// obiectele trebuie adaptate in mod corespunzator pentru a le utiliza 
// MAP (container asociat) 
// => asocierea intre marca persoanei (cheie primara, valoare care identifica in mod unic o persoana) 
// si persoana (restul detaliilor care caracterizeaza un obiect de tip Persoana)

class Persoana {
private:
	int marca;
	int varsta;
	string nume;
	
public:
	/*
	// 2 in 1 :))
	// constructor implicit + constructor cu parametri
	Persoana(int fmarca, int fvarsta = 0, string fnume = "Necunoscut/a") : 
		marca(fmarca), varsta(fvarsta), nume(fnume) 
	{ }
	*/

	Persoana() {
		this->marca = 0;
		this->varsta = 0;
		this->nume = "Necunoscut/a";
	}

	Persoana(int _marca, int _varsta, string _nume) {
		this->marca = _marca;
		this->varsta = _varsta;
		this->nume = _nume;
	}

	Persoana(const Persoana& pers) {
		this->marca = pers.marca;
		this->varsta = pers.varsta;
		this->nume = pers.nume;
	}

	Persoana operator= (const Persoana& pers) {
		this->marca = pers.marca;
		this->varsta = pers.varsta;
		this->nume = pers.nume;
		return*this;
	}

	friend ostream& operator<<(ostream& out, const Persoana& pers) {
		out << "Marca: " << pers.marca
			<< " | Varsta: " << pers.varsta
			<< " | Nume: " << pers.nume;
		return out;
	}

	int getMarca() {
		return this->marca;
	}
	void setMarca(int val) {
		this->marca = val;
	}
	int getVarsta() {
		return this->varsta;
	}
	string getNume() {
		return this->nume;
	}
};

void main() {
	Persoana p;
	cout << "p -> " << p << endl;

	Persoana p1(101, 23, "Anamaria");
	cout << "p1 -> " << p1 << endl;

	Persoana p2(102, 20, "Valentina");
	cout << "p2 -> " << p2 << endl;

	Persoana p3(103, 19, "Stefania");
	cout << "p3 -> " << p3 << endl;

	Persoana p4(p2);
	p4.setMarca(104);
	cout << "p4 -> " << p4 << endl;

	Persoana p5;
	p5 = p3;
	cout << p5.getMarca() << " | " 
		 << p5.getVarsta() << " | " 
		 << p5.getNume() << endl;
	p5.setMarca(105);
	cout << "p5 -> " << p5 << endl;

	Persoana p6(106, 22, "Maria");
	cout << "p6 -> " << p6 << endl;

	// vector dinamic de tipul Persoana
	cout << endl << "-------- Vector dinamic --------" << endl;
	Persoana* vectPD;
	vectPD = new Persoana[3]{p1, p2, p3};
	for (int i = 0; i < 3; i++) {
		cout << vectPD[i] << endl;
	}

	// vector static de tipul Persoana
	cout << endl << "-------- Vector static --------" << endl;
	Persoana vectPS[6]{ p1, p2, p3, p4, p5, p6 };
	for (int i = 0; i < 3; i++) {
		cout << vectPS[i] << endl;
	}

	// STL => definire obiect de tip MAP
	cout << endl << "-------- MAP pe baza vectorului static --------" << endl;
	map<int, Persoana> mapP;
	// container parametrizat la nivel de sablon prin intermediul a doua tipuri de date care se pot furniza distinct
	// MAP este o colectie de elemente
	// PAIR pentru definirea elementelor 
	for (int i = 0; i < sizeof(vectPS)/sizeof(Persoana); i++) {
		pair<int, Persoana> pereche(vectPS[i].getMarca(), vectPS[i]);
		mapP.insert(pereche);
	}
	map<int, Persoana>::iterator itrVectPS;
	for (itrVectPS = mapP.begin(); itrVectPS != mapP.end(); itrVectPS++) {
		cout << "[" << (*itrVectPS).first 
			 << " - ( " << itrVectPS->second 
			 << " ) ]" << endl;
	}

	cout << endl << "-------- MAP pe baza vectorului dinamic--------" << endl;
	map<int, Persoana, greater<int>> mapPD;
	for (int i = 0; i < 3; i++) {
		mapPD.insert(pair<int, Persoana> (vectPD[i].getMarca(), vectPD[i]));
	}
	map<int, Persoana>::iterator itrVectPD;
	for (itrVectPD= mapPD.begin(); itrVectPD != mapPD.end(); itrVectPD++) {
		cout << "[" << (*itrVectPD).first
			<< " - ( " << itrVectPD->second
			<< " ) ]" << endl;
	}
}