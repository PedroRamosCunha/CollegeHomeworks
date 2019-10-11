#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



#define registro (120*sizeof(char)+1*sizeof(int))
	
	//Struct do problema
	typedef struct 
	{
	 char firstname[20];
	 char lastname[20];
	 char email[50];
	 char nationality[30];
	 char idade[3];
	}person_data;


	

	//abertura de arquivo para leitura e edição
	FILE *open_file()
	{
		FILE *fp;
		fp = fopen("DataBank.txt", "a+");
		 if (fp==NULL)
		{
			printf("COULD NOT OPEN FILE\n FATAL ERROR \n END PROGRAM");
			return NULL;
		}
		return fp;
	}


	//Fechamento de arquivo
	int close_file(FILE *fp)
	{
		int a=10;
		a = fclose(fp);
		if(a==0)
		{
			printf("ARQUIVO FECHADO COM SUCESSO\n");
			return 0;
		}
		else
		{
			for (int i = 0; i < 50; ++i)
			{
				printf("ERRO ERRO ERRO ERRO\n");
			}
		}
		return 0;
	}


	//interface principal do sistema
	void main_inteface()
	{
		printf("		______________________________________________________\n");
		printf("		*                                                    *\n" );
		printf("		*              Bem-vindo ao Ciferri 3000             *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		*    1 - Adicionar novos cadastros                   *\n");
		printf("		*    2 - Ler um registro                             *\n");
		printf("		*    3 - Encerrar o programa                         *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		------------------------------------------------------\n");
	}

	//interface 1
	void first_interface()
	{
		printf("		______________________________________________________\n");
		printf("		*                                                    *\n");
		printf("		*                    Ciferri 3000                    *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		*    Firstname:                                      *\n");
		printf("		*    Lastname:                                       *\n");
		printf("		*    E-mail:                                         *\n");
		printf("		*    Nationality:                                    *\n");
		printf("		*    Age:                                            *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		------------------------------------------------------\n");
	}

	void menu_default()
	{
		
		printf("		______________________________________________________\n");
		printf("		*                                                    *\n");
		printf("		*                    Ciferri 3000                    *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		*         OPÇÃO INVÁLIDA, TENTE NOVAMENTE            *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		------------------------------------------------------\n");
		system("Pause");
		system("cls");
	
	}

	void encerramento()
	{
		printf("		______________________________________________________\n");
		printf("		*                                                    *\n");
		printf("		*                    Ciferri 3000                    *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		*            ENCERRADO! TENHA UM BOM DIA!            *\n");
		printf("		*                                                    *\n");
		printf("		*                                                    *\n");
		printf("		------------------------------------------------------\n");
	}

	void print_me(person_data *me)
	{
		printf("\n \n");
		printf("Firstname: %s\n", me->firstname);
		printf("Lastname: %s\n", me->lastname);
		printf("E-mail: %s\n", me->email);
		printf("Nationality: %s\n", me->nationality);
		printf("Age: %s \n", me->idade);
	}
	void write_on_file(person_data* me, FILE* fp)
	{
		fwrite(me->firstname,sizeof(char),20,fp);
		fwrite(me->lastname,sizeof(char),20,fp);
		fwrite(me->email,sizeof(char),50,fp);
		fwrite(me->nationality,sizeof(char),30,fp);
		fwrite(me->idade,sizeof(char),3,fp);
	}

	void setCad( FILE *fp)
	{
		person_data me[1];
		first_interface();
		printf("\n\n");
		printf("		Firstname: ");
		fflush(stdin);
		scanf("%s", me->firstname);

		printf("		Lastname: ");
		fflush(stdin);
		scanf("%s", me->lastname);

		printf("		E-mail: ");
		fflush(stdin);
		scanf("%s", me->email);

		printf("		Nationality: ");
		fflush(stdin);
		scanf("%s", me->nationality);

		printf("		Age: ");
		fflush(stdin);
		scanf("%s", me->idade);

		write_on_file(me, fp);	
	}


	void getSearch(FILE *fp, int RRN)
	{
		person_data me[1];
		fseek(fp, 0,SEEK_SET);
		fseek(fp, (RRN*registro),SEEK_SET);
		fread(me->firstname, sizeof(char),20, fp);
		fread(me->lastname, sizeof(char),20, fp);
		fread(me->email, sizeof(char),50, fp);
		fread(me->nationality, sizeof(char),30, fp);
		fread(me->idade, sizeof(char),3, fp);
		print_me(me);
		fseek(fp, 0, SEEK_END);
	}



//Funcão principal (main)
int main(int argc, char const *argv[])
{
	int menu = 0;
	FILE *fp;
	int RRN;
	fp = open_file();

	while(menu != 3)
	{
		main_inteface();
		fflush(stdin);
		scanf("%d", &menu);
		fflush(stdin);

		if (menu==1)
		{
			system("cls");
			setCad(fp);
		}
		else if (menu==2)
		{
			system("cls");
			fflush(stdin);
			printf("		Forneça o RRN:");
			scanf("%d", &RRN);
			getSearch(fp, RRN);
		}
		else if (menu !=3)
		{
			system("cls");
			menu_default();
		}
	}
	encerramento();
	close_file(fp);
	return 0;
}