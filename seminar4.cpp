//SEMINAR 4 POO - 21.10.2024 - Sãpt 4

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

	//Constructor de copiere 
	//forma (prototip) standard
	Produs(const Produs& fprod) : cantitate(fprod.cantitate), pret(fprod.pret)  
		//transmis ca o constanta si prin referinta -> copiaza o adresa de fapt 
	{
		numeProdus = new char[strlen(fprod.numeProdus) + 1];
		strcpy_s(numeProdus, strlen(fprod.numeProdus) + 1, fprod.numeProdus);
		strcpy_s(unitateDeMasura, strlen(fprod.unitateDeMasura) + 1, fprod.unitateDeMasura);
	}

	//Supradefinire operator= (operator de atribuire)
	Produs& operator=(Produs& fprodusGeneral){
		// fprodusGeneral -> parametru formal 
		
		numeProdus = new char[strlen(fprodusGeneral.numeProdus) + 1];
		strcpy_s(numeProdus, strlen(fprodusGeneral.numeProdus) + 1, fprodusGeneral.numeProdus);
		//setNumeProdus(fprodusGeneral.numeProdus);
		strcpy_s(unitateDeMasura, strlen(fprodusGeneral.unitateDeMasura) + 1, fprodusGeneral.unitateDeMasura);
		cantitate = fprodusGeneral.cantitate;
		pret = fprodusGeneral.pret;

		return*this;
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

	void afisareProdusTabel() {
		cout << setw(20) << setiosflags(ios::left) << numeProdus << resetiosflags(ios::left)
			<< setw(4) << " | " << unitateDeMasura
			<< setw(5) << " | " << cantitate
			<< setw(8) << setiosflags(ios::fixed) << setprecision(2) << " | " << pret
			<< setw(8) << setiosflags(ios::fixed) << setprecision(2) << " | " << getValoare() << "\n";
	}

	void citireProdus() 
	{		
		cout << "Introduceti detaliile despre produs: " << endl;

		char sirTemp[100];
		cout << "NUME: "; cin >> sirTemp;
		setNumeProdus(sirTemp);

		/*
		if (strlen(sirTemp) > strlen(numeProdus))
		{
			delete[] numeProdus;
			numeProdus = new char[strlen(sirTemp) + 1];
		}
		strcpy_s(numeProdus, strlen(sirTemp) + 1, sirTemp);
		*/

		cout << "UNITATE DE MASURA: "; cin >> unitateDeMasura;
		cout << "CANTITATE: "; cin >> cantitate;
		cout << "PRET: "; cin >> pret;
	}

	char* getNumeProdus() {
		return numeProdus;
	}

	~Produs() {
		//cout << endl << "-----> APEL DESTRUCTOR <-----" << endl;
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

	cout << "p1: "; p1.afisareProdus();
	cout << "p2: "; p2.afisareProdus();
	cout << "p3: "; p3.afisareProdus();
	cout << "p4: "; p4.afisareProdus();
	cout << "CONSTRUCTOR DE COPIERE --> p5 = p2: "; p5.afisareProdus();
	cout << "OPERATOR= --> p6 = p3: "; p6.afisareProdus();

	/*
		Produs vectP[10] = { Produs(), Produs("zahar", "kg", 20, 2.5) }; 
	int nrP;
	cout << "Introduceti numarul de produse: ";
	cin >> nrP;
	nrP += 2;
	for (int i = 2; i < nrP; i++) {  
		vectP[i].citireProdus();
	}

	cout << endl;

	for (int i = 0; i < nrP; i++) {
		vectP[i].afisareProdus();
		cout << endl;
	}

	Produs* vectPointerProdus[10];
	int nrPP;
	cout << "Introduceti numarul de produse pentru vectorul de pointeri la obiecte: ";
	cin >> nrPP;
	nrPP += 2;

	vectPointerProdus[0] = new Produs(); 
	vectPointerProdus[1] = new Produs("zahar", "kg", 20, 2.5);

	for (int i = 2; i < nrPP; i++) {
		vectPointerProdus[i] = new Produs();
		vectPointerProdus[i]->citireProdus();
	}

	cout << endl;

	for (int i = 0; i < nrPP; i++) {
		vectPointerProdus[i]->afisareProdus();
		cout << endl;
	}

	cout << "Afisare produse sub forma de tabel --> " << endl;

	for (int i = 0; i < nrPP; i++) {
		vectPointerProdus[i]->afisareProdusTabel();
		delete vectPointerProdus[i];
	}
	*/

	/*
	Produs p1;
	Produs p2("zahar", "kg", 20, 2.5);

	p1.afisareProdus();
	p2.afisareProdus();

	p1.setNumeProdus("faina");
	p1.setCantitate(20);
	p1.afisareProdus();
	*/
}