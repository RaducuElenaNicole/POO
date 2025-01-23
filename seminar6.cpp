//SEMINAR 6 POO - 04.11.2024 - Sãpt 6

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
	friend Produs operator+(int intreg, Produs &prod) {
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

void main()
{
	Produs p1;
	Produs p2("zahar", "kg", 20, 2.5);
	Produs p3("cozonac", "kg", 3, 34.99);
	Produs p4("mere", "kg", 10.5, 28.5);
	Produs p5(p2);
	Produs p6 = p3;

	cout << "p1: "; cout << p1;
	cout << "p2: "; cout << p2;
	cout << "p3: "; cout << p3;
	cout << "p4: "; cout << p4;
	cout << "p5: "; cout << p5;
	cout << "p6: "; cout << p6;
	p3 = ++p6;
	cout << "p3: "; cout << p3;

	//Produs p7; 
	//cin >> p7;
	//cout << endl << "p7: "; cout << p7;

	float valoare = 20;
	Produs p8("chec", "kg", 4, 5);
	cout << "p8: "; cout << p8;

	Produs p9("amandina", "kg", 10.5, 28.5);
	cout << "p9: "; cout << p9;

	cout << endl;

	if (p8 == p9)
		cout << "DA! Produsele sunt la fel. Valoarea lor este aceeasi: " << p8.getValoare();
	else
		cout << "NU! Produsele NU sunt la fel. Valoarea lor NU este aceeasi." << endl
		<< "Valoarea lui p8: " << p8.getValoare()
		<< " | Valoarea lui p9: " << p9.getValoare();

	cout << endl;

	//if (p8 == 20)
	//	cout << "Produsele sunt la fel. Valoarea lor este aceeasi: " << p8.getValoare();
	//else
	//	cout << "Produsele NU are valoarea egala cu " << valoare << endl
	//	<< "Valoarea lui p8: " << p8.getValoare();

	cout << endl;

	p4++; 
	cout << "p4: "; cout << p4;

	valoare = p8;
	cout << "Supraincarcare operator de cast -> " << valoare << endl;

	int valoareIntreg = 20;
	Produs p10 = p9 + valoareIntreg;
	cout << "p10: "; cout << p10;
	cout << "Cantitate nemodificata: " 
		 << p9.getCantitate() 
		 << " | Valoarea intreaga cu care se modifica: " 
		 << valoareIntreg << " | Cantitate modificata: " 
		 << p10.getCantitate() 
		 << endl;

	valoareIntreg = 15;
	Produs p11 = valoareIntreg + p2;
	cout << "p11: "; cout << p11;
	cout << "Cantitate nemodificata: "
		<< p2.getCantitate()
		<< " | Valoarea intreaga cu care se modifica: "
		<< valoareIntreg << " | Cantitate modificata: "
		<< p11.getCantitate()
		<< endl;

	//de facut p1 + p2 -> supraincarcare adunare cu 2 produse -> concatenare de nume + unitatea de masura a lui p1 + adunare de cantitati + pretul lui p1 
}