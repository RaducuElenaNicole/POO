// Supraincarcari de operatori + Exemplu de exceptie default

/*
Exista expresia: a + b, unde a si b sunt operanzi (operand), iar + este operator

Tipuri de operatori:
1. UNARI (lucreaza cu un singur obiect/operand)
	op++, op--, op!
	!! op++ => preincrementare, incrementare prefixata VS postincrementare, incrementare postfixata
	!! op-- => predecrementare, decrementare prefixata VS postdecrementare, decrementare postfixata

2. BINARI (lucreaza cu doua obiecte/operanzi)
	op+, op-, op* (operator de inmultire) => au aceeasi modalitate de implementare 
	3 forme - obiect + valoare
	        - obiect + obeict 
			- valoare + obiect (valoarea poate fi numerica, string, etc.)

3. BOOL (operatori binari)
	op<, op>, op<=, op>=, op==, op!= 
		- operatorii <, >, <=, >= -> au aceeasi modalitate de implementare  
		- operatorii == si != -> au aceeasi modalitate de implementare

4. CAZURI SPECIALE 
	4.1. operator functie => operator() 
	4.2. operator cast 
		2 forme - implicit 
				- explicit 
	4.3. operator indexare => operator[]
	4.4. op~ 
	4.5. op+=, op-=, op*=, op/= (operatori compusi)
*/

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

	void afisareVectorNote() {
		for (int i = 0; i < nrMaterii; i++)
			cout << listaNote[i] << " | ";
	}
	void afisareVectorMaterii() {
		for (int i = 0; i < nrMaterii; i++)
			cout << listaMaterii[i] << " | ";
	}

	// get pe varsta 
	int getVarsta() {
		return this->varsta;
	}
	// get pe nume 
	char* getNumeStud() {
		return this->numeStud;
	}
	// get pe faculatate
	string getFacultate() {
		return this->facultate;
	}

	// SUPRAINCARCARI
	// 1. OPERATORI UNARI => op++, op--, op! 
	
	// op++ (forma pre-incrementare)
	int operator++() {
		varsta++;
		return varsta;
	}
	// op++ (forma post-incrementare)
	int operator++(int x) {
		Student copieStud = *this;
		varsta++;
		return copieStud.varsta;
	}

	// op-- (forma pre-decrementare)
	Student& operator--() {
		varsta--;
		return*this;
	}
	// op-- (forma post-decrementare)
	int operator--(int x) {
		Student copieStud = *this;
		varsta--;
		return copieStud.varsta;
	}
	/*
	Varianta asta NU arata ce presupune de fapt op-- forma postdecrementare!!!!
	Student operator--(int x) {
		Student copieStud = *this;
		this->varsta--;
		return copieStud;
	}
	*/

	// op! - operator unar, dar returneaza bool 
	bool operator!() {
		if (varsta >= 18)
			return true; 
		return false;
	}

	// 2. OPERATORI BINARI
	// op+ (obiect + valoare)
	Student& operator+(int val) {
		this->varsta = this->varsta + val;
		return*this;
	}
	// op+ (valoare + obiect)
	// in acest caz, supraincarcarea se realizeaza pentru int (tip de data); NU exista this; functia nu face parte din clasa
	friend Student operator+(int val, Student& stud) {
		stud.varsta = stud.varsta + val;
		return stud;
	}
	// op+ (obiect + obiect)
	Student& operator+(Student stud) {
		this->varsta = this->varsta + stud.varsta;
		return*this;
	}
	// op+ (string + obiect)
	friend string operator+(string numeUnivesitate, Student& stud) {
		stud.facultate = stud.facultate + " " + numeUnivesitate;
		return stud.facultate;
	}

	// 3. BOOL
	// op>= 
	bool operator>=(Student stud) {
		if (this->varsta >= stud.varsta)
			return true; 
		return false; 
	}
	// op<
	bool operator<(int val) {
		int ok = 1; // presupunem ca studentul nu are restante => este integralist
		for (int i = 0; i < nrMaterii; i++)
			if (listaNote[i] < 5)
				ok = 0;
		if(ok == 1)
				return true; // INTEGRALIST
			else
				return false; // RESTANTIER
	}
	// op!=
	bool operator!=(Student stud) {
		if (strcmp(this->numeStud, stud.numeStud) == 0)
			return true;
		return false;
	}

	// 4. CAZURI SPECIALE 
	
	// 4.1. operator() - operator functie
	float operator()() {
		float sumaNote = 0;
		int nrNote = 0;
		for (int i = 0; i < nrMaterii; i++) {
			if (listaNote[i] >= 5) {
				sumaNote += listaNote[i];
				nrNote++;
			}
		}
		float medie = 0;
		medie = sumaNote / nrNote;
		return medie;
	}
	Student operator()(float punctajBonus) {
		for (int i = 0; i < nrMaterii; i++) {
			listaNote[i] = listaNote[i] + punctajBonus;
		}
		return*this;
	}

	// 4.2. operator de cast 
	// forma implicita 
	int nrMateriiPromavate() {
		int nrMateriiPromovate = 0;
		for (int i = 0; i < nrMaterii; i++)
			if (listaNote[i] >= 5)
				nrMateriiPromovate++;
		return (int)nrMateriiPromovate;
	}
	// forma explicita 
	explicit operator float() {
		return varsta + 0.1;
	}

	// 4.3. operator[] - operator de indexare
	string operator[](int index) {
		if (index >= 0 && index < nrMaterii && listaMaterii != NULL)
			return listaMaterii[index];
		else
			throw exception();
		// return "Indexul nu este asociat cu o materie!";
	}

	// 4.4. operator~
	float operator~() {
		varsta = varsta + 2;
		return varsta;
	}

	// 4.5. op+= 
	Student& operator+=(float notaNoua) {
		float* copieListaNote = new float[nrMaterii + 1];
		string* copieListaMaterii = new string[nrMaterii + 1];
		for (int i = 0; i < nrMaterii; i++) {
			copieListaNote[i] = listaNote[i];
			copieListaMaterii[i] = listaMaterii[i];
		}

		copieListaNote[nrMaterii] = notaNoua;
		copieListaMaterii[nrMaterii] = "Info";
		nrMaterii++;

		delete[] listaMaterii;
		delete[] listaNote;

		listaMaterii = new string[nrMaterii];
		listaNote = new float[nrMaterii];
		for (int i = 0; i < nrMaterii; i++) {
			listaNote[i] = copieListaNote[i];
			listaMaterii[i] = copieListaMaterii[i];
		}

		return*this;
	}

	// metode de adaugare materie si nota in vector
	Student& adaugaMaterie(float notaNoua, string materieNoua) {
		float* copieListaNote = new float[nrMaterii + 1];
		string* copieListaMaterii = new string[nrMaterii + 1];
		for (int i = 0; i < nrMaterii; i++) {
			copieListaNote[i] = listaNote[i];
			copieListaMaterii[i] = listaMaterii[i];
		}

		copieListaNote[nrMaterii] = notaNoua;
		copieListaMaterii[nrMaterii] = materieNoua;
		nrMaterii++;

		delete[] listaMaterii;
		delete[] listaNote;

		listaMaterii = new string[nrMaterii];
		listaNote = new float[nrMaterii];
		for (int i = 0; i < nrMaterii; i++) {
			listaNote[i] = copieListaNote[i];
			listaMaterii[i] = copieListaMaterii[i];
		}

		return*this;
	}
};
string Student::universitate = "ASE";

void main() {
	Student s;
	cout << "s -> " << s << endl;

	Student s1(101, "Popescu Ana", 'F', 17, "Facultatea de Cibernetica", 3, new string[3]{ "Microeconomie", "Bazele Ciberneticii", "Statistica" }, new float[3] {5.90, 9.45, 3});
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


	Student s6(106, "Vasilescu Matei", 'M', 20, "Facultatea de Informatica", 2, new string[2]{ "Programare Orientata Obiect", "Bazele Programarii Calculatoarelor" }, new float[2] {10, 7.85});
	cout << "s6 -> " << s6 << endl;

	cout << "---------- operator++ ---------- " << endl;
	// initial: s5.varsta = 21 
	// dupa post-incrementare: s5.varsta = 21 (asta se vede la consola, dar varsta creste de fapt => 22)
	// dupa pre-incrementare: s5.varsta = 22 + 1 = 23
	cout << "Initial: " << s5.getVarsta();
	cout << endl << "	OP++ -> POST-incrementare - " << s5++ << endl;
	cout << "			" << s5.getVarsta() << endl;
	cout << "	OP++ -> PRE-incrementare - " << ++s5 << endl;

	cout << endl;

	cout << "---------- operator-- ---------- ";
	// initial: s3.varsta = 21
	// dupa post-decrementare: s3.varsta = 21 (asta se vede la consola, dar varsta scade de fapt => 20)
	// dupa pre-decrementare: s3.varsta = 20 - 1 = 19
	cout << endl << "Initial: " << s3.getVarsta();
	cout << endl << "	OP-- -> POST-decrementare - " << s3-- << endl;
	cout << "			" << s3.getVarsta() << endl;
	--s3;
	cout << "	OP-- -> PRE-decrementare - " << s3.getVarsta() << endl;

	cout << endl;

	cout << "---------- operator! ---------- ";
	// op! 
	// cout << endl << s1.getVarsta() << !s1 ? " => Major" : "=> Copil"; DE VERIFICAT! 
	cout << endl << s1.getVarsta();
	if (!s1)
		cout << " => Major";
	else
		cout << " => Copil";
	
	cout << endl << s2.getVarsta();
	if (!s2)
		cout << " => Major";
	else
		cout << " => Copil";

	cout << endl << endl;

	// op+
	cout << "---------- operator+ ---------- ";
	cout << endl << s2.getVarsta();
	s2 + 3;
	cout << " | " << s2.getVarsta();
	4 + s2;
	cout << " | " << s2.getVarsta();
	s2 + s1;
	cout << " | " << s2.getVarsta() << " unde s1.varsta = " << s1.getVarsta() << endl;
	cout << "s2.faculatate: " << s2.getFacultate();
	"ASE" + s2;
	cout << " | " << s2.getFacultate() << endl;

	cout << endl;

	// op>=
	cout << "---------- operator>= ---------- " << endl;
	cout << "s1.varsta = " << s1.getVarsta() << " | s2.varsta = " << s2.getVarsta() << " => ";
	if (s1 >= s2)
		cout << "s1 estre mai mare";
	else
		cout << "s2 este mai mare";
	cout << endl;
	cout << "s1.varsta = " << s1.getVarsta() << " | s3.varsta = " << s3.getVarsta() << " => ";
	if (s3 >= s1)
		cout << "s3 estre mai mare";
	else
		cout << "s1 este mai mare";

	cout << endl << endl;

	// op> 
	cout << "---------- operator> ---------- " << endl;
	s2.afisareVectorNote();
	if (s2 < 5)
		cout << "Student integralist!";
	else
		cout << "Student restantier!";
	cout << endl;
	s1.afisareVectorNote();
	if (s1 < 5)
		cout << "Student integralist!";
	else
		cout << "Student restantier!";

	cout << endl << endl;

	// op!= 
	cout << "---------- operator!= ---------- ";
	cout << endl << s6.getNumeStud() << " | " << s2.getNumeStud() << " => ";
	if (s6 != s2)
		cout << "Studentii au acelasi nume.";
	else
		cout << "Studentii NU au acelasi nume.";
	cout << endl << s1.getNumeStud() << " | " << s2.getNumeStud() << " => ";
	if (s1 != s2)
		cout << "Studentii au acelasi nume.";
	else
		cout << "Studentii NU au acelasi nume.";

	cout << endl << endl;

	// op() + op(val) - operator functie
	cout << "---------- operator() ---------- " << endl;
	cout << "Note s2: ";
	s2.afisareVectorNote(); 
	cout << " Media notelor lui s2 = " << s2() << " | notele finale cu punctajul bonus: ";
	s2(2.5);
	s2.afisareVectorNote();
	cout << endl;

	cout << "Note s1: ";
	s1.afisareVectorNote();
	cout << " Media notelor lui s1 = " << s1() << " | notele finale cu punctajul bonus: ";
	s1(1);
	s1.afisareVectorNote();
	cout << endl;

	cout << endl; 

	// op[] - indexare
	// cout << s1[5] << " | " << s2[1] << endl;
	cout << "---------- operator[] ---------- " << endl;
	try {
		cout << s1[10] << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	cout << endl;

	// op cast explicit 
	cout << "---------- operator cast explicit ----------" << endl;
	cout << s1.getVarsta() << " | " << (float)s1 << endl;

	cout << endl;

	// op cast implicit 
	cout << "---------- operator cast implicit ---------- " << endl;
	cout << "Note s2: ";
	s2.afisareVectorNote();
	cout << "Numarul de materii promovate este: " << s2.nrMateriiPromavate() << endl;
	cout << "Note s1: ";
	s1.afisareVectorNote();
	cout << "Numarul de materii promovate este: " << s1.nrMateriiPromavate() << endl;

	cout << endl;

	// op~
	cout << "---------- op~ ----------" << endl;
	cout << s2.getVarsta();
	~s2;
	cout << " | " << s2.getVarsta();

	cout << endl << endl;

	// op+=
	cout << "---------- op+= ----------" << endl;
	cout << "vector note = ";
	s2.afisareVectorNote();
	s2 += 10;
	cout << "vector note dupa op+= = ";
	s2.afisareVectorNote();

	cout << endl << endl;

	cout << "---------- adaugaMaterie ----------" << endl;
	s2.adaugaMaterie(5.80, "Economie");
	s2.afisareVectorNote();
	s2.afisareVectorMaterii();
	s2.adaugaMaterie(9.80, "SDD");
	s2.adaugaMaterie(8.40, "PAW");
	s2.adaugaMaterie(2.40, "Java");
	cout << endl << s2;

	cout << endl;

	// verficare preincrementare si postincrementare pe o variabila int simpla 
	cout << "--------------------------------------- " << endl;
	int x = 10;
	cout << ++x << endl; // 11
	cout << x++ << endl; // 11 (x creste la 12, dar la consola afiseaza 11)
	cout << x << endl << endl; // 12

	// op++
	cout << "---------- operator++ ---------- " << endl;
	// cout << s6.getVarsta() << " | " << ++s6 << " | " << s6++ << " | " << s6.getVarsta() << endl; -> nu e bun apelul (scade varsta) 
	cout << s6.getVarsta() << endl;
	cout << ++s6 << endl; // preincrementare 
	cout << s6++ << endl; // postincrementare
	cout << s6.getVarsta() << endl;

}