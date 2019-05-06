#include <stdio.h>
#include <string.h>
struct trabajador {
	char departamento[50];
	char nombre[50];
	char apellido[50];
	int phone;
	int dni;
	
};
 struct producto  
 {
 	int codigo;
 	int unidades;
} ;

void imprimirBanner();
int menu();


int main()
{
	struct trabajador plantilla[100];
	int opcion,codigo,unidades, trabajadores=0,i,j;
	int decision;
	int verifica;
	char comprobador_nombre[50];
	FILE*fichero;
	FILE*productos;
	struct producto A={1515,100}, B={9191,250}, C={3131,1250};
do
{
	imprimirBanner();
	//Se llama a la funcion menu
	opcion=	menu();
		switch (opcion)
		{
			case 1:
				// sentencias para contratar personal
				// nombre, apellidos, dni, telefono
				fichero = fopen("plantilla.txt", "r");
					while (fscanf(fichero, "%s %s %s %d %d", plantilla[trabajadores].departamento, plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni) != EOF){
					trabajadores++;
					}
			fclose(fichero);
			printf("Departamento: \n");
			scanf("%s", plantilla[trabajadores].departamento);
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
			for (i=0; i<trabajadores; i++) 
			{	
				fprintf(fichero, "%d\t",i+1);
				fprintf(fichero, "%s\t",plantilla[i].departamento);
				fprintf(fichero, "%s\t",plantilla[i].nombre);
				fprintf(fichero, "%s\t",plantilla[i].apellido);		
				fprintf(fichero, "%d\t",plantilla[i].phone);
				fprintf(fichero, "%d\n",plantilla[i].dni);		
			}
			fclose(fichero);
			trabajadores=0;
			return 1;
			break;

			case 2:
				// sentencias para despedir personal
					fichero = fopen("plantilla.txt", "r");
					while (fscanf(fichero,  "%s %s %s %d %d", plantilla[trabajadores].departamento ,plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni) != EOF){
					trabajadores++;
					}
				if (trabajadores == 0){
				printf("no tienes trabajadores, contratalos\n");
				}
				break;
	
				for(j=0;j<trabajadores;j++){
				strcpy(comprobador_nombre,plantilla[j].nombre);
				_strupr(comprobador_nombre);
					if(strcmp(comprobador_nombre,plantilla[j].nombre)==0){
					printf("%s\t %s\t %s\t %d\t %d\n", plantilla[j].departamento, plantilla[j].nombre,plantilla[j].apellido, &plantilla[j].phone, &plantilla[j].dni);
					verifica=1;
					}
				}
					if (verifica==0)
					{
					printf("El contacto \n");
					}
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
				printf("-------------------------------------------------------------------------------\n");
				printf("%-10s\t %-5s\t %-10s\n","Compuesto", "codigo", "unidades");
				printf("-------------------------------------\n");
				printf("acido sulfurico\t %d\t %d \n",A.codigo,A.unidades);
				printf("acido nitrico\t %d\t %d \n",B.codigo,B.unidades);
				printf("etanol\t\t %d\t %d \n",C.codigo,C.unidades);
				printf("-------------------------------------------------------------------------------\n");
			break;
			case 6:
				fichero = fopen("plantilla.txt", "r");
					while (fscanf(fichero, "%s %s %s %d %d", plantilla[trabajadores].departamento, plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni) != EOF){
					trabajadores++;
					}
			fclose(fichero);
				printf("-------------------------------------------------------------------------------\n");	
				printf("%-3s\t %-10s\t %-10s\t %-10s\t %-10s\t %-10s\n", "Num", "Deparamento", "Nombre", "Apellido", "Telefono", "DNI");
				printf("-------------------------------------------------------------------------------\n");
				for (i=0; i<trabajadores; i++) {
				printf("%d\t",i+1);
				printf("%-10s\t",plantilla[i].departamento);
				printf("%-10s\t",plantilla[i].nombre);
				printf("%-10s\t",plantilla[i].apellido);		
				printf("%d\t",plantilla[i].phone);
				printf("%d\n",plantilla[i].dni);	
			}
				printf("-------------------------------------------------------------------------------\n");
			trabajadores=0;
			}
	}while (opcion != 7);

	return 0;

}


void imprimirBanner(){
	printf("------------------------------------------------------------------------------------------------\n");
	printf("----------------------------------BIENVENIDOS A LA EMPRESA QUIMICA------------------------------\n");
	printf("------------------------------------------------------------------------------------------------\n");

}

int menu(){
	int opcion;
	printf("1-Contratar personal\n");
	printf("2-Despedir personal\n"); 
	printf("3-Vender productos\n"); 
	printf("4-Comprar reactivos\n");
	printf("5-Estado almacen\n");
	printf("6-Mostrar lista de trabajadores\n");
	printf("7-Salir del programa\n");
	printf("Seleccione la operacion deseada\n");
	fflush(stdin);
	scanf("%d",&opcion);
	
	return opcion;
}
