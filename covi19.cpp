                                                     /*Mayra Golcalves*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct covid19{ // Estrutara chamada covid19
	char pais[30]; 
	int casos;
	int recuperados;
	int obitos; 
	int casos_ativos;
    struct covid19 *Seguinte;
}covid19;

    covid19 *CriarLista(char p[30], int c, int r, int o, int ca);
    covid19 *inserirNoInicio(covid19 *inicio,char p[30], int c, int r, int o, int ca);
    covid19 *inserirNoMeio(covid19 *inicio,char p[30], int c, int r, int o, int ca);
    covid19 *inserirNoFinal(covid19 *inicio,char p[30], int c, int r, int o, int ca);
    void imprimirLista(covid19 *inicio);
    covid19 *removerNoInicio(covid19 *inicio, char paises[30]);
    covid19 *removerNoFinal(covid19 *inicio,char paises[30]);
    covid19 *removerElemento(covid19 *inicio, int valor);
    covid19 *removerQualquerElemento(covid19 *inicio);
    void enviarNoFicheiro(covid19 *inicio);
    void enviarCasosAtivosFicheiro(covid19 *inicio);
    void totalCasos(covid19 *inicio);
    void totalMortes(covid19 *inicio);
    void totalRecuperados(covid19 *inicio);
    covid19* pesquisarElemento(covid19* le, char busca[30]);
    void ordemAscendente(covid19 **p);
    void menu();
    covid19 *Covid19 =NULL;
    
int main(){
    	
    system("COLOR 1F");
    setlocale(LC_ALL, "Portuguese");
    
    int opcao;
    int casos, recuperados, obitos,casos_ativos;
    char pais[30], paises[30];
    char busca[30];
		
    	do{
         system("cls");
         printf("\n\t\t\t\t|--------------------------------------------------------------|");
         printf("\n\t\t\t\t|                  LISTA LIGADA SIMPLES | AED                  |");
         printf("\n\t\t\t\t|                             |                                |");
         printf("\n\t\t\t\t|--------------------------------------------------------------|");
         printf("\n\t\t\t\t|  1  - INSERIR NÓ NO INICIO DA LISTA                          |");
         printf("\n\t\t\t\t|  2  - INSERIR NÓ NO MEIO DA LISTA                            |");
         printf("\n\t\t\t\t|  3  - INSERIR NÓ NO FINAL DA LISTA                           |");
         printf("\n\t\t\t\t|  4  - IMPRIMIR NÓ  DA LISTA                                  |");
         printf("\n\t\t\t\t|  5  - PESQUISAR PAÍS                                         |");
         printf("\n\t\t\t\t|  6  - CÁLCULO TOTAL DE CASOS                                 |");
         printf("\n\t\t\t\t|  7  - CÁLCULO TOTAL DE MORTES                                |");
         printf("\n\t\t\t\t|  8  - CÁLCULO TOTAL DE RECUPERADOS                           |");
         printf("\n\t\t\t\t|  9  - ORDENAR PAÍSES EM ORDEM ASCENDENTES COM MAIS CASOS     |");
         printf("\n\t\t\t\t|  10 - ENVIAR TODOS OS NÓS PARA FICHEIRO ELEMENTOS            |");
         printf("\n\t\t\t\t|  11 - REMOVER NÓ NO INICIO  DA LISTA                         |");
         printf("\n\t\t\t\t|  12 - REMOVER NÓ NO FINAL DA LISTA                           |");
         printf("\n\t\t\t\t|  13 - REMOVER QUALQUER ELEMENTE DA LISTA                     |");
         printf("\n\t\t\t\t|  14 - SAIR                                                   |");
         printf("\n\t\t\t\t|--------------------------------------------------------------|");
         printf("\n\t\t\t\t|                     ESCOLHA UMA OPÇÃO!!!                     |");
         printf("\n\t\t\t\t|--------------------------------------------------------------|\n");
         scanf("%d",&opcao);
          setbuf(stdin,NULL);

        switch(opcao){
        case 1:
            printf("Digite o nome do país: ");
            scanf("%[^\n]s",&pais);
            setbuf(stdin,NULL);
            printf("Digite o número de casos: ");
            scanf("%d",&casos);
            printf("Digite o número de recuperados: ");
            scanf("%d",&recuperados);
            printf("Digite o número de obitos: ");
            scanf("%d",&obitos);
            casos_ativos = casos - recuperados - obitos;
            printf("Casos ativos: %d\n",casos_ativos);
            Covid19 = inserirNoInicio(Covid19,pais,casos,recuperados,obitos,casos_ativos);
            enviarCasosAtivosFicheiro(Covid19);
            printf("\n");
            system("pause");
            break;
        case 2:
            printf("Digite o nome do país: ");
            scanf("%[^\n]s",&pais);
            setbuf(stdin,NULL);
            printf("Digite o número de casos: ");
            scanf("%d",&casos);
            printf("Digite o número de recuperados: ");
            scanf("%d",&recuperados);
            printf("Digite o número de obitos: ");
            scanf("%d",&obitos);
            casos_ativos = casos - recuperados - obitos;
            printf("Casos ativos: %d\n",casos_ativos);
            Covid19=inserirNoMeio(Covid19,pais,casos,recuperados,obitos,casos_ativos);
            enviarCasosAtivosFicheiro(Covid19);
            printf("\n");
            system("pause");
            break;
        case 3:
            printf("Digite o nome do país: ");
            scanf("%[^\n]s",&pais);
            setbuf(stdin,NULL);
            printf("Digite o número de casos: ");
            scanf("%d",&casos);
            printf("Digite o número de recuperados: ");
            scanf("%d",&recuperados);
            printf("Digite o número de obitos: ");
            scanf("%d",&obitos);
            casos_ativos = casos - recuperados - obitos;
            printf("Casos ativos: %d\n",casos_ativos);
            Covid19=inserirNoFinal(Covid19,pais,casos,recuperados,obitos,casos_ativos);
            enviarCasosAtivosFicheiro(Covid19);
            printf("\n");
            system("pause");
            break;
        case 4:
            system("cls");
            imprimirLista(Covid19);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
            system("pause");
            break;
         case 5:
            system("cls");
            printf("\n\nNome do pais que desejas procurar: ");
            scanf("%s",&busca);
            Covid19 = pesquisarElemento(Covid19, busca);
            if(Covid19 == 0){
            	printf("País nao encontrado na lista");
			}else{	
             printf("\nPais: %s",Covid19->pais);
             printf("\nNúmeros de casos: %d",Covid19->casos);
             printf("\nNúmeros de recuperados: %d",Covid19->recuperados);
             printf("\nNúmeros de obitos:%d",Covid19->obitos);
             printf("\nNúmeros de casos ativos: %d\n",Covid19->casos_ativos);
			}
			 printf("\n\nClique qualquer tecla para continuar?\n\n");
			 system("pause");
            break;    
        case 6:
            system("cls");
            totalCasos(Covid19);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
			system("pause");
            break;    
        case 7:
            system("cls");
            totalMortes(Covid19);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
			system("pause");
            break;    
        case 8:
            system("cls");
            totalRecuperados(Covid19);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
			system("pause");
            break;    
        case 9:
            system("cls");
            ordemAscendente(&Covid19);
            enviarCasosAtivosFicheiro(Covid19);//Atualiza o ficheiro "CasosAtivo.txt" ordenanado so paises por numeros de casos na ordem ascendente
            printf("\nPaíses em ordem ascendente, com mais casos de COVID-19\n\n");
            imprimirLista(Covid19);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n"); 
			system("pause");
            break;    
        case 10:
            system("cls");
            enviarNoFicheiro(Covid19);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n"); 
			system("pause");
            break;  
        case 11:
		    system("cls");
            Covid19 = removerNoInicio(Covid19,paises);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
            system("pause");
            break;
        case 12:
        	system("cls");
            Covid19 = removerNoFinal(Covid19,paises);
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
            system("pause");
        case 13:
        	system("cls");
            Covid19=removerQualquerElemento(Covid19);
            printf("FORAM REMOVIDOS TODOS OS NÓS");
            printf("\n\nClique qualquer tecla para continuar!!!\n\n");
            system("pause");
            break;	
       case 14:
       	     system("cls");
        	 printf("SAINDO DO PROGRAMA!!!\n");
	    	break;    
        default:printf("Opção inválido!");
        }
    }while(opcao !=14);	
    	return 0;
	}
	
covid19 *CriarLista(char p[30], int c, int r, int o, int ca){
    //inicializar a Lista vazia
     covid19 *novoNO = (covid19*)malloc(sizeof(covid19));
      if(novoNO==NULL)return NULL;
        strcpy(novoNO->pais,p);
        novoNO->casos=c;
        novoNO->recuperados=r;
        novoNO->obitos=o;
        novoNO->casos_ativos=ca;
        
        novoNO->Seguinte =NULL;//NULL
        return  novoNO;

}

covid19 *inserirNoInicio(covid19 *inicio, char p[30], int c, int r, int o, int ca){
    covid19 * novoNO= CriarLista(p,c,r,o,ca); //novoNO = (Lista*)malloc(sizeof(Lista));
    if(novoNO==NULL)
        return inicio;
    if(inicio==NULL)
        return novoNO;
    else
        novoNO->Seguinte =inicio;
        inicio =novoNO;

    return inicio;
}
	
covid19 *inserirNoMeio(covid19 *inicio, char p[30], int c, int r, int o, int ca){
    covid19 *novoNO, *aux;
    covid19 *anterior=NULL;
    novoNO = CriarLista(p,c,r,o,ca);
    if(novoNO==NULL) return inicio;
    if(inicio==NULL) return novoNO;
        aux=inicio;
    while(aux->Seguinte!=NULL && aux->pais<p){
            anterior=aux;
            aux=aux->Seguinte;
            }
    novoNO->Seguinte=aux;
    if(anterior==NULL)
        inicio=novoNO;
    else
        anterior->Seguinte=novoNO;
    return inicio;
}

covid19 *inserirNoFinal(covid19 *inicio, char p[30], int c, int r, int o, int ca){
    covid19 * novoNO= CriarLista(p,c,r,o,ca);
    if(novoNO==NULL)
        return inicio;
    if(inicio==NULL)
        return novoNO;
    covid19 *aux=inicio;
        while(aux->Seguinte!=NULL)
            aux =aux->Seguinte;
        aux->Seguinte =novoNO;
        return inicio;
}	
	
void imprimirLista(covid19 *inicio){
    if(inicio==NULL)
        printf("LISTA VAZIA\n");
    else{
        covid19 *aux=inicio;
     printf("INICIO!-> ");
        while(aux!=NULL){// enquanto existe dado
        printf("%s->| ",aux->pais);//imprimir dado
        printf("|%d->",aux->casos);//imprimir dado
        printf("|%d->",aux->recuperados);//imprimir dado
        printf("|%d->",aux->obitos);//imprimir dado
        printf("%d->| ",aux->casos_ativos);//imprimir dado
            aux=aux->Seguinte;//ir para o nó seguinte
        }
    }
    printf("!NULL\n\n");
}

covid19 *removerNoInicio(covid19 *inicio, char paises[30]){
    covid19 * aux;
    if(inicio==NULL)
        printf("Nao há elementa na lista");
    else{
        aux=inicio;
        paises=aux->pais;
        inicio=aux->Seguinte;
        printf("Foi removido o elemento %s\n",paises);
        free(aux);
    }
    return inicio;//retorna lista atualizada

}	

covid19 *removerNoFinal(covid19 *inicio, char paises[30]){
    covid19 *aux, *anterior;
    if(inicio==NULL)
         printf("Não há elementa na lista");
    else{
        aux=inicio;
        while(aux->Seguinte!=NULL){
            anterior=aux;//receber anterior de ultimo
            aux=aux->Seguinte;//ultimo da lista
        }
        paises=aux->pais;
        anterior->Seguinte=NULL;
        printf("Foi removido o elemento %s\n",paises);
        free(aux);//eliminar ultima da lista
       }
    return inicio;
}

covid19 *removerQualquerElemento(covid19 *inicio){
    covid19 * aux =inicio;
    covid19 * anterior=NULL;
    while(aux!=NULL){
            anterior=aux;
            aux=aux->Seguinte;
            free(anterior);

    }
    printf("foi removido todos os paises da lista\n");
    return NULL;
}

void enviarNoFicheiro(covid19 *inicio){
	
	FILE *fp;
    fp = fopen ("elementos.txt", "w");
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       system("pause");
    }
    if(inicio==NULL)
        fprintf(fp,"LISTA VAZIA\n");
    else{
        covid19 *aux=inicio;
     printf("\n\nTODOS OS NÓS FORAM ENVIADOS PARA O FICHEIRO COM SUCESSO!-> ");
        while(aux!=NULL){// enquanto existe dado
        fprintf(fp,"%s->| ",aux->pais);//escreve no ficheiro
        fprintf(fp,"|%d->",aux->casos);//escreve no ficheiro
        fprintf(fp,"|%d->",aux->recuperados);//escreve no ficheiro
        fprintf(fp,"|%d->",aux->obitos);//escreve no ficheiro
        fprintf(fp,"%d->| ",aux->casos_ativos);//escreve no ficheiro
            aux=aux->Seguinte;//ir para o nó seguinte
        }
    }   
    fclose (fp);
}

void enviarCasosAtivosFicheiro(covid19 *inicio){
	
	FILE *fp;
    fp = fopen ("CasosAtivos.txt", "w"); // Abrir ficheiro para escrita | limpando todos os dados nela contidos
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       system("pause");
    }
    if(inicio==NULL)
        fprintf(fp,"LISTA VAZIA\n");
    else{
        covid19 *aux=inicio;
        while(aux!=NULL){// enquanto existe dado
        fprintf(fp,"%s -> casos ativos:  %d\n",aux->pais,aux->casos_ativos);// Escreve no ficheiro pais com calculos de casos ativos
            aux=aux->Seguinte;//ir para o nó seguinte
        }
    }   
    fclose (fp);
}

void totalCasos(covid19 *inicio){
	int somaCasos = 0;
    if(inicio==NULL)
        printf("LISTA VAZIA -> 0 casos\n");
    else{
        covid19 *aux=inicio;
        while(aux!=NULL){// enquanto existe dado
        somaCasos += aux->casos;
            aux=aux->Seguinte;//ir para o nó seguinte
        }
    }
   printf("\nTOTAL DE CASOS: %d",somaCasos);//imprimir dado

}

void totalMortes(covid19 *inicio){
	int somaObitos = 0;
    if(inicio==NULL)
        printf("LISTA VAZIA -> 0 casos\n");
    else{
        covid19 *aux=inicio;
        while(aux!=NULL){// enquanto existe dado
        somaObitos += aux->obitos;
            aux=aux->Seguinte;//ir para o nó seguinte
        }
    }
   printf("\nTOTAL DE MORTES: %d",somaObitos);//imprimir dado

}

void totalRecuperados(covid19 *inicio){
	int somaRecuperados = 0;
    if(inicio==NULL)
        printf("LISTA VAZIA -> 0 casos\n");
    else{
        covid19 *aux=inicio;
        while(aux!=NULL){// enquanto existe dado
        somaRecuperados += aux->recuperados;
            aux=aux->Seguinte;//ir para o nó seguinte
        }
    }
   printf("\nTOTAL DE RECUPERADOS: %d",somaRecuperados);//imprimir dado
}

covid19* pesquisarElemento(covid19* le, char busca[30]){
   covid19* p;
      for (p=le; p!=NULL; p=p->Seguinte)
	        if (strcmp(p->pais, busca)==0)
			         return p;  
		return NULL; // caso nao elemento
}

 void ordemAscendente(covid19 **p){
  if(*p == NULL || (*p)->Seguinte == NULL) return; //se for nulo(vazio), ou apenas 1 elemento
  covid19 *aux = *p, *t;
  int rcasos; //precisa de espacao suficiente para armazenar o nome

   while(aux != NULL) {
      t = aux->Seguinte;
      while(t != NULL) {
        if(aux->casos > t->casos) { //se vir depois
            rcasos= aux->casos;
            aux->casos= t->casos;
            t->casos= rcasos;
        }
        t = t->Seguinte;
      }
      aux = aux->Seguinte;
    }
}
	
