#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien {
public:
	string nama;
	vector<dokter*>daftar_dokte;
	pasien(string pNama) :nama(pNama) {
		cout << "Pasien \"" << nama << "\" ada\n";
	}
	~pasien() {
		cout << "Pasien \"" << nama << "\" tidak ada\n";
	}
	void tambahDokter(dokter*);
	void cetakDokter();
};

class dokter {
public:
	string nama;
	vector<pasien*> daftar_pasien;

	dokter(string pNama) :nama(pNama) {
		cout << "Dokter \"" << nama << "\" ada\n";
	}
	~dokter() {
		cout << "Dokter \"" << nama << "\" tidak ada\n";
	}

	void tambahPasien(pasien*);
	void cetakPasien();
};

void pasien::tambahDokter(dokter* pDokter) {
	daftar_dokte.push_back(pDokter);
}
void pasien::cetakDokter() {
	cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
	for (auto& a : daftar_dokte) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void dokter::tambahPasien(pasien* pPasien) {
	daftar_pasien.push_back(pPasien);
	pPasien->tambahDokter(this);
}
void dokter::cetakPasien() {
	cout << "Daftar Pasien dari dokter \"" << this->nama << "\":\n";
	for (auto& a : daftar_pasien) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	dokter* varDokter1 = new dokter("dr.Mochi");
	dokter* varDokter2 = new dokter("dr.Matcha");
	pasien* varPasien1 = new pasien("Muza");
	pasien* varPasien2 = new pasien("Raiz");

	varDokter1->tambahPasien(varPasien1);
	varDokter2->tambahPasien(varPasien2);
	varDokter1->tambahPasien(varPasien1);

	varDokter1->cetakPasien();
	varDokter2->cetakPasien();
	varPasien1->cetakDokter();
	varPasien2->cetakDokter();

	delete varPasien1;
	delete varPasien2;
	delete varDokter1;
	delete varDokter2;

	return 0;
}