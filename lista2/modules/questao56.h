void questao56(){
  // system("clear");
  // questao 5
  typedef struct appoiment_book{
    char name[60];
    char address[200];
    char tel[15];
    char status[1];
  } Appoiment_book;

  // questão 6
  int action,i,j,current=0,id;
  char string_search[60];
  Appoiment_book apmt[2];

  // menu
  void drawn(int qtd, char symbol){
    for(j=0;j<qtd;j++){
      printf("%c",symbol);
    }
  }
  // esqueleto do menu
  void menu(){
    drawn(40,'*');
    printf("\n\t\tMENU\n");
    drawn(40,'*');
    printf("\n");
    printf("\tEscolha uma opção abaixo:\n");
    printf("\t1 - Novo registro\n\t2 - Pesquisar registro\n\t3 - Alterar registro\n\t4 - Sair\n");
    drawn(40,'*');
    printf("\n");
  }
  void insert(struct appoiment_book* apm,int current){
    printf("Nome: ");
    scanf(" %60[^\n]",apm[current].name);
    getchar();
    printf("Endereço: ");
    scanf(" %200[^\n]",apm[current].address);
    getchar();
    printf("Telefone: ");
    scanf(" %15[^\n]",apm[current].tel);
    getchar();
    printf("Status: [L - Livre | O - Ocupado | * Apagado] ");
    scanf(" %1[^\n]",apm[current].status);
    getchar();
    printf("\n O ID DO SEU REGISTRO É [%d]\n",current);
  }
  void find(struct appoiment_book* apm,char *search,int current){
    for(i=0;i<current;i++){
      if(strcmp(apm[i].name, search)==0){
        drawn(40,'#');
        printf("\nRESULTADO DA BUSCA\n");
        drawn(40,'#');
        printf("\n");
        printf("Nome: %s\n",apm[i].name);
        printf("Endereço: %s\n",apm[i].address);
        printf("Telefone: %s\n",apm[i].tel);
        printf("Status: %s\n",apm[i].status);
        drawn(40,'#');
        printf("\n");
        break;
      }
    }
  }
  void update(struct appoiment_book* apm,int id){
    printf("Nome: ");
    scanf(" %60[^\n]",apm[id].name);
    getchar();
    printf("Endereço: ");
    scanf(" %200[^\n]",apm[id].address);
    getchar();
    printf("Telefone: ");
    scanf(" %15[^\n]",apm[id].tel);
    getchar();
    printf("Status: [L - Livre | O - Ocupado | * Apagado] ");
    scanf(" %1[^\n]",apm[id].status);
    getchar();
  }
  // funcionalidade de fato
  do{
    menu();
    scanf("%d",&action);
    system("clear");
    if(action == 1){
      if(current < 2){
        insert(apmt, current);
        current += 1;
      }else{
        drawn(40,'#');
        printf("\nPara inserir mais registros, favor, comprar a licença PREMIUM pelo email:\n");
        printf("pagueumboquete@online.com\n");
        drawn(40,'#');
        printf("\n");
      }
    }else if(action == 2){
      printf("Nome a ser pesquisado: ");
      scanf(" %60[^\n]",string_search);
      find(apmt,string_search,current);
    }else if(action == 3){
      printf("ID do usuário a ser atualizado: ");
      scanf("%d",&id);
      update(apmt,id);
      printf("\nDados atualizados!\n");
    }
  }while(action != 4);
}
