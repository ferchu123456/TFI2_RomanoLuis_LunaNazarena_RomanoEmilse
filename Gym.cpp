#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct fecha{
	int dia,mes,anio;
};
struct Usuario{
	char usuario[10];
	char contrasena[10];
	char apell_nom[60];
};
struct ct{
	char usuario[10];
	char contrasena[32];
};
struct entrenadorr{
	char apell_nom[60];
	int dias;
	int legajo;
	char contrasena[10];
	char actividades[380];
	};
struct socios{
		char apell_nom[60];
		char domicilio[60];
		int dni,edad,telefono;
		fecha fech;
		float altura;
		float peso;
		int nrosocio;
		int actividad;
	};
struct turnos{
		int legajoentr;
	
		int nrosocio;
		int horario;
	};
struct mayorhora{
	int hora,legajo;
	char nombre[60];
	
};
struct pagos{
	int horas;
	int legajo;
	char nombre[60];
	
};
	
void cuenta(FILE *arch_usuarioo);//crea la cuenta del usuario que accede 
void MENUP();//menu de inicio
void MENU1(FILE *arch_usuarioo,FILE *arch_socios,FILE *arch_entrenadores);//Modulo del Gym
void MENU2(FILE *arch_usuarioo,FILE *arch_socios,FILE *arch_entrenadores,FILE *arch_turnos,FILE *arch_recep);//modulo de recepcion
void MENU3(FILE *arch_usuarioo,FILE *arch_socios,FILE *arch_entrenadores,FILE *arch_turnos,FILE *arch_recep);//modulo de administracion
void sesionentrenador(FILE *arch_entrenadores,int &band);//inicio de sesion de entrenadores
void sociosyactividades(FILE *arch_socios);//socios y actividad que desarrolla
void rutinas(FILE *arch_entrenadores);//registrar rutinas de gimnasia
void sesionrecepcion(FILE *arch_recep,int &bandd);//inicio de sesion de atencion al publico
void registrarsocios(FILE *arch_socios,FILE *arch_entrenadores,FILE *arch_turnos);//registrar nuevos socios
void listarsocios(FILE *arch_socios);//listar los socios registrados
void listapagos(FILE *arch_socios);//listar los pagos mensuales de los socios
void registroact(FILE *arch_turnos,FILE *arch_socios,FILE *arch_entrenadores);//registrar el tipo de actividad que esta a cargo cada entrenador
void pagoentrenador(FILE *arch_turnos, FILE *arch_entrenadores);//lo que se pagara a cada entrenador por horas
void mayorcarga(FILE *arch_turnos,FILE *arch_entrenadores);//muestra quien obtuvo la mayor cantidad de horas laborales

main()
{
	

	MENUP();
}

void MENUP()
{
	system("color 30");
	FILE *arch_usuarioo;
	FILE *arch_entrenadores;
	FILE *arch_socios;
	FILE *arch_turnos;
	FILE *arch_recep;

int Opcion;
		arch_usuarioo=fopen("usuarios.dat","a+b");
		arch_entrenadores=fopen("entrenadores.dat","a+b");
		arch_socios=fopen("socios.dat","a+b");
		arch_turnos=fopen("turnos.dat","a+b");
		arch_recep=fopen("recep.dat","a+b");
	do{
		system("cls");
		printf("\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\t\t°          1_CREAR CUENTA                                         °\n");  
		printf("\t\t°          2_MODULO DEL GYM                                       °\n");
		printf("\t\t°          3_MODULO DE RECEPCION                                  °\n");
		printf("\t\t°          4_MODULO DE ADMINISTRACION                             °\n");
		printf("\t\t°          5_SALIR DEL PROGRAMA                                   °\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\nOPCION: ");
		scanf("%d",&Opcion);
		system("cls");
		switch(Opcion)
		{
			case 1:
			printf("\n\t\tCREAR CUENTA");
			cuenta(arch_usuarioo);
			break;
				
			case 2:
			printf("\n\t\tMODULO DEL GYM");
			MENU1(arch_usuarioo,arch_socios,arch_entrenadores);
			break;
			
			case 3:
			printf("\n\t\tMODULO DE RECEPCION");
			MENU2(arch_usuarioo,arch_socios,arch_entrenadores,arch_turnos,arch_recep);
			break;
				
			case 4:	
			printf("\n\t\tMODULO DE ADMINISTRACION");
			MENU3(arch_usuarioo,arch_socios,arch_entrenadores,arch_turnos,arch_recep);
			break;
			
			case 5:
			printf("\nUsted salio del programa\n");
			
		
				
			default:("\nOPCION NO VALIDA");
			
				
		}
		printf("\n\n");
		system("pause");
	
		
	}while(Opcion!=5);

}

void MENU1(FILE *arch_usuarioo,FILE *arch_socios,FILE *arch_entrenadores)//MODULO DEL GYM acceso de entrenadores con cuenta
{
	int op,i=0,c,u,encontrado=0,band=0;
	char usu[100],contr[100];
	ct cuentaa;
	system("color 40");
		printf("\n1_INICIAR SESION en una cuenta existente:");
		printf("\nNombre de usuario: ");
		_flushall();
	    gets(usu);
		printf("\ncontrasena: ");
		_flushall();
		gets(contr);
		rewind(arch_usuarioo);
		fread(&cuentaa,sizeof(ct),1,arch_usuarioo);
	
	
		while(!feof(arch_usuarioo))
		{
			
		u=strcmp(cuentaa.usuario,usu);
		c=strcmp(cuentaa.contrasena,contr);
		if(u==0 and c==0)
		{
			encontrado=1;
		}
		
			
			fread(&cuentaa,sizeof(ct),1,arch_usuarioo);
		}
	if(encontrado==1)
	{
			do{
		system("cls");
			printf("\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\t\t°          1_INICIAR SESION                                           °\n");  
		printf("\t\t°          2_VISUALIZAR LISTADO DE SOCIOS Y ACTIVIDAD QUE DESARROLLA  °\n");
		printf("\t\t°          3_REGISTRAR RUTINAS DE GIMNASIA                            °\n");
		printf("\t\t°          4_CERRAR LA APLICACION                                     °\n");
		printf("\t\t°                                                                     °\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\nOPCION: ");
    	
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:printf("\n1_INICIAR SESION:");
				sesionentrenador(arch_entrenadores,band);
			case 2:
			printf("\n\t\tLISTADO DE SOCIOS Y ACTIVIDADES");
			if(band==1)
			{
				sociosyactividades(arch_socios);
				
			}
			else
			{
				printf("\nEL ENTRENADOR NO INICIO SESION!!");
			}
				break;
				
			case 3:	
			printf("\n\t\tREGISTRAR RUTINAS DE GIMNASIA");
			rutinas(arch_entrenadores);
				break;
			
			case 4:
			printf("\n\t\tSALIO DE LA APLICACION\n");
			
			default:("\nOPCION NO VALIDA");
		
			
				
		}
		printf("\n\n");
		system("pause");
	
	
		
	}while(op!=4);
	}
	else
	{
		printf("\nNOMBRE DE USUARIO INCORRECTO O CONTRASENIA INCORRECTA");
	}
	

}
//MODULO DE RECEPCION
void MENU2(FILE *arch_usuarioo,FILE *arch_socios,FILE *arch_entrenadores,FILE *arch_turnos,FILE *arch_recep)
{
	
	system("color 1F");
	
	int op,u,c,band=0;
	char usu[100],contr[100];
	Usuario recepcion;
	
	printf("\n1_INICIAR SESION en una cuenta existente:");
		printf("\nNombre de usuario: ");
		_flushall();
	    gets(usu);
		printf("\ncontrasena: ");
		_flushall();
		gets(contr);
		rewind(arch_recep);
		fread(&recepcion,sizeof(Usuario),1,arch_recep);
	
	
		while(!feof(arch_recep))
		{
			
		u=strcmp(recepcion.usuario,usu);
		c=strcmp(recepcion.contrasena,contr);
		if(u==0 and c==0)
		{
			band=1;
		}
		
			
			fread(&recepcion,sizeof(Usuario),1,arch_recep);
		}
	do{
		system("cls");
		printf("\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\t\t°          1_REGISTRAR SOCIOS Y ACTIVIDADES                           °\n");  
		printf("\t\t°          2_LISTADO DE SOCIOS                                        °\n");
		printf("\t\t°          3_LISTADO DE FECHAS DE PAGOS                               °\n");
		printf("\t\t°          4_CERRAR LA APLICACION                                     °\n");
		printf("\t\t°                                                                     °\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\nOPCION: ");
    	
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
		
				case 1:
				if(band==1)
				{
					printf("\n\t\tREGISTRAR SOCIOS Y ACTIVIDADES");
					registrarsocios(arch_socios,arch_entrenadores,arch_turnos);
				}
				else
				{
					printf("\nNo es posible registrar socios sin iniciar sesion un recepcionista");
				}
			
				break;
			
			case 2:
					if(band==1)
				{
					printf("\n\t\tLISTADO DE SOCIOS");
					listarsocios(arch_socios);
				}
				else
				{
					printf("\nNo es posible mostrar listado de socios sin iniciar sesion un recepcionista");
				}
			
				break;
			
			case 3:
					if(band==1)
				{
					printf("\n\t\tLISTADO DE FECHAS DE PAGO");
					listapagos(arch_socios);
				}
				else
				{
					printf("\nNo es posible mostrar listado de fechas de pago sin iniciar sesion un recepcionista");
				}
			
				break;
			
			case 4:
			printf("\n\t\tUSTED SALIO DEL PROGRAMA\n");
			
			default:("\nOPCION NO VALIDA");
			
				
		}
		printf("\n\n");
		system("pause");
	
		
	}while(op!=4);
}
//MODULO DE ADMINISTRACION
void MENU3(FILE *arch_usuarioo,FILE *arch_socios,FILE *arch_entrenadores,FILE *arch_turnos,FILE *arch_recep)
{
	system("color 70");
		int op,bandd=0,i=0,c,u,encontrado=0;
	char usu[100],contr[100];
	ct cuentaa;
		
	do{
		system("cls");
		printf("\n\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\t\t°          1_INICIAR SESION                                           °\n");  
		printf("\t\t°          2_REGISTRAR USUARIO DE RECEPCION                           °\n");
		printf("\t\t°          3_REGISTRAR ACTIVIDADES DEL GYM                            °\n");
		printf("\t\t°          4_CALCULAR PAGO DEL ENTRENADOR                             °\n");
		printf("\t\t°          5_ENTRENADOR CON MAYOR CARGA HORARIA                       °\n");
		printf("\t\t°          6_CERRAR LA APLICACION                                     °\n");
		printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	
		printf("\nOPCION: ");
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:
			printf("\n\t\tINICIAR SESION");
			printf("\n1_INICIAR SESION en una cuenta existente:");
		printf("\n~Nombre de usuario: ");
		_flushall();
	    gets(usu);
		printf("\n~Contrasena: ");
		_flushall();
		gets(contr);
		rewind(arch_usuarioo);
		fread(&cuentaa,sizeof(ct),1,arch_usuarioo);
	
	
		while(!feof(arch_usuarioo))
		{
			
		u=strcmp(cuentaa.usuario,usu);
		c=strcmp(cuentaa.contrasena,contr);
		if(u==0 and c==0)
		{
			encontrado=1;
		}
		
			
			fread(&cuentaa,sizeof(ct),1,arch_usuarioo);
		}
	
		
				break;
			
			case 2:
				if(encontrado==1)
				{
					printf("\n\t\tREGISTRAR USUARIO DE RECEPCION");
				sesionrecepcion(arch_recep,bandd);
				}
				else
				{
					printf("\n\tNo es posible registrar recepcionistas sin iniciar sesion con una cuenta existente");
					printf("\nRecuerde registrarse al inicio");
				}
			
				break;
				
			case 3:	
			if(bandd==1)
			{
				printf("\n\t\tREGISTRAR ACTIVIDADES DEL GYM");
				registroact(arch_turnos,arch_socios,arch_entrenadores);
			}
			else
			{
				printf("\n\tEs necesario que se registre el usuario de Recepcion!!");
			}
		
				break;
			
			case 4:
				if(bandd==1)
				{
						printf("\n\t\tCALCULAR PAGO DEL ENTRENADOR");
						pagoentrenador(arch_turnos,arch_entrenadores);
				}
				else
				{
					printf("\n\tEs necesario que se registre el usuario de Recepcion!!");
				}
		
				break;
			
			case 5:
				if(bandd==1)
				{
					
						mayorcarga(arch_turnos,arch_entrenadores);
						
				}
				else
				{
					
					printf("\nEs necesario que se registre el usuario de Recepcion!!");
				}
					break;
		
			
			case 6:
			printf("\n\t\tSE CERRO LA APLICACION\n");
			
				
			
			default:("\nOPCION NO VALIDA");
			
				
		}
		printf("\n\n");
		system("pause");
	
	
		
	}while(op!=6);
	
}
//CUENTA PRINCIPAL
void cuenta(FILE *arch_usuarioo)
{
	int len=0,j,mayus=0,minus=0,band=0,digitos=0,digitosconse=0;
	ct cuentaa;

	

	
	if(arch_usuarioo==NULL)
	{
		printf("\nArchivo no existente\n");system("pause");exit(1);
	}
	
	
	printf("\n\n\n");
	printf("\t\t************************************************\n");
	printf("\t\t*     Debe contener entre 6 y 10 caracteres    *\n");
	printf("\t\t*     Al menos dos mayusculas                  *\n");
	printf("\t\t*     comenzar con minuscula                   *\n");
	printf("\t\t*     maximo 3 digitos                         *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t************************************************\n");
	printf("\n~~USUARIO: ");
	_flushall();
	scanf("%s",&cuentaa.usuario);
    len=strlen(cuentaa.usuario);
  	printf("\nEL NOMBRE ES: %s ",cuentaa.usuario);printf("\n");system("pause");system("cls");
	
	for(j=0;j<len;j++)
	{
		if((cuentaa.usuario[j]>='A')&&(cuentaa.usuario[j]<='Z'))
		{
			mayus++;
			
		}
		if((cuentaa.usuario[j]>='a')&&(cuentaa.usuario[j]<='z'))
		{                                  
			minus++;
			 
		}
			if(j==1 and minus<1)
			{
				
				band=1;
			}
			if((cuentaa.usuario[j]=='0')||(cuentaa.usuario[j]=='1')||(cuentaa.usuario[j]=='2')||(cuentaa.usuario[j]=='3')||(cuentaa.usuario[j]=='4')||(cuentaa.usuario[j]=='5')||(cuentaa.usuario[j]=='6')||(cuentaa.usuario[j]=='7')||(cuentaa.usuario[j]=='8')||(cuentaa.usuario[j]=='9'))
		{
			digitos++;
		}
	}
                                   
                                
	while(mayus<2 or band==1 or (digitos<1 or digitos>3)or(len<6 or len>10) )
	{band=0;mayus=0;minus=0;digitos=0;
			printf("\n\n\n");
	printf("\t\t************************************************\n");
	printf("\t\t*     Debe contener entre 6 y 10 caracteres    *\n");
	printf("\t\t*     Al menos dos mayusculas                  *\n");
	printf("\t\t*     comenzar con minuscula                   *\n");
	printf("\t\t*     maximo 3 digitos                         *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t************************************************\n");
		printf("\n~~INGRESE NUEVAMENTE EL USUARIO: ");
	printf("\nUSUARIO: ");
	_flushall();
	scanf("%s",&cuentaa.usuario);
	printf("\nEL NOMBRE ES: %s ",cuentaa.usuario);printf("\n");system("pause");system("cls");
	 len=strlen(cuentaa.usuario);
	 
		for(j=0;j<len;j++)
	{
		if((cuentaa.usuario[j]>='A')&&(cuentaa.usuario[j]<='Z'))
		{
			mayus++;
			
		}
		if((cuentaa.usuario[j]>='a')&&(cuentaa.usuario[j]<='z'))
		{
			minus++;
			
		}
			if(j==1 and minus<1)
			{
				
				band=1;
			}
			if((cuentaa.usuario[j]=='0')||(cuentaa.usuario[j]=='1')||(cuentaa.usuario[j]=='2')||(cuentaa.usuario[j]=='3')||(cuentaa.usuario[j]=='4')||(cuentaa.usuario[j]=='5')||(cuentaa.usuario[j]=='6')||(cuentaa.usuario[j]=='7')||(cuentaa.usuario[j]=='8')||(cuentaa.usuario[j]=='9'))
		{
			digitos++;
		}
	}
	}
	system("cls");

	j=0;band=0;mayus=0;minus=0;digitos=0;
	printf("\n\n");
	printf("\t\t*********************************************************************************************************************\n");
	printf("\t\t*         Ingrese la contraseña:                                                                                    *\n");
	printf("\t\t*         Deberá contener al menos una letra mayúscula, una letra minúscula y un número                             *\n");
	printf("\t\t*         No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanumericos   *\n");
	printf("\t\t*          No debe tener más de 3 caracteres numéricos consecutivos                                                 *\n");
	printf("\t\t*********************************************************************************************************************\n");
	printf("\nCONTRASENA: ");
	_flushall();
	gets(cuentaa.contrasena);
	len=strlen(cuentaa.contrasena);
		printf("\nLA CONTRASENIA ES: %s ",cuentaa.usuario);printf("\n");system("pause");system("cls");
	
	for(j=0;j<len;j++)
	{
		if((cuentaa.contrasena[j]>='A')&&(cuentaa.contrasena[j]<='Z'))
		{
			mayus++;
			
		}
		if((cuentaa.contrasena[j]>='a')&&(cuentaa.contrasena[j]<='z'))
		{
			minus++;
			
		}
			
	if((cuentaa.contrasena[j]=='1' and cuentaa.contrasena[j+1]=='2')||(cuentaa.contrasena[j]=='2' and cuentaa.contrasena[j+1]=='3')||(cuentaa.contrasena[j]=='3' and cuentaa.contrasena[j+1]=='4')||(cuentaa.contrasena[j]=='4' and cuentaa.contrasena[j+1]=='5')||(cuentaa.contrasena[j]=='5' and cuentaa.contrasena[j+1]=='6')||(cuentaa.contrasena[j]=='6' and cuentaa.contrasena[j+1]=='7')||(cuentaa.contrasena[j]=='7' and cuentaa.contrasena[j+1]=='8')||(cuentaa.contrasena[j]=='8' and cuentaa.contrasena[j+1]=='9'))
		{
			digitosconse++;
		}
	
		
			if((cuentaa.contrasena[j]=='0')||(cuentaa.contrasena[j]=='1')||(cuentaa.contrasena[j]=='2')||(cuentaa.contrasena[j]=='3')||(cuentaa.contrasena[j]=='4')||(cuentaa.contrasena[j]=='5')||(cuentaa.contrasena[j]=='6')||(cuentaa.contrasena[j]=='7')||(cuentaa.contrasena[j]=='8')||(cuentaa.contrasena[j]=='9'))
		{
			digitos++;
		}
	}

	
		while(mayus<1 or minus<1 or digitos<1 or(len<6 or len>32) or digitosconse>3 )
	{band=0;mayus=0;minus=0;digitos=0;digitosconse=0;
	printf("\n\n");
	printf("\t\t*********************************************************************************************************************\n");
	printf("\t\t*         Ingrese la contraseña:                                                                                    *\n");
	printf("\t\t*         Deberá contener al menos una letra mayúscula, una letra minúscula y un número                             *\n");
	printf("\t\t*         No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanumericos   *\n");
	printf("\t\t*          No debe tener más de 3 caracteres numéricos consecutivos                                                 *\n");
	printf("\t\t*********************************************************************************************************************\n");
	printf("\nINGRESE NUEVAMENTE CONTRASENA: ");
	_flushall();
	gets(cuentaa.contrasena);
	len=strlen(cuentaa.contrasena);
	
	for(j=0;j<len;j++)
	{
		if((cuentaa.contrasena[j]>='A')&&(cuentaa.contrasena[j]<='Z'))
		{
			mayus++;
			
		}
		if((cuentaa.contrasena[j]>='a')&&(cuentaa.contrasena[j]<='z'))
		{
			minus++;
			
		}
			
	if((cuentaa.contrasena[j]=='1' and cuentaa.contrasena[j+1]=='2')||(cuentaa.contrasena[j]=='2' and cuentaa.contrasena[j+1]=='3')||(cuentaa.contrasena[j]=='3' and cuentaa.contrasena[j+1]=='4')||(cuentaa.contrasena[j]=='4' and cuentaa.contrasena[j+1]=='5')||(cuentaa.contrasena[j]=='5' and cuentaa.contrasena[j+1]=='6')||(cuentaa.contrasena[j]=='6' and cuentaa.contrasena[j+1]=='7')||(cuentaa.contrasena[j]=='7' and cuentaa.contrasena[j+1]=='8')||(cuentaa.contrasena[j]=='8' and cuentaa.contrasena[j+1]=='9'))
		{
			digitosconse++;
		}
	
		
			if((cuentaa.contrasena[j]=='0')||(cuentaa.contrasena[j]=='1')||(cuentaa.contrasena[j]=='2')||(cuentaa.contrasena[j]=='3')||(cuentaa.contrasena[j]=='4')||(cuentaa.contrasena[j]=='5')||(cuentaa.contrasena[j]=='6')||(cuentaa.contrasena[j]=='7')||(cuentaa.contrasena[j]=='8')||(cuentaa.contrasena[j]=='9'))
		{
			digitos++;
		}
	}

    }
    	fwrite(&cuentaa,sizeof(ct),1,arch_usuarioo);
    printf("\nEL USUARIO ES: ");
    puts(cuentaa.usuario);
    printf("\nContrasenia: ");
    puts(cuentaa.contrasena);
    
    	
    	
    	
}
//INICIO DE SSESION COMO ENTRENADOR
void sesionentrenador(FILE *arch_entrenadores,int &band)
{
	int len;
	entrenadorr ent;
	printf("\n");
	printf("\t\t**********************************************\n");
	printf("\t\t*       INICIO DE SESION ENTRENADOR          *\n");
	printf("\t\t**********************************************\n");
	printf("\n\tIngrese su Nombre: ");_flushall();
	gets(ent.apell_nom);
	printf("\n\tDias de atencion de lunes a sabados: ");
	scanf("%d",&ent.dias);
	
	while(ent.dias>6 or ent.dias<1)
	{
		printf("\nSolo dias del 1 al 6 semanales");
		printf("\nDias de atencion de lunes a sabados: ");
		scanf("%d",&ent.dias);
	}
	printf("\nIngrese su legajo: ");
	scanf("%d",&ent.legajo);
	printf("\nContrasenia sin condiciones maximo 10 caracteres: ");
	_flushall();
	gets(ent.contrasena);
	
	len=strlen(ent.contrasena);
	while(len>10)
	{
		printf("\nIncorrecto vuelva a ingresar");
	printf("\nContrasenia sin condiciones maximo 10 caracteres: ");
	_flushall();
	gets(ent.contrasena);
		
	}
	fwrite(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	//mostrar los datos ingresados del entrenador
	system("cls");
	printf("\n\n");
	printf("\t\t\t%s\n",ent.apell_nom);
	printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	printf("\t\t°            SUS DATOS                        \n");
	printf("\t\t°     Dias de atencion: %d                    \n",ent.dias);
	printf("\t\t°     Legajo: %d                              \n",ent.legajo);
	printf("\t\t°     Contrasenia:%s                          \n  ",ent.contrasena);
	printf("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	printf("\n");system("pause");system("cls");
	band=1;
	
}

//Listado de socios y actividades
void sociosyactividades(FILE *arch_socios)/*NO TE OLVIDE QUE NO ESTA TERMINADO*/
{
	socios soc;
	int act;
	if(arch_socios==NULL)
	{
		printf("\nAUN NO SE REGISTRO SOCIOS\n");
		system("pause");
		exit(1);
	}
	rewind(arch_socios);
	fread(&soc,sizeof(socios),1,arch_socios);
	
	while(!feof(arch_socios))
	{
		printf("\nSocio: ");
		puts(soc.apell_nom);
		
		act=soc.actividad;
		printf("Actividad que desarrolla: ");
		if(act==1)
		{
			printf("ZUMBA");
		}
		
		if(act==2)
		{
			printf("SPINING");
		}
		
		if(act==3)
		{
			printf("PILATE");
		}
		printf("\n-------------------------------------------\n");
		
			fread(&soc,sizeof(socios),1,arch_socios);
	
	}

	
}

//registrar rutinas de gimnasia
void rutinas(FILE *arch_entrenadores)
{
	entrenadorr ent;

	printf("\nREGISTRE LAS RUTINAS DE GIMNASIA QUE DESARROLLA ");
	printf("\nRUTINA:");
	_flushall();
	gets(ent.actividades);
	fwrite(&ent,sizeof(entrenadorr),1,arch_entrenadores);
}
//inicio de sesion para recepcionistas
void sesionrecepcion(FILE *arch_recep,int &bandd)
{
	char respuesta='n',nombre[10],contrasenia[60];
	Usuario recepcion;
	int band1=0,u,c;
	printf("\n\tPERSONAL DE ATENCION AL PUBLICO");
	printf("\n¿POSEE UNA SESION EN RECEPCION CREADA?");
	_flushall();
	printf("\nS/N: ");scanf("%c",&respuesta);
	if(respuesta=='s'||respuesta=='S')
	{
		system("cls");
    rewind(arch_recep);
	printf("\nusuario: ");_flushall();gets(nombre);
	printf("\ncontrasenia: ");_flushall();gets(contrasenia);
	fread(&recepcion,sizeof(Usuario),1,arch_recep);
	while(!feof(arch_recep))
	{
		u=strcmp(recepcion.usuario,nombre);
		c=strcmp(recepcion.contrasena,contrasenia);
	if(u==0 and c==0)
	{
		band1=1;
	}
	fread(&recepcion,sizeof(Usuario),1,arch_recep);
	}
	
		
	}
	if(band1==1)
	{
		printf("\nUSUARIO ENCONTRADO");
		printf("\nBIENVENIDO %s",nombre);
		bandd=1;
	}
	if( band1!=1)
	{
	printf("\nUSUARIO INEXISTENTE, ES NECESARIO CREAR UNO");
	printf("\nusuario: ");_flushall();gets(recepcion.usuario);
	printf("\ncontrasenia: ");_flushall();gets(recepcion.contrasena);
	printf("\nApellido y Nombre: ");_flushall();gets(recepcion.apell_nom);
	system("cls");
	printf("\nSUS DATOS: ");
	printf("\nusuarios: ");puts(recepcion.usuario);
	printf("contrasenia: ");puts(recepcion.contrasena);
	printf("Apellido y nombre: ");puts(recepcion.apell_nom);
	fwrite(&recepcion,sizeof(Usuario),1,arch_recep);
	bandd=1;
	}

}
//registro de socios del gimnasio
void registrarsocios(FILE *arch_socios,FILE *arch_entrenadores,FILE *arch_turnos)
{
	socios soc;
	turnos turn;
	entrenadorr ent;
	int hora;
	printf("\n\tREGISTRO DE UN NUEVO SOCIO");
	
	printf("\nIngrese los siguientes datos que se solicitan: ");
	printf("\nApellido y Nombre: ");
	_flushall();
	gets(soc.apell_nom);
	
	printf("Edad: ");
	scanf("%d",&soc.edad);
	
	printf("\nDNI: ");
	scanf("%d",&soc.dni);
	
	printf("\nPeso: ");
	scanf("%f",&soc.peso);
	
	printf("Altura: ");
	scanf("%f",&soc.altura);
	
	printf("Direccion: ");
	_flushall();
	gets(soc.domicilio);
	
	printf("Telefono: ");
	scanf("%d",&soc.telefono);
	
	printf("\nFecha de inscripcion: ");
	printf("\nDia: ");
	scanf("%d",&soc.fech.dia);
	while(soc.fech.dia>31 or soc.fech.dia<1)
	{
	printf("\nDia: ");
	scanf("%d",&soc.fech.dia);
		
	}
	
	printf("\nMes: ");
	scanf("%d",&soc.fech.mes);
	while(soc.fech.mes<1 or soc.fech.mes>12)
	{
		printf("\nMes: ");
	scanf("%d",&soc.fech.mes);
	}
	
	printf("\nAnio: ");
	scanf("%d",&soc.fech.anio);
	
	printf("\n");system("pause");
	
	system("cls");
	
	printf("\nActividad que desarrollara: ");
	printf("\n1_Zumba");
	printf("\n2_Spining");
	printf("\n3_Pilate");
	printf("\nEleccion: ");
	scanf("%d",&soc.actividad);
	
	while(soc.actividad<1 or soc.actividad>3)
	{
			
	printf("\nEscoger una actividad Valida!!!!: ");
	printf("\n1_Zumba");
	printf("\n2_Spining");
	printf("\n3_Pilate");
	printf("\nEleccion: ");
	scanf("%d",&soc.actividad);
	
	}
	
	printf("\nNumero de socio: ");
	scanf("%d",&soc.nrosocio);
	system("cls");
	fwrite(&soc,sizeof(socios),1,arch_socios);
	
	printf("\nProcede a elegir un turno: ");
	printf("\nTURNOS: ");
	printf("\n1_maniana");
	printf("\n2_tarde");
	printf("\n3_noche");
	printf("\nopcion: ");
	scanf("%d",&hora);
	
	while(hora>3 or hora<1)
	{
	printf("\nProcede a elegir un turno que sea VALIDO del 1 al 3: ");
	printf("\nTURNOS: ");
	printf("\n1_maniana");
	printf("\n2_tarde");
	printf("\n3_noche");
	printf("\nopcion: ");
	scanf("%d",&hora);
	}
	if(hora==1)
	{
		printf("\ncuantas horas trabajara desde las 6:00 a.m hasta las 11:00 p.m");
		printf("\nHoras: ");
		scanf("%d",&hora);
		system("cls");
		
		while(hora>5)
		{
		printf("\nIngrese las horas disponibles en su turno");
		printf("\ncuantas horas trabajara desde las 6:00 a.m hasta las 11:00 p.m");
		printf("\nHoras: ");
		scanf("%d",&hora);
		}
	}
	
	if(hora==2)
	{
		printf("\ncuantas horas trabajara desde las 1:00 p.m hasta las 6:00 p.m");
		printf("\nHoras: ");
		scanf("%d",&hora);
		system("cls");
		
		while(hora>5)
		{
		printf("\nIngrese las horas disponibles en su turno");
		printf("\ncuantas horas trabajara desde las 1:00 p.m hasta las 6:00 p.m");
		printf("\nHoras: ");
		scanf("%d",&hora);
		}
		
	}
	
		if(hora==3)
	{
		printf("\ncuantas horas trabajara desde las 6:00 p.m hasta las 11:00 p.m");
		printf("\nHoras: ");
		scanf("%d",&hora);
		system("cls");
		
		while(hora>5)
		{
		printf("\nIngrese las horas disponibles en su turno");
		printf("\ncuantas horas trabajara desde las 6:00 p.m hasta las 11:00 p.m");
		printf("\nHoras: ");
		scanf("%d",&hora);
		}
		
	}
	//
	printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	printf("\nSe procede a escoger un entrenador que supervisara sus actividades en los turnos elegidos");
	printf("\nuna vez se elija una opcion se registraran con:");
	printf("\nLegajo de su entrenador");
	printf("\nFecha en la que se los asigno");
	printf("\nSu numero de socio");
	printf("\nhoras que trabajaran");
	printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	printf("\n\n");
	system("pause");
	
	int i=0;
	rewind(arch_entrenadores);
	fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	
	while(!feof(arch_entrenadores))
	{
		printf("\nEntrenador %d: ",i+1);
		printf("\nNombre: ");
		puts(ent.apell_nom);
		printf("Dias de atencion: %d",ent.dias);
		printf("\n\n");
		
		fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	i++;
		
	}
	
	int num,leg,nsoc;
	i=0;
	printf("\nIngrese el numero del entrenador: ");
	scanf("%d",&num);
	
	rewind(arch_entrenadores);
	fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	
	while(!feof(arch_entrenadores))
	{printf("entro");
		if(i==(num-1))
		{
			printf("\nSe asignara el entrenador %d: ",num);
			puts(ent.apell_nom);
			nsoc=soc.nrosocio;
			leg=ent.legajo;
			
			turn.legajoentr=leg;
			turn.nrosocio=nsoc;
			turn.horario=hora;
			
			fwrite(&turn,sizeof(turnos),1,arch_turnos);
			
		}
		i++;
		
		fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	}
}
//Listar socios
void listarsocios(FILE *arch_socios)
{
		socios soc;
		rewind(arch_socios);
		fread(&soc,sizeof(socios),1,arch_socios);
		
		while(!feof(arch_socios))
		{
			printf("\napellido y nombre: ");puts(soc.apell_nom);
			printf("Edad: %d",soc.edad);
			printf("\nDNI: %d",soc.dni);
			printf("\nPeso: %.2f kg",soc.peso);
			printf("\nAltura: %.2f cm",soc.altura);
			printf("\nDomicilio: ");puts(soc.domicilio);
			printf("Telefono: %d",soc.telefono);
			printf("\nFECHA DE INSCRIPCION: %d / %d / %d",soc.fech.dia,soc.fech.mes,soc.fech.anio);
			printf("\n-----------------------------------------------------------------\n");
			
			
			 
			
		    fread(&soc,sizeof(socios),1,arch_socios);
		}
	
}                                      
//Listar pagos
void listapagos(FILE *arch_socios)
{
	socios soc;
	rewind(arch_socios);
	int mes,anio;
	fread(&soc,sizeof(socios),1,arch_socios);
	while(!feof(arch_socios))
	{
		mes=soc.fech.mes+1;
		if(mes>12)
		{
			mes=1;
			anio=soc.fech.anio+1;
		}
		
		printf("\nSocio: ");
		puts(soc.apell_nom);
		printf("fecha de ingreso: %d / %d / %d",soc.fech.dia,soc.fech.mes,soc.fech.anio);
		printf("\nFECHA DE PAGO: %d / %d / %d",soc.fech.dia,mes,anio);
		
		printf("\n-------------------------------------------------\n");
		fread(&soc,sizeof(socios),1,arch_socios);
		
	}
	printf("\n");
	system("pause");
}              

void registroact(FILE *arch_turnos,FILE *arch_socios,FILE *arch_entrenadores)
{
	socios soc;
	turnos turn;
	entrenadorr ent;
	int act,i=0;
	
	rewind(arch_turnos);
	rewind(arch_socios);
	rewind(arch_entrenadores);
	
	fread(&soc,sizeof(socios),1,arch_socios);
	fread(&turn,sizeof(turnos),1,arch_turnos);
	fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	
	while(!feof(arch_turnos))
	{
			i=0;
			while(!feof(arch_entrenadores))
			{
				if(turn.legajoentr==ent.legajo and i==0)
		        {
		        	printf("\nEntrenador: ");puts(ent.apell_nom);
		        	printf("Horas: %d\n",turn.horario);
		 		i++;
		     	}
		     	fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
		     }
		     i=0;
		     while(!feof(arch_socios))
		     {
		     	if(turn.nrosocio==soc.nrosocio and i==0)
		     	{
		     		printf("\nActividad que desarrolla: ");
		     		
		     		if(soc.actividad==1)
		     		{
		     			printf("\nZUMBA");
		     		}
		     		
		     		if(soc.actividad==2)
		     		{
		     			printf("\nSPINING");
		     		}
		     		
		     		if(soc.actividad==3)
		     		{
		     			printf("\nPILATE");
		     		}
		     		i++;
		     	}
		     	fread(&soc,sizeof(socios),1,arch_socios);
		     }
		     rewind(arch_socios);
		     rewind(arch_entrenadores);
		      
        fread(&turn,sizeof(turnos),1,arch_turnos);
        printf("\n---------------------------------------\n");

	}

	
	}
	
	void pagoentrenador(FILE *arch_turnos, FILE *arch_entrenadores)
	{
		turnos turn;
		pagos pag[100];
		entrenadorr ent;
		float porhora=250.00,cargah=0;
		int i=0,band=0,n;
		rewind(arch_entrenadores);
		rewind(arch_turnos);
		
		fread(&turn,sizeof(turnos),1,arch_turnos);
		fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
	
		while(!feof(arch_turnos))
		{
			pag[i].horas=0;
		
			while(!feof(arch_entrenadores))
			{
			
				
				if(turn.legajoentr==ent.legajo)
			{
				pag[i].horas+=turn.horario;
				pag[i].legajo=turn.legajoentr;
				strcpy(pag[i].nombre,ent.apell_nom);
				
			
				
			}
			fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
				
			}
			i++;
			rewind(arch_entrenadores);
			
		
			fread(&turn,sizeof(turnos),1,arch_turnos);
		}
		n=i;
	
		for(i=0;i<n;i++)
		{
			printf("\nEntrenador: ");puts(pag[i].nombre);
			printf("Recibe un pago de: %.2f",pag[i].horas*porhora);
		    printf("\nHoras trabajadas: %d",pag[i].horas);
		    printf("\n------------------------------------------\n");
			
		}
	
		
	}
    
    void mayorcarga(FILE *arch_turnos,FILE *arch_entrenadores)
    {
    		turnos turn;
		entrenadorr ent;
		mayorhora hor[300];
	
		int i=0,band=0,mayorcargah=0,cargah=0,leg,n,mayorleg;
		char entre[100];
		
		
		rewind(arch_entrenadores);
		rewind(arch_turnos);
		
		fread(&turn,sizeof(turnos),1,arch_turnos);
		mayorcargah=turn.horario;
		fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
		
		while(!feof(arch_turnos))
		{
			hor[i].hora=0;
			while(!feof(arch_entrenadores))
			{	
			if(turn.legajoentr==ent.legajo)
			{
				hor[i].hora+=turn.horario;
				hor[i].legajo=ent.legajo;
				strcpy(hor[i].nombre,ent.apell_nom);
			
			}
			fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
			
			}
		 	i++;
		
			fread(&turn,sizeof(turnos),1,arch_turnos);
		}
		n=i;
		int x;
		for(i=0;i<n;i++)
		{
			if(hor[i].hora>mayorcargah)
			{
				mayorcargah=hor[i].hora;
				mayorleg=hor[i].legajo;
			
				x=i;
				
			}
		}
		printf("\n");
		printf("\t\t********************************************************\n");
		printf("\t\t*     EL ENTRENADOR CON MAYOR CARGA HORARIA            *\n");
		printf("\t\t********************************************************\n");
		printf("Nombre: ");puts(hor[x].nombre);
		printf("\nLegajo: %d",hor[x].legajo);
		printf("\nHoras: %d",mayorcargah);
		printf("\n");system("pause");
		
		
		/*
		rewind(arch_entrenadores);
		fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
		while(!feof(arch_entrenadores))
		{
			
			if(leg==ent.legajo)
			{
					printf("\nEl entrenador con mayor carga horaria es: ");puts(ent.apell_nom);
				
			}
			fread(&ent,sizeof(entrenadorr),1,arch_entrenadores);
		}
	
		printf("\nHoras: %d",mayorcargah);
	
    	*/
}
