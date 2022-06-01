#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<windows.h>


using namespace std;

//DECLARAR FUNCIONES

int menu();
void agregar(ofstream &); //crear archivo
void leer_registro(ifstream &); //leer archivo
void buscar(ifstream &); //buscar
void modificar(ifstream &); //modificar
void eliminar(ifstream &); //eliminar
void EliminadoLogico(ifstream &); //EliminadoLogico

int main(){
	ofstream archivo;
	ifstream arch_lec;
	int op;
	do{
		system("cls");
		op=menu();

		switch(op){

			case 1: agregar(archivo);
				break;
			case 2: leer_registro(arch_lec);
				break;
			case 3:  buscar(arch_lec);
				break;
			case 4:
				modificar(arch_lec);
				break;
			case 5:
				eliminar(arch_lec);
				break;
			case 6:
                EliminadoLogico(arch_lec);
			break;
			case 7:
			exit(-1);

			default:
				cout << "Opcion invalida";

		}
	}while(op!=6);



}

//Definir funciones

int menu(){
	int x;

	system("cls");

	cout << "---------------------------------------------"<<endl;
	cout << "                     Menu                    "<<endl;
    cout << "---------------------------------------------"<<endl;
	cout << "1) Agregar personas " << endl;
	cout << "2) Ver personas " << endl;
	cout << "3) Buscar " << endl;
	cout << "4) Modificar " << endl;
	cout << "5) Eliminar " << endl;
    cout << "6) EliminaLogico " << endl;
	cout << "7) Salir " << endl;
	cout << "opcion: ";
	cin >> x;

	return x;
}

void agregar(ofstream &arch){

	system("cls");

	string nom,ape,ced;
	arch.open("registro.txt", ios::out | ios::app);

	if(arch.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}


	cout<< "Dame el nombre: " ;
	cin >> nom;
	cout << "Dame el apellido: ";
	cin >> ape;
	cout << "Dame tu cedula: ";
	cin >> ced;

	arch<<nom<<" "<<ape<<" "<<ced<<" \n";

	arch.close();
}


void leer_registro(ifstream &arch_lec){
	system("cls");
	string nom,ape,ced;

	arch_lec.open("registro.txt", ios::in);

	if(arch_lec.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

	arch_lec>>nom;  //posicionarse desde donde va a comenzar a leer los datos
	while(!arch_lec.eof()){
		arch_lec>>ape;
		arch_lec>>ced;
		cout << "Nombre: " << nom <<endl;
		cout << "Apellido: " << ape <<endl;
		cout << "Cedula: " << ced <<endl;
		cout << "-----------------" <<endl;
		arch_lec>>nom;
	}
	arch_lec.close();
	system("pause");
}

void buscar(ifstream &arch_lec){

	system("cls");
	string nom,ape,ced,cedaux;

	bool encontrado = false; //bandera

	arch_lec.open("registro.txt",ios::in);

	if(arch_lec.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

	cout << "Dame la cedula buscar: ";
	fflush(stdin);
	cin >> cedaux;
	arch_lec>>nom;
		while(!arch_lec.eof() && !encontrado){
		arch_lec>>ape;
		arch_lec>>ced;

		if(ced==cedaux){
			cout << "Nombre: " << nom <<endl;
			cout << "Apellido: " << ape <<endl;
			cout << "Cedula: " << ced <<endl;
			cout << "-----------------" <<endl;
			encontrado = true;

		}
		arch_lec>>nom;
		}arch_lec.close();

		if(!encontrado){
			cout << "Dato NO encontrado" << endl;
		}
		else{
			cout << "Dato encontrado" << endl;
		}

		system ("pause");

	}

void modificar(ifstream &arch){
	system("cls");

	string nom,ape,ced,cedaux, nomaux;

	arch.open("registro.txt",ios::in);

	if(arch.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

	ofstream aux("auxiliar.txt",ios::out);
	if(aux.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

		cout << "Dame la cedula a buscar/modificar: ";
		cin >> cedaux;

		arch >> nom;
		while(!arch.eof()){
			arch >> ape;
			arch >> ced;

			if( ced == cedaux){
				cout << "Ingresa el nuevo nombre: ";
				cin >> nomaux;


				aux << nomaux <<  "" << ape<< "" << ced << " \n";
			}
			else {
					aux << nom <<  "" << ape<< "" << ced << " \n";
			}


			arch >> nom;
		}
		arch.close();
		aux.close();

		remove( "registro.txt");
		rename ("auxiliar.txt", "registro.txt");



	}

void eliminar(ifstream &arch){
	system("cls");

	string nom,ape,ced,cedaux, nomaux;

	arch.open("registro.txt",ios::in);

	if(arch.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

	ofstream aux("auxiliar.txt",ios::out);
	if(aux.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

		cout << "Dame la cedula a buscar/eliminar: ";
		cin >> cedaux;

		arch >> nom;
		while(!arch.eof()){
			arch >> ape;
			arch >> ced;

			if( ced == cedaux){
				cout << "Registro eliminado exitosamente \n";

			}
			else {
					aux << nom <<  " " << ape<< " " << ced << " \n";

			}


			arch >> nom;
		}
		arch.close();
		aux.close();

		remove( "registro.txt");
		rename ("auxiliar.txt", "registro.txt");
		system("pause");
}

void EliminadoLogico(ifstream &arch)
{
 	system("cls");

	string nom,ape,ced,cedaux, nomaux;

	arch.open("registro.txt",ios::in);

	if(arch.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

	ofstream aux("auxiliar.txt",ios::out);
	if(aux.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);	}

		cout << "Dame la cedula a buscar/modificar: ";
		cin >> cedaux;

		arch >> nom;
		while(!arch.eof()){
			arch >> ape;
			arch >> ced;

			if( ced == cedaux){
				cout << "Ingresa el nuevo nombre: ";
				cin >> nomaux;


				aux << nomaux <<  " -" << ape<< " -" << ced <<endl;
                cout<<"Elimnado logico exitoso......";
                system("pause");

			}

			arch >> nom;
		}
		arch.close();
		aux.close();

		remove( "registro.txt");
		rename ("auxiliar.txt", "registro.txt");

}
