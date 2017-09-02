void questao56(){
  // system("clear");
  // questao 5
  struct appoiment_book{
    char name[60];
    char address[200];
    char tel[15];
    char status[1];
  };

  // questão 6
  int action,i;
  struct appoiment_book apmt[2];
  char *searchtable;
  void menu(){
    printf("============MENU=============\n");
    printf("0 - para inserir registros\n");
    printf("1 - para realizar pesquisa via nome\n");
    printf("2 - para atualizar um registro\n");
    printf("3 - para voltar\n");
    printf("4 - para sair do programa\n");
    printf("=============================\n");
    scanf("%d",&action);
    system("clear");
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <
  }
  void insert(){
    for (i = 0; i < 2; i++) {
      printf("Nome: ");
      fgets(apmt[i].name,sizeof(apmt[i].name),stdin);
      fflush(stdin); //usado no para limpar buffer do teclado no Windows
      __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
      printf("Endereço: ");
      fgets(apmt[i].address,sizeof(apmt[i].address),stdin);
      fflush(stdin); //usado no para limpar buffer do teclado no Windows
      __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
      printf("Telefone: ");
      fgets(apmt[i].tel,sizeof(apmt[i].tel),stdin);
      fflush(stdin); //usado no para limpar buffer do teclado no Windows
      __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
      printf("Status: ");
      fgets(apmt[i].name,sizeof(apmt[i].name),stdin);
      fflush(stdin); //usado no para limpar buffer do teclado no Windows
      __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    }
  }
  void search(){
    printf("Insira o nome a ser pesquisado: ");
    scanf("%s",searchtable);
    // fgets(searchtable,sizeof(searchtable),stdin);
    fflush(stdin);
    __fpurge(stdin);
    for(i = 0;i < 2;i++){
      if(strcmp(apmt[i].name,searchtable) == 0){
        printf("%s\n",apmt[i].name);
        printf("%s\n",apmt[i].address);
        printf("%s\n",apmt[i].tel);
        printf("%s\n",apmt[i].status);
      }
    }
  }
  void update(){
    printf("atualizando");
  }
  do{
    menu();
    switch (action) {
      case 0:
        insert(); break;
      case 1:
        search(); break;
      case 2:
        update(); break;
      case 3:
        menu(); break;
    }
  }while(action != 4);
}
