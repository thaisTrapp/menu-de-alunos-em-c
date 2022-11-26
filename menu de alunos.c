#include <stdio.h>
#include <string.h>
#include <time.h>

//typedefs
typedef struct
{
  char nome[50];
  int id;
  int excluido;
  double notas[3];
  double media;

} cadastroAluno;

//variaveis globais
int IDs = 1;
int quantAlunos=20;
cadastroAluno aluno[20];

//pre declaracao das funcoes alunos
void alunos ();
void cadastrarAluno ();
void consultarID ();
void exluirID ();
void alterarID();
void relatorioAluno();
int existeID();
void tempo();

//pre declaracao das funcoes notas
void menuNotas();
int cadastrarNotas();
void alterarNotas();
void excluirNotas();
void consultaNotas();

//pre declaracao das funcoes relatorio
void menuRelatorio();
void relatorioNotas();
void relatorioMedia();
  void media();


//main
int main ()
{

//variaveis
int i=0,a=0, menu;
//iniciando variavel com todos os alunos excluidos
while (i<quantAlunos) {
aluno[i].excluido = 1;
i++;
}
i=0;
//iniciando variavel com todos os ids e notoas zerados
while (i<quantAlunos) {
aluno[i].id = 0;
i++;
}
for(i=0;i<quantAlunos;i++){
for(a=0;a<3;a++){
aluno[i].notas[a] = -1; 
}
}


//menu  1
  while (menu != 4)

    {
      switch (menu)
	{
	case 1:
	  alunos ();
	  break;
	case 2:
	  menuNotas();
	  break;
	case 3:
	  menuRelatorio();
	  break;
	case 4:
	  break;
	}
      printf("Escolha uma opcao para prosseguir:\n1- Aluno\n2- Notas \n3- Relatorio\n4-Sair\n");
      scanf ("%d", &menu);
    }


  return 0;
}

//funcao alunos
void alunos ()
{
  //menu  alunos
  int menuAlunos = 0;

  while (menuAlunos != 6)
    {
      switch (menuAlunos)
	{
	case 1:
	  cadastrarAluno ();
	  break;
	case 2:
	  consultarID ();
	  break;
	case 3:
	  exluirID();
	  break;
	case 4:
	  alterarID();
	  break;
	case 5:
	  relatorioAluno();
	  break;
	case 6:
	  break;

	}
      printf ("\n\nEscolha uma opcao para prosseguir:\n1- Cadastrar\n2- Consultar por id\n3- Excluir por id\n4- Alterar por id\n5- RelatC3rio\n6- Voltar\n");
      scanf ("%d", &menuAlunos);
    }



}

//funcao cadastro de aluno
void cadastrarAluno ()
{
  int a =0;

  printf ("\nDigite nome do aluno:  ");
 
  while(existeID(IDs) == 1){
     IDs++;
  } 
  
  aluno[IDs].id = IDs;
  aluno[IDs].excluido = 0; 
   
  while (a == 0)//garantir q nome digitado tem mais 3 caracteres
    {

      fflush(stdin);
      fgets (aluno[IDs].nome, 50, stdin);
      if (strlen (aluno[IDs].nome) > 3)
	{
	  //  fgets(exemplo, sizeof exemplo, stdin);
int len = strlen(aluno[IDs].nome);
if (aluno[IDs].nome[len - 1] == '\n') {
    aluno[IDs].nome[--len] = 0; // remove quebra de linha
        }
	   printf("Aluno: %s\nCodigo aluno: %i\n", aluno[IDs].nome,aluno[IDs].id); 
    a++;
  } else
printf("entrada inválida");
    }
    

 
  
IDs++;
}

//funcao consultar aluno por id
void consultarID ()
{

  int a;
  
  printf ("\nDigite id do aluno:  ");
  scanf ("%d", &a);
  
  if (aluno[a].excluido == 0 && aluno[a].id != 0)
    {
      printf ("\nCC3digo do Aluno: %d\nAluno: %s", a, aluno[a].nome);

    }
  else
    printf ("NC#o existe o Id na base de alunos!");

}

//funcao excluir alunos
void exluirID ()
{
  int a;
  char opcao;
  
   printf ("\nDigite id do aluno:  ");
    scanf("%d",&a);
    fflush(stdin);

if (aluno[a].excluido == 0 && aluno[a].id != 0){
   printf("\n ID aluno:%d\n Aluno: %s\n", a, aluno[a].nome );
   printf("Confirma Exclusão [S]im, [N]ão:  \n");
    opcao= getc(stdin);
    fflush(stdin);

if(opcao == 's' || opcao == 'S'){
  aluno[a].excluido = 1;
}

}
else 
printf("Aluno não existe na base!");

}

//funcao alterar aluno por id
void alterarID()
{
  int a, i = 0;

  printf ("\nDigite id do aluno:  ");
    scanf("%d",&a);
 
 if(aluno[a].excluido == 0){
  printf ("\nNome do aluno: %s ",aluno[a].nome);
  printf ("\nDigite novo nome do aluno para cadastro:   ");
  //garantir q nome digitado tem mais 3 caracteres
  while (i == 0)
    {
      fgets (aluno[a].nome, 50, stdin);
      if (strlen (aluno[a].nome) > 3)
	        {
	        i++;
          printf ("\nNome do aluno alterado para: %s ",aluno[a].nome);
	        }
    }
  }

  else 
  printf("ID inválido!");
}

//funcao relatorio aluno
void relatorioAluno()
{
int i,y,z =0;

///////////////////////////////
for(i=0;i<88;i++){
    printf("-");
}
printf("\n                                   Relatório de Alunos\n");
for(i=0;i<88;i++){
    printf("-");
}
    printf("\n|         ID         |                 Nome                       |        Excluido    |\n");
for(i=0;i<88;i++){
    printf("-");
}
///////////////////////////////
i=1;

while(i<quantAlunos){

if(aluno[i].id != 0){

if(aluno[i].id < 10){
printf("\n|         %i          |",aluno[i].id);
}
else if(aluno[i].id >= 10){
printf("\n|        %i          |",aluno[i].id);
}

printf(" %s",aluno[i].nome);

y = 43 - strlen(aluno[i].nome);
for(z=0;z<y;z++){
printf(" ");
}

if(aluno[i].excluido == 1){
printf("|         x          |\n");
}
if(aluno[i].excluido == 0){
printf("|                    |\n");
}

z=0;
for(z=0;z<88;z++){
    printf("-");
}
}
i++;
}
printf("\n");
for(i=0;i<58;i++){
    printf("-");
}

tempo();
   
}

//verifica se ID é único
int existeID(int IDs){

int i=0;

for(i=0;i<quantAlunos;i++){
if (aluno[i].id == IDs ){
  return 1;
}
 
}
 
 return 0;

}

// Imprime a data e hora atuais
 void tempo()
{
    int hr, min, dia, mes, ano;
    time_t now;

    time(&now);

    struct tm *local = localtime(&now);
    hr = local->tm_hour;        
    min = local->tm_min;       
    
    dia = local->tm_mday;
    mes = local->tm_mon + 1;
    ano = local->tm_year + 1900;

    // imprime a data e hora atual
    printf("Gerado em: %02d/%02d/%d as ", dia, mes, ano);
 printf("%02d:%02d\n",hr,min);
}

//funcao menu alunos
void menuNotas()
{
  //menu  alunos
  int menuNotas = 0;

  while (menuNotas != 5)
    {
      switch (menuNotas)
	{
	case 1:
	 cadastrarNotas();
	  break;
	case 2:
	 alterarNotas();
	  break;
	case 3:
    excluirNotas();
	  break;
	case 4:
    consultaNotas();
	  break;
	case 5:
	  break;

	}
      printf ("\n\nEscolha uma opcao para prosseguir:\n1- Incluir Nota do Aluno\n2- Alterar Nota do Aluno\n3- Excluir Nota do Aluno\n4- Consultar Notas do Aluno\n5- Voltar\n");
      scanf ("%d", &menuNotas);
    }
}

//funcao de cadastro das notas
int cadastrarNotas()
{
  int i=0,a=0;
  float n;

  printf ("\nDigite id do aluno:  ");
  scanf ("%d", &a);
  printf ("\nCodigo do Aluno: %d\nAluno: %s\n", a, aluno[a].nome);

  if (aluno[a].excluido == 0 && aluno[a].id != 0)
    {
      if(aluno[a].notas[0] != -1 && aluno[a].notas[1] != -1 && aluno[a].notas[0] != -1){
        printf("\nAluno com todas as notas cadastradas!\n");
        return 0;
      }

      for(i=0;i<3;i++){
          
          int z=0;

          if (aluno[a].notas[i] != -1){
              i++;
          }

          printf ("Digite a nota %d do aluno %d:",i+1,a);          
          while(z == 0){
          scanf("%f",&n);
          if(n >= 0 && n <= 10){
            aluno[a].notas[i] =n;
              z++;}

             }
              }  
               }   

  else
    printf ("NC#o existe o Id na base de alunos!");

}

//funcao alterar nota por id
void alterarNotas()
{
  int a,b,i = 0;
  float n;

  printf ("\nDigite id do aluno:  ");
  scanf("%d",&a);
 
  if(aluno[a].excluido == 0){
  printf ("\nCodigo do Aluno: %d\nAluno: %s", a, aluno[a].nome);
     for(i=0;i<3;i++){
     printf ("\nnota %d: %.2f",i+1,aluno[a].notas[i]); 
      }
i=0;


printf("\nInsira numero da nota para alteração:  ");
while(i==0){
scanf("%d",&b);
if(b<4){
  b=b-1;
  i++;
 } 
  }

i=0;
printf("\nAlterar a nota %d de %.2f para:  ",b,aluno[a].notas[b]);          
          while(i == 0){
            scanf("%f",&n);
            if(n >= 0 && n <= 10){
                aluno[a].notas[b] =n;
                i++;}
                else
                printf("\nNota não existe! Digitar novamente.");
             }

  
  }
  else 
  printf("Aluno não existe na base!");
}

//funcao excluir nota por id
void excluirNotas()
{
  int a,b,i = 0;

  printf ("\nDigite id do aluno:  ");
  scanf("%d",&a);
 
  if(aluno[a].excluido == 0){
     printf ("\nCodigo do Aluno: %d\nAluno: %s", a, aluno[a].nome);
     for(i=0;i<3;i++){
      if(aluno[a].notas[i] != -1){
        printf ("\nnota %d: %.2f",i+1,aluno[a].notas[i]); 
      }
      else
      printf ("\nnota %d: ",i+1);
      }
i=0;

printf("\nInsira numero da nota para exclusao  ");
while(i==0){
  scanf("%d",&b);
   if(b<4){
      b=b-1;
      if (aluno[a].notas[b] != -1){
        aluno[a].notas[b] = -1;
        printf("\nnota %d excluida",b);
        i++;
        } 
        else if (aluno[a].notas[b] == -1){
        printf("\nNota do aluno não cadastrada!");

        }
           }

    else 
      printf("\nNota não existe! Digitar novamente.");
  }
  
  }
  else 
  printf("Aluno não existe na base!");
}

//funcao consulta nota por id
void consultaNotas()
{
  int a,i = 0;

  printf ("\nDigite id do aluno:  ");
  scanf("%d",&a);
 
  if(aluno[a].excluido == 0){
     printf ("\nCodigo do Aluno: %d\nAluno: %s", a, aluno[a].nome);
     for(i=0;i<3;i++){
      if(aluno[a].notas[i] != -1){
        printf ("\nnota %d: %.2f",i+1,aluno[a].notas[i]); 
      }
      else
        printf ("\nnota %d: ",i+1);
      }
  }
  else 
  printf("Aluno não existe na base!");

}

//funcao menu relatorios
void menuRelatorio()
{
  //menu  relatorio
  int menuRelatorio = 0;

  while (menuRelatorio != 3)
    {
      switch (menuRelatorio)
	{
	case 1:
	 relatorioNotas();
	  break;
	case 2:
	 relatorioMedias();
	  break;
	case 3:
	  break;

	}
      printf ("\n\nEscolha uma opcao para prosseguir:\n1- Relatório de notas\n2- Relatório de Médias\n3- Voltar\n");
      scanf ("%d", &menuRelatorio);
    }
}

//funcao gera relatorio de notas
void relatorioNotas()
{
int i,y,z =0;

///////////////////////////////
for(i=0;i<118;i++){
    printf("-");
}
printf("\n                                   Relatório de Notas\n");
for(i=0;i<118;i++){
    printf("-");
}
    printf("\n|         ID         |                 Nome                       |      Nota 01   |      Nota 02   |      Nota 03   |\n");
for(i=0;i<118;i++){
    printf("-");
}
///////////////////////////////
i=1;

while(i<quantAlunos){

if(aluno[i].id != 0){

if(aluno[i].id < 10){
printf("\n|         %i          |",aluno[i].id);
}
else if(aluno[i].id >= 10){
printf("\n|        %i          |",aluno[i].id);
}

printf(" %s",aluno[i].nome);

y = 43 - strlen(aluno[i].nome);
for(z=0;z<y;z++){
printf(" ");
}
//\/\/\/\/\/\\/\ NOTAS \/\/\//\/\/\//

if(aluno[i].notas[0] >= 0){
 
printf("|      %.2f       ",aluno[i].notas[0]);
 if(aluno[i].notas[0] < 10){
  printf(" ");
}}
if(aluno[i].notas[1] >= 0){
printf("|      %.2f     ",aluno[i].notas[1]);
if(aluno[i].notas[0] < 10){
  printf(" ");
}}
if(aluno[i].notas[2] >= 0){
printf("|      %.2f     ",aluno[i].notas[2]);
if(aluno[i].notas[0] < 10){
  printf(" ");
}}
printf("|\n");
z=0;
for(z=0;z<118;z++){
    printf("-");
}

}
i++;
}
printf("\n");
for(i=0;i<88;i++){
    printf("-");
}

tempo();
   
}

//funcao gera relatorio de notas
void relatorioMedias()
{
int i,y,z =0;


for(i=0;i<118;i++){
    printf("-");
}
printf("\n                                   Relatório de Médias\n");
for(i=0;i<84;i++){
    printf("-");
}
    printf("\n|         ID         |                 Nome                        |      Media     |\n");
for(i=0;i<84;i++){
    printf("-");
}

i=1;

while(i<quantAlunos){

if(aluno[i].id != 0){

//print id
printf("\n|         %i          |",aluno[i].id);
if(aluno[i].id < 10){
printf(" ");
}

//print nome do aluno
printf(" %s",aluno[i].nome);

y = 43 - strlen(aluno[i].nome);
for(z=0;z<y;z++){
printf(" ");
}
///////// MEDIA /////////
media(i);
 
 //print media
printf("|      %.2f    ",aluno[i].media);
 if(aluno[i].notas[0] < 10){
  printf(" ");
}
printf("|\n");
i++;
}
else 
i++;
}
z=0;
for(z=0;z<84;z++){
    printf("-");
}


printf("\n");
for(z=0;z<54;z++){
    printf("-");
}

tempo();
   
}

//media das notas
void media(int a){
  int i;
  double soma=0;


for (i=0;i<3;i++){
  if(aluno[a].notas[i] >= 0){
soma = soma + aluno[a].notas[i];
}
}

aluno[a].media = (soma/3);


}