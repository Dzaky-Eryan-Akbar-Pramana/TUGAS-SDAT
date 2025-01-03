#include <iostream>
#include <fstream>
using namespace std;

struct KTP {
    string nik;
    string nama;
    string tempatLahir;
    string tanggalLahir;
    string jenisKelamin;
    string alamat;
    string rt;
    string rw;
    string kelurahan;
    string kecamatan;
    string agama;
    string statusPerkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string berlakuHingga;
};

struct Pelanggan {
    string nik;
    string nama;
    string waktuKedatangan;
    int jam;
    int menit;
};

struct Barang {
    string kodeItem;
    string namaItem;
    string tanggalMasuk;
};

struct NodeBarang {
    Barang data;
    NodeBarang* next;
};

struct NodePelanggan {
    Pelanggan data;
    NodePelanggan* next;
};

KTP inputDataKTP() {
    KTP ktp;
    cout << "Masukkan Data Admin (KTP)\n";
    cout << "NIK              : ";
    cin >> ktp.nik;
    cin.ignore();
    cout << "Nama             : ";
    getline(cin, ktp.nama);
    cout << "Tempat Lahir     : ";
    getline(cin, ktp.tempatLahir);
    cout << "Tanggal Lahir    : ";
    getline(cin, ktp.tanggalLahir);
    cout << "Jenis Kelamin    : ";
    getline(cin, ktp.jenisKelamin);
    cout << "Alamat           : ";
    getline(cin, ktp.alamat);
    cout << "RT               : ";
    cin >> ktp.rt;
    cout << "RW               : ";
    cin >> ktp.rw;
    cin.ignore();
    cout << "Kelurahan        : ";
    getline(cin, ktp.kelurahan);
    cout << "Kecamatan        : ";
    getline(cin, ktp.kecamatan);
    cout << "Agama            : ";
    getline(cin, ktp.agama);
    cout << "Status Perkawinan: ";
    getline(cin, ktp.statusPerkawinan);
    cout << "Pekerjaan        : ";
    getline(cin, ktp.pekerjaan);
    cout << "Kewarganegaraan  : ";
    getline(cin, ktp.kewarganegaraan);
    cout << "Berlaku Hingga   : ";
    getline(cin, ktp.berlakuHingga);
    return ktp;
}

void displayktp(KTP* ktpList, int banyak) {
    for (int i = 0; i < banyak; ++i) {
        cout << "====DATA ADMIN KE-" << i + 1 << "====\n";
        cout << "nik              : " << ktpList[i].nik << "\n";
        cout << "nama             : " << ktpList[i].nama << "\n";
        cout << "tempat lahir     : " << ktpList[i].tempatLahir << "\n";
        cout << "tanggal lahir    : " << ktpList[i].tanggalLahir << "\n";
        cout << "jenis kelamin    : " << ktpList[i].jenisKelamin << "\n";
        cout << "alamat           : " << ktpList[i].alamat << "\n";
        cout << "RT               : " << ktpList[i].rt << "\n";
        cout << "RW               : " << ktpList[i].rw << "\n";
        cout << "kelurahan        : " << ktpList[i].kelurahan << "\n";
        cout << "kecamatan        : " << ktpList[i].kecamatan << "\n";
        cout << "agama            : " << ktpList[i].agama << "\n";
        cout << "status perkawinan: " << ktpList[i].statusPerkawinan << "\n";
        cout << "pekerjaan        : " << ktpList[i].pekerjaan << "\n";
        cout << "kewarganegaraan  : " << ktpList[i].kewarganegaraan << "\n";
        cout << "berlaku hingga   : " << ktpList[i].berlakuHingga << "\n";
        cout << "========================\n";
        cout << endl;
    }
}

void simpanDataKTP(KTP ktp) {
    ofstream file("data_ktp.txt", ios::app);
    file << "====DATA ADMIN====\n";
    file << "nik              : " << ktp.nik << "\n";
    file << "nama             : " << ktp.nama << "\n";
    file << "tempat lahir     : " << ktp.tempatLahir << "\n";
    file << "tanggal lahir    : " << ktp.tanggalLahir << "\n";
    file << "jenis kelamin    : " << ktp.jenisKelamin << "\n";
    file << "alamat           : " << ktp.alamat << "\n";
    file << "RT               : " << ktp.rt << "\n";
    file << "RW               : " << ktp.rw << "\n";
    file << "kelurahan        : " << ktp.kelurahan << "\n";
    file << "kecamatan        : " << ktp.kecamatan << "\n";
    file << "agama            : " << ktp.agama << "\n";
    file << "status perkawinan: " << ktp.statusPerkawinan << "\n";
    file << "pekerjaan        : " << ktp.pekerjaan << "\n";
    file << "kewarganegaraan  : " << ktp.kewarganegaraan << "\n";
    file << "berlaku hingga   : " << ktp.berlakuHingga << "\n";
    file << "========================\n";
    file.close();
    cout << "Data KTP berhasil disimpan!" << endl;
}

bool cekKTP(string& nik,string& nama, KTP* ktpList, int banyak) {
    for (int i = 0; i < banyak; ++i) {
        if (ktpList[i].nik == nik && ktpList[i].nama == nama) {
            return true;
        }
    }
    return false;
}


NodeBarang* headBarang = NULL;
NodePelanggan* headPelanggan = NULL;

void pushBarang(Barang brg) {
    NodeBarang* newNode = new NodeBarang;
    newNode->data = brg;
    newNode->next = headBarang;
    headBarang = newNode;
}

bool isEmptyBarang() {
    return headBarang == NULL;
}

Barang popBarang() {
    if (!isEmptyBarang()) {
        NodeBarang* temp = headBarang;
        Barang data = temp->data;
        headBarang = headBarang->next;
        delete temp;
        return data;
    }
    Barang empty;
    return empty;
}

void displayBarang() {
    NodeBarang* current = headBarang;
    cout << "\nDaftar Barang dalam Gudang (LIFO):\n";
    cout << "Kode Item\tNama Item\tTanggal Masuk\n";
    while (current != NULL) {
        cout << current->data.kodeItem << "\t\t";
        cout << current->data.namaItem << "\t\t";
        cout << current->data.tanggalMasuk << endl;
        current = current->next;
    }
}

bool isEmptyPelanggan() {
    return headPelanggan == NULL;
}

void displayPelanggan() {
    if (isEmptyPelanggan()) {
        cout << "\nAntrian pelanggan kosong.\n";
        return;
    }
    NodePelanggan* current = headPelanggan;
    cout << "\nDaftar Antrian Pelanggan (FIFO):\n";
    cout << "NIK\t\tNama\t\tWaktu Kedatangan\n";
    while (current != NULL) {
        cout << current->data.nik << "\t" 
             << current->data.nama << "\t\t" 
             << current->data.waktuKedatangan << endl;
        current = current->next;
    }
}

int konversistring(string str) {
    int hasil = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            hasil = hasil * 10 + (str[i] - '0');
        }
    }
    return hasil;
}

void Waktukedatangan(Pelanggan& pelanggan) {
    string jam_str = pelanggan.waktuKedatangan.substr(0, pelanggan.waktuKedatangan.find(":"));
    string menit_str = pelanggan.waktuKedatangan.substr(pelanggan.waktuKedatangan.find(":") + 1);
    pelanggan.jam = konversistring(jam_str);
    pelanggan.menit = konversistring(menit_str);
}


void enqueuePelanggan(Pelanggan pelanggan) {
    Waktukedatangan(pelanggan);
    NodePelanggan* newNode = new NodePelanggan;
    newNode->data = pelanggan;
    newNode->next = NULL;

    if (headPelanggan == NULL || 
        (pelanggan.jam < headPelanggan->data.jam || 
         (pelanggan.jam == headPelanggan->data.jam && pelanggan.menit < headPelanggan->data.menit))) {
        newNode->next = headPelanggan;
        headPelanggan = newNode;
        return;
    }

    NodePelanggan* current = headPelanggan;
    while (current->next != NULL && 
           (current->next->data.jam < pelanggan.jam || 
            (current->next->data.jam == pelanggan.jam && current->next->data.menit <= pelanggan.menit))) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

Pelanggan dequeuePelanggan() {
    if (!isEmptyPelanggan()) {
        NodePelanggan* temp = headPelanggan;
        Pelanggan data = temp->data;
        headPelanggan = headPelanggan->next;
        delete temp;
        return data;
    }
    Pelanggan empty;
    return empty;
}

int main() {
    string nik, nama;
    int pilihan, banyak;
    bool isLoggedIn = false;
    int ktpbanyak = 0;
    KTP* ktpList = new KTP[100];

    cout << "Masukan Jumlah Admin : ";
    cin >> banyak;
    cin.ignore();

    for (int i = 0; i < banyak; i++) {
        cout << "DATA KE " << i + 1 << endl;
        KTP ktp = inputDataKTP();
        simpanDataKTP(ktp);
        ktpList[ktpbanyak++] = ktp;
        cout << endl;
    }

    displayktp(ktpList, ktpbanyak);
    cout << endl;

    while (!isLoggedIn) {
        cout << "=== Login Admin ===\n";
        cout << "Masukkan NIK: ";
        cin >> nik;
        cin.ignore();
        cout << "Masukkan Nama: ";
        getline(cin, nama);

        if (cekKTP(nik, nama, ktpList, ktpbanyak)) {
    		cout << "Login berhasil!\n";
   		    isLoggedIn = true;
        }else {
    		 cout << "Data KTP tidak ditemukan.\n";
    		 cout << "Silakan daftar terlebih dahulu.\n";
			 KTP ktpBaru = inputDataKTP();
			 simpanDataKTP(ktpBaru);
			 ktpList[ktpbanyak++] = ktpBaru;
			 cout << "Registrasi berhasil! Silakan login kembali.\n";
		}
    }

    do {
        cout << "\nMenu Sistem Inventori dan Antrian\n";
        cout << "1. Entri Item Barang\n";
        cout << "2. Catat Pembeli\n";
        cout << "3. Jual Item Barang\n";
        cout << "4. Cetak Daftar Barang\n";
        cout << "5. Cetak Daftar Pelanggan\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Barang brg;
                int input;
                cout << "Masukan jumlah barang : ";
                cin >> input;
                cin.ignore();
                
                for (int i = 1; i <= input; i++) {
                    cout << "\nMasukkan Data Barang ke- " << i << endl;
                    cout << "Kode Item: ";
                    cin >> brg.kodeItem;
                    cin.ignore();
                    cout << "Nama Item: ";
                    getline(cin, brg.namaItem);
                    cout << "Tanggal Masuk (YYYY-MM-DD): ";
                    getline(cin, brg.tanggalMasuk);
                    pushBarang(brg);
                    cout << "Barang berhasil ditambahkan ke inventori.\n";
                }
                break;
            }
            
			case 2: {
   			    int jumlahPembeli;
    		    cout << "Masukkan jumlah pembeli: ";
    			cin >> jumlahPembeli;

    			for (int i = 1; i <= jumlahPembeli; i++) {
        			Pelanggan pelanggan;
        			cout << "\nMasukkan Data Pembeli ke-" << i << endl;
        			cout << "NIK: ";
        			cin >> pelanggan.nik;
        			cin.ignore();
        			cout << "Nama: ";
        			getline(cin, pelanggan.nama);
        			cout << "Waktu Kedatangan (format HH:MM): ";
        			getline(cin, pelanggan.waktuKedatangan);
        			enqueuePelanggan(pelanggan);
        			cout << "Pembeli ke-" << i << " berhasil dicatat dan masuk antrian.\n";
    			}
    			break;
			}
			
            case 3: {
                if (!isEmptyPelanggan() && !isEmptyBarang()) {
                    Pelanggan pelanggan = dequeuePelanggan();
                    Barang barang = popBarang();
                    cout << "\nTransaksi Penjualan\n";
                    cout << "Pembeli: " << pelanggan.nama << " (Waktu: " << pelanggan.waktuKedatangan << ")" << endl;
                    cout << "Barang: " << barang.kodeItem << " - " << barang.namaItem << endl;
                    cout << "Transaksi berhasil.\n";
                } else {
                    cout << "Antrian kosong atau tidak ada barang tersedia.\n";
                }
                break;
            }
            
            case 4: {
                displayBarang();
                break;
            }
            
            case 5: {
            	displayPelanggan();
				break;
			}
            
            case 6: {
                cout << "Terima kasih telah menggunakan sistem.\n";
                break;
            }
            
            default: {
                cout << "Pilihan tidak valid.\n";
                break;
            }
        }
    } while (pilihan != 6);

    return 0;
}

