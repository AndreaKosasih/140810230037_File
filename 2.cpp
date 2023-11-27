/*
Buatlah program C++ untuk menghitung jumlah karakter tertentu, misalnya karakter ‘A’. 
Input berupa nama file dan karakter yang akan dihitung.
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

void cariJumlahKarakter(string namaFileInput, char karakter){
 	int jumlahKarakter = 0;
	char ch;
    ifstream fileteks;
    fileteks.open(namaFileInput);
	while(fileteks.get(ch)){
    	if(toupper(ch) == toupper(karakter)){
        	jumlahKarakter += 1;
    	}
	}
 	fileteks.close();      
	cout << "Jumlah Karakter : " << jumlahKarakter << endl;
}

int main(){
	string namaFileInput;
 	char karakter;
 	
	cout << "Masukkan Nama File : "; 
    getline(cin, namaFileInput);     
 	periksaFile(namaFileInput);

	cout << "Masukkan Karakter/Huruf Yang Ingin Dihitung : ";
	cin >> karakter;

	cariJumlahKarakter(namaFileInput, karakter);
	return 0;
}