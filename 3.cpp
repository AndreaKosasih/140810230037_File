/*
Misalkan suatu file teks berisi listing program C++. 
Buatlah program untuk menghitung pasangan kurung kurawal yang ada pada file teks tersebut.
*/

#include <iostream>
#include <fstream>
#include <string>       

using namespace std;

void periksaFile(string namaFileInput){
	ifstream fileteks; 			
	fileteks.open(namaFileInput);
	if(fileteks.fail()){
		cout << "File tidak ditemukan!";
		exit(1);
    }
	else{
		cout << "File ditemukan!" << endl;
    }
	fileteks.close();      
}

void cariJumlahPasanganKurungKurawal(string namaFileInput, char karakter){
    int jumlahPasangan = 0;
    int jumlahKurung = 0;
    ifstream fileteks;     
    fileteks.open(namaFileInput); 
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
    string namaFileInput;
    char karakter;

    cout << "Masukkan Nama File : "; 
    getline(cin, namaFileInput);
    periksaFile(namaFileInput);
    
    cariJumlahPasanganKurungKurawal(namaFileInput, karakter);
    return 0;
}