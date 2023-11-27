#include <iostream>
#include <fstream>
#include <string>       

using namespace std;

void periksaFile(string namaFile){
	ifstream fileteks; 			
	fileteks.open(namaFile);
	if(fileteks.fail()){
		cout << "File tidak ditemukan!";
		exit(1);
    }
	else{
		cout << "File ditemukan!" << endl;
    }
	fileteks.close();      
}

void cariJumlahPasanganKurungKurawal(string file, char karakter){
    int jumlahPasangan = 0;
    int jumlahKurung = 0;
    ifstream fileteks;     
    fileteks.open(file); 
    while(fileteks.get(karakter)){
        if(karakter == '{'){
            jumlahKurung += 1;
        } 
        else if(karakter == '}'){
            if(jumlahKurung > 0){
                jumlahPasangan += 1;
                jumlahKurung -= 1;
            }
        }
    }
    cout << "Jumlah pasangan kurung kurawal : " << jumlahPasangan << endl;
    fileteks.close();
}

int main(){
    string namaFile;
    char karakter;

    cout << "Masukkan Nama File : "; 
    getline(cin, namaFile);
    periksaFile(namaFile);
    
    cariJumlahPasanganKurungKurawal(namaFile, karakter);
    return 0;
}