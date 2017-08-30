void questao2(){
  //creating struct
  struct register_employe{
    char name[35];
    char gender;
    int production;
  };

  struct register_employe employe[4];
  int i = 0, prod_m=0,prod_f=0,j=0,mothafoca=0;
  //permite armazenar uma string independente da quantidade de caracteres
  char *employe_master;
  printf("===========CONTROLE DE FUNCIONARIOS V1.0====================\n");
  while(i<4){
    printf("#################################################################\n");
    printf("Funcionário: ");
    fgets(employe[i].name,sizeof(employe[i].name),stdin);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    printf("Sexo[M/F]: ");
    scanf("%c",&employe[i].gender);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    printf("Produção: ");
    scanf("%d",&employe[i].production);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    printf("\n");
    i++;
  }
  //quantidade de peças produzidas
  while(j<4){
    if(employe[j].gender=='M'){
      prod_m = prod_m + employe[j].production;
    }else{
      prod_f = prod_f + employe[j].production;
    }
    if(employe[j].production > mothafoca){
      mothafoca = employe[j].production;
      employe_master = employe[j].name;
    }
    j++;
  }
  printf("\n*********************RELATÓRIOS************************\n");
  printf("Produção pelo SEXO MASCULINO: %d\n",prod_m);
  printf("Produção pelo SEXO FEMININO: %d\n",prod_f);
  printf("Maior produtor: %s \n",employe_master );
}
