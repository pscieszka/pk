#include <iostream>
#include "string.h"
void statyczne_alokowanie() {
	char str[] = "";
	char sstr[64] = "";
	size_t sz_mem = sizeof(str);
	size_t len_str = strlen(str);
	sz_mem = sizeof(sstr);
	len_str = strlen(sstr);
}

void wczytanie_z_klawiatury(char* str, size_t SilentBytes) {
	size_t ss = sizeof(str);
	if (gets_s(str, SilentBytes - 1) == NULL)
		printf("??? %s\n", str);

}
void sklejanie(char* str, char str1[], size_t SilentBytes) {
	strcat_s(str, SilentBytes, " ");
	strcat_s(str, SilentBytes, str1);
}
void kopiowanie(char* str, char str1[], size_t SilentBytes) {
	strcpy_s(str, SilentBytes, str1);
}
int main()
{
	char name[32];
	char surname[32];

	statyczne_alokowanie();
	printf_s("insert name\n");
	wczytanie_z_klawiatury(name, sizeof(name));
	printf_s("insert surname\n");
	wczytanie_z_klawiatury(surname, sizeof(surname));
	sklejanie(name, surname, sizeof(name));
	printf_s("%s", name);
	kopiowanie(surname, name, sizeof(name));
	printf_s("%s", name);

}
