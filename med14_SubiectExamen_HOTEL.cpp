#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; 

class CameraHotel {
private:
	int nrCamera;
	int etajCamera;
	string denumireCamera;
	char* tipCamera;
	int nrFacilitatiCamera;
	string* facilitatiCamera;
	const int id;

public:
	// constructor implicit/default/fara parametri 
	CameraHotel() : id(0) 
	{
		this->nrCamera = 0;
		this->etajCamera = 0;
		this->denumireCamera = "Necunoscut/a";
		this->tipCamera = new char[strlen("Necunoscut/a") + 1];
		strcpy(this->tipCamera, "Necunoscut/a");
		this->nrFacilitatiCamera = 1;
		this->facilitatiCamera = new string[this->nrFacilitatiCamera];
		for (int i = 0; i < this->nrFacilitatiCamera; i++) {
			this->facilitatiCamera[i] = "Necunoscut/a";
		}
	}

	// constructor cu parametri 
	CameraHotel(int nrCamera,
				int etajCamera,
				string denumireCamera,
				const char* tipCamera,
				int nrFacilitatiCamera,
				string* facilitatiCamera,
				const int _id) : id(_id) 
	{
		this->nrCamera = nrCamera;
		this->etajCamera = etajCamera;
		this->denumireCamera = denumireCamera;
		this->tipCamera = new char[strlen(tipCamera) + 1];
		strcpy(this->tipCamera, tipCamera);
		this->nrFacilitatiCamera = nrFacilitatiCamera;
		this->facilitatiCamera = new string[this->nrFacilitatiCamera];
		for (int i = 0; i < this->nrFacilitatiCamera; i++) {
			this->facilitatiCamera[i] = facilitatiCamera[i];
		}
	}

	// constructor de copiere 
	CameraHotel(const CameraHotel& camH) : id(camH.id)
	{
		this->nrCamera = camH.nrCamera;
		this->etajCamera = camH.etajCamera;
		this->denumireCamera = camH.denumireCamera;
		this->tipCamera = new char[strlen(camH.tipCamera) + 1];
		strcpy(this->tipCamera, camH.tipCamera);
		this->nrFacilitatiCamera = camH.nrFacilitatiCamera;
		this->facilitatiCamera = new string[this->nrFacilitatiCamera];
		for (int i = 0; i < this->nrFacilitatiCamera; i++) {
			this->facilitatiCamera[i] = camH.facilitatiCamera[i];
		}
	}

	// operator=
	CameraHotel& operator=(const CameraHotel& camH) {
		// pasul 1: destructor
		if (this->tipCamera != NULL) {
			delete[] this->tipCamera;
		}
		if (this->facilitatiCamera != NULL) {
			delete[] this->facilitatiCamera;
		}
		
		// pasul 2: constructor de copiere
		this->nrCamera = camH.nrCamera;
		this->etajCamera = camH.etajCamera;
		this->denumireCamera = camH.denumireCamera;
		this->tipCamera = new char[strlen(camH.tipCamera) + 1];
		strcpy(this->tipCamera, camH.tipCamera);
		this->nrFacilitatiCamera = camH.nrFacilitatiCamera;
		this->facilitatiCamera = new string[this->nrFacilitatiCamera];
		for (int i = 0; i < this->nrFacilitatiCamera; i++) {
			this->facilitatiCamera[i] = camH.facilitatiCamera[i];
		}
		 
		// pasul 3: return 
		return*this;
	}

	// destructor
	~CameraHotel() {
		if (this->tipCamera != NULL) {
			delete[] this->tipCamera;
		}
		if (this->facilitatiCamera != NULL) {
			delete[] this->facilitatiCamera;
		}
	}

	// operator<< -> supraincarcare operator de afisare 
	friend ostream& operator<<(ostream& out, const CameraHotel& camH) {
		out << "CameraHotel --- NR: " << camH.nrCamera
			<< " | ETAJ: " << camH.etajCamera
			<< " | DENUMIRE: " << camH.denumireCamera
			<< " | TIP: " << camH.tipCamera
			<< " | NR FACILITATI: " << camH.nrFacilitatiCamera
			<< " | FACILITATI: ";
		for (int i = 0; i < camH.nrFacilitatiCamera; i++) {
			out << i + 1 << "= " << camH.facilitatiCamera[i] << " ";
		}
		out << "| ID: " << camH.id;
		out << endl;
		return out;
	}

	// operator++ - forma prefixata (preincrementare)
	int operator++() {
		return ++this->etajCamera;
	}

	// operator++ - forma postfixata (postincrementare)
	int operator++(int x) {
		CameraHotel copie = *this;
		this->etajCamera++;
		return copie.etajCamera;
	}
};

void main() {
	CameraHotel c;
	cout << "c -> " << c;

	CameraHotel c1(123, 3, "Paris", "Single", 3, 
				   new string[3]{ "Wi-fi", "Aer conditionat", "Televizor" }, 101);
	cout << "c1 -> " << c1;

	CameraHotel c2(478, 1, "Atena", "Family", 4,
				   new string[4]{ "Wi-fi", "Bluetooth", "Aer conditionat", "Televizor"}, 102);
	cout << "c2 -> " << c2;

	CameraHotel c3(935, 7, "Anglia", "Twin", 2,
				   new string[2]{ "Wi-fi", "Bluetooth"}, 103);
	cout << "c3 -> " << c3;

	CameraHotel c4(459, 5, "Italia", "King", 5,
				   new string[5]{ "Wi-fi", "Bluetooth", "Lumina calda", "Aer conditionat", "Televizor" }, 104);
	cout << "c4 -> " << c4;

	CameraHotel c5(c3);
	cout << "c5 -> " << c5;

	CameraHotel c6;
	c6 = c4;
	cout << "c6 -> " << c6;

	cout << ++c6;
	int x = 10;
	cout << endl << x++ << endl;
	cout << x;

	cout << endl;
	cout << c6++ << endl;
	cout << c6;
}