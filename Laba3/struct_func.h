#ifndef STRUCT_FUNC_H
#define STRUCT_FUNC_H
#include <string>
#include <vector>
using namespace std;

//ќбъект дл€ разработки структуры Ц квартира.
//ќбъ€вить пол€ :
//Ц  јдрес(структура с пол€ми улица, номер дома и квартиры)
//Ц  Ќазвание района
//Ц   оличество комнат
//Ц  ÷ена
struct Address_s
{
	string street;
	int number_of_house;
	int number_of_kv;
};
struct kvartira
{
	Address_s address;
	string raion;
	int komnati;
	int price;
};

void adr_in(Address_s& adr);
void kv_in(kvartira& kv);
void struct_in(kvartira kv[], const int size);
void struct_out(const kvartira kv1);
void struct_mass_out(const kvartira kv[], const int size);
void struct_out_menu(const kvartira kv[], int n);
void writestruct(const kvartira kv[], int size, const string& filenamewrite);
bool readstruct(vector<kvartira>& flat, const string& filenameread);
#endif