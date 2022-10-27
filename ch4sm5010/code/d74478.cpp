#include <Arduino.h>
//Declaring all variables as integers
int Z=0,Y=0,X=0,W=0;
int A,B,C,D;
int H,I,J,K,L,M,N;
//Code released under GNU GPL.  Free to use for anything.

void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g);
}
void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    //pinMode(9,INPUT);
    //pinMode(10,INPUT);
    //pinMode(11,INPUT);
    //pinMode(12,INPUT);

}
void loop()
{
  //W = digitalRead(9);//LSB
  //X = digitalRead(10);
  //Y = digitalRead(11);
  //Z = digitalRead(12);//MSB
  //A=!W;
  A=(!W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&!X&&!Y&&Z) || (!W&&X&&Y&&!Z);
B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);
W=A;
X=B;
Y=C;
Z=D;
H = (!Z&&!Y&&!X&&W) || (Y&&!X&&!W);
I = (Y&&!X&&W) || (Y&&X&&!W);
J = (!Y&&X&&!W);
K = (Y&&!X&&!W) || (Y&&X&&W) || (!Y&&!X&&W);
L = W || (Y&&!X);
M = (X&&W) || (!Z&&!Y&&W) || (!Y&&X);
N = (!Z&&!Y&&!X) || (Y&&X&&W);
sevenseg(H,I,J,K,L,M,N);
delay(2000);


/*
if(Z==0 && Y==0 && X==0 && W==1){
sevenseg(1,0,0,1,1,1,1);
delay(1000);}
if(Z==0 && Y==0 && X==1 && W==0){
sevenseg(0,0,1,0,0,1,0);
delay(1000);}
if(Z==0 && Y==0 && X==1 && W==1){
sevenseg(0,0,0,0,1,1,0);
delay(1000);}
if(Z==0 && Y==1 && X==0 && W==0){
sevenseg(1,0,0,1,1,0,0);
delay(1000);}
if(Z==0 && Y==1 && X==0 && W==1){
sevenseg(0,1,0,0,1,0,0);
delay(1000);}
if(Z==0 && Y==1 && X==1 && W==0){
sevenseg(0,1,0,0,0,0,0);
delay(1000);}
if(Z==0 && Y==1 && X==1 && W==1){
sevenseg(0,0,0,1,1,1,1);
delay(1000);}
if(Z==1 && Y==0 && X==0 && W==0){
sevenseg(0,0,0,0,0,0,0);
delay(1000);}
if(Z==1 && Y==0 && X==0 && W==1){
sevenseg(0,0,0,0,1,0,0);
delay(1000);}
if(Z==0 && Y==0 && X==0 && W==0){
sevenseg(0,0,0,0,0,0,1);
delay(1000);}
*/
}
