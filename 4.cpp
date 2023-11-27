/*
Buatlah program C++ untuk melakukan enkripsi shift chiper suatu file teks 
(dengan asumsi semua karakter huruf adalah huruf kapital). 
Inputnya adalah file teks yang akan dienkripsi dan besar pergeseran (integer). 
Outputnya adalah file teks hasil enkripsi.

Hint:
Ide dasar shift chiper adalah mengubah setiap karakter huruf ke karakter huruf lain. 
Misalkan pergeserannya 2, maka berikut ini karakter hasil enkripsi :
awal A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
hasil C D E F G H I J K L M N O P Q R S T U V W X Y Z A B
Sehingga misal diberikan suatu teks
C++ IS EASY,
maka hasil enkripsinya adalah
E++ KU GCUA
*/

#include <iostream>
#include <fstream>
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

void shiftCipher(string namaFileInput, string namaFileOutput, int n, string text){ 
    ifstream inputFileStream;
    inputFileStream.open(namaFileInput);
    getline(inputFileStream, text);
    inputFileStream.close();

    ofstream fileteks;     
    fileteks.open(namaFileOutput); 
    for(int i = 0; i < text.size(); i++){
        if(isupper(text[i])) {
            text[i] = (text[i] - 'A' + n) % 26 + 'A';
        }
    }
    fileteks << text;
    fileteks.close();
}

int main(){
    string inputFile, outputFile;
    int n;
    string text;

    cout << "Masukkan Nama File : ";
    getline(cin, inputFile);
    periksaFile(inputFile);

    cout << "Masukkan Besar Pergeseran : ";
    cin >> n;
    cin.ignore();

    cout << "Masukkan Nama File Hasil Enkripsi : ";
    getline(cin, outputFile);

    shiftCipher(inputFile, outputFile, n, text); 
    return 0;
}