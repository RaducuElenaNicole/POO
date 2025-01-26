// Functii accesor / metode de acces 
// GET & SET

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student {
private:
	const int nrCrt;
	static string universitate;
	char* numeStud;
	char sex;
	int varsta;
	string facultate;
	int nrMaterii;
	string* listaMaterii;
	float* listaNote;

public:
	// constructor implicit / fara parametri / default 
	Student() : nrCrt(0) {
		this->universitate = "Necunoscuta";
		this->numeStud = new char[strlen("Necunoscut/a") + 1];
		strcpy(this->numeStud, "Necunoscut/a");
		this->sex = '-';
		this->varsta = 0;
		this->facultate = "Necunoscuta";
		this->nrMaterii = 1;
		this->listaMaterii = new string[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaMaterii[i] = "N/A";
		}
		this->listaNote = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaNote[i] = 0;
		}
	}

	// constructor cu parametri 
	Student(const int _nrCrt,
		const char* numeStud,
		char sex,
		int varsta,
		string facultate,
		int nrMaterii,
		string* listaMaterii,
		float* listaNote) : nrCrt(_nrCrt)
	{
		this->numeStud = new char[strlen(numeStud) + 1];
		strcpy(this->numeStud, numeStud);
		this->sex = sex;
		this->varsta = varsta;
		this->facultate = facultate;
		this->nrMaterii = nrMaterii;
		this->listaMaterii = new string[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaMaterii[i] = listaMaterii[i];
		}
		this->listaNote = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaNote[i] = listaNote[i];
		}
	}

	// constructor de copiere 
	Student(const Student& stud) : nrCrt(stud.nrCrt)
	{
		this->numeStud = new char[strlen(stud.numeStud) + 1];
		strcpy(this->numeStud, stud.numeStud);
		this->sex = stud.sex;
		this->varsta = stud.varsta;
		this->facultate = stud.facultate;
		this->nrMaterii = stud.nrMaterii;
		this->listaMaterii = new string[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaMaterii[i] = stud.listaMaterii[i];
		}
		this->listaNote = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaNote[i] = stud.listaNote[i];
		}
	}

	// destructor - pentru atributele alocate dinamic 
	~Student()
	{
		if (this->listaMaterii != NULL) {
			delete[] this->listaMaterii;
		}
		if (this->listaNote != NULL) {
			delete[] this->listaNote;
		}
	}

	// supraincarcare operator=
	Student& operator=(const Student& stud)
	{
		// pas 1 - destructor
		if (this->listaMaterii != NULL) {
			delete[] this->listaMaterii;
		}
		if (this->listaNote != NULL) {
			delete[] this->listaNote;
		}

		// pas 2 - constructor de copiere 
		this->numeStud = new char[strlen(stud.numeStud) + 1];
		strcpy(this->numeStud, stud.numeStud);
		this->sex = stud.sex;
		this->varsta = stud.varsta;
		this->facultate = stud.facultate;
		this->nrMaterii = stud.nrMaterii;
		this->listaMaterii = new string[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaMaterii[i] = stud.listaMaterii[i];
		}
		this->listaNote = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++) {
			this->listaNote[i] = stud.listaNote[i];
		}

		// pas 3 - returnarea valorii de la pointerul this (*this)
		return*this;
	}

	// supraincarcare operator<<
	friend ostream& operator<<(ostream& out, const Student stud)
	{
		out << "Student --- NR CRT: " << stud.nrCrt
			<< " | UNIVERSITATE: " << stud.universitate
			<< " | FACULTATE: " << stud.facultate
			<< " | NUME: " << stud.numeStud
			<< " | SEX: " << stud.sex
			<< " | VARSTA: " << stud.varsta
			<< " | NUMAR MATERII: " << stud.nrMaterii
			<< " | NOTA per MATERIE: ";
		if (stud.listaNote[0] == 0 && stud.listaMaterii[0] == "N/A")
			out << "Nu exista inregistrari pentru note si pentru materii!" << endl;
		else {
			out << endl;
			for (int i = 0; i < stud.nrMaterii; i++)
			{
				out << "     " << i + 1 << ": " << stud.listaMaterii[i] << " / " << stud.listaNote[i] << endl;
			}
		}

		return out;
	}

	// FUNCTII ACCESOR

	// VARSTA
	void setVarsta(int varstaNoua) {
		this->varsta = varstaNoua;
	}
	int getVarsta() {
		return this->varsta;
	}

	// NUMESTUD
	void setNumeStud(const char* numeStudNou) {
		delete[] this->numeStud;
		this->numeStud = new char[strlen(numeStudNou) + 1];
		strcpy(this->numeStud, numeStudNou);
	}
	char* getNumeStud() {
		return this->numeStud;
	}

	// FACULTATE
	void setFacultate(string facultateNoua) {
		this->facultate = facultateNoua;
	}
	string getFacultate() {
		return this->facultate;
	}

	// SEX
	void setSex(char sexNou) {
		this->sex = sexNou;
	}
	char getSex() {
		return this->sex;
	}

	// get si set pe vector 
	float getNota(int index) {
		if (index >= 0 && index < this->nrMaterii && this->listaNote != NULL)
			return listaNote[index];
		return -1;
	}
	void setNotaPunctajBonus(int index, float punctajBonus) {
		if (index >= 0 && index < this->nrMaterii && this->listaNote != NULL)
			listaNote[index] = listaNote[index] + punctajBonus;
	}
	void setVectorNoteMaterii(float notaNoua, string materieNoua) {
		// pas 1: alocare memorie pentru copiile vectorilor cu dimensiunea + 1
		float* copieListaNote = new float[nrMaterii + 1];
		string* copieListaMaterii = new string[nrMaterii + 1];

		// pas 2: copierea vectorilor u=in copiile lor 
		for (int i = 0; i < nrMaterii; i++) {
			copieListaNote[i] = this->listaNote[i];
			copieListaMaterii[i] = this->listaMaterii[i];
		}

		// pas 3: adaugarea elementului final la finalul copiei 
		copieListaNote[nrMaterii] = notaNoua;
		copieListaMaterii[nrMaterii] = materieNoua;

		// pas 4: cresterea dimensiunii vectorilor initiali cu o unitate
		nrMaterii++;

		// pas 5: dezalocarea memoriei pentru vectorii initiali 
		delete[] this->listaNote;
		delete[] this->listaMaterii;

		// pas 6: alocarea memoriei pentru vectori 
		this->listaMaterii = new string[nrMaterii];
		this->listaNote = new float[nrMaterii];

		// pas 7: copierea in vector a tuturor elementelor copiilor 
		for (int i = 0; i < nrMaterii; i++) {
			listaNote[i] = copieListaNote[i];
			listaMaterii[i] = copieListaMaterii[i];
		}
	}

	void setVector(int nrMateriiNou, float* listaNoteNoi, string* listaMateriiNoi) {
		// pas 1: alocare memorie pentru copiile vectorilor cu dimensiunea + 1
		int copieNrMaterii = this->nrMaterii;
		float* copieListaNote = new float[nrMaterii + nrMateriiNou];
		string* copieListaMaterii = new string[nrMaterii + nrMateriiNou];

		// pas 2: copierea vectorilor u=in copiile lor 
		for (int i = 0; i < nrMaterii; i++) {
			copieListaNote[i] = this->listaNote[i];
			copieListaMaterii[i] = this->listaMaterii[i];
		}

		// pas 3: actualizare dimensiune 
		nrMaterii = nrMaterii + nrMateriiNou;

		// pas 4: dezalocarea memoriei pentru vectorii initiali 
		delete[] this->listaNote;
		delete[] this->listaMaterii;

		// pas 5: alocarea memoriei pentru vectori 
		this->listaMaterii = new string[nrMaterii];
		this->listaNote = new float[nrMaterii];

		// pas 6: actualizarea copiilor prin adaugarea elementelor din vectorii noi 
		for (int i = copieNrMaterii; i < nrMaterii; i++) {
			copieListaNote[i] = listaNoteNoi[i - copieNrMaterii];
			copieListaMaterii[i] = listaMateriiNoi[i - copieNrMaterii];
		}

		// pas 7: copierea in vectorii initiali a tuturor elementelor copiilor 
		for (int i = 0; i < nrMaterii; i++) {
			listaNote[i] = copieListaNote[i];
			listaMaterii[i] = copieListaMaterii[i];
		}
	}
};
string Student::universitate = "ASE";

void main() {
	Student s;
	cout << "s -> " << s << endl;

	Student s1(101, "Popescu Ana", 'F', 23, "Facultatea de Cibernetica", 3, new string[3]{ "Microeconomie", "Bazele Ciberneticii", "Statisctica" }, new float[3] {5.90, 9.45, 3});
	cout << "s1 -> " << s1 << endl;

	Student s2(102, "Vasilescu Matei", 'M', 20, "Facultatea de Informatica", 2, new string[2]{ "Programare Orientata Obiect", "Bazele Programarii Calculatoarelor" }, new float[2] {10, 7.85});
	cout << "s2 -> " << s2 << endl;

	Student s3(103, "Savu Stefania", 'F', 21, "Facultatea de Economie", 4, new string[4]{ "Microeconomie", "Contabilitate", "Finante", "Statistica" }, new float[4] {8, 3.2, 9.80, 7.55});
	cout << "s3 -> " << s3 << endl;

	Student s4(s2);
	cout << "s4 -> " << s4 << endl;

	Student s5;
	cout << "Inainte de atribuire (inainte de apelul operatorlui =)" << endl;
	cout << "s5 -> " << s5 << endl;
	s5 = s3;
	cout << "Dupa atribuire (dupa apelul operatorului= ) " << endl << "s5 -> " << s5 << endl;

	cout << endl;

	cout << s1.getVarsta() << " | ";
	s1.setVarsta(25);
	cout << s1.getVarsta() << endl;

	cout << endl;

	cout << s1.getNumeStud() << " | ";
	s1.setNumeStud("Teodora Matei");
	cout << s1.getNumeStud() << endl; 

	cout << endl;

	cout << s1.getFacultate() << " | ";
	s1.setFacultate("Facultatea de Inginerie Medicala");
	cout << s1.getFacultate() << endl;

	cout << endl;

	cout << s1.getSex() << " | ";
	s1.setSex('N');
	cout << s1.getSex() << endl; 

	cout << endl;

	cout << "s1 -> " << s1 << endl; 
	cout << s1.getNota(10) << " | " << s1.getNota(0) << endl;
	s1.setVectorNoteMaterii(8.90, "Macroeconomie");
	cout << "s1 -> " << s1;
	cout << s1.getNota(1) << " | ";
	s1.setNotaPunctajBonus(1, 5.5);
	cout << s1.getNota(1) << endl;

	cout << endl;

	cout << s2;
	s2.setVector(4, new float[4] {10, 3.5, 7.90, 8.60}, new string[4]{ "SDD", "PAW", "DSAD", "TW" });
	cout << s2;
}