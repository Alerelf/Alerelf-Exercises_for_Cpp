#include<iostream>
using namespace std;

class F {
//fraction
    private:
    long a,b,c,n; 
    //integer, numerator, denominator, variable
    short d; 
    //counter
public:
 F(): a(0),b(0),c(1),d(0){}

long set(){

cout<<"\nВведите целую часть ";cin>>a;
cout<<"\nВведите числитель ";cin>>b;
cout<<"\nВведите знаменатель ( не 0 ) ";cin>>c;
cout<<'\n';
    while(c==0){
        if(d>0)return 0;
        cout<<"\nВведите знаменатель неравный 0. У вас 1 шанс.\n";
        cin>>c;d++;
    }
//dcg
    for(long i=c;i>0;i--){
        if(b%i==0 && c%i==0){
            b=b/i;c=c/i;
        }
    }
    if(b>=c){
        a+=b/c;b=b%c;
    }
    return 0;
}

void get(){
    for(long i=c;i>0;i--){
        if(b%i==0 && c%i==0){
            b=b/i;c=c/i;
        }
    }
    if(b>=c){
        a+=b/c;b=b%c;
    }
    
    cout<<"\nРезультат:";
    
    if(b<c){
        if(b<0){a+=b/c;b=b%c;};
        if(a==0 && b==0)cout<<' '<<b<<endl;
    }
    
    if(a!=0)cout<<' '<<a<<" целая(ых)";
    if(b!=0)cout<<' '<<b<<"/"<<c<<endl;    
}
    
F ad(F e){ 
    //addition
    F f;
    f.a=a+e.a;
//складывать ли 0и?
   /* if (c==e.c){
        f.b=b+e.b;
        f.c=c;
    } else { */
    
        f.b=b*e.c+e.b*c;
        f.c=c*e.c;
   // }
    return f;
}

F s(F e){ 
    //subtraction
    F f;
    if(c==e.c){
        f.b=a*c+b-(e.a*c+e.b);
        f.c=c;
    }else{
        f.b=(a*c+b)*e.c-(e.a*e.c+e.b)*c;
        f.c=c*e.c;
    }
    return f;
}

F m(F e){ 
    //multiplication
    F f;
    f.b=(a*c+b)*(e.a*e.c+e.b);
    f.c=c*e.c;
    return f;
}

F dv(F e){
//division
    F f;
    f.b=(a*c+b)*e.c;
    f.c=c*(e.a*e.c+e.b);
    return f;
}};

int main(){

F a,b,c;

short d=1,k=0;char o;

cout<<"Добро пожаловать в калькулятор дробей.\n\n";
while(d>0){
if(k==0){
cout<<"\nВведите две дроби: \n";a.set();b.set();
k=1;
}
if(k>0){
cout<<"\nВыберите операцию:"
<<"\n + сумма, - разность,"
<<"\n * произведение или / деление.\n";
cin>>o;switch(o){
case '+':c=a.ad(b);c.get();break;
case '-':c=a.s(b);c.get();break;
case '*':c=a.m(b);c.get();break;
case '/':c=a.dv(b);c.get();break;
default:cout<<"\nПопробуйте ещё\n";break;
}
cout<<"\nХотите операции с дробями ещё? Y/n(1 or 0).\n";
cin>>d;
if(d>0){
cout<<"\nС этими же дробями? Y/n(1 or 0).\n";
cin>>k;
}}} 
return 0;
}