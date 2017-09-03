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
  int action,i,index=0;
  char *string_search;
  Appoiment_book apmt[2];

  // menu
  void drawn(int qtd, char symbol){
    for(i=0;i<qtd;i++){
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
  void insert(struct appoiment_book* apm,int index){
    printf("Nome: ");
    fgets(apm[index].name,sizeof(apm[index].name),stdin);
    __fpurge(stdin);
    getchar();
    printf("Endereço: ");
    fgets(apm[index].address,sizeof(apm[index].address),stdin);
    __fpurge(stdin);
    getchar();
    printf("Telefone: ");
    fgets(apm[index].tel,sizeof(apm[index].tel),stdin);
    __fpurge(stdin);
    getchar();
    printf("Status: [L - Livre | O - Ocupado | * Apagado] ");
    fgets(apm[index].status,sizeof(apm[index].status),stdin);
    __fpurge(stdin);
    getchar();
    printf("\n%s",apm[index].name);
  }
  void find(struct appoiment_book* apm,char *search,int index){
    // for(i=0;i<=index;i++){
      // if(strcmp(apmt[i].name, search)==0){
        printf("%s",apm[0].name);//apm[i].name);
      // }
    // }
  }
  // funcionalidade de fato
  do{
    menu();
    scanf("%d",&action);
    system("clear");
    if(action == 1){
      if(index < 2){
        insert(apmt, index);
        index += 1;
      }else{
        drawn(40,'#');
        printf("Para inserir mais registros, favor, comprar a licença PREMIUM pelo email:\n");
        printf("chupaquedeuva@softwares.com\n");
        drawn(40,'#');
      }
    }else if(action == 2){
      printf("Nome a ser pesquisado:(pressione enter para sair)");
      scanf("%s",string_search);
      // fgets(string_search,sizeof(string_search),stdin);
      // __fpurge(stdin);

      find(apmt,string_search,index);
    }else if(action == 3){

    }
  }while(action != 4);
}
