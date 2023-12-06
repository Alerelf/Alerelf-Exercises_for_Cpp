#include<iostream>
//#include<conio.h>
using namespace std;
/*const char Esc=27;
const float TOLL=0.5;

K=getche();
k=Esc выход по нажатию клавиши.*/

class Co{

private:
unsigned int a;float b;
public:
Co():a(0),b(0.0){}

void payCar(){
a++;b+=0.5;
}
void noCar(){
a++;
}
void display(){
cout<<"Авто: "
<<a<<" Сумма: "<<b;
}};

int main(){
Co c;
unsigned short f=0,i=0,j=0,k;
cout<<"Машина с оплатой - нажмите '1'"
<<"\nбез оплаты - нажмите '0'";
while(f<3){
f++;cin>>k;
while(k>1 && i<3){
cout<<"Введите 1 или 0. У вас 3 попытки."
<<"\nЕсли вы не справитесь"<<
"\n то подсчёт будет закончен.";
cin>>k;i++;
}
f+=i;
if(k==0)c.noCar();
else if(k==1)c.payCar();
}
c.display();
return 0;
}