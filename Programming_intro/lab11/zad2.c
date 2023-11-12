#include <stdio.h>

int rzymskie_arabskie (char*  x, int size){
int wynik=0;
for(int i=0; i<size; i++){
if(x[i]=='I' && x[i+1] == 'V'){
wynik+=4;
i++;
}
else if(x[i]=='I' && x[i+1] == 'X'){
wynik+=9;
i++;
}
else if(x[i]=='X' && x[i+1] == 'L'){
wynik+=40;
i++;
}
else if(x[i]=='X' && x[i+1] == 'C'){
wynik+=90;
i++;
}
else if(x[i]=='C' && x[i+1] == 'D'){
wynik+=400;
i++;
}
else if(x[i]=='C' && x[i+1] == 'M'){
wynik+=900;
i++;
}
else if(x[i]== 'I'){
wynik+=1;
}
else if(x[i]== 'V'){
wynik+=5;
}
else if(x[i]== 'X'){
wynik+=10;
}
else if(x[i]== 'L'){
wynik+=50;
}
else if(x[i]== 'C'){
wynik+=100;
}
else if(x[i]== 'D'){
wynik+=500;
}
else if(x[i]== 'M'){
wynik+=1000;
}

}
return wynik;
}

void arabskie_rzymskie (int n){  
    printf("wynik="); 
    while(n != 0){
    if (n >= 1000)       
    {
        printf("M");
        n -= 1000;
    }
    else if (n >= 900)   
    {
        printf("CM");
        n -= 900;
    }        
    else if (n >= 500)   
    {           
        printf("D");
        n -= 500;
    }
    else if (n >= 400)  
    {
        printf("CD");
        n -= 400;
    }
    else if (n >= 100)
    {
        printf("C");
        n -= 100;                       
    }
    else if (n >= 90)    
    {
        printf("XC");
        n -= 90;                                              
    }
    else if (n >= 50)    
    {
        printf("L");
        n -= 50;                                                                     
    }
    else if (n >= 40)    
    {
        printf("XL");           
        n -= 40;
    }
    else if (n >= 10)    
    {
        printf("X");
        n -= 10;           
    }
    else if (n >= 9)     
    {
        printf("IX");
        n -= 9;                         
    }
    else if (n >= 5)     
    {
        printf("V");
        n -= 5;                                     
    }
    else if (n >= 4)     
    {
        printf("IV");
        n -= 4;                                                            
    }
    else if (n >= 1)     
    {
        printf("I");
        n -= 1;                                                                                   
    }
    }
}
int main(){
printf("Podaj 2 liczby rzymskie z przedzialu I..M(drukowanymi literami np. CMXCIX)\n");
char a[20];
char b[20];
printf("Podaj pierwsza liczbe:");
scanf("%s",a);
int wielkosc_a = sizeof(a);
int wynik1;
wynik1 = rzymskie_arabskie(a,wielkosc_a);

printf("Podaj pierwsza liczbe:");
scanf("%s",b);
int wielkosc_b = sizeof(b);
int wynik2;
wynik2 = rzymskie_arabskie(b,wielkosc_b);
int wynik3=wynik1+wynik2;
arabskie_rzymskie(wynik3);
}