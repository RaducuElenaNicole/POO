//Să se definească clasa Autobuz care are câmpurile :
//
//• nrAutobuze – întreg static – contorizează automat numărul de autobuze create;
//
//• idAutobuz - intreg constant - id - ul unic al autobuzului
//
//• capacitate – întreg – numărul de persoane care pot fi îmbarcate în autobuz pe locuri;
//
//• nrPersoaneImbarcate – întreg – numărul de persoane aflate în autobuz.Nu poate fi mai mare decât capacitatea autobuzului;
//
//• producator – char* -numele producătorului autobuzului.
//
//Atributele clasei se definesc în zona privată a clasei
//
//Să se definească pentru clasa Autobuz constructor fără parametri, constructor cu parametri și destructor.Constructorul cu parametri conține validări pentru parametrii primiți.
//
//Să se definească pentru clasa Autobuz constructorul de copiere și metode accesor(get si set) pentru doua atribute la alegere.Testați în funcția main().
//
//Să se supraîncarce pentru clasa Autobuz operatorul = (de atribuire) fără a genera memory leaks și să nu permită auto - atribuirea.Testați în funcția main().
//
//Să se supraîncarce operatorul << pentru afișarea obiectelor de tipul Autobuz.Elementele sunt afișate pe aceeași linie despărțite prin punct și virgulă și spațiu(; ).Testați în funcția main().
//
//Să se definească metoda getNumarLocuriLibere() care calculează și returnează numărul de locuri libere rămase în autobuz.Testați în funcția main().
//
//Să se supraîncarce operator de cast la int care determină numărul de persoane urcate deja în autobuz.Testați în funcția main().
//
//Să se supraîncarce operator> care va compara două autobuze după capacitatea acestora.Testați în funcția main().

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	Autobuz() :idAutobuz(1) {
		capacitate = 20;
		nrPersoaneImbarcate = 10;
		producator = new char[strlen("Solaris Bus") + 1];
		strcpy(producator, "Solaris Bus");

	}

	Autobuz(const int idAutobuz, int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(idAutobuz) {
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);

	}

	~Autobuz() {
		if (producator != NULL) {
			delete[] producator;
		}
	}

	Autobuz(const Autobuz& a) : idAutobuz(a.idAutobuz) {
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
	}

	char* getProducator() {
		return producator;
	}

	void setProducator(const char* producator_nou) {
		if (producator != NULL) {
			delete[] producator;
		}

		this->producator = new char[strlen(producator_nou) + 1];
		strcpy(this->producator, producator_nou);
	}

	int getCapacitate() {
		return capacitate;
	}

	void setCapacitate(int capacitate_noua) {
		this->capacitate = capacitate_noua;
	}

	Autobuz& operator=(Autobuz& a) {
		if (producator != NULL) {
			delete[] producator;
		}
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);

		return *this;
	}

	friend ostream& operator<<(ostream& out, Autobuz& a) {
		out << a.nrAutobuze << "; ";
		out << a.idAutobuz << "; ";
		out << a.capacitate << "; ";
		out << a.nrPersoaneImbarcate << "; ";
		out << a.producator << "; ";

		return out;
	}

	int getNumarLocuriLibere() {
		int nrlocuriLibere = capacitate - nrPersoaneImbarcate;
		return nrlocuriLibere;
	}

};

int Autobuz::nrAutobuze = 2;

void main() {
	Autobuz a;
	cout << a << endl;

	Autobuz a1(2, 10, 5, "Karsan");
	cout << a1 << endl;

	// operator de copiere
	Autobuz a2(a1);
	cout << a2 << a1 << endl;


	cout << a2.getProducator() << endl;
	a2.setProducator("BMC");

	cout << a2.getProducator() << endl;

	cout << a2.getCapacitate() << endl;
	a2.setCapacitate(25);

	cout << a2.getCapacitate() << endl;

	// operator =

	a = a1;
	cout << a << endl;
	cout << a1 << endl;

	cout << a1.getNumarLocuriLibere() << endl;


}