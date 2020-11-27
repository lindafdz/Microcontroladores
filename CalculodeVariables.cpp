//		INSTITUTO POLITECNICO NACIONAL
//		UPIITA
//		uP, uC e I
//		25 DE SEPTIEMBRE 2020
//		FERNÁNDEZ OLVERA LINDA MARÍA
//		CALCULO DE VALORES EN SUBRUTINAS DE TIEMPO
//		PROF. DAVID ARTURO GUTIERREZ BEGOVICH
//		LENGUAJE: C++ ESTE PROGRAMA CALCULA LAS VARIABLES DE SUBRUTINAS  DE TIEMPO PARA  1, 2 Y 3 VARIABLES


#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribir1(int D1);
void escribir2(int D1, int D2);
void escribir3(int D1, int D2, int D3);

int main (){
	int T, f;
	int Form, NOP=3, Vf1, Vf2, Vf3, Da;
	int V1[256], V2[256], V3[256];
	int numero;

	cout<<"\nFRECUENCIA DEL PIC [MHz]: ";
	cin>>f;
	cout<<"\nPERIODO [us]: ";
	cin>>T;
	cout<<"\nNUMERO DE NOPS: 3 ";


	Da=0;
	system("cls");

	for (int i=0; i<=255; i++){
			V1[i+1]=i;
			V2[i+1]=i;
			V3[i+1]=i;
	}

		system("cls");

// CALCULO 1 VARIABLE
	cout<<"\nUNA VARIABLE";
		for(int i=1; i<=256; i++){
			Form=5+(V1[i]*(NOP+3));
			if (Form<T){
				if (Form >=Da){
					Da = Form;
					Vf1 = V1[i];
				}
			}
		}
		cout<<"\n\VALOR 1: " << Vf1;
		cout<<"\nCICLOS DE MAQUINA ALCANZADOS: "<<Da;
		cout<<"\nCICLOS FALTANTES: " << T-Da;
		escribir1(Vf1);

// CALCULO 2 VARIABLES
	cout<<"\nDOS VARIABLES";
		for(int i=1; i<=256; i++){
			for(int j=1; j<=256; j++){
				Form=7+((NOP+3)*V1[i]*V2[j])+(4*V2[j]);
				if (Form<T){
					if(Form>=Da){
						Da = Form;
						Vf1 = V1[i];
						Vf2 = V2[j];
					}
				}
			}
		}
		cout<<"\nVALOR 1: " << Vf1;
		cout<<"\nVALOR 2: " << Vf2;
		cout<<"\nCICLOS DE MAQUINA ALCANZADOS: "<<Da;
		cout<<"\nCICLOS FALTANTES: " << T-Da;
		escribir2(Vf1, Vf2);

// CALCULO 3 VARIABLES
	cout<<"\nTRES VARIABLES";
		for(int i=1; i<=256; i++){
			for(int j=1; j<=256; j++){
				for(int k=1; k<=256; k++){
					Form=9+(4*V1[i]*(1+V3[k]))+(V1[i]*V2[j]*V3[k]*(3+NOP));
					if (Form<T){
						if(Form>=Da){
							Da = Form;
							Vf1 = V1[i];
							Vf2 = V2[j];
							Vf3 = V3[k];
						}
					}
				}
			}
		}
		cout<<"\nVALOR 1: " << Vf1;
		cout<<"\nVALOR 2: " << Vf2;
		cout<<"\nVALOR 3: " << Vf3;
		cout<<"\nCICLOS DE MAQUINA ALCANZADOS: "<<Da;
		cout<<"\nCICLOS FALTANTES: " << T-Da;
		escribir3(Vf1, Vf2, Vf3);

	return 0;
}
//GENERAR ARCHIVO 1 VARIABLE
void escribir1(int D1){
		ofstream CalculoVariables;
		CalculoVariables.open("C:\Users\Lieblich\Documents\UPIITA\SEMESTRE 21-1\MICROCONTROLADORES\CALCULO DE VARIABLES\Calculo1Var.asm",ios::out);

		if(CalculoVariables.fail()){
			cout<<"\nNO SE CREO EL ARCHIVO";
			exit(1);
		}

		CalculoVariables<<"			INCLUDE			 <C:\Users\Lieblich\Documents\UPIITA\SEMESTRE 21-1\MICROCONTROLADORES\MPLAB\ENCABEZADO.asm> ; B1, PUERTO A,B,D,E SALIDAS DIGITALES"<<endl;
		CalculoVariables<<"\n			CLRF	    		STATUS"<<endl;
		CalculoVariables<<"			ADDLW	    		0XEE"<<endl;
		CalculoVariables<<"			ADDLW			0XEE"<<endl;
		CalculoVariables<<"			ADDLW			0XEE"<<endl;
		CalculoVariables<<"\n			MOVLW			."<<D1<<endl;
		CalculoVariables<<"			MOVWF	    		0X60"<<endl;
		CalculoVariables<<"			CALL			ST1V"<<endl;
		CalculoVariables.close();
		cout<<"\nARCHIVO GENERADO\n";
}
// GENERAR ARCHIVO 2 VARIABLES
void escribir2(int D1, int D2){
		ofstream CalculoVariables;
		CalculoVariables.open("C:\Users\Lieblich\Documents\UPIITA\SEMESTRE 21-1\MICROCONTROLADORES\CALCULO DE VARIABLES\Calculo2Var.asm",ios::out);

		if(CalculoVariables.fail()){
			cout<<"\nNO SE CREO EL ARCHIVO";
			exit(1);
		}

		CalculoVariables<<"			INCLUDE			 <C:\Users\Lieblich\Documents\UPIITA\SEMESTRE 21-1\MICROCONTROLADORES\MPLAB\ENCABEZADO.asm>;B1, PUERTO A,B,D,E SALIDAS DIGITALES"<<endl;
		CalculoVariables<<"\n			CLRF	    		STATUS"<<endl;
		CalculoVariables<<"			ADDLW	    		0XEE"<<endl;
		CalculoVariables<<"			ADDLW			0XEE"<<endl;
		CalculoVariables<<"			ADDLW			0XEE"<<endl;
		CalculoVariables<<"\n			MOVLW			."<<D1<<endl;
		CalculoVariables<<"			MOVWF	    		0X62"<<endl;
		CalculoVariables<<"\n			MOVLW			."<<D2<<endl;
		CalculoVariables<<"			MOVWF	    		0X61"<<endl;
		CalculoVariables<<"			CALL			ST3V"<<endl;
		CalculoVariables.close();
		cout<<"\nARCHIVO GENERADO\n";
}
// GENERAR ARCHIVO 3 VARIABLES
void escribir3(int D1, int D2, int D3){
		ofstream CalculoVariables;
		CalculoVariables.open("C:\Users\Lieblich\Documents\UPIITA\SEMESTRE 21-1\MICROCONTROLADORES\CALCULO DE VARIABLES\Calculo3Var.asm",ios::out);

		if(CalculoVariables.fail()){
			cout<<"\nNO SE CREO EL ARCHIVO";
			exit(1);
		}

		CalculoVariables<<"			INCLUDE			 <C:\Users\Lieblich\Documents\UPIITA\SEMESTRE 21-1\MICROCONTROLADORES\MPLAB\ENCABEZADO.asm>;B1, PUERTO A,B,D,E SALIDAS DIGITALES"<<endl;
		CalculoVariables<<"\n			CLRF	    		STATUS"<<endl;
		CalculoVariables<<"			ADDLW	    		0XEE"<<endl;
		CalculoVariables<<"			ADDLW			0XEE"<<endl;
		CalculoVariables<<"			ADDLW			0XEE"<<endl;
		CalculoVariables<<"\n			MOVLW			."<<D1<<endl;
		CalculoVariables<<"			MOVWF	    		0X64"<<endl;
		CalculoVariables<<"\n			MOVLW			."<<D2<<endl;
		CalculoVariables<<"			MOVWF	    		0X65"<<endl;
		CalculoVariables<<"\n			MOVLW			."<<D3<<endl;
		CalculoVariables<<"			MOVWF	    		0X66"<<endl;
		CalculoVariables<<"			CALL			ST3V"<<endl;
		CalculoVariables.close();
		cout<<"\nARCHIVO GENERADO\n";
}
