#include <stdio.h>
struct trabajador {
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
int main()
{
	 struct trabajador plantilla[100];
	int opcion,codigo,unidades, trabajadores=0,i;
	int decision;
	FILE *fichero;
	struct producto A={1515,100}, B={9191,250}, C={3131,1250};
do
{
		printf("  MENU:\n \t1-contratar personal\n \t2-despedir personal\n \t3-vender productos\n \t4-comprar reactivos\n \t5-estado almacen\n\t6-Mostrar lista de trabajadores\n\t7-salir del programa\n seleccione la operacion deseada.\n");
		scanf("%d",&opcion);
		fflush(stdin);
		switch (opcion)
		{
			case 1:
				// sentencias para contratar personal
				// nombre, apellidos, dni, telefono
				fichero = fopen("plantilla.txt", "r");
					while (fscanf(fichero,  "%s %s %d %d", plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni) != EOF){
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
			for (i=0; i<trabajadores; i++) 
			{
				fprintf(fichero, "%s\t", plantilla[i].nombre);
				fprintf(fichero, "%s\t",plantilla[i].apellido);		
				fprintf(fichero, "%d\t",plantilla[i].phone);
				fprintf(fichero, "%d\n",plantilla[i].dni);		
			}
			fclose(fichero);
			trabajadores=0;
				
			break;

			case 2:
				// sentencias para despedir personal
					fichero = fopen("plantilla.txt", "r");
					while (fscanf(fichero,  "%s %s %d %d", plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni) != EOF){
					trabajadores++;
					}
			fclose(fichero);
			if (trabajadores == 0){
				printf("no tienes trabajadores, contratalos\n");
	
			}
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
					while (fscanf(fichero,  "%s %s %d %d", plantilla[trabajadores].nombre,plantilla[trabajadores].apellido, &plantilla[trabajadores].phone, &plantilla[trabajadores].dni) != EOF){
					trabajadores++;
					}
			fclose(fichero);
				printf("-----------------------------------------------------------\n");	
				printf("%-10s\t %-10s\t %-10s\t %-10s\n","nombre", "apellido", "telefono", "DNI");
				printf("-----------------------------------------------------------\n");
				for (i=0; i<trabajadores; i++) {
				printf("%-10s\t", plantilla[i].nombre);
				printf("%-10s\t",plantilla[i].apellido);		
				printf("%d\t",plantilla[i].phone);
				printf("%d\n",plantilla[i].dni);	
			}
				printf("-----------------------------------------------------------\n");
			trabajadores=0;
			}
	}while (opcion != 7);

	return 0;

}
