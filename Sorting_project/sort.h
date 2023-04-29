void swap(int *x, int *y);
void wstawianie(int* tab, int n);
void selekcja(int* tab, int n);
void bombel(int* tab, int n);
void quicksort(int* tab, int left, int right);
void ReBuildHeap(int *tab, int last);
void BuildHeap(int *tab, int n);
void kopcowanie(int* tab,int n);
void shell(int* tab, int n);
void shellInsert(int* tab, int imax, int h);


// array and files functions
int *CreateArray(int n);
void reset(int* tab, int n);
void FillArray(int *tab, int n);
int* FreeArray(int*tab);

void test1(int *tab,int n); // testowanie algorytmow grupy 1
void test2(int *tab, int n); // testowanie algorytmow grupy 2
void readFromFile(char *filename, int *tab, int n);
