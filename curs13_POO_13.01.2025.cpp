// STL (colectii/containere) - curs 13 - sapt 13 - 13.01.2025 
// biblioteca de sabloane 
// Standard Template Library (STL)

#include<iostream>

#include<vector>
#include<list> 
#include<map>
#include<stack>

using namespace std;

// containere secveventiale - vector (masiv), lista (lista dublu inlantuita)
// containere adaptive - stiva(FIFO), coada(LIFO) 
// containere asociave - set, map, multiset, multimap (asociere intre cheie si valoare) 

// definire obiect vector pe baza unui sablon 
void main() {
	cout << "--------------------- CONTAINER SECVENTIAL --------------------- " << endl;
	cout << endl << "--------------------- VECTOR --------------------- " << endl;
	vector<int> vectI; // vector de int (nr intregi)
	// adaugarea elementelor in vector => metoda push_back() 
	vectI.push_back(200);
	vectI.push_back(150);
	vectI.push_back(600);
	vectI.push_back(90);
	// metoda size() => numarul de elemente din vector 
	for (int i = 0; i < vectI.size(); i++) {
		cout << vectI[i] << " | ";
	}
	cout << endl;
	// pentru fiecare element din vectI => un fel de foreach
	for (auto element : vectI) {
		cout << element << " | ";
	}
	cout << endl;
	vector<int>::iterator itrV;
	for (itrV = vectI.begin(); itrV != vectI.end(); itrV++) {
		cout << *itrV << " | ";
	}
	cout << endl;

	vector<int>::reverse_iterator itrVR;
	for (itrVR = vectI.rbegin(); itrVR != vectI.rend(); itrVR++) {
		cout << *itrVR << " | ";
	}
	cout << endl;
	// la vector merge vectI.begin() + 1 ptc vectorul are elementele asezate in memorie unul dupa celalat (elemente contigue) 
	// la lista nu este asa!!!!!!!
	cout << vectI.at(2) << endl; // metoda at(index) => acceseaza elementul de la indexul index
	cout << endl << "--------------------- LIST --------------------- " << endl;
	list<double> listD; 
	listD.push_back(23.78);
	listD.push_back(89.28);
	listD.push_back(73.25);
	listD.push_back(10.99);
	listD.push_back(18.55);
	listD.push_front(100.55); // se adauga in capatul listei 
	// iterator => definit ca fiind o clasa inclusa in vector/lista etc. (in general in cantainer)
	// iteratorul este general 
	list<double>::iterator itr;
	// :: = operator de rezolutie 
	// itr -> marcheaza inceputul si sfarsitul elementelor din container
	for (itr = listD.begin(); itr != listD.end(); itr++) {
		// listD.begin() => primul element din lista 
		// (iteratorul refera primul element al listei listD si iteratorul se va pozitiona la colectia lista listD)
		// listD.end() = ultimul element din lista  
		// itr = pointer => pentru extragerea valorii de la adresa de memorie => *
		cout << *itr << " | ";
	}
	cout << endl << endl << endl;

	cout << "--------------------- CONTAINER ASOCIATIV --------------------- " << endl;
	cout << endl << "--------------------- MAP --------------------- " << endl;
	map<int, string> mapS;
	// int = cheie 
	// string = valoare
	pair<int, string> elem1(500, "Elena");
	pair<int, string> elem2(900, "Valentina");
	pair<int, string> elem3(260, "Ana");
	pair<int, string> elem4(90, "Gigi");
	pair<int, string> elem5(890, "Stefania");
	// ordine crescatoare dupa cheie !!!!
	mapS.insert(elem1);
	mapS.insert(elem2);
	mapS.insert(elem3);
	mapS.insert(elem4);
	mapS.insert(elem5);
	map<int, string>::iterator itrM;
	for (itrM = mapS.begin(); itrM != mapS.end(); itrM++) {
		cout << "(" << (*itrM).first << " - " << itrM->second << ") | ";
	}
	cout << endl;
	map<int, string, greater<int>> mapSDesc; // ordine descrescatoare 
	map<int, string, less<int>> mapSCresc; // ordine crescatoare (less este implicit) 

	cout << endl << endl << endl << "--------------------- CONTAINER ADAPTIV --------------------- " << endl;
	cout << endl << "--------------------- STIVA --------------------- " << endl;
	// se adapteaza la operatiile stivei => push() si pop()
	stack<int, list<int>> stivaI;
	stivaI.push(200);
	stivaI.push(900);
	stivaI.push(150);
	stivaI.push(550);
	stivaI.push(660);
	cout << stivaI.top() << endl;
	cout << stivaI.top() << endl;
	stivaI.pop();
	cout << stivaI.top() << endl;
	cout << stivaI.top() << endl;
}