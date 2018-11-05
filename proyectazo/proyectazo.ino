#include <LiquidCrystal.h>//importamos libreria para usar la pantalla LCD 16x2.
//variables de los sensores.
byte sol_1 = 13;
byte cent_50 = 12;
byte cent_20 = 11;
byte cent_10 = 10;
//variables LCD.
int d4 = 9;
int d3 = 8;
int d2 = 7;
int d1 = 6;
int en = 5;
int rs = 4;
//control de saldo.
double saldo = 0;
//precios.
double oreo = 0.5;
//instancia del lcd.
LiquidCrystal lcd(4,5,6,7,8,9);
//bluetooth.
int estado = 0;

void setup(){
  
  //configurar pines.
  pinMode(sol_1,INPUT);
  pinMode(cent_50,INPUT);
  pinMode(cent_20,INPUT);
  pinMode(cent_10,INPUT);
  //tamaño del lcd.
  lcd.begin(16, 2);
  //bluetooth.
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()>0){
    estado = Serial.read();
  }
  if(sol_1 == HIGH){//verifica la moneda de un sol.
    saldo += 1;
  }

  if(cent_50 == HIGH){//verifica la moneda de 50 centimos.
    saldo += 0.5;
  }

  if(cent_20 == HIGH){//verifica la moneda de 20 centimos.
    saldo += 0.2;
  }

  if(cent_10 == HIGH){//verifica la moneda de 10 centimos.
    saldo += 0.1;
  }
  //Bluetooth.
  if(saldo > 0){
    if(estado == '1'){
      saldo -= 0.3;
    }
    
    if(estado == '2'){
      saldo -= 0.8;
    }
  
  
    if(estado == '3'){
      //descontar saldo.
    }
  
    if(estado == '4'){
      //descontar saldo.
    }

  
    if(estado == '5'){
      //descontar saldo.
    }
    
    if(estado == '6'){
      //descontar saldo.
    }
  }else{
    lcd.print("Introduzca monedas :|");
  }
  
  lcd.print("saldo: ");
  lcd.print(saldo);//imprime el saldo en el LCD.
  delay(1000);

}
