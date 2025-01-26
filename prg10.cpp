// Metode statice
// Functii accesor / Metode de acces / GET + SET pe atribut STATIC
// Compunere 1:1 

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
	Student() : nrCrt(0) 
	{
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
		if (this->numeStud != NULL) {
			delete[] this->numeStud;
		}
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

	// metoda statica
	static string modificareUniversitate(string universitateNoua) {
		universitate = universitateNoua;
		return universitate;
	}

	friend static float medieVarstaStudenti(int nrStud, Student* stud);

	// get + set pe atribut static 
	static string getUniversitate() {
		return universitate;
	}
	static void setUniversitate(string universitateNoua) {
		universitate = universitateNoua;
	}
};
string Student::universitate = "ASE";

// functie static
static int nrMateriiPromavate(int nrNote, float* note) {
	int nrMateriiPromovate = 0;
	for (int i = 0; i < nrNote; i++)
		if (note[i] >= 5)
			nrMateriiPromovate++;
	return nrMateriiPromovate;
}

// functie statica pe vector de obiecte + functie globala 
static float medieVarstaStudenti(int nrStud, Student* stud) {
	int sumaVarsta = 0;
	for (int i = 0; i < nrStud; i++) {
		sumaVarsta = sumaVarsta + stud[i].varsta;
	}
	return (float)sumaVarsta / nrStud;
}

// 1:1
class BurseErasmus {
public:
	string tara;
	Student stud;

	BurseErasmus() {
		this->tara = "N/A";
		this->stud = Student();
	}

	BurseErasmus(string tara, Student stud) {
		this->tara = tara;
		this->stud = stud; 
	}

	friend ostream& operator<<(ostream& out, const BurseErasmus& brsE) {
		out << "Burse Erasmus --- TARA: " << brsE.tara << " | STUDENT: " << brsE.stud << endl;
		return out;
	}
};

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
	cout << "Dupa atribuire (dupa apelul operatorului= ) " << endl << "s5 -> " << s5 << endl << endl;

	cout << "-------------------- operator= " << endl;
	s2 = s3; 
	cout << "s2 -> " << s2 << endl;

	cout << nrMateriiPromavate(4, new float[4] {8, 3.2, 9.80, 7.55}) << endl;
	cout << nrMateriiPromavate(3, new float[3] {2, 3.2, 1.80}) << endl;

	cout << endl;

	cout << medieVarstaStudenti(5, new Student[5]{ s1, s2, s3, s4, s5 }) << endl;

	cout << endl;

	BurseErasmus b;
	cout << "b -> " << b;

	BurseErasmus b1("Italia", s2);
	cout << "b1 -> " << b1;

	cout << endl << endl;
	cout << s3.getUniversitate() << " | ";
	s3.setUniversitate("FIM");
	cout << s3.getUniversitate() << endl;
}