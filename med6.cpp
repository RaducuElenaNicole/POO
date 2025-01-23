#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std; 

class Prajitura {
private:
	char* denumire;
	unsigned int nrCalorii; 
	unsigned int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	float pret;
	static string magazin;
	const int id;

public:
	Prajitura() : id(0) {
		denumire = new char[strlen("Necunoscut") + 1];
		strcpy(denumire, "Necunoscut");
		nrCalorii = 0;
		nrIngrediente = 0;
		gramajIngrediente = NULL;
		esteVegana = false;
		pret = 0;
	}

	Prajitura(const char* denumire, unsigned int nrCalorii, unsigned int nrIngrediente,
		float* gramajIngrediente, bool esteVegana, float pret, int id) : id(id) 
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->nrCalorii = nrCalorii;
		this->nrIngrediente = nrIngrediente;
		this->gramajIngrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->gramajIngrediente[i] = gramajIngrediente[i];
		}
		this->esteVegana = esteVegana;
		this->pret = pret;
	}

	Prajitura(const Prajitura& p) : id(p.id) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->nrCalorii = p.nrCalorii;
		if (p.nrIngrediente != 0 && p.gramajIngrediente != NULL) {
			this->nrIngrediente = p.nrIngrediente;
			this->gramajIngrediente = new float[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
		}
		this->esteVegana = p.esteVegana;
		this->pret = p.pret;
	}

	~Prajitura() {
		delete[] denumire; 
		delete[] gramajIngrediente;
	}

	Prajitura& operator= (const Prajitura& p) {
		// autoasignare => daca prajitura pe care vreau sa o modific e acceeasi 
		if (this != &p) {
			delete[] denumire;
			delete[] gramajIngrediente;
		}

		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->nrCalorii = p.nrCalorii;
		if (p.nrIngrediente != 0 && p.gramajIngrediente != NULL) {
			this->nrIngrediente = p.nrIngrediente;
			this->gramajIngrediente = new float[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
		}
		this->esteVegana = p.esteVegana;
		this->pret = p.pret;

		return*this;
	}

	friend ostream& operator<<(ostream& out, Prajitura& p) {
		out << "DENUMIRE: " << p.denumire << " | NR CALORII: " << p.nrCalorii <<
			" | NR INGREDIENTE: " << p.nrIngrediente << " | GRAMAJE INGREDINTE: ";
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << p.gramajIngrediente[i] << " ";
		}
		out << " | ESTE VEGANA: " << p.esteVegana <<
			" | PRET: " << p.pret <<
			" | MAGAZIN: " << p.magazin <<
			" | ID: " << p.id << "\n";
		return out;
	}

	// getteri si setteri 
	char* getDenumire() {
		return this->denumire;
	}

	void setDenumire(const char* denumireNoua) {
		if (denumire != NULL) {
			delete[] denumire;
		}
		this->denumire = new char[strlen(denumireNoua) + 1];
		strcpy(this->denumire, denumireNoua);
	}

	// getter si setter pentru vector 
	float getGramajIngrediente(int index) {
		if(index >= 0 && index < this->nrIngrediente)
			return this->gramajIngrediente[index];
	}

	void setGramajIngrediente(int nrIngredienteNou, float* gramajIngredienteNou) {
		if (gramajIngrediente != NULL)
			delete[] gramajIngrediente;
		if (nrIngredienteNou != 0 && gramajIngredienteNou != NULL) 
		{
			this->nrIngrediente = nrIngredienteNou;
			this->gramajIngrediente = new float[nrIngredienteNou];
			for (int i = 0; i < nrIngredienteNou; i++) {
				this->gramajIngrediente[i] = gramajIngredienteNou[i];
			}
		}
	}
};

string Prajitura::magazin = "Tip Top";

void main() {
	Prajitura p1;
	cout <<"p1 = " << p1;

	Prajitura p2("Amandina", 320, 3, new float[3]{1, 7, 8}, true, 25.55, 1);
	cout << "p2 = " << p2;

	Prajitura p3(p2);
	cout << "p3 = " << p3;

	Prajitura p4;
	cout << "p4 = " << p4;
	p4 = p2;
	cout << "p4 = " << p4;

	cout << p2.getDenumire() << endl;

	p2.setDenumire("Tiramisu");
	cout << p2.getDenumire() << endl;

	cout << p2.getGramajIngrediente(2) << endl;

	p1.setGramajIngrediente(4, new float[4] {3, 8, 9, 2});
	cout << "p1 = " << p1;
}

//EXCEPTIE !!!!!
// get si set pe atribute statice 