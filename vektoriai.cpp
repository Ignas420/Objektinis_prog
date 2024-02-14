#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

struct Mokinys {
    string vardas;
    string pavarde;
    vector<int> ND;
    int egzaminas;
};

bool Patikrinimas(const string& kint);
void Vidurkis(vector<Mokinys>& A, vector<double>& VID);
void Isvedimas(const vector<Mokinys>& A, const vector<double>& VID, const vector<double>& MED);

int main() {
    vector<Mokinys> A;
    vector<double> VID;
    vector<double> MED;
    string kint;
    char input;
    Mokinys temp;
    int ND_kiekis, ND_kiekis2;

    srand(time(NULL));

    cout << "Irasykite vardus ir pavardes: " << endl;

    while (true) {
        cin >> temp.vardas >> temp.pavarde;
        if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde)) {
            cout << "Ivestas netinkamas vardas arba pavarde" << endl;
            return 0;
        }
        A.push_back(temp);
        cout << "Jei norite baigti, irasykite 't', kitu atveju irasykite bet koki simboli: " << endl;
        cin >> input;
        if (input == 't') break;
    }

    for (int i = 0; i < A.size(); i++) {
        ND_kiekis = 0;
        cout << "Irasykite namu darbu pazymius: " << endl;
        while (true) {
            int pazymys;
            cin >> pazymys;
            A[i].ND.push_back(pazymys);
            if(cin.fail()){
                cout << "Namu darbai turi buti skaicius!" <<endl;
                return 0;
            }
            if(pazymys < 1 || pazymys > 10){
                cout << "Pazymys turi buti desimtbaleje sistemoje!";
                return 0;
            }
            cout << "Jei norite baigti, irasykite 't', kitu atveju irasykite bet koki simboli: " << endl;
            cin >> input;
            if (input == 't') break;
            ND_kiekis++;
        }
        if(ND_kiekis2 != ND_kiekis && i!=0){
            cout << "Namu darbu kiekis turi buti vienodas!" << endl;
            return 0;
        }
        ND_kiekis2 = ND_kiekis;
        cout << "Irasykite egzamino rezultata: " << endl;
        cin >> A[i].egzaminas;
        if(cin.fail()){
                cout << "Pazymys turi buti skaicius!" <<endl;
                return 0;
            }
        if(A[i].egzaminas < 1 || A[i].egzaminas > 10){
                cout << "Pazymys turi buti desimtbaleje sistemoje!";
                return 0;
            }
}


    Vidurkis(A, VID);

    for (int i = 0; i < A.size(); i++) {
        const Mokinys& mok = A[i];
        vector<int> temp = mok.ND;
        temp.push_back(mok.egzaminas);
        sort(temp.begin(), temp.end());
        double mediana;
        int n = temp.size();
        if (n % 2 == 0)
            mediana = (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
        else
            mediana = temp[n / 2];
        MED.push_back(mediana);
    }

    Isvedimas(A, VID, MED);

    return 0;
}

void Vidurkis(vector<Mokinys>& A, vector<double>& VID) {
    for (Mokinys& mok : A) {
        double suma = 0;
        for (int pazymys : mok.ND) {
            suma += pazymys;
        }
        suma += mok.egzaminas;
        double vidurkis = suma / (mok.ND.size() + 1);
        VID.push_back(vidurkis);
    }
}

bool Patikrinimas(const string& kint) {
    const int ilgis = kint.length();
     char* temp_array = new char[ilgis + 1];
     strcpy(temp_array, kint.c_str());
         for(int i=0; i<ilgis; i++){
             if(!isalpha(temp_array[i]))
                 return false;
         }
     delete[] temp_array;
     return true;
}

void Isvedimas(const vector<Mokinys>& A, const vector<double>& VID, const vector<double>& MED) {
    cout << endl;
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavardė" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
    cout << setfill('-') << setw(80) << " " << endl;
    cout << setfill(' ');

    for (int i = 0; i < A.size(); i++) {
        cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << VID[i] << setw(18) << right << MED[i] << endl;
    }
}
