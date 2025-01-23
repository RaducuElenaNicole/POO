#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

//global
float nrInvalid = -1000;


class Produs {
private:
	const int codBare;
protected:
	char* denumire;
	float pret;
	int nrIngrediente;
	float* ingrediente;
	static string magazin; // este acelasi pentru toate produsele
	static int nrMaxIngrediente;


public:

	Produs() :codBare(12121) {
		this->denumire = new char[strlen("D") + 1];
		strcpy(this->denumire, "D");
		this->pret = 100;
		//this->nrIngrediente = 0;
		//this->ingrdinte = NULL;
		this->nrIngrediente = 2;
		this->ingrediente = new float[nrIngrediente];
		this->ingrediente[0] = 3.9;
		this->ingrediente[1] = 8.9;
		/*for (int i = 0; i < nrIngrediente; i++) {
			this->ingrdinte[i] = 10.99;
		}*/
	}

	//const hibrid- el nu are ttoti param, pt atributele care nu au parametrii mergem ca la constr defaut
	Produs(char* denumire, float pret) :codBare(2222) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->nrIngrediente = 2;
		this->ingrediente = new float[nrIngrediente];
		this->ingrediente[0] = 3.9;
		this->ingrediente[1] = 8.9;

	}

	//constr cu toti parametrii
	Produs(const int codBare, const char* denumire, float pret,
		int nrIngrediente, float* ingrdinte) :codBare(codBare) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->nrIngrediente = nrIngrediente;
		this->ingrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->ingrediente[i] = ingrdinte[i];
		}

	}

	//constr de copy
	Produs(const Produs& p) :codBare(p.codBare) {

		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->pret = p.pret;
		this->nrIngrediente = p.nrIngrediente;
		this->ingrediente = new float[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			this->ingrediente[i] = p.ingrediente[i];
		}
	}

	//destructor-elibereza zonele de memorie dinamice(*), se apeleaza automat
	//daca am atribute cu * este obligatoriu sa am dest ->regula celor 3(toti constr, op= si dest)
	~Produs() {
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}
		if (ingrediente != NULL) {
			delete[]ingrediente;
		}
	}

	//op=

	Produs& operator=(const Produs& p) {
		//destr+const de copiere+ return * this
		//this->codBare = p.codBare;ERR!!!
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}
		if (ingrediente != NULL) {
			delete[]ingrediente;
		}
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->pret = p.pret;
		this->nrIngrediente = p.nrIngrediente;
		this->ingrediente = new float[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			this->ingrediente[i] = p.ingrediente[i];
		}
		return *this;
	}


	//op<<-> nu este din cadrul clasei => nu are this
	friend ostream& operator<<(ostream& out, Produs& p) {
		out << "Produs -> COD BARE: " << p.codBare;
		out << " | DENUMIRE: " << p.denumire;
		out << " | PRET: " << p.pret;
		out << " | NR INGREDIENTE: " << p.nrIngrediente;
		out << " | INGREDIENTE : ";
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << i + 1 << ": " << p.ingrediente[i] << " | ";
		}
		out <<  " MAGAZIN:" << p.magazin << endl;

		return out;
	}

	//metode accesor - get si set = acesul pentru atributele private
	//get-acces la vizualizare, folosi valoarea 
	//are return getAtribut() nu are parametrii

	const int getCod() {
		return codBare;
	}

	char* getDenumire() {
		return denumire;
	}

	//incapsulare-punerea in private a atr
	/*char* getDenumire() {
		char* copieLaDenumire = new char[strlen(denumire) + 1];
		strcpy(copieLaDenumire, denumire);

		return copieLaDenumire;
	}*/
	int getPret() {
		return pret;
	}
	int getNr() {
		return nrIngrediente;
	}

	float* getIngrediente() {
		return ingrediente;
	}

	//get cu modificare
	float& getIngredient(int pozitie) {
		if (pozitie >= 0 && pozitie < nrIngrediente && ingrediente != NULL)
			return ingrediente[pozitie];
	}

	static string getMagazin() {
		return magazin;
	}

	//set - modifica un atr
	//nu are tip ret: void dar are parametrii
	//Pt const NU exista set

	void setDenumire(const char* denumire_noua) {
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}
		this->denumire = new char[strlen(denumire_noua) + 1];
		strcpy(this->denumire, denumire_noua);
	}


	void setPret(float pret) {
		this->pret = pret;
	}

	static void setMagazin(static string magazin_nou) {
		magazin = magazin_nou;
	}



	//operatori->supraincarcare
	//op unari- ca lucreaza cu un singur obict
	//op++;op--;op!
	//op++->se supraincarca in 2 forme: pre-incrementare si post-incrementare
	Produs& operator++() {
		pret++;
		return *this;
	}

	Produs operator++(int x) {//x este un parametru pe care nu il folosesc- doar fac departajarea intre cele doua functii
		Produs copie = *this;//am apelat constr de copiere 
		//Produs copie(*this);//alta varianta
		pret++;//this
		return copie;
		//la consola eu vad copia ininte de crestere , dar produsul meu creste defapt
	}

	//op! - unar doar ca el ret bool
	bool operator!() {
		if (pret >= 10) {
			return true;
		}
		return false;
	}

	//op binari - au 2 operanzi ->ca avem parametru
	//op+->se face in 3 moduri:ob+valoare;ob+ob;valoare+obiect
	//ob+val
	Produs& operator+(float valoare) {
		pret = pret + valoare;
		return *this;
	}

	//ob+ob
	Produs& operator+(Produs p) {
		pret = pret + p.pret;
		return *this;
	}

	//val+ob->supraincarc pt float si nu Podus, nu exista this, functia nu face parte din clasa

	friend Produs operator+(float valoare, Produs& p) {
		p.pret = p.pret + valoare;
		return p;
	}

	//string + obiect

	/*friend float operator+(float valoare, Produs& p) {
		p.pret = p.pret + valoare;
		return p.pret;
	}*/

	//bool- binari
	//<;>;<=;>=
	bool operator<(Produs p) {
		if (this->pret < p.pret);
		{
			return true;
		}return false;
	}

	bool operator>=(Produs p) {
		if (this->pret >= p.pret);
		{
			return true;
		}return false;
	}

	//op==1
	//bool operator==(Produs p) {
	//	if (this->codBare == p.codBare) {
	//		return true;
	//	}return false;

	//}

	//op==2
	bool operator==(Produs p) {
		if (this->codBare == p.codBare && strcmp(this->denumire, p.denumire) == 0 &&
			this->pret == p.pret && this->nrIngrediente == p.nrIngrediente) {
			return true;
		}
		return false;
	}

	//op!=
	bool operator!= (Produs p) {
		if (strcmp(this->denumire, p.denumire) == 0) {
			return true;
		}
		return false;
	}

	//cazuri exceptionale:

	//op functie: operator()
	float operator()() {
		pret = pret + (pret * 0.1);
		//pret*1.1;
	}

	//float operator()(float procent) {
	//	pret = pret * procent;
	//}

	//float operator()() {
	//	pret = 2*pret + 0.1;
	//}

	// op de indexare []
	// operatorul sa permita modificarea &
	float operator[](int index) {
		if (index >= 0 && index < nrIngrediente && ingrediente != NULL) {
			return ingrediente[index];
		}
		else return -1000;//nrInvalid
	}

	//op de cast - in 2 moduri: explicit si implicit
	//implicit - cel deja cleat si noi doar in folosim 
	//explicit cel pe care il cream noi

	//calculati media ingredientelor dintr -un produs, aceasta medie sa fie returnata int cast la int
	float medie() {
		float suma = 0;
		for (int i = 0; i < nrIngrediente; i++) {
			suma += ingrediente[i];
		}

		return (int)suma / nrIngrediente;
	}

	explicit operator int() {
		return pret;
	}

	float operator~() {
		return pret * 2;
	}

	float operator*(int val) {
		return pret * val;
	}


	string culoare = "rosu";
	//string + obiect
	friend string operator+(string valoare, Produs& p) {
		p.culoare = valoare + " " + p.culoare;
		return p.culoare;
	}

	//+= si -=
	/*Produs& operator+= (float val) {
		for (int i = 0; i < nrIngrediente; i++) {
			ingrediente[i] += val;
		}
		return*this;
	}*/

	Produs& operator+=(float val) {
		float* copie = new float[nrIngrediente + 1];
		for (int i = 0; i < nrIngrediente; i++) {
			copie[i] = ingrediente[i];
		}
		copie[nrIngrediente] = val;
		delete[]ingrediente;
		nrIngrediente++;
		//ingrediente=copie
		ingrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			ingrediente[i] = copie[i];
		}
		return *this;
	}

	//metoda care sa adauge un ceva
	Produs& adaugareIngredient(float val) {
		float* copie = new float[nrIngrediente + 1];
		for (int i = 0; i < nrIngrediente; i++) {
			copie[i] = ingrediente[i];
		}
		copie[nrIngrediente] = val;
		delete[]ingrediente;
		nrIngrediente++;
		//ingrediente=copie
		ingrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			ingrediente[i] = copie[i];
		}
		return *this;
	}


	//operator-=
	Produs& operator-=(float val) {
		nrIngrediente--;
		float* copie = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			copie[i] = ingrediente[i];
		}
		delete[]ingrediente;

		ingrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			ingrediente[i] = copie[i];
		}
		return *this;
	}

	//Produs& operator-=(float val) {
	//	
	//	float* copie = new float[nrIngrediente-1];
	//	for (int i = 0; i < nrIngrediente; i++) {
	//		if (ingrediente[i] != val) {
	//			copie[i] = ingrediente[i];
	//		}
	//	}
	//	delete[]ingrediente;
	//	nrIngrediente--;
	//	ingrediente = new float[nrIngrediente];
	//	for (int i = 0; i < nrIngrediente; i++) {
	//		ingrediente[i] = copie[i];
	//	}
	//	return *this;
	//}

	// get + set pe atribut static -> metode statice 
	/*
	static string getMagazin() {
		return magazin;
	}

	static void setMagazin(static string magazinNou) {
		magazin = magazinNou;
	}
	*/

	static int dublareNrMaxIngrediente() {
		return 2 * nrMaxIngrediente;
	}

	float marirePret() {
		return pret * 0.2;
	}
};

string Produs::magazin = "Altex";
int Produs::nrMaxIngrediente = 5;

// metode statice 
static double mediePreturi(int nrProduse, Produs* vectorProdus) {
	if (nrProduse > 0 && vectorProdus != NULL) {
		double suma = 0;
		for (int i = 0; i < nrProduse; i++) {
			suma += vectorProdus[i].getPret();
		}
		return suma / nrProduse;
	}
	return 0;
}

// IS A
class Prajitura : public Produs {
public:
	// Prajitura are toate atributele din Produs 
	string crema;
	float greutate;

	// constructorul fara parametri -> apel la constr fara parametri din Produs + definire atribute noi din Prajitura
	// nu se mai initializeaza atributul constant ptc s-a mostenit din clasa Produs de la constr fara parametri
	Prajitura() : Produs() {
		this->crema = "Necunoscuta";
		this->greutate = 0;
	}

	// constructorul cu parametri
	// -> apel la constr cu parametri din Produs + definire atribute noi din Prajitura
	// contine toti parametrii -> atribute din Produs + atribute din Prajitura 
	Prajitura(const int _codBare,
		const char* _denumire,
		float _pret,
		int _nrIngrediente,
		float* _ingrediente,
		string crema,
		float greutate) : Produs(_codBare, _denumire, _pret, _nrIngrediente, _ingrediente) 
	{
		this->crema = crema;
		this->greutate = greutate;
	}

	// constructorul de copiere 
	Prajitura(const Prajitura& prj) : Produs(prj) {
		this->crema = prj.crema;
		this->greutate = prj.greutate;
	}

	// operator egal -> apelul la operator= din clasa Produs se face prin operatorul de REZOLUTIE 
	Prajitura& operator=(const Prajitura& praji) {
		Produs :: operator=(praji); 

		this->crema = praji.crema;
		this->greutate = praji.greutate;

		return*this;
	}

	/*friend ostream& operator<<(ostream& out, Prajitura& praji) {
		out << (Produs&)praji;
		out << "Prajitura -> CREMA: " << praji.crema << " | GREUTATE: " << praji.greutate << endl;
		return out;
	}*/
};

// HAS A (compunere 1:1)
class Cadou {
	Produs p;
	Prajitura prj;

	string ambalaj;

	Cadou() {
		this->p = Produs();
		this->prj = Prajitura();

		ambalaj = "Necunoscut";
	}

	Cadou(Produs _p, Prajitura _prj) {
		this->p = _p;
		this->prj = _prj;
	}
};

// HAS A (compunere 1:M)
// varianta cu vector static 
class Platou {
	Prajitura vectPrj[5];

	Platou() {
		for (int i = 0; i <= 4; i++) {
			vectPrj[i] = Prajitura();
		}
	}

	Platou(Prajitura vectPrj[5]) {
		for (int i = 0; i <= 4; i++) {
			this->vectPrj[i] = vectPrj[i];
		}
	}
};

// HAS A (compunere 1:M)
// varianta cu vector dinamic
class Cofetarie {
public:
	string adresa;
	int nrPrajituri;
	Prajitura* vectPrj;

	Cofetarie() {
		adresa = "Necunoscuta";
		nrPrajituri = 3;
		vectPrj = new Prajitura[nrPrajituri];
		for (int i = 0; i < nrPrajituri; i++) {
			this->vectPrj[i] = Prajitura();
		}
	}

	Cofetarie(string adresa, int nrPrajituri, Prajitura* vectPrj) {
		this->adresa = adresa;
		this->nrPrajituri = nrPrajituri;
		this->vectPrj = new Prajitura[nrPrajituri];
		for (int i = 0; i < nrPrajituri; i++) {
			this->vectPrj[i] = vectPrj[i];
		}
	}

	Cofetarie(const Cofetarie& cof) {
		this->adresa = cof.adresa;
		this->nrPrajituri = cof.nrPrajituri;
		this->vectPrj = new Prajitura[cof.nrPrajituri];
		for (int i = 0; i < cof.nrPrajituri; i++) {
			this->vectPrj[i] = cof.vectPrj[i];
		}
	}

	Cofetarie& operator=(const Cofetarie& cof) {
		if (vectPrj != NULL) {
			delete[] vectPrj;
		}

		this->adresa = cof.adresa;
		this->nrPrajituri = cof.nrPrajituri;
		this->vectPrj = new Prajitura[cof.nrPrajituri];
		for (int i = 0; i < cof.nrPrajituri; i++) {
			this->vectPrj[i] = cof.vectPrj[i];
		}

		return*this;
	}

	friend ostream& operator<<(ostream& out, Cofetarie& cof) {
		out << "COFETARIE -> ADRESA: " << cof.adresa << " | NUMAR PRAJITURI: " << cof.nrPrajituri << endl;
		for (int i = 0; i < cof.nrPrajituri; i++) {
			out << "prj " << i + 1 << ": " << cof.vectPrj[i];
		}
		out << endl;
		return out;
	}
};

// HAS A (compunere) cu vector dinamic de pointeri la obiecte
class Cofetarie1 {
public:
	int nrPrajituri;
	Prajitura** prajituri;

	Cofetarie1() {
		this->nrPrajituri = 1;
		this->prajituri = new Prajitura * [nrPrajituri] {new Prajitura()};
	}

	Cofetarie1(int nrPrajituri, Prajitura** prajituri) {
		this->nrPrajituri = nrPrajituri;
		this->prajituri = new Prajitura * [nrPrajituri];
		for (int i = 0; i < nrPrajituri; i++) {
			this->prajituri[i] = prajituri[i];
		}
	}

	friend ostream& operator<< (ostream& out, Cofetarie1& cof1) {
		out << "COFETARIE1 -> NR PRAJITURI: " << cof1.nrPrajituri << " | PRAJITURI: " << endl;
		for (int i = 0; i < cof1.nrPrajituri; i++) {
			out << i + 1 << ": " << *cof1.prajituri[i] << " | ";
		}
		return out;
	}
};

void main() {
	Produs p;
	Produs p1(1211, "Corn", 18.99, 3, new float[3] { 2.33, 1.2, 8.99 });
	//constr de copiere
	Produs p2(p1);
	cout << p1 << p2 << endl;

	cout << p << endl;
	//op =
	p = p1;
	cout << p << endl;


	cout << p.getIngrediente() << endl;
	cout << p.getIngredient(2) << endl;
	p.setMagazin("Carrefour");
	cout << p << p1 << p2 << endl;


	int x = 10;
	//prei-ncreemntare
	cout << ++x << endl;

	//post-incrementare
	cout << x++ << endl;
	cout << x << endl;


	//pre-increemntare
	cout << ++p << endl;

	//post-incrementare
	p++;
	cout << p << endl;

	//op!
	!p1;
	//apel pt bool
	if (!p1) {
		cout << "pretul este mai mare decat 10 de lei" << endl;
	}
	else {
		cout << "pretul NU este mai mare decat 10 de lei" << endl;
	}


	// ob+val
	p1 + 100;
	cout << p1 << endl;
	//cout << p1+100 << endl;

	//ob+ob
	cout << p1 + p2 << endl;

	//val+ob
	//pt return float
	//cout << 1000 + p2 << endl;
	1000 + p2;
	cout << p2 << endl;

	if (p1 == p1) {
		cout << "Obiectele sunt egale!!" << endl;
	}
	else {
		cout << "Obiectele NU sunt egale!!" << endl;
	}

	cout << p2.medie() << endl;
	cout << (int)p2 << endl;
	cout << "este" + p2 << endl;

	p2 += 10;
	cout << p2 << endl;

	p2 += 2.33;
	cout << p2 << endl;
	p2 -= 1.2;
	cout << p2 << endl;


	//ce se intampla daca dau delete pe denumire??????si apoi incerc sa afisez
	//metode statice -get si set pe static si met care primesc vector de obiecte la param
	//is a
	//has a - compunere
	//abstactizare-*****
	//exceptii 
	//constr hybrid


	Produs p7 = p2;//costr copiere
	Produs p8;//impl
	p8 = p1;//op=

	cout << mediePreturi(4, new Produs[4]{ p1, p2, p7, p8 }) << endl;

	Prajitura pr;
	cout << pr;

	Prajitura pr1(333, "Amandina", 15.99, 4, new float[4] { 7.83, 1.79, 15.99, 10 }, "Rom", 10.5);
	cout << pr1;

	Prajitura pr2(pr);
	cout << pr2;

	Prajitura pr3;
	pr3 = pr1;
	cout << pr3;

	Prajitura pr4(333, "Tiramisu", 19.25, 3, new float[3] { 7.65, 2.50, 15.99}, "Mascarpone", 22.25);
	cout << pr4;

	// sciere si citire in/din fisier 
	// vector dinamic de pointeri la obiecte 
	// functie statice care opereaza pe mai multe obiecte (acelasi tip de obiect) + friend  

	cout << endl;

	Cofetarie cof;
	cout << cof;


	Cofetarie cof1("Str. Frumoasa, nr. 35", 3, new Prajitura[3] {pr1, pr4, pr2});
	cout << cof1;

	Cofetarie cof2("Str. Argedava, nr. 2", 2, new Prajitura[2]{ pr1, pr4});
	cout << cof2;

	Cofetarie cof3(cof);
	cout << cof3;

	Cofetarie cof4;
	cof4 = cof2;
	cout << cof4;

	// vector de pointeri (**)
	Prajitura** prajituri; 
	// * - vector de prajituri (vector dinamic)
	// * - se pune PRajitura*
	int nrPrajituri = 3;
	prajituri = new Prajitura * [nrPrajituri] {&pr1, &pr4, &pr3};
	Cofetarie1 cf1(nrPrajituri, prajituri);
	cout << cf1;
}
