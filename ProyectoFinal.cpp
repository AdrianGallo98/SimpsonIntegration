 #include <stdio.h>  
 #include <windows.h>  
 #include <iostream>
 #include <conio.h>
 #include <math.h>

 #define PI 3.14159
 #define e 	2.71828
 
using namespace std;
 	
 	double rms=0,RMS=0;
 		
 		
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
 void derivada(int orden, float a[], int *lim){ //obtiene la derivada de orden n de un polinomio
	int i, j;
	for(i=0;i<orden;i++){
		for(j=0;j<*lim-1;j++){
			a[j]=((j+1)*a[j+1]);
		}
		a[*lim-1]=0;
	}	
}

void trap(float h, double f0, double f1){
	double trapecio;
	trapecio=h*((f0+f1)/2);
	gotoxy(15,10);
	cout<<"Con el metodo del trapecio la Integral aproximada es: "<<trapecio;
	rms=trapecio;
}

void traperror(double x0, double x1, float a[], int *lim){//limite inferior, Limite superior, vector derivada2, n
	double error;//error de truncamiento
	float valprom;
	float b[*lim];//guardar el valor de la integral
	float evaluacionA=0;//evaluacion en el limite inferior
	float evaluacionB=0;//evaluacion en el limite superior
	float intervalo;
	intervalo=x0-x1;
	int i,j;
	for(i=0;i<*lim;i++){
		evaluacionA=evaluacionA+((pow(x0,i))*a[i]);	
		evaluacionB=evaluacionB+((pow(x1,i))*a[i]);		
	}
	valprom=((evaluacionA-evaluacionB)/(intervalo));
	error=((pow(intervalo,3)*valprom)/3);
	gotoxy(15,15);
	cout<<"error de truncamiento: "<<error;
}

void trapmult(float h,int n,double f[]){//Tamaño total del intervalo, numero de untervalos, funcion 
	double sum,trapm;
	int i;
	sum=f[0];
	for(i=1;i<n;i++){
		sum=sum+(2*f[i]);
	}
	sum=sum+f[n];
	trapm=(h/n)*(sum/(2));
	gotoxy(15,10);
	cout<<"Con el metodo del trapecio la Integral aproximada es: "<<trapm;
	rms=trapm;
}
void traperrormul(int n,double x0, double x1, float a[], int *lim){//limite inferior, Limite superior, vector derivada2, n
	double error;//error de truncamiento
	float valprom;
//	float b[*lim];//guardar el valor de la integral
	float evaluacionA=0;//evaluacion en el limite inferior
	float evaluacionB=0;//evaluacion en el limite superior
	float intervalo;
	intervalo=x0-x1;
	int i,j;
	for(i=0;i<*lim;i++){
		evaluacionA=evaluacionA+((pow(x0,i))*a[i]);	
		evaluacionB=evaluacionB+((pow(x1,i))*a[i]);		
	}
	valprom=((evaluacionA-evaluacionB)/(intervalo));
	error=((pow(intervalo,3)*valprom)/(12*pow(n,2)));
	gotoxy(15,15);
	cout<<"error de truncamiento: "<<error;
}


void simps13(float h, float f0, float f1, float f2 ){
	float simps13;
	simps13= h*((f0+(4*f1)+f2)/6);
	gotoxy(15,10);
	cout<<"Con el metodo de simpson 1/3 simple, la Integral aproximada es: "<<simps13;
	rms=simps13;
}
void simps13error(double x0, double x1, float a[], int *lim){//limite inferior, Limite superior, vector derivada2, n
	double error;//error de truncamiento
	float valprom;
//	float b[*lim];//guardar el valor de la integral
	float evaluacionA=0;//evaluacion en el limite inferior
	float evaluacionB=0;//evaluacion en el limite superior
	float intervalo;
	intervalo=x0-x1;
	int i,j;
	for(i=0;i<*lim;i++){
		evaluacionA=evaluacionA+((pow(x0,i))*a[i]);	
		evaluacionB=evaluacionB+((pow(x1,i))*a[i]);		
	}
	valprom=((evaluacionA-evaluacionB)/(intervalo));
	error=(pow(intervalo,5)/(2288))*valprom;
	gotoxy(15,15);
	cout<<"error de truncamiento: "<<error;
}

double simps13m(float h,int n, double f[]){//Tamaño del intervalo, numero de segmentos, f(x)
	double sum, simps13m;
	int i;
	sum=f[0];
	for(i=1;i<n-2;i=i+2){
		sum=sum+(4*f[i])+(2*f[i+1]);
	}
	sum=sum+(4*f[n-1])+f[n];
	simps13m= (h/n)*(sum/3);
	gotoxy(15,10);
	cout<<"Con el metodo de simpson 1/3 multiple, la Integral aproximada es: "<<simps13m;
	rms=simps13m;
	return simps13m;
}
void simps13errormul(int n, double x0, double x1, float a[], int *lim){//limite inferior, Limite superior, vector derivada2, n
	double error;//error de truncamiento
	float valprom;
//	float b[*lim];//guardar el valor de la integral
	float evaluacionA=0;//evaluacion en el limite inferior
	float evaluacionB=0;//evaluacion en el limite superior
	float intervalo;
	intervalo=x0-x1;
	int i,j;
	for(i=0;i<*lim;i++){
		evaluacionA=evaluacionA+((pow(x0,i))*a[i]);	
		evaluacionB=evaluacionB+((pow(x1,i))*a[i]);		
	}
	valprom=((evaluacionA-evaluacionB)/(intervalo));
	error=(pow(intervalo,5)/(180*(pow(n,4))))*valprom;
	gotoxy(15,15);
	cout<<"error de truncamiento: "<<error;
}


double simps18(float h, double f0, double f1, double f2, double f3){
	double simps18;
	simps18=h*((f0+3*(f1+f2)+f3)/8);
	gotoxy(15,10);
	cout<<"Con el metodo de simpson 3/8 simple, la Integral aproximada es: "<<simps18;
	rms=simps18;
	return simps18;
}
void simps18error(double x0, double x1, float a[], int *lim){//limite inferior, Limite superior, vector derivada2, n
	double error;//error de truncamiento
	float valprom;
//	float b[*lim];//guardar el valor de la integral
	float evaluacionA=0;//evaluacion en el limite inferior
	float evaluacionB=0;//evaluacion en el limite superior
	float intervalo;
	intervalo=x0-x1;
	int i,j;
	for(i=0;i<*lim;i++){
		evaluacionA=evaluacionA+((pow(x0,i))*a[i]);	
		evaluacionB=evaluacionB+((pow(x1,i))*a[i]);		
	}
	valprom=((evaluacionA-evaluacionB)/(intervalo));
	error=(pow(intervalo,5)/(6480))*valprom;
	gotoxy(15,15);
	cout<<"error de truncamiento: "<<error;
}


void simps18m(float h, int n, double f[]){
	int m;
	double simps18m=0;
	m=n-3;
	double funaux[m+1];
	for(int i=0;i<=m;i++){
		funaux[m]=f[m];
	}
	simps18m=simps18m+simps13m(h,n,funaux);
	simps18m=simps18m+simps18(h,f[m],f[n-2],f[n-1],f[n]);
	cout<<"Con el metodo de simpson 3/8 multiple, la Integral aproximada es: "<<simps18m;
	rms=simps18m;
}

 int main(){  
 	int i, j;
 	int limite;//Tamaño de vector
 	int opc, opcinte;
	int n;//Numero de segmentos
	int band;//Valida que los segmentos sean los correctos para cada metodo 
	float limsuper, liminfer;//Limites inferior y superior de integración
	double tamintervalo, tampaso; //Tamaño del intervalo de integracion y tamaño de paso
	int grado;//guarda el grado del polinomio
	
	
	double funct[2][n+1];//Matriz donde se tabula la funcion 
	float fun[grado+1];//Vector que guarda la funcion 
	float b[grado+1];//Auxiliar del vector polinomio
	double fx[n+1];//Guarda los f(x)
				
				
	float sum, valor;
	
	string metodo;//Imprimir el metodo usado
	
	do{//Valida el menú principal 
		cout<<"\n\n\n\n\t\t\t\t\t\tINTEGRACION \n\n\n************************************************************************************************************************"<<endl;
		cout<<"1.- Integraci\242n de un polinomio"<<endl;
		cout<<"2.- Valor RMS de una funcion periodica"<<endl;
		cout<<"3.- Salir"<<endl;
		cin>>opc;
		system("cls");
		switch (opc)
			{
			case 1://CASO DEL POLINOMOMIO************************************************************************************************************
				{
					do{//Valida el valor del grado del polinomio
					cout<<"Dame el grado del polinomio(mayor a 0)"<<endl;
					cin>>grado;
					system("cls");
				}while(grado<1||grado>10);
				
				do{//Valida el numero de segmentos
					cout<<"Dame el numero de segmentos (mayor a 0)"<<endl;
					cin>>n;	
					system("cls");
				}while(n<0||n>10);
				
				double funct[2][n+1];//Matriz donde se tabula la funcion 
				
				float fun[grado+1];//Vector que guarda la funcion 
				float b[grado+1];//Auxiliar del vector polinomio
				
				double fx[n+1];//Guarda los f(x)
	
	
				do{//Valida que el limite superior sea mayor al inferior
					cout<<"(El limite inferior debe ser menor al superior)"<<endl;
					cout<<"Dame el valor del limite inferior"<<endl;
					cin>>liminfer;
					cout<<"Dame el valor del limite superior"<<endl;
					cin>>limsuper;
					system("cls");
				}while(limsuper<=liminfer);
				
				tamintervalo=limsuper-liminfer;//Tamaño del intervalo 
				tampaso=tamintervalo/n;//Tamaño de paso
				
				for(i=0;i<2;i++){ //Imprime la matriz de tabulacion 
					for(j=0;j<n+1;j++){
						funct[i][j]=0;
				}}
				
				gotoxy(2,7);cout<<"f(x)="<<endl;
				for(i=0;i<=grado;i++){//imprime las x para el polinomio 
					gotoxy(15+(i*10),7);
				    cout<<"X^"<<grado-i;
				}
				for(i=0;i<=grado;i++){// Lee los coeficientes de cada x
					gotoxy(11+(i*10),7);
					cin>>fun[grado-i];
				}
				
				/*for(j=0;j<=grado;j++){
						cout<<fun[j]<<"     ";//Imprime el vector de coeficientes del polinomio 
					}
				cout<<endl<<endl<<endl;
				
				for(i=0;i<2;i++){ //Imprime la matriz de tabulacion 
					for(j=0;j<n+1;j++){
						cout<<funct[i][j]<<"     ";
					}
					cout<<endl;
				}*/
				cout<<endl<<endl<<endl;
				
				for(i=0;i<=n;i++){//Asigna las x de la matriz de tabulacion
					funct[0][i]=(liminfer+(i*tampaso));
				}	
				

				for(i=0;i<=n;i++){//Evalua las f(x) y las guarda en la segunda fila 
					sum=0;	
					valor=funct[0][i];
					for(j=0;j<=grado;j++){
						sum=sum+((fun[j])*(pow(valor,j)));
					}
					funct[1][i]=sum;
				}

				
				limite=(sizeof(fun)/sizeof(fun[0]));//Establece el tamaño del vector del polinomio
				
				
				
				for(i=0;i<limite;i++){//Igualar el valor del polinomio en una variable aux
					b[i]=fun[i];
				}
				for(i=0;i<=n;i++){
					fx[i]=funct[1][i];
				}
				
				do{//Valida el menú de metodos
					if(band==1){//Da las opciones segun los segmentos ingresados
						if(n==1){
							cout<<"\n\n\tIngresaste un segmento, puedes usar los siguientes metodos:\n\n";
							cout<<"\t-> Trapecio simple"<<endl;
						}else if(n==2){
							cout<<"\n\n\tIngresaste 2 segmentos, puedes usar los siguientes metodos:\n\n";
							cout<<"\n\t-> Trapecio multiple"<<endl;
							cout<<"\t-> Simpson 1/3";
						}else if(n==3){
							cout<<"\n\n\tIngresaste 3 segmentos, puedes usar los siguientes metodos:\n\n";
							cout<<"\t-> Trapecio multiple"<<endl;
							cout<<"\t-> Simpson 3/8 multiple";
						}else if((n%2)==0 && n!=2){
							cout<<"\n\n\tIngresaste un numero par de segmentos, puedes usar los siguientes metodos:\n\n";
							cout<<"\t-> Trapecio multiple"<<endl;
							cout<<"\t-> Simpson 1/3 multiple";
						}else if((n%2)==1 && n>3){
							cout<<"\n\n\tIngresaste un numero par de segmentos, puedes usar los siguientes metodos:\n\n";
							cout<<"\t-> Trapecio multiple"<<endl;
							cout<<"\t-> Simpson 3/8";
						}
					}
					getch();
					system("cls");
					band=0;
					cout<<"Metodo de integtaci\242n:\n\n\n"<<endl;
					cout<<"\t1.-Trapecio simple"<<endl;
					cout<<"\t2.-Trapecio multiple"<<endl;
					cout<<"\t3.-Simpson 1/3 simple"<<endl;
					cout<<"\t4.-Simpson 1/3 multiple"<<endl;
					cout<<"\t5.-Simpson 3/8 simple"<<endl;
					cout<<"\t6.-Simpson 3/8 multiple"<<endl;
					cout<<"\t7.-Salir"<<endl;
					cin>>opcinte;
					system("cls");
						switch(opcinte){
							case 1://CASO TRAPECIO SIMPLE-----------------------------------
								if(n!=1){
									cout<<"\n\n\tPara el metodo de trapecio simple necesitas solamente un segmento....\n\n\n\n"<<endl;
									band=1;
								}else{
									derivada(1,b,&limite);
									gotoxy(15,5);
									cout<<"Para el polinomio: ";
									gotoxy(15,7);
									cout<<"f(x): ";
									for(j=grado;j>=0;j--){
										gotoxy((23+(j*10)),7);
										cout<<fun[j]<<"  x^"<<j;//Imprime el vector de coeficientes del polinomio 
									}
									trap(tamintervalo, funct[1][0],funct[1][1]);
									traperror(funct[0][0],funct[0][1], b, &limite);	
								}
								break;
							case 2://CASO TRAPECIO MULTIPLE-----------------------------------
								derivada(1,b,&limite);
								gotoxy(15,5);
								cout<<"Para el polinomio: ";
								gotoxy(15,7);
								cout<<"f(x): ";
								for(j=grado;j>=0;j--){
									gotoxy((23+(j*10)),7);
									cout<<fun[j]<<"  x^"<<j;//Imprime el vector de coeficientes del polinomio 
								}
								trapmult(tamintervalo, n, fx);
								traperrormul(n,funct[0][0],funct[0][1], b, &limite);
								break;
							case 3://CASO SIMPSON 1/3 SIMPLE-----------------------------------
								if(n!=2){
									cout<<"\n\n\tPara el metodo de Simpson 1/3 simple necesitas solamente dos segmento....\n\n\n\n"<<endl;
									band=1;
								}else{
									derivada(3,b,&limite);
									gotoxy(15,5);
									cout<<"Para el polinomio: ";
									gotoxy(15,7);
									cout<<"f(x): ";
									for(j=grado;j>=0;j--){
										gotoxy((23+(j*10)),7);
										cout<<fun[j]<<"  x^"<<j;//Imprime el vector de coeficientes del polinomio 
									}
									simps13(tamintervalo, funct[1][0], funct[1][1], funct[1][2]);
									simps13error(funct[0][0],funct[0][1], b, &limite);
								}
								break;
							case 4://CASO SIMPSON 1/3 MULTPLE-----------------------------------
								if((n%2)!=0 || n==2){
									cout<<"\n\n\tPara el metodo de Simpson 1/3 multiple necesitas segmentos multiplos de 2 ( >2 )....\n\n\n\n"<<endl;
									band=1;
								}else{
									derivada(3,b,&limite);
									gotoxy(15,5);
									cout<<"Para el polinomio: ";
									gotoxy(15,7);
									cout<<"f(x): ";
									for(j=grado;j>=0;j--){
										gotoxy((23+(j*10)),7);
										cout<<fun[j]<<"  x^"<<j;//Imprime el vector de coeficientes del polinomio 
									}
									simps13m(tamintervalo, n, fx);
									simps13errormul(n,funct[0][0],funct[0][1], b, &limite);
								}
								break;
							case 5://CASO SIMPSON 3/8 SIMPLE-----------------------------------
								if(n!=3){
									cout<<"\n\n\tPara el metodo de Simpson 3/8 necesitas solamente 3 segmentos....\n\n\n\n"<<endl;
									band=1;
								}else{
									derivada(3,b,&limite);
									gotoxy(15,5);
									cout<<"Para el polinomio: ";
									gotoxy(15,7);
									cout<<"f(x): ";
									for(j=grado;j>=0;j--){
										gotoxy((23+(j*10)),7);
										cout<<fun[j]<<"  x^"<<j;//Imprime el vector de coeficientes del polinomio 
									}
								simps18(tamintervalo, funct[1][0],funct[1][1],funct[1][2],funct[1][3]);
								simps18error(funct[0][0],funct[0][1], b, &limite);
								}
								break;
							case 6://CASO SIMPSON 3/8 MULTIPLE-----------------------------------
								if((n%2)==0 || n<=3){
									cout<<"\n\n\tPara el metodo de Simpson 3/8 necesitas un numero impar (< 3) de segmentos....\n\n\n\n"<<endl;
									band=1;
								}else{
									gotoxy(15,5);
									cout<<"Para el polinomio: ";
									gotoxy(15,7);
									cout<<"f(x): ";
									for(j=grado;j>=0;j--){
										gotoxy((23+(j*10)),7);
										cout<<fun[j]<<"  x^"<<j;//Imprime el vector de coeficientes del polinomio 
									}
									simps18m(tamintervalo, n, fx);
								}
								break;
							case 7:
								break;
						}
				}while(opcinte<1||opcinte>7||band==1);
				break;
					
				}
				
				
				
			case 2://CASO DE LA FUNCION sen ESTABLECIDA************************************************************************************************************
				{
					liminfer=0;
					limsuper=.5;
					do{//Valida el numero de segmentos
						cout<<"Dame el numero de segmentos (mayor a 0)"<<endl;
						cin>>n;	
						system("cls");
					}while(n<1||n>10);
					
					double funct1[2][n+1];//Matriz donde se tabula la funcion 
					double fx1[n+1];//Guarda los f(x)
					
					
					tamintervalo=.5;
					tampaso=tamintervalo/n;
					
					
					for(i=0;i<2;i++){ 
						for(j=0;j<n+1;j++){
							funct1[i][j]=0;
						}
					}
					
					for(i=0;i<=n;i++){
						funct1[0][i]=i*tampaso;
					}
					
					//x=12;//funct1[0][2];
					for(j=0;j<=n;j++){//Define los f(x)
						
						funct1[1][j]=((100*sin((2*funct1[0][j])*PI))/(pow(e,(2*funct1[0][j]))));
					}
					
					/*for(i=0;i<2;i++){ //Imprime la matriz de tabulacion 
						for(j=0;j<n+1;j++){
							cout<<funct1[i][j]<<"     ";
						}
						cout<<endl;
					}
					cout<<endl<<endl<<endl;*/
					
					for(i=0;i<=n;i++){
						fx1[i]=funct1[1][i];
					}

					do{//Valida el menú de metodos
						if(band==1){//Da las opciones segun los segmentos ingresados
							if(n==1){
								cout<<"\n\n\tIngresaste un segmento, puedes usar los siguientes metodos:\n\n";
								cout<<"-> Trapecio simple"<<endl;
							}else if(n==2){
								cout<<"\n\n\tIngresaste 2 segmentos, puedes usar los siguientes metodos:\n\n";
								cout<<"\t-> Trapecio multiple"<<endl;
								cout<<"-\t> Simpson 1/3";
							}else if(n==3){
								cout<<"\n\n\tIngresaste 3 segmentos, puedes usar los siguientes metodos:\n\n";
								cout<<"\t-> Trapecio multiple"<<endl;
								cout<<"\t-> Simpson 3/8 multiple";
							}else if(n%2==0 && n!=2){
								cout<<"\n\n\tIngresaste un numero par de segmentos, puedes usar los siguientes metodos:\n\n";
								cout<<"\t-> Trapecio multiple"<<endl;
								cout<<"\t-> Simpson 1/3 multiple";
							}else if(n%2==1 && n>3){
								cout<<"\n\n\tIngresaste un numero par de segmentos, puedes usar los siguientes metodos:\n\n";
								cout<<"\t-> Trapecio multiple"<<endl;
								cout<<"\t-> Simpson 3/8";
							}
						getch();
						}
						system("cls");
						band=0;
						cout<<"Metodo de integtaci\242n:\n\n\n"<<endl;
						cout<<"\t1.-Trapecio simple"<<endl;
						cout<<"\t2.-Trapecio multiple"<<endl;
						cout<<"\t3.-Simpson 1/3 simple"<<endl;
						cout<<"\t4.-Simpson 1/3 multiple"<<endl;
						cout<<"\t5.-Simpson 3/8 simple"<<endl;
						cout<<"\t6.-Simpson 3/8 multiple"<<endl;
						cout<<"\t7.-Salir"<<endl;
						cin>>opcinte;
						system("cls");
							switch(opcinte){
								case 1://CASO TRAPECIO SIMPLE-----------------------------------
									if(n!=1){
										cout<<"\n\n\tPara el metodo de trapecio simple necesitas solamente un segmento....\n\n\n\n"<<endl;
										band=1;
									}else{
										trap(tamintervalo, funct1[1][0],funct1[1][1]);
										system("cls");
										RMS=pow(rms,0.5);
										metodo="Trapecio simple";
									}
									break;
								case 2://CASO TRAPECIO MULTIPLE-----------------------------------
									trapmult(tamintervalo, n, fx1);
									system("cls");
									RMS=pow(rms,0.5);
									metodo="Trapecio multiple";
									break;
								case 3://CASO SIMPSON 1/3 SIMPLE-----------------------------------
									if(n!=2){
										cout<<"\n\n\tPara el metodo de Simpson 1/3 simple necesitas solamente 2 segmentos....\n\n\n\n"<<endl;
										band=1;
									}else{
										simps13(tamintervalo, funct1[1][0], funct1[1][1], funct1[1][2]);
										system("cls");
										RMS=pow(rms,0.5);
										metodo="Simpson 1/3 simple";
									}
									break;
								case 4://CASO SIMPSON 1/3 MULTPLE-----------------------------------
									if((n%2)==1 || n==2){
										cout<<"\n\n\tPara el metodo de Simpson 1/3 multiple necesitas segmentos multiplos de 2 ( >2 )....\n\n\n\n"<<endl;
										band=1;
									}else{
										simps13m(tamintervalo, n, fx1);
										system("cls");
										RMS=pow(rms,0.5);
										metodo="Simpson 1/3 multiple";
									}
									
									break;
								case 5://CASO SIMPSON 3/8 SIMPLE-----------------------------------
									if(n!=3){
										cout<<"\n\n\tPara el metodo de Simpson 3/8 necesitas solamente 3 segmentos....\n\n\n\n"<<endl;
										band=1;
									}else{
										simps18(tamintervalo, funct1[1][0],funct1[1][1],funct1[1][2],funct1[1][3]);
										system("cls");
										RMS=pow(rms,0.5);
										metodo="Simpson 3/8 simple";
									}	
									break;
								case 6://CASO SIMPSON 3/8 MULTIPLE-----------------------------------
									if((n%2)==0 || n<=3){
										cout<<"\n\n\tPara el metodo de Simpson 3/8 multiple necesitas un numero impar (< 3) de segmentos....\n\n\n\n"<<endl;
										band=1;
									}else{
										simps18m(tamintervalo, n, fx1);
										system("cls");
										RMS=pow(rms,0.5);
										metodo="Simpson 3/8 multiple";
									}
									break;
								case 7:
									band=2;
									break;
						}
					}while(opcinte<1||opcinte>7||band==1);
					if(band==0){
						gotoxy(15,5);
						cout<<"Para la funci\242n  \237(t)= 10e^(-t/T)sin(2 t/T)";
						gotoxy(15,7);
						cout<<"con: ";
						gotoxy(15,8);
						cout<<"->  "<<n<<" segmentos";
						gotoxy(15,9);
						cout<<"->  Un periodo de 1 segundo";
						gotoxy(15,10);
						cout<<"->  Evaluando de 0seg - 0.5seg";
						gotoxy(20,14);
						cout<<"Usando el metodo de  "<<metodo;
						gotoxy(18,16);
						cout<<"El valor RMS es: 	"<<RMS<<endl<<endl<<endl<<endl<<endl;
					}
				}
				break;
			//FIN CASO DE LA SINOIDAL
			case 3:
				break;
			}
	}while(opc<1||opc>3);
	return 0;	
 } 
