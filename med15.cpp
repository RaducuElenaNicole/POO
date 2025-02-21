#include<iostream>
using namespace std;

template<typename T>

class Locuinta {

private:
    const int cod;
    char* adresa;
    float suprafataLocuinta;
    bool etaj;
    int nrCamere;
    T* suprafeteCamere;//suprafata poate fi int sau float sau double
    string* denumireCamera;

public:
    Locuinta() : cod(0)
    {
        this->adresa = new char[strlen("Necunoscut/a") + 1];
        strcpy_s(this->adresa, strlen("Necunoscut/a") + 1, "Necunoscut/a");
        this->suprafataLocuinta = 0;
        this->etaj = false;
        this->nrCamere = 1;
        this->suprafeteCamere = new T[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            this->suprafeteCamere[i] = 0;
        }
        this->denumireCamera = new string[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            this->denumireCamera[i] = "N/A";
        }
    }

    Locuinta(const int _cod,
        const char* adresa,
        float suprafataLocuinta,
        bool etaj,
        int nrCamere,
        float* suprafeteCamere,
        string* denumireCamera) : cod(_cod) {

        this->adresa = new char[strlen(adresa) + 1];
        strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
        this->suprafataLocuinta = suprafataLocuinta;
        this->etaj = etaj;
        this->nrCamere = nrCamere;
        this->suprafeteCamere = new T[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            this->suprafeteCamere[i] = suprafeteCamere[i];
        }
        this->denumireCamera = new string[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            this->denumireCamera[i] = denumireCamera[i];
        }
    }

    Locuinta(const Locuinta& loc) : cod(loc.cod) {
        this->adresa = new char[strlen(loc.adresa) + 1];
        strcpy_s(this->adresa, strlen(loc.adresa) + 1, loc.adresa);
        this->suprafataLocuinta = loc.suprafataLocuinta;
        this->etaj = loc.etaj;
        this->nrCamere = loc.nrCamere;
        this->suprafeteCamere = new float[loc.nrCamere];
        for (int i = 0; i < loc.nrCamere; i++) {
            this->suprafeteCamere[i] = loc.suprafeteCamere[i];
        }
        this->denumireCamera = new string[loc.nrCamere];
        for (int i = 0; i < loc.nrCamere; i++) {
            this->denumireCamera[i] = loc.denumireCamera[i];
        }
    }

    ~Locuinta() {
        delete[] this->adresa;
        delete[] this->suprafeteCamere;
        delete[] this->denumireCamera;
    }

    Locuinta& operator=(const Locuinta& loc) {
        if (this->adresa != NULL) {
            delete[] this->adresa;
        }
        if (this->suprafeteCamere != NULL) {
            delete[] this->suprafeteCamere;
        }
        if (this->denumireCamera != NULL) {
            delete[] this->denumireCamera;
        }

        this->adresa = new char[strlen(loc.adresa) + 1];
        strcpy_s(this->adresa, strlen(loc.adresa) + 1, loc.adresa);
        this->suprafataLocuinta = loc.suprafataLocuinta;
        this->etaj = loc.etaj;
        this->nrCamere = loc.nrCamere;
        this->suprafeteCamere = new float[loc.nrCamere];
        for (int i = 0; i < loc.nrCamere; i++) {
            this->suprafeteCamere[i] = loc.suprafeteCamere[i];
        }
        this->denumireCamera = new string[loc.nrCamere];
        for (int i = 0; i < loc.nrCamere; i++) {
            this->denumireCamera[i] = loc.denumireCamera[i];
        }

        return*this;
    }

    char* getadresa() {
        return this->adresa;
    }
    int getNrCamere() {
        return this->nrCamere;
    }
    void setNrCamere(int nrCamereNou, float* suprafeteCamereNou, string* denumireCameraNou) {
        if (this->suprafeteCamere != NULL) {
            delete[] this->suprafeteCamere;
        }
        if (this->denumireCamera != NULL) {
            delete[] this->denumireCamera;
        }

        this->nrCamere = nrCamereNou;
        this->suprafeteCamere = new float[nrCamereNou];
        for (int i = 0; i < nrCamereNou; i++) {
            this->suprafeteCamere[i] = suprafeteCamereNou[i];
        }
        this->denumireCamera = new string[nrCamereNou];
        for (int i = 0; i < nrCamereNou; i++) {
            this->denumireCamera[i] = denumireCameraNou[i];
        }

    }
    void setAdresa(const char* adresaNou) {
        if (this->adresa != NULL) {
            delete[] this->adresa;
            this->adresa = new char[strlen(adresaNou) + 1];
            strcpy_s(this->adresa, strlen(adresaNou) + 1, adresaNou);
        }
    }

    friend ostream& operator<<(ostream& out, Locuinta& loc) 
    {
        out << "Cod: " << loc.cod
            << " | Adresa: " << loc.adresa
            << " | Suprafata: " << loc.suprafataLocuinta
            << " | Etaj: " << loc.etaj
            << " | Numar camere: " << loc.nrCamere << endl;
        for (int i = 0; i < loc.nrCamere; i++) {
            out << "Camera " << i + 1 << " - ( Suprafata: " << loc.suprafeteCamere[i] << " | Denumire: " << loc.denumireCamera[i] << " ) ";
            out << endl;
        }
        return out;
    }

    bool operator()(int nrLocatari) {
        if (nrLocatari > this->nrCamere)
            return false;
        else
            return true;
    }
};

void main() {
    Locuinta<float> l;//late binding
    cout << "l -> " << l;

    Locuinta<int> l1(101, "Dumbravei", 2500, true, 5,
        new float[5] { 250, 450, 90, 700, 150 }, new string[5]{ "A1", "A2", "A3", "A4", "A5" });
    cout << "l1 -> " << l1;

    Locuinta<int> l2(102, "Dumbravei", 2500, true, 5,
        new float[5] { 250, 450, 90, 700, 150 }, new string[5]{ "A1", "A2", "A3", "A4", "A5" });
    cout << "l2 -> " << l2;

    if (l1(10))
        cout << "TRUE";
    else
        cout << "FALSE";

    cout << endl;

    if (l1(2))
        cout << "TRUE";
    else
        cout << "FALSE";

    cout << endl;

}