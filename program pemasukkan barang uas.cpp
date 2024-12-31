#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Barang {
    string kode;
    string nama;
    int jumlah;
    double harga;
};

const int MAX = 100;
Barang daftar[MAX];
int totalBarang = 0;


void inputBarang() {
    cout << "\n======= INI PROGRAM PEMASUKKAN BARANG KE PABRIK`````````` " << endl;
    
  
    cout << "Kode barang   : ";
    cin >> daftar[totalBarang].kode;
    cin.ignore();
    
   
    cout << "Nama barang   : ";
    getline(cin, daftar[totalBarang].nama);
    
    do {
        cout << "Jumlah barang : ";
        cin >> daftar[totalBarang].jumlah;
        if(daftar[totalBarang].jumlah <= 0) {
            cout << "Error: Jumlah harus lebih dari 0!\n";
        }
    } while(daftar[totalBarang].jumlah <= 0);
    

    do {
        cout << "Harga barang  : Rp";
        cin >> daftar[totalBarang].harga;
        if(daftar[totalBarang].harga <= 0) {
            cout << "Error: Harga harus lebih dari 0!\n";
        }
    } while(daftar[totalBarang].harga <= 0);
    
    totalBarang++;
    cout << "\nBarang berhasil ditambahkan!" << endl;
}


void tampilkanBarang() {
    if(totalBarang == 0) {
        cout << "\nBelum ada data barang!" << endl;
        return;
    }

    cout << "\n=== DAFTAR BARANG ===" << endl;
    cout << "Jumlah data: " << totalBarang << endl;
    

    cout << setfill('-') << setw(65) << "-" << endl;
    cout << setfill(' ');
    cout << left << setw(5)  << "No"
         << setw(10) << "Kode"
         << setw(20) << "Nama"
         << right << setw(15) << "Jumlah"
         << setw(15) << "Harga" << endl;
    cout << setfill('-') << setw(65) << "-" << endl;
    cout << setfill(' ');
    
 
    for(int i = 0; i < totalBarang; i++) {
        cout << left << setw(5)  << i+1
             << setw(10) << daftar[i].kode
             << setw(20) << daftar[i].nama
             << right << setw(15) << daftar[i].jumlah
             << setw(15) << fixed << setprecision(0) 
             << daftar[i].harga << endl;
    }
    cout << setfill('-') << setw(65) << "-" << endl;
}


int main() {
    int pilihan;
    
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Input Barang" << endl;
        cout << "2. Tampilkan Barang" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                inputBarang();
                break;
            case 2:
                tampilkanBarang();
                break;
            case 3:
                cout << "\nProgram selesai!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while(pilihan != 3);
    
    return 0;
}
