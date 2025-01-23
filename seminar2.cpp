//SEMINAR 2 POO - 07.10.2024 - SAPT 2

#include <iostream>
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
	char* getNumeProdus() {
		return numeProdus;
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
	Produs p1;
	Produs p2("zahar", "kg", 20, 2.5);

	//p2.setCantitate(20);

	//problema la constructor !!!!!
	p1.afisareProdus();
	p2.afisareProdus();

	p1.setNumeProdus("faina");
	p1.setCantitate(20);
	p1.afisareProdus();
}