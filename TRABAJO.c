#include <stdio.h>
#include <string.h>
 typedef struct  
 {
 	int codigo;
 	int unidades;
} producto;
struct contratar{
	char departamento[100];
	char nombre[50];
	char apellidos[100];
	int DNI;//El Dni contiene solo los ocho numeros
	int telefono;//El numero de telefono está formado por un numero de 9 cifras
};
struct despedir{//La empresa tiene 20 trabajadores
	char departamento[100];
	char nombre[50];
	char apellidos[100];
	int DNI;
	int telefono;
};

int main()
{
	int opcion,op,codigo,unidades;
	producto A={1515,100}, B={9191,250}, C={3131,1250};
	struct contratar trabajador[100];
	FILE *puntero;
	struct despedir personal[100];
	int n; //Numero de nuevos trabajadores que la empresa quiere contratar
	int digitos;
	int i;
do
{
		printf(" MENU:\n \t1-contratar personal\n \t2-despedir personal\n \t3-vender productos\n \t4-comprar reactivos\n \t5-estado almacen\n ¿que operacion desea realizar?\n");
		scanf("%d",&opcion);
		switch (opcion)
		{
			case 1:
				// sentencias para contratar personal
				// nombre, apellidos, dni, telefono
				printf("Introduzca el numero de trabajadores que quiere contratar:");
				scanf("%d", &n);
				for (i=0; i<n; i++) {
					printf("Nombre: %d\n", i+1);
					scanf("%s",trabajador[i].nombre);
					printf("Apellidos: %d\n", i+1);
					scanf("%s",trabajador[i].apellidos);
					printf("DNI formado por 8 digitos numericos:\n");	
					scanf("%d", &trabajador[i].DNI);
					printf("Telefono formado por 9 digitos:\n");
					scanf("%d", &trabajador[i].telefono);
					fflush(stdin);
				}
				
			break;
			
			case 2:
				// sentencias para despedir personal y acceder a sus datos
				puntero=fopen("datos.txt", "w");
	
				if(puntero==NULL){	
					printf("No es posible  abrir el fichero\n");
					return -1;
				}
				i=1;
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Investigacion","Juan","Jimenez", 12345999,676767123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Investigacion","Laura","Garcia", 30065089,676766123 );
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Investigacion","Esteban","Lopez", 12345999,676765123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Investigacion","Patricia","Gomez",12345998,676747123 );
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Marketing","Pablo","Martinez", 12345122,676763123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Marketing","Paula","Perez",12345989,676762123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Marketing","Sergio","Sanchez",12345799,676761123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Marketing","Rafael","Rodriguez",12345978,676797123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Compra Venta","Alberto","Cañal",12345456,676787123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Compra Venta","Sandra","Varga",12345678,67677123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Compra Venta","Pilar","Montero",12345123,676757123);
				fprintf(puntero,"%s\t%s\t%s\t%d\t%d\n","Departamento de Compra Venta","Luis","Pacheco",12345321,676747123);
	
				fclose(puntero);
				printf("MENU:\n \t1-lista de trabajadores \n \t2-despedir\n ¿que operacion desea realizar?\n");
				switch (op)
				{
					case 1:
						puntero=fopen("datos.txt", "r");
	
						if(puntero==NULL){
						printf("No es posible  abrir el fichero\n");
						return -1;// Se termina el programa
						}
						i=0;
						while(fscanf(puntero,"%s %s %s %d %d", &personal[i].departamento,personal[i].nombre,&personal[i].apellidos, &personal[i].DNI,&personal[i].telefono)!=EOF){
						printf("Leyendo: %s %s %s %d %d\n",personal[i].departamento,personal[i].nombre, personal[i].apellidos,personal[i].DNI,personal[i].telefono);
						i++; 
							}
						fclose(puntero);
						break;
						
						//case 2:
							
						//	break;
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
				printf("compuesto\t codigo\t unidades:\n");
				printf("acido sulfurico\t %d\t %d \n",A.codigo,A.unidades);
				printf("acido nitrico\t %d\t %d \n",B.codigo,B.unidades);
				printf("etanol\t\t %d\t %d \n",C.codigo,C.unidades);
			break;
			}
	}while (opcion != 6);

	return 0;
	
}
