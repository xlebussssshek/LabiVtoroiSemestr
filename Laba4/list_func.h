#ifndef STRUCT_FUNC_H
#define STRUCT_FUNC_H
#include <string>
#include <vector>
using namespace std;

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
    kvartira operator=(const kvartira& a) {
        address.street = a.address.street; address.number_of_house = a.address.number_of_house;
        address.number_of_kv = a.address.number_of_kv; raion = a.raion; komnati = a.komnati; price = a.price; return *this;
    }
};

struct Node_queue
{
    kvartira data;
    Node_queue* next;

};

void shapka();
void adr_in(Address_s& adr);
void kv_in(kvartira& kv);
void struct_in(kvartira kv[], const int size);
void struct_out(const kvartira kv1);
void struct_mass_out(const kvartira kv[], const int size);
void struct_out_menu(const kvartira kv[], int n);
void writestruct(Node_queue* head, const string& filenamewrite);
bool readstruct(Node_queue*& head, Node_queue*& tail, const string& filenameread);
void list_append(Node_queue*& head, Node_queue*& tail, const kvartira& fl);
void headlist_out(Node_queue*& head, Node_queue*& tail);
void list_delete(Node_queue*& head);
void lastlist_delete(Node_queue*& head, Node_queue*& tail);
void deletecurrent(Node_queue*& head, Node_queue*& tail, Node_queue*& poisk);
void editstruct(kvartira& kv1);
#endif