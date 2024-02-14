#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <conio.h>

using namespace std;
const int CMax = 10;
double VID[CMax] = {0};

struct Mokinys{
  string vardas;
  string pavarde;
  int ND[CMax];
  int egzaminas;
};

bool Patikrinimas(string kint);
void Vidurkis(Mokinys A[], int kiekis, int ND_kiekis);

int main(){
    Mokinys A[CMax], B[CMax];
    int DID[CMax];
    string kint;
    int temp=0;
    int kiekis = 0;
    char input;
    int ND_kiekis=0;
    int ND_kiekis2;

    cout << "Irasykite vardus ir pavardes: " << endl;

    while(1){ 
        cin >> A[temp].vardas >> A[temp].pavarde;
        if(Patikrinimas(A[temp].vardas) == false || Patikrinimas(A[temp].pavarde) == false){
            cout << "Ivestas netinkamas vardas arba pavarde" <<endl;
            return 0;
        }
        temp++;
        kiekis++;
        cout<<"Ar norite baigti irasyma, jie taip, irasykite 'T': " << endl;
        cin >> input;
        if(input == 'T') break;
        
    }

    temp = 0;

    for(int i=0; i<kiekis; i++){
        ND_kiekis = 0;
        cout << "Irasykite namu darbu pazymius: " << endl;
        
        while(true){
            cin >> A[i].ND[temp];
            temp++;
            ND_kiekis++;
            cout<<"Ar norite baigti irasyma, jie taip, irasykite 'T': " << endl;
            cin >> input;
            if(input == 'T') break;
        }
        if(ND_kiekis2 != ND_kiekis && i!=0){
            cout << "Namu darbu kiekis turi buti vienodas!" << endl;
            break;
        }
        ND_kiekis2 = ND_kiekis;
        temp = 0;
        cout << "Irasykite egzamino rezultata: " << endl;
        cin >> A[i].egzaminas;
    }

    for(int i=0; i<kiekis; i++){
        for(int j=0; j<ND_kiekis; j++)
            B[i].ND[j] = A[i].ND[j];
        B[i].ND[ND_kiekis] = A[i].egzaminas;
    }

    Vidurkis(A, kiekis, ND_kiekis);

    double MED[CMax];

    for(int i=0; i<kiekis; i++){
        sort(B[i].ND, B[i].ND + (ND_kiekis+1));
        cout<<endl;
        if((ND_kiekis+1)%2==0)
            MED[i] = (double) (B[i].ND[(ND_kiekis+1)/2 - 1] + B[i].ND[(ND_kiekis+1)/2]) / 2.0;
        else
            MED[i] = B[i].ND[(ND_kiekis+1)/2];
    }

    cout<<endl;
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavardė" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)"<<endl;
    cout << setfill('-') << setw(80) << " " << endl;
    cout << setfill(' ');

    for(int i = 0; i<kiekis; i++){
         cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << VID[i] << setw(18) << right << MED[i] << endl;
     }
     return 0;
}
void Vidurkis(Mokinys A[], int kiekis, int ND_kiekis){
    for(int i=0; i<kiekis; i++){
        double suma = 0;
        for(int j=0; j<ND_kiekis; j++){
            cout<< A[i].ND[j]<<" ";
            suma += A[i].ND[j];
        }
        suma += A[i].egzaminas;
        VID[i] = suma / (ND_kiekis + 1);
    }
}
 bool Patikrinimas(string kint){
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
