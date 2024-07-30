#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct untuk menyimpan data lari
struct DataLari {
    string nama;
    string jenisKelamin;
    double totalWaktuMenit;
    double totalWaktuDetik;
    double totalJarak;
};

// Fungsi untuk menghitung pace
double hitungPace(double totalWaktuMenit, double totalWaktuDetik, double totalJarak) {
    double totalWaktu = totalWaktuMenit + (totalWaktuDetik / 60.0);
    return totalWaktu / totalJarak;
}

// Fungsi untuk menghitung kecepatan (speed) dalam satuan detik per kilometer
double hitungKecepatanDetik(double totalWaktuMenit, double totalWaktuDetik, double totalJarak) {
    double totalWaktuDetikTotal = (totalWaktuMenit * 60) + totalWaktuDetik;
    return totalJarak / totalWaktuDetikTotal; // dalam kilometer per detik
}

// Fungsi untuk menentukan intensitas berdasarkan kecepatan
string tentukanIntensitas(double kecepatanDetik) {
    double kecepatanMph = kecepatanDetik * 0.0372823; 
    double paceMenit = 3600 / (kecepatanDetik * 60); 

    if (kecepatanMph < 3) {
        return "Intensitas Ringan: Pace lebih dari 20 menit per mil";
    } else if (kecepatanMph >= 3 && kecepatanMph < 4) {
        return "Intensitas Sedang: Pace antara 16 dan 20 menit per mil";
    } else if (kecepatanMph >= 4 && kecepatanMph < 5) {
        return "Intensitas Menengah: Pace antara 12 dan 15 menit per mil";
    } else {
        return "Intensitas Tinggi: Pace kurang dari 12 menit per mil";
    }
}




int main() {
    vector<DataLari> dataLariList;
    int pilihan;

    do {
        cout << "=== Program Penghitung Pace Lari ===" << endl;
        cout << "1. Input data lari" << endl;
        cout << "2. Tampilkan hasil perhitungan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                DataLari dataLari;
                cout << "Masukkan nama: ";
                cin >> dataLari.nama;
                cout << "Masukkan jenis kelamin: ";
                cin >> dataLari.jenisKelamin;
                cout << "Masukkan total waktu (menit): ";
                cin >> dataLari.totalWaktuMenit;
                cout << "Masukkan total waktu (detik): ";
                cin >> dataLari.totalWaktuDetik;
                cout << "Masukkan total jarak (km): ";
                cin >> dataLari.totalJarak;
                dataLariList.push_back(dataLari);
                break;
            }
            case 2: {
                for (const auto& dataLari : dataLariList) {
                    double pace = hitungPace(dataLari.totalWaktuMenit, dataLari.totalWaktuDetik, dataLari.totalJarak);
                    double kecepatan = hitungKecepatanDetik(dataLari.totalWaktuMenit, dataLari.totalWaktuDetik, dataLari.totalJarak);
                    cout << "Nama: " << dataLari.nama << endl;
                    cout << "Jenis Kelamin: " << dataLari.jenisKelamin << endl;
                    cout << "Pace: " << pace << " menit per km" << endl;
                    cout << "Kecepatan: " << kecepatan << " km per detik" << endl;
                    cout << endl;
                }
                break;
            }
            case 3:
                cout << "Aplikasi keluar. Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
