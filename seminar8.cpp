//SEMINAR 8 POO - 18.11.2024 - Sãpt 8

// relatia IS-A -> se pune in evidenta relatie de derivare 

#include<iostream>
#include<iomanip>
using namespace std;

// produsul care se vinde angro
// clasa de baza 
class ProdusG 
{
protected:
	// protected -> are sens daca clasele sunt in relatie de mostenire 
	// protected -> in clasa, se comporta ca private 
	string numeProdus;
	int cheltuieliMateriale;
	int cheltuieliSalariale;
	int profit; 

	// metoda de calcul al pretului
	virtual int calculPret() 
	{
		return cheltuieliMateriale + cheltuieliSalariale + profit;
	}

public: 
	// rol de constructor implicit si cu parametri 
	ProdusG(string fNumeProdus = "Nedefinit", 
			int fCheltuieliMateriale = 0, 
			int fCheltuieliSalariale = 0, 
			int fProfit = 0) : numeProdus(fNumeProdus), 
							   cheltuieliMateriale(fCheltuieliMateriale), 
							   cheltuieliSalariale(fCheltuieliSalariale), 
							   profit(fProfit) 
	{

	}

	friend ostream& operator<<(ostream out, ProdusG& prod) 
	{
		out << "NUME PRODUS: " << prod.numeProdus 
			<< " | CHELTUIELI MATERIALE: " << prod.cheltuieliMateriale 
			<< " | CHELTUIELI SALARIALE: " << prod.cheltuieliMateriale 
			<< " | PROFIT: " << prod.profit 
			<< " PRET PRODUS: " << prod.calculPret() << endl; 
		return out;
	}
};
// ProdusA -> clasa derivata din clasa ProdusG
class ProdusA : public ProdusG
{
	int adaosComercial;

public:
	// contsructor implicit 
	ProdusA() : adaosComercial(0) 
	{

	}

	// constructor cu parametri
	ProdusA(string fNumeProdus,
		int fCheltuieliMateriale,
		int fCheltuieliSalariale,
		int fProfit, 
		int fAdaosComercial) : ProdusG(fNumeProdus, fCheltuieliMateriale, fCheltuieliSalariale, fProfit)
	{

	}

	int calculPret()
	{
		return ProdusG::calculPret() + adaosComercial;
	}
};

void main() 
{
	// vector de pointeri 
	ProdusG* vectProduse[] = {new ProdusG ("mere", 23, 56, 5), 
							  new ProdusA("sacou", 6, 20, 6, 19),
							  new ProdusA("aspirator", 50, 100, 60, 5) };

	for(int i = 0; i < 3; i++){
		cout << vectProduse[i];
	}

}