#include <stdio.h>
 typedef struct  
 {
 	int codigo;
 	int unidades;
} producto;
int main()
{
	int opcion,codigo,unidades;
	producto A={1515,100}, B={9191,250}, C={3131,1250};
do
{
		printf("  MENU:\n \t1-contratar personal\n \t2-despedir personal\n \t3-vender productos\n \t4-comprar reactivos\n \t5-estado almacen\n ¿que operacion desea realizar?\n");
		scanf("%d",&opcion);
		switch (opcion)
		{
			case 1:
				// sentencias para contratar personal
				// nombre, apellidos, dni, telefono
			break;
			
			case 2:
				// sentencias para despedir personal
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
