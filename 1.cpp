/*
Buatlah program untuk menghitung jumlah karakter vocal dan konsonan dalam suatu file. 
Inputnya adalah nama file text dan pathnya.
*/

#include <iostream>
#include <fstream>      
#include <string>       
#include <cctype>

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

void cariJumlahKarakterVokal(string namaFileInput, char karakter){
    int jumlahKarakter = 0;
    ifstream fileteks;      
    fileteks.open(namaFileInput);    
    while(fileteks.get(karakter)){ 
        if(isalpha(karakter)){
            char ch = tolower(karakter); 
            if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o'){
                jumlahKarakter += 1;
            }
        }
    }
    fileteks.close();      
    cout << "Jumlah karakter vokal : " << jumlahKarakter << endl;
}

void cariJumlahKarakterKonsonan(string namaFileInput, char karakter){
    int jumlahKarakter = 0;
    ifstream fileteks;      
    fileteks.open(namaFileInput);    
    while(fileteks.get(karakter)){ 
        if (isalpha(karakter)) {
            char ch = tolower(karakter); 
            if (!(ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o')){
                jumlahKarakter += 1;
            }
        }
    }
    fileteks.close();       
    cout << "Jumlah karakter konsonan : " << jumlahKarakter << endl;
}

int main(){
    string namaFileInput;
    char karakter;

    cout << "Masukkan Nama File : "; 
    getline(cin, namaFileInput); 
    periksaFile(namaFileInput);

    cariJumlahKarakterVokal(namaFileInput, karakter);
    cariJumlahKarakterKonsonan(namaFileInput, karakter);
    return 0;
}


