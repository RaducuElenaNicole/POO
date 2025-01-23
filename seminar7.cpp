//SEMINAR 7 POO - 11.11.2024 - Sãpt 7

#include<iostream>
#include<iomanip>
using namespace std;

class Produs
{
	char* numeProdus;
	char unitateDeMasura[5];
	int cantitate;
	float pret;

public:
	Produs(const char* fnumeProdus = "Nedefinit",
		const char* funitateDeMasura = "N/A",
		int fcantitate = 0,
		float fpret = 0) : cantitate(fcantitate), pret(fpret)
	{
		numeProdus = new char[strlen(fnumeProdus) + 1];
		strcpy_s(numeProdus, strlen(fnumeProdus) + 1, fnumeProdus);
		strcpy_s(unitateDeMasura, strlen(funitateDeMasura) + 1, funitateDeMasura);
	}

	Produs(const Produs& fprod) : cantitate(fprod.cantitate), pret(fprod.pret)
	{
		numeProdus = new char[strlen(fprod.numeProdus) + 1];
		strcpy_s(numeProdus, strlen(fprod.numeProdus) + 1, fprod.numeProdus);
		strcpy_s(unitateDeMasura, strlen(fprod.unitateDeMasura) + 1, fprod.unitateDeMasura);
	}

	Produs& operator=(Produs& fprodusGeneral)
	{
		numeProdus = new char[strlen(fprodusGeneral.numeProdus) + 1];
		strcpy_s(numeProdus, strlen(fprodusGeneral.numeProdus) + 1, fprodusGeneral.numeProdus);
		strcpy_s(unitateDeMasura, strlen(fprodusGeneral.unitateDeMasura) + 1, fprodusGeneral.unitateDeMasura);
		cantitate = fprodusGeneral.cantitate;
		pret = fprodusGeneral.pret;

		return*this;
	}

	friend ostream& operator<<(ostream& out, Produs& prod)
	{
		out << setw(20) << setiosflags(ios::left) << prod.numeProdus << resetiosflags(ios::left)
			<< setw(4) << prod.unitateDeMasura << " | "
			<< setw(5) << prod.cantitate << " | "
			<< setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod.pret << " | "
			<< setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod.getValoare() << " | " << "\n";

		return out;
	}

	friend void operator>>(istream& in, Produs& prod)
	{
		cout << "Introduceti detaliile despre produs: " << endl;

		char sirTemp[100];
		cout << "NUME: "; in >> sirTemp;
		prod.setNumeProdus(sirTemp);

		cout << "UNITATE DE MASURA: "; in >> prod.unitateDeMasura;
		cout << "CANTITATE: "; in >> prod.cantitate;
		cout << "PRET: "; in >> prod.pret;
	}

	bool operator==(Produs& p) {
		return getValoare() == p.getValoare();
	}

	bool operator==(float valoare) {
		return getValoare() == valoare;
	}

	friend bool operator==(float valoare, Produs& prod) {
		return prod.getValoare() == valoare;
	}

	//supraincarcare operator++ -> preincrementare 
	Produs& operator++() {
		cantitate++;
		return*this;
	}

	//supraincarcare operator++ -> prostincrementare 
	Produs operator++(int) {
		// int -> rol de a deosebi apelul
		Produs prodNou(*this); // prodNou -> copie a lui *this (-> produsul curent)
		cantitate++;
		return prodNou;
	}

	//operator de conversie / cast 
	//conversia unui obiect de tip clasa Produs la float => generare valorii => returneaza valoarea produsului 
	operator float()
	{
		return getValoare();
	}

	//supraincarcare operator de adunare 
	//adunarea intre produs si intreg
	Produs operator+(int intreg) {
		return Produs(numeProdus, unitateDeMasura, intreg + cantitate, pret);
	}

	//adunarea intre un intreg si un produs 
	friend Produs operator+(int intreg, Produs& prod) {
		return Produs(prod.numeProdus, prod.unitateDeMasura, prod.cantitate + intreg, prod.pret);
	}

	void setCantitate(int);
	void setNumeProdus(const char*);

	int getCantitate()
	{
		return cantitate;
	}

	float getValoare()
	{
		return pret * cantitate;
	}

	void afisareProdus()
	{
		cout << "NUME: " << numeProdus
			<< " | UNITATE DE MASURA: " << unitateDeMasura
			<< " | CANTITATE: " << cantitate
			<< " | PRET: " << pret
			<< " | VALOARE: " << getValoare()
			<< "\n";
	}

	void citireProdus()
	{
		cout << "Introduceti detaliile despre produs: " << endl;

		char sirTemp[100];
		cout << "NUME: "; cin >> sirTemp;
		setNumeProdus(sirTemp);

		cout << "UNITATE DE MASURA: "; cin >> unitateDeMasura;
		cout << "CANTITATE: "; cin >> cantitate;
		cout << "PRET: "; cin >> pret;
	}

	char* getNumeProdus() {
		return numeProdus;
	}

	~Produs()
	{
		delete[] numeProdus;
	}
};

void Produs::setCantitate(int fcantitate)
{
	if (fcantitate >= 0) {
		cantitate = fcantitate;
	}
	else {
		cerr << "EROARE! Cantitatea nu poate fi negativa!";
	}
}

void Produs::setNumeProdus(const char* numeNouProdus)
{
	if (strlen(numeNouProdus) > strlen(numeProdus))
	{
		delete[] numeProdus;
		numeProdus = new char[strlen(numeNouProdus) + 1];
	}
	strcpy_s(numeProdus, strlen(numeNouProdus) + 1, numeNouProdus);
}

// clasa Magazie este un container de produse -> MOSTENIRE 
// relatie de tip HAS-A vs IS-A
class Magazie {
private:
	char numeMagazie[20];
	int nrProduse; 
	// vector de pointeri la produse 
	Produs* vProd[100];

public:
	// constructor care are rol si de implicit si de explicit 
	Magazie(const char* fnumeMagazie = "N/A") : nrProduse(0) 
	{ 
		strcpy_s(numeMagazie, strlen(fnumeMagazie) + 1, fnumeMagazie);
	}

	// se supradefineste operatorul <<
	Magazie& operator<<(Produs* prod) 
	{
		vProd[nrProduse++] = prod;
		return*this; 
	}
	
	//supradefinirea operatorului de afisare 
	friend ostream& operator<<(ostream& out, Magazie& mag)
	{
		out << "NUME MAGAZIE: " << mag.numeMagazie << " | "
			<< "NUMAR DE PRODUSE: " << mag.nrProduse << " | "
			<< "PRODUSE: \n";

		for (int i = 0; i < mag.nrProduse; i++) {
			out << "          produsul " << i + 1 << " -> " << *mag.vProd[i]; 
			// derefentiere pentru accesarea valorii de la adresa de memorie mag.vProd[i]
			// vProd este vector !!!
			// operatorul cu proprietatea cea mai mare => . si [] (se evalueaza de la stanga la dreapta) 
		}
		
		out << "VALOAREA TOTALA PRODUSE: " << mag.valoareTotalaMagazie() << " \n ";

		return out;
	}

	float valoareTotalaMagazie() {
		float val = 0.0; 
		for (int i = 0; i < nrProduse; i++) {
			val += vProd[i]->getValoare();
		}
		return val; 
	}
};

void main()
{
	Magazie m1("Victoria");
	// Magazie -> obiect de tip flux 
	// produsele se trimit in obiectul de tipul clasei Magazie 
	m1 << new Produs("Mouse", "buc", 5, 89.99)
		<< new Produs("Laptop", "buc", 3, 4599.99)
		<< new Produs("Tastatura", "buc", 5, 550)
		<< new Produs("Monitor", "buc", 6, 1200); 
	cout << m1;
}

// supraincarcare cast pgt returnarea valoarea produselor din magazie 
