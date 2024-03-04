#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct users{
	char Nama[30];
	char Email[30];
	char password[20];
	char username[20];
	char passwordconfirm[20];
};

int main(){
	struct users user[100];
	int i;
	printf("Register Akun\n");
	printf("=============\n");	
	for(i=0; i<100; i++)
	{	
		printf("Masukkan nama anda : ");
		scanf("%s", user[i].Nama);
		
		printf("Masukkan email : ");
		scanf("%s", user[i].Email);
		
		printf("Masukkan username : ");
		scanf("%s", user[i].username);
		
		printf("Masukkan password : ");
		scanf("%s", user[i].password);
		
		FILE *f_B;
		f_B = fopen("file_user.txt", "w");
		fprintf(f_B, "%d %s %s %s %s\n", i, user[i].Nama, user[i].Email, user[i].username, user[i].password);
		fclose(f_B);
		{
			system("cls");
			printf("==========\n");
			printf("Konfirm password : ");
			scanf("%s", user[i].passwordconfirm);
			int verify = strcmp(user[i].password,user[i].passwordconfirm);
			if(verify == 0)break;
		}
	}
	printf("\nRegister Berhasil\n");
	
	return 0;
}
