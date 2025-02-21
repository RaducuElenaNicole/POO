// Relatia HAS-A -> compunere 1:M cu vector static 

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
};
string Student::universitate = "ASE";

class Grupa {
public:
	string numeGrupa;
	Student vectStud[5]; // vector static -> alocare statica de memorie 

	Grupa() {
		this->numeGrupa = "N/A";
		for (int i = 0; i < 5; i++)
			this->vectStud[i] = Student();
	}

	Grupa(string numeGrupa, Student vectStud[5]) {
		this->numeGrupa = numeGrupa;
		for (int i = 0; i < 5; i++)
			this->vectStud[i] = vectStud[i];
	}

	friend ostream& operator<<(ostream& out, const Grupa& grp) {
		out << "Grupa --- NUME: " << grp.numeGrupa << " | Studenti: " << endl;
		for (int i = 0; i < 5; i++) {
			out << i + 1 << ": " << grp.vectStud[i];
		}
		out << endl;
		return out;
	}
};

void main() {
	Student s;
	cout << "s -> " << s << endl;

	Student s1(101, "Popescu Ana", 'F', 23, "Facultatea de Cibernetica", 3, 
		new string[3]{ "Microeconomie", "Bazele Ciberneticii", "Statisctica" }, new float[3] {5.90, 9.45, 3});
	cout << "s1 -> " << s1 << endl;

	Student s2(102, "Vasilescu Matei", 'M', 20, "Facultatea de Informatica", 2, 
		new string[2]{ "Programare Orientata Obiect", "Bazele Programarii Calculatoarelor" }, new float[2] {10, 7.85});
	cout << "s2 -> " << s2 << endl;

	Student s3(103, "Savu Stefania", 'F', 21, "Facultatea de Economie", 4, 
		new string[4]{ "Microeconomie", "Contabilitate", "Finante", "Statistica" }, new float[4] {8, 3.2, 9.80, 7.55});
	cout << "s3 -> " << s3 << endl;

	Student s4(s2);
	cout << "s4 -> " << s4 << endl;

	Student s5;
	cout << "Inainte de atribuire (inainte de apelul operatorlui =)" << endl;
	cout << "s5 -> " << s5 << endl;
	s5 = s3;
	cout << "Dupa atribuire (dupa apelul operatorului= ) " << endl << "s5 -> " << s5 << endl;

	Grupa g;
	cout << "g -> " << g;

	Grupa g1("B_101", new Student[5]{ s1, s2, s3, s4, s5 });
	cout << "g1 -> " << g1;
}