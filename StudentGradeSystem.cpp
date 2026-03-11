#include <iostream>
using namespace std;

struct Nilai {
    float absen;
    float tugas;
    float uts;
    float uas;
    float akhir;
    char huruf;
};

struct Mahasiswa {
    string npm;
    string nama;
    Nilai nilai;
};

Mahasiswa dataMhs[20];
int banyak = 0;

float hitungNilaiAkhir(float a, float t, float u1, float u2) {
    return (0.1*a) + (0.2*t) + (0.3*u1) + (0.4*u2);
}

char getHuruf(float n) {
    if (n > 80) return 'A';
    else if (n > 70) return 'B';
    else if (n > 60) return 'C';
    else return 'D';
}

int cariData(string npm) {
    for (int i = 0; i < banyak; i++) {
        if (dataMhs[i].npm == npm)
            return i;
    }
    return -1;
}

void tambah() {
    if (banyak >= 20) {
        cout<<"Data penuh\n";
        return;
    }

    cout<<"NPM : ";
    cin>>dataMhs[banyak].npm;

    cout<<"Nama : ";
    cin>>dataMhs[banyak].nama;

    cout<<"Absen : ";
    cin>>dataMhs[banyak].nilai.absen;

    cout<<"Tugas : ";
    cin>>dataMhs[banyak].nilai.tugas;

    cout<<"UTS : ";
    cin>>dataMhs[banyak].nilai.uts;

    cout<<"UAS : ";
    cin>>dataMhs[banyak].nilai.uas;

    dataMhs[banyak].nilai.akhir =
        hitungNilaiAkhir(
            dataMhs[banyak].nilai.absen,
            dataMhs[banyak].nilai.tugas,
            dataMhs[banyak].nilai.uts,
            dataMhs[banyak].nilai.uas
        );

    dataMhs[banyak].nilai.huruf =
        getHuruf(dataMhs[banyak].nilai.akhir);

    banyak++;
}

void tampil() {
    if (banyak == 0) {
        cout<<"Tidak ada data\n";
        return;
    }

    for (int i=0;i<banyak;i++) {
        cout<<"\nNPM : "<<dataMhs[i].npm;
        cout<<"\nNama : "<<dataMhs[i].nama;
        cout<<"\nNilai akhir : "<<dataMhs[i].nilai.akhir;
        cout<<"\nHuruf : "<<dataMhs[i].nilai.huruf;
        cout<<"\n-------------------";
    }
}

void edit() {
    string npm;
    cout<<"Masukkan NPM : ";
    cin>>npm;

    int i = cariData(npm);

    if (i == -1) {
        cout<<"Tidak ditemukan\n";
        return;
    }

    cout<<"Nama : ";
    cin>>dataMhs[i].nama;

    cout<<"Absen : ";
    cin>>dataMhs[i].nilai.absen;

    cout<<"Tugas : ";
    cin>>dataMhs[i].nilai.tugas;

    cout<<"UTS : ";
    cin>>dataMhs[i].nilai.uts;

    cout<<"UAS : ";
    cin>>dataMhs[i].nilai.uas;

    dataMhs[i].nilai.akhir =
        hitungNilaiAkhir(
            dataMhs[i].nilai.absen,
            dataMhs[i].nilai.tugas,
            dataMhs[i].nilai.uts,
            dataMhs[i].nilai.uas
        );

    dataMhs[i].nilai.huruf =
        getHuruf(dataMhs[i].nilai.akhir);
}

void hapus() {
    string npm;
    cout<<"Masukkan NPM : ";
    cin>>npm;

    int i = cariData(npm);

    if (i == -1) {
        cout<<"Tidak ditemukan\n";
        return;
    }

    for (int k=i; k<banyak-1; k++) {
        dataMhs[k] = dataMhs[k+1];
    }

    banyak--;
    cout<<"Data dihapus\n";
}

int main() {

    int pilih;

    do {
        cout<<"\nMENU";
        cout<<"\n1. Input";
        cout<<"\n2. Tampil";
        cout<<"\n3. Edit";
        cout<<"\n4. Hapus";
        cout<<"\n5. Keluar";
        cout<<"\nPilih : ";
        cin>>pilih;

        switch(pilih) {
            case 1: tambah(); break;
            case 2: tampil(); break;
            case 3: edit(); break;
            case 4: hapus(); break;
        }

    } while(pilih != 5);

}
