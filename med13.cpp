// varianta laptop 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
using namespace std;

class Laptop {
private:
	char* model;
	string tipProcesor;
	int nrComponente;
	string* listaComponente;
	int garantie;
	const int serieCarcasa;

public:
	// constructor implicit 
	Laptop() : serieCarcasa(0) 
	{
		this->model = new char[strlen("Necunoscut/a") + 1];
		strcpy(this->model, "Necunoscut/a");
		this->tipProcesor = "Necunoscut/a";
		this->nrComponente = 1;
		this->listaComponente = new string[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++)
			listaComponente[i] = "Necunoscut/a";
		this->garantie = 0;
	}

	// constructor cu parametri 
	Laptop(const char* model, 
			string tipProcesor, 
			int nrComponente,
			string* listaComponente, 
			int garantie, const int _serieCarcasa) : serieCarcasa(_serieCarcasa)
	{
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->tipProcesor = tipProcesor;
		this->nrComponente = nrComponente;
		this->listaComponente = new string[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++)
			this->listaComponente[i] = listaComponente[i];
		this->garantie = garantie;
	}

	// constructor de copiere 
	Laptop(const Laptop& lpt) : serieCarcasa(lpt.serieCarcasa)
	{
		this->model = new char[strlen(lpt.model) + 1];
		strcpy(this->model, lpt.model);
		this->tipProcesor = lpt.tipProcesor;
		this->nrComponente = lpt.nrComponente;
		this->listaComponente = new string[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++)
			this->listaComponente[i] = lpt.listaComponente[i];
		this->garantie = lpt.garantie;
	}

	// destructor 
	~Laptop() 
	{
		if (this->model != NULL) {
			delete[] this->model;
		}

		if (this->listaComponente != NULL) {
			delete[] this->listaComponente;
		}
	}

	// operatorul egal DEEP_COPY
	Laptop& operator=(const Laptop& lpt)
	{
		// pasul 1 - destructorul 
		if (this->model != NULL) {
			delete[] this->model;
		}

		if (this->listaComponente != NULL) {
			delete[] this->listaComponente;
		}

		// pasul 2 - constructorul de copiere 
		this->model = new char[strlen(lpt.model) + 1];
		strcpy(this->model, lpt.model);
		this->tipProcesor = lpt.tipProcesor;
		this->nrComponente = lpt.nrComponente;
		this->listaComponente = new string[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++)
			this->listaComponente[i] = lpt.listaComponente[i];
		this->garantie = lpt.garantie;

		// pasul 3 
		return*this;
	}

	// operator<< 
	friend ostream& operator<<(ostream& out, const Laptop& lpt)
	{
		out << "MODEL: " << lpt.model << " | TIP PROCESOR: " << lpt.tipProcesor << " | NR COMPONENTE: " << lpt.nrComponente;
		out << " | LISTA COMPONENTE: ";
		for (int i = 0; i < lpt.nrComponente; i++) {
			out << i + 1 << " = " << lpt.listaComponente[i] << " ";
		}
		out << "| GARANTIE: " << lpt.garantie << " | TIP CARCASA: " << lpt.serieCarcasa << endl;
		return out;
	}

	// operator>>
	friend istream& operator>>(istream& in, Laptop& lpt) {
		/*
		char* model;
		string tipProcesor;
		int nrComponente;
		string* listaComponente;
		int garantie;
		const int serieCarcasa;
		*/

		cout << "Introduceti detalii laptop " << endl;

		// citire de la tastatura pentru char*
		cout << "Model: "; 
		char buffer[50]; 
		in >> buffer;
		delete[] lpt.model;
		lpt.model = new char[strlen(buffer) + 1];
		strcpy(lpt.model, buffer);

		cout << "Tip procesor: ";
		in >> lpt.tipProcesor;

		cout << "Nr componente: ";
		in >> lpt.nrComponente;

		cout << "Componente: ";
		delete[] lpt.listaComponente;
		lpt.listaComponente = new string[lpt.nrComponente];
		for (int i = 0; i < lpt.nrComponente; i++) {
			in >> lpt.listaComponente[i];
		}

		cout << "Garantie: ";
		in >> lpt.garantie;

		return in;
	}

	// scrierea in fisier txt 
	friend ofstream& operator<<(ofstream& fout, const Laptop& lpt)
	{
		fout << lpt.model << endl << lpt.tipProcesor << endl << lpt.nrComponente << endl;
		for (int i = 0; i < lpt.nrComponente; i++) {
			fout << lpt.listaComponente[i] << endl;
		}
		fout << lpt.garantie << endl;
		return fout;
	}

	// citirea din fisier txt
	friend ifstream& operator>>(ifstream& fin, Laptop& lpt) 
	{
		char buffer[50];
		fin >> buffer;
		delete[] lpt.model;
		lpt.model = new char[strlen(buffer) + 1];
		strcpy(lpt.model, buffer);

		fin >> lpt.tipProcesor;

		fin >> lpt.nrComponente;

		delete[] lpt.listaComponente;
		lpt.listaComponente = new string[lpt.nrComponente];
		for (int i = 0; i < lpt.nrComponente; i++) {
			fin >> lpt.listaComponente[i];
		}

		fin >> lpt.garantie;

		return fin;
	}

	// get + set
	// char* 
	char* getModel() {
		return this->model;
	}
	void setModel(const char* modelNou) {
		if (this->model != NULL) {
			delete[] this->model;
		}
		if (modelNou != NULL) {
			this->model = new char[strlen(modelNou) + 1];
			strcpy(this->model, modelNou);
		}
		else {
			this->model = new char[strlen("Necunoscut/a") + 1];
			strcpy(this->model, "Necunoscut/a");
		}
	}
	// string*
	string getListaComponente(int index) {
		if (index >= 0 && index < this->nrComponente) {
			return this->listaComponente[index];
		}
		else
			return "Index invalid!!!";
	}
	void setListaComponente(int nrComponenteNou, string* listaComponenteNou) {
		if (this->listaComponente != NULL) {
			delete[] this->listaComponente;
		}
		if (nrComponenteNou != 0 && listaComponenteNou != NULL) {
			this->nrComponente = nrComponenteNou;
			this->listaComponente = new string[nrComponenteNou];
			for (int i = 0; i < nrComponenteNou; i++) {
				this->listaComponente[i] = listaComponenteNou[i];
			}
		}
		else {
			this->nrComponente = 1;
			this->listaComponente = new string[this->nrComponente];
			for (int i = 0; i < this->nrComponente; i++)
				listaComponente[i] = "Necunoscut/a";
		}
	}

	// operator*
	Laptop operator*(int valoare)
	{
		this->garantie = this->garantie * valoare;
		return*this;
	}

	// operator cast la string 
	explicit operator string() {
		return this->model;
	}

	// operator<
	friend bool operator<(const Laptop& lpt, const Laptop& lpt1) {
		return lpt.garantie<lpt1.garantie;
		
	}
};

// IS-A (mostenire)
class Upgrade : public Laptop {
	// Laptop - clasa mama 
public:
	string placaVideo;

	Upgrade() : Laptop() {
		// s-a apelat constructorul default din clasa de baza (clasa mama)
		this->placaVideo = "Necunoscut/a";
	}

	Upgrade(const char* _model, 
			string _tipProcesor, 
			int _nrComponente,
			string* _listaComponente, 
			int _garantie, 
			const int _serieCarcasa, 
			string placaVideo) : Laptop(_model, 
										_tipProcesor, 
										_nrComponente, 
										_listaComponente, 
										_garantie, 
										_serieCarcasa)
	{
		this->placaVideo = placaVideo;
	}

	Upgrade(const Upgrade& upg) : Laptop(upg) 
	{
		this->placaVideo = upg.placaVideo;
	}

	Upgrade operator=(const Upgrade& upg) 
	{
		Laptop::operator=(upg);
		this->placaVideo = upg.placaVideo;
		return*this;
	}

	friend ostream& operator<<(ostream& out, const Upgrade& upg) {
		out << (Laptop&)upg; // upcasting
		out << "PLACA VIDEO: " << upg.placaVideo << endl;
		return out;
	}
};

void main() {
	Laptop l;
	cout << "l -> " << l;

	Laptop l1("Asus", "Intel I5", 3, new string[3]{ "tastatura", "mouse", "monitor" }, 3, 101);
	cout << "l1 -> " << l1;

	Laptop l2("Lenovo", "Intel I7", 4, new string[4]{ "tastatura", "microfon", "mouse", "monitor" }, 5, 102);
	cout << "l2 -> " << l2;

	Laptop l3("Dell", "Intel I9", 2, new string[2]{ "tastatura", "mouse" }, 2, 103);
	cout << "l3 -> " << l3;

	Laptop l4(l2);
	cout << "l2 -> " << l2;

	Laptop l5;
	cout << "l5 -> " << l5;
	l1 = l5;
	cout << "l1 -> " << l1;
	l5 = l3;
	cout << "l5 -> " << l5;

	l3.setModel("Lenovo");
	cout << l3.getModel() << endl;

	l3.setListaComponente(4, new string[4]{ "tastatura", "mouse", "monitor" , "microfon" });
	cout << l3;

	cout << l3.getListaComponente(6) << endl;
	cout << l3.getListaComponente(2) << endl;

	cout << l2 * 3;

	cout << (string)l2 << endl;

	Laptop l6;
	//cin >> l6;
	cout << "l6 -> " << l6;

	ofstream g("fisier.txt");
	g << l6;
	g.close();

	Laptop l7;
	ifstream f("fisier.txt");
	f >> l7;
	cout << "l7 -> " << l7;

	cout << endl << endl;

	Upgrade u;
	cout << "u -> " << u;

	Upgrade u1("Asus", "Intel I5", 3, new string[3]{ "tastatura", "mouse", "monitor" }, 3, 111, "placa video 1");
	cout << "u1 -> " << u1;

	Upgrade u2("Dell", "Intel I9", 2, new string[2]{ "tastatura", "mouse" }, 2, 112, "placa video 2");
	cout << "u2 -> " << u2;

	Upgrade u3("Lenovo", "Intel I7", 4, new string[4]{ "tastatura", "microfon", "mouse", "monitor" }, 5, 113, "placa video 3");
	cout << "u3 -> " << u3;

	Upgrade u4(u2);
	cout << "u4 -> " << u4;

	Upgrade u5;
	u5 = u3;
	cout << "u5 -> " << u5;

	// STL

	cout << endl << "--- STL_VECTOR ---" << endl;
	vector<Laptop> vectLaptop;
	vectLaptop.push_back(l1);
	vectLaptop.push_back(l2);
	vectLaptop.push_back(l3);
	vectLaptop.push_back(l4);
	vectLaptop.push_back(l5);
	vectLaptop.push_back(l6);
	vectLaptop.push_back(l7);
	for (Laptop lpt : vectLaptop) {
		cout << lpt;
	}

	// STL - set 
	cout << endl << "--- STL_SET ---" << endl;
	set<Laptop> setLaptop;
	setLaptop.insert(l1);
	setLaptop.insert(l2);
	setLaptop.insert(l3);
	setLaptop.insert(l4);
	setLaptop.insert(l1);
	for (Laptop lpt : setLaptop) {
		cout << lpt;
	}
}