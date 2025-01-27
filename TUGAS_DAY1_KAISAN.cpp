// TUGAS DAY 1 CA-RSC

// Nama : Muhammad Kaisan Khasyyatullah Ismail
// NIM  : 13323023

// Deskripsi : Dibutuhkanya sebuah program untuk mengelola daftar kontak. Program ini akan menyimpan informasi kontak dalam PhoneBook. Setiap kontak memiliki nama,tempat tinggal, alamat, dan kekuatan.
// PhoneBook dapat menampung maksimal 8 kontak. Jika PhoneBook sudah penuh, maka kontak yang paling lama akan diganti dengan kontak yang baru. 
// Program ini memiliki 4 perintah: ADD, SEARCH, DISPLAY, dan EXIT. 
// Perintah ADD digunakan untuk menambahkan kontak baru ke PhoneBook. 
// Perintah SEARCH digunakan untuk mencari kontak berdasarkan nama. 
// Perintah DISPLAY digunakan untuk menampilkan semua nama kontak yang ada di PhoneBook. 
// Perintah EXIT digunakan untuk keluar dari program.

// MATERI DAY 1 YANG DIGUNAKAN :
// 1. Inheritance : Class PhoneBook mewarisi atribut dan method dari class Contact
// 2. Encapsulation : Atribut pada class Contact di-encapsulate dengan private, sehingga hanya dapat diakses melalui method getNama dan displayInfo
// 3. Polymorphism : Method displayInfo pada class Contact dapat diakses oleh class PhoneBook
// 4. Abstraction : Class Contact dan PhoneBook merupakan representasi dari objek nyata yang memiliki atribut dan method yang sesuai
// 5. CONSTRUCTOR : Constructor digunakan untuk menginisialisasi atribut pada class Contact


#include <iostream>
#include <string>

// Membuat Class CONTACT yang berisikan nama, tempat tinggal, alamat, dan kekuatan
class Contact {
private:
    std::string nama;
    std::string tempat_tinggal;
    std::string alamat;
    std::string kekuatan;

public:
    Contact() : nama(""), tempat_tinggal(""), alamat(""), kekuatan("") {}
    Contact(std::string nama_, std::string tempat_tinggal_, std::string alamat_, std::string kekuatan_)
        : nama(nama_), tempat_tinggal(tempat_tinggal_), alamat(alamat_), kekuatan(kekuatan_) {}

    std::string getNama() const {
        return nama;
    }

    void displayInfo() const {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Tempat Tinggal: " << tempat_tinggal << std::endl;
        std::cout << "Alamat: " << alamat << std::endl;
        std::cout << "Kekuatan: " << kekuatan << std::endl;
    }
};

// Membuat Class PHONEBOOK untuk menyimpan kontak
class PhoneBook : public Contact {
private:
    Contact contacts[8]; // Membuat array untuk menyimpan kontak dengan kuantitas maksimum 8 kontak
    int jumlah_kontak; // Jumlah kontak saat ini

public:
    PhoneBook() : jumlah_kontak(0) {}

    // Menambahkan kontak ke PhoneBook
    void ADD(const std::string& nama, const std::string& tempat_tinggal, const std::string& alamat, const std::string& kekuatan) {
        if (jumlah_kontak >= 8) {
            // Mengganti kontak yang paling lama jika PhoneBook sudah penuh
            for (int i = 1; i < 8; i++) {
                contacts[i - 1] = contacts[i];
            }
            // Substitusi kontak terakhir
            contacts[7] = Contact(nama, tempat_tinggal, alamat, kekuatan);
        } else {
            contacts[jumlah_kontak++] = Contact(nama, tempat_tinggal, alamat, kekuatan);
        }
        std::cout << "Kontak berhasil ditambahkan\n";
    }

    // Mencari kontak berdasarkan nama
    void SEARCH(const std::string& name) const {
        for (int i = 0; i < jumlah_kontak; i++) {
            if (contacts[i].getNama() == name) {
                std::cout << "Informasi Kontak:\n";
                contacts[i].displayInfo();
                return;
            }
        }
        std::cout << "Kontak tidak ditemukan.\n";
    }

    // Menampilkan semua kontak
    void DISPLAY() const {
        if (jumlah_kontak == 0) {
            std::cout << "PhoneBook kosong.\n";
            return;
        }

        std::cout << "Daftar Kontak:\n";
        for (int i = 0; i < jumlah_kontak; i++) {
            std::cout << "- " << contacts[i].getNama() << std::endl;
        }
    }

    // Menghapus seluruh kontak
    void CLEAR() {
        jumlah_kontak = 0;
        std::cout << "PhoneBook telah dikosongkan.\n";
    }
};

// Membuat sistemasi kinerja program

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "\nPILIH OPSI UNTUK SISTEM : ADD, SEARCH, DISPLAY, EXIT\n";
        std::cout << "OPSI : ";
        std::cin >> command;

        if (command == "ADD") {
            std::string nama, tempat_tinggal, alamat, kekuatan;
            std::cout << "Masukkan nama: ";
            std::cin >> nama;
            std::cout << "Masukkan tempat tinggal: ";
            std::cin >> tempat_tinggal;
            std::cout << "Masukkan alamat: ";
            std::cin >> alamat;
            std::cout << "Masukkan kekuatan: ";
            std::cin >> kekuatan;
            phoneBook.ADD(nama, tempat_tinggal, alamat, kekuatan);
        } else if (command == "SEARCH") {
            std::string nama;
            std::cout << "Masukkan nama kontak yang ingin dicari: ";
            std::cin >> nama;
            phoneBook.SEARCH(nama);
        } else if (command == "DISPLAY") {
            phoneBook.DISPLAY();
        } else if (command == "EXIT") {
            phoneBook.CLEAR();
            std::cout << "Keluar dari program.\n";
            break;
        } else {
            std::cout << "Perintah tidak dikenali. Coba lagi.\n";
        }
    }

    return 0;
}
