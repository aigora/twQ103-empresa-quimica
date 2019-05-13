#include <stdio.h>
#include <string.h>
// introducimos las dos estructuras de vectores
//estructura de la ficha de los trabajadores
struct trabajador {
	char nombre[50];
	char apellido[50];
	int phone;
	int dni;
	int fuera; // 0=Despedido, 1=contratado
};
//estructura del almacenamiento de los productos
 struct producto  
 {
 	int codigo;
 	int unidades;
} ;
//FUNCIONES
//funcion que inicializa el menu
int menu();

int main()
{
	//iniciamos el vector de estructura llamado plantilla
	 struct trabajador plantilla[100];
	int codigo,unidades, trabajadores=0,i,aux;
	int decision;
	int opcion1,j;
	char despedido[40];
	FILE *fichero;
	FILE *despedidos;
	struct producto A={1515,100}, B={9191,250}, C={3131,1250};
		do
	{	

	opcion1=menu();
		
		switch (opcion1)
		{
			case 1:
				//abrimos y leemos el fichero plantilla y cuenta el numero de trabajadores
				fichero = fopen("plantilla.txt", "r");
					if(fichero == NULL){
						printf("Error al abrir el fichero\n");
						return -1;
					}
					while (fscanf(fichero,  "%s %s %d %d %d", plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni, &plantilla[trabajadores].fuera) != EOF){
						trabajadores++;
						}
				fclose(fichero);
				printf("Nombre: \n");
				scanf("%s", plantilla[trabajadores].nombre);
				printf("Apellido: \n");
				scanf("%s", plantilla[trabajadores].apellido);
				printf("Telefono: \n");
				scanf("%d", &plantilla[trabajadores].phone);
				printf("DNI (sin letra): \n");
				scanf("%d", &plantilla[trabajadores].dni);
				trabajadores++;
				
					//grabar los datos en el fichero
					fichero = fopen("plantilla.txt", "w");
					if(fichero == NULL){
						printf("Error al abrir el fichero\n");
						return -1;
					}
						for (i=0; i<trabajadores; i++) 
						{
							fprintf(fichero, "%s\t", plantilla[i].nombre);
							fprintf(fichero, "%s\t",plantilla[i].apellido);		
							fprintf(fichero, "%d\t",plantilla[i].phone);
							fprintf(fichero, "%d\n",plantilla[i].dni);	
							fprintf(fichero, "%d\n", plantilla[i].fuera=1);	
						}
					fclose(fichero);
					trabajadores=0;
				
					break;

			case 2:
				// sentencias para despedir personal
		
					fichero = fopen("plantilla.txt", "r");
					if(fichero == NULL){
						printf("Error al abrir el fichero\n");
						return -1;
					}
					while (fscanf(fichero,  "%s %s %d %d %d" , plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni ,&plantilla[trabajadores].fuera) != EOF){
					trabajadores++;
					}
					fclose(fichero);
						if (trabajadores == 0){
							printf("no tienes trabajadores, contratalos\n");
						}
					printf("Introduce el nombre del empleado que desee despedir: \n");
					scanf("%s", despedido);
					i=0;
					for(i=0;i<trabajadores;i++){
							if(strcmp(despedido, plantilla[i].nombre)==0){
									printf("Vas a despedir a %s\n", plantilla[i].nombre);
									despedidos=1;
									plantilla[i].fuera=0;
							}
							if(despedidos!=1)
								printf("No hay ningun empleado con ese nombre\n");
						}
						fichero=fopen("plantilla.txt", "w");
						if(fichero == NULL){
						printf("Error al abrir el fichero\n");
						return -1;
						i=0;
						}
							for (i=0; i<trabajadores; i++) 
						{
							fprintf(fichero, "%s\t", plantilla[i].nombre);
							fprintf(fichero, "%s\t",plantilla[i].apellido);		
							fprintf(fichero, "%d\t",plantilla[i].phone);
							fprintf(fichero, "%d\t",plantilla[i].dni);	
							fprintf(fichero, "%d\n", plantilla[i].fuera);	
						}
						trabajadores=0;
						fclose(fichero);
					break;
			case 3:
				// sentencias para vender productos
				printf("introduzca el codigo y cuantas unidades quiere:\n");
				scanf("%d %d", &codigo, &unidades);
					if(codigo==A.codigo)
						{
							if(unidades<=A.unidades)
								A.unidades-=unidades;
							else
								printf("No hay unidades suficientes\n");
						}

					else if(codigo==B.codigo)
						{
							if(unidades<=B.unidades)
								B.unidades-=unidades;
							else 
								printf("No hay unidades suficientes\n");
						}
					else if(codigo==C.codigo)
					{
						if(unidades<=C.unidades)
							C.unidades-=unidades;
						else 
							printf("No hay unidades suficientes\n");
					}
						else
							printf("el codigo no es correcto\n");
			break;
			case 4:
				// sentencias para comprar productos
				printf("introduzca el codigo del producto y cuantas unidades quiere comprar:\n");
				scanf("%d %d", &codigo, &unidades);
					if(codigo==A.codigo)
					{
						A.unidades+=unidades;
					}
					else if(codigo==B.codigo)
					{
						B.unidades+=unidades;
					}
					else if(codigo==C.codigo)
					{
					if(unidades<=C.unidades)
						C.unidades+=unidades;
					}
					else
						printf("el codigo no es correcto\n");
			break;
			case 5:
				printf("-------------------------------------\n");	
				printf("%-10s\t %-5s\t %-10s\n","Compuesto", "codigo", "unidades");
				printf("-------------------------------------\n");
				printf("acido sulfurico\t %d\t %d \n",A.codigo,A.unidades);
				printf("acido nitrico\t %d\t %d \n",B.codigo,B.unidades);
				printf("etanol\t\t %d\t %d \n",C.codigo,C.unidades);
				printf("-------------------------------------\n");
			break;
			case 6:
				fichero = fopen("plantilla.txt", "r");
					if(fichero == NULL){
						printf("Error al abrir el fichero\n");
						return -1;
					}
					while (fscanf(fichero,  "%s %s %d %d %d", plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni, &plantilla[trabajadores].fuera) != EOF){
					trabajadores++;
					}
			fclose(fichero);
				printf("------------------------------------------------------------------------------------\n");	
				printf("%-10s\t %-10s\t %-10s\t %-10s\t %-10s\n","nombre", "apellido", "telefono", "DNI","despedido(0=si,1=no)");
				printf("----------------------------------------------------------------------\n");
				for (i=0; i<trabajadores; i++) {
				printf("%-10s\t", plantilla[i].nombre);
				printf("%-10s\t",plantilla[i].apellido);		
				printf("%d\t",plantilla[i].phone);
				printf("%d\t",plantilla[i].dni);
				printf("%d\n", plantilla[i].fuera);	
			}
				printf("-----------------------------------------------------------------------------------\n");
			trabajadores=0;
		
	}
	}while(opcion1 != 7);

	return 0;
}

int menu(){
		int opcion;
		printf("...............MENU DE OPCIONES.................\n");
		printf("\t1-contratar personal\n \t2-despedir personal\n \t3-vender productos\n \t4-comprar reactivos\n \t5-estado almacen\n\t6-Mostrar lista de trabajadores\n\t7-salir del programa\n");
		printf("Introduce una de estas opciones\n");
		scanf("%d", &opcion);	
		return opcion;
}

