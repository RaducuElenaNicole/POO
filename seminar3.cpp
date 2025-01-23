//SEMINAR 3 POO - 14.10.2024 - Sãpt 3

#include<iostream>
#include<iomanip>
using namespace std;

class Produs
{
	//de obicei in partea private se pun elemente care tin de implementare 
	//default este private 
	char numeProdus[100];
	char unitateDeMasura[5];
	//alocare dinamica ??? 
	int cantitate;
	float pret;

public:
	//constructor implicit si explicit 
	Produs(const char* fnumeProdus = "Nedefinit", const char* funitateDeMasura = "N/A", int fcantitate = 0, float fpret = 0) : cantitate(fcantitate), pret(fpret) {
		//parametru formal 
		strcpy_s(numeProdus, strlen(fnumeProdus) + 1, fnumeProdus);
		strcpy_s(unitateDeMasura, strlen(funitateDeMasura) + 1, funitateDeMasura);
	}

	//functii accesor 
	//operatii de modificare sau de obtinere a starii obiectelor => functii acces 
	//modificare => SET
	//obtinere => GET
	void setCantitate(int);
	void setNumeProdus(const char*);

	int getCantitate() {
		//nu am parametru, "obtine starea (cantitatea)" 
		return cantitate;
	}
	//metoda (functie accesor) de obtinere/returnare a valorii unui produs 
	float getValoare() {
		return pret * cantitate;
	}

	void afisareProdus() {
		cout << "NUME: " << numeProdus << " | UNITATE DE MASURA: " << unitateDeMasura << " | CANTITATE: " << cantitate
			<< " | PRET: " << pret << " | VALOARE: " << getValoare() << "\n";
	}

	void afisareProdusTabel() {
		cout << setw(20) << setiosflags(ios::left) << numeProdus << resetiosflags(ios::left) 
			 << setw(4) << " | " << unitateDeMasura 
			 << setw(5) << " | " << cantitate
			 << setw(8) << setiosflags(ios::fixed) << setprecision(2) << " | " << pret 
			//formatul fix de reprezentare a numarului cu punct cu 2 zecimale dupa virgula 
			 << setw(8) << setiosflags(ios::fixed) << setprecision(2) << " | " << getValoare() << "\n";
	}

	void citireProdus() {
		cout << "Introduceti detaliile despre produs: " << endl;
		cout << "NUME: "; 
		cin >> numeProdus;
		cout << "UNITATE DE MASURA: ";
		cin >> unitateDeMasura;
		cout << "CANTITATE: ";
		cin >> cantitate;
		cout << "PRET: ";
		cin >> pret;
	}

	char* getNumeProdus() {
		return numeProdus;
	}

	~Produs() {
		cout << endl <<"-----> APEL DESTRUCTOR <-----" << endl;
	}
};

//metode inline => se comporta ca niste macrodefinitii (in interioru clasei) => sunt mai simple 
//metode outline (sunt mai ample)

void Produs::setCantitate(int fcantitate) {
	//operator de rezolutie
	//setCantitate nu e functie independenta, ci tine de clasa Produs 
	//se defineste setCantitate din clasa Produs 
	//functie vs metoda ????
	if (fcantitate >= 0) {
		cantitate = fcantitate;
	}
	else {
		//consola pentru erori, se afiseaza mesajele generate de erori 
		//cerr => dispozitivul care primeste mesajele de eroare
		//mecanism de tratare a erorilor prin exceptii (urmeaza sa se faca)
		cerr << "EROARE! Cantitatea nu poate fi negativa!";
	}
}

void Produs::setNumeProdus(const char* numeNouProdus) {
	strcpy_s(numeProdus, strlen(numeProdus) + 1, numeNouProdus);
}

void main() {
	Produs vectP[10] = {Produs(), Produs("zahar", "kg", 20, 2.5)}; //se ocupa spatiul pentru 10 produse, cele care nu sunt introduse folosesc contructorul implicit 
	//construirea unor obiecte anonime ???? 
	int nrP;
	cout << "Introduceti numarul de produse: "; 
	cin >> nrP;
	nrP += 2;
	for (int i = 2; i < nrP; i++) { // incep cu i de la 2 ptc am adaugat deja 2 produse in vectP
		// \t -> tab 
		vectP[i].citireProdus(); 
	}

	cout << endl;

	for (int i = 0; i < nrP; i++) {
		vectP[i].afisareProdus();
		cout << endl;
	}

	//vector de pointer la obiecte
	//ALOCARE DINAMICA
	Produs* vectPointerProdus[10];
	int nrPP;
	cout << "Introduceti numarul de produse pentru vectorul de pointeri la obiecte: ";
	cin >> nrPP;
	nrPP += 2;

	//operator de alocare de memorie -> new 
	// malloc VS new -> new aloca zona de memorie, dar apeleaza si contructorul 

	vectPointerProdus[0] = new Produs(); //apeleaza constructorul implicit si aloca memorie 
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


	/*
	Produs p1;
	Produs p2("zahar", "kg", 20, 2.5);

	//problema la constructor !!!!!
	p1.afisareProdus();
	p2.afisareProdus();

	p1.setNumeProdus("faina");
	p1.setCantitate(20);
	p1.afisareProdus();
	*/
}