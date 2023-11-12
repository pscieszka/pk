void swap(int *x, int *y);
void insert(int* tab, int n);
void selection(int* tab, int n);
void bubble(int* tab, int n);
void quicksort(int* tab, int left, int right);
void reBuildHeap(int *tab, int last);
void buildHeap(int *tab, int n);
void heap(int* tab,int n);
void shell(int* tab, int n);
void shellInsert(int* tab, int imax, int h);


// array and files functions
int *CreateArray(int n);
int* FreeArray(int*tab);
void printArray(int* tab, int n);

void test(int* tab, int n, char* file, int flag);
void readFromFile(char *filename, int *tab, int n);