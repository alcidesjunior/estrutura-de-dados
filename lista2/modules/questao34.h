void questao34(){
  // questão 3
  struct student{
    char name[60];
    float score[3];
  };
  int i;
  struct student students[35];
  // questão 4
  printf("CADASTRO DE ESTUDANTES=======================================\n");
  for(i = 0;i < 35; i++){
    printf("#%d - Nome do %dº aluno: ",i+1,i+1);
    fgets(students[i].name,sizeof(students[i].name),stdin);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    printf("Nota 1: ");
    scanf("%f",&students[i].score[0]);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    printf("Nota 2: ");
    scanf("%f",&students[i].score[1]);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
    printf("Nota 3: ");
    scanf("%f",&students[i].score[2]);
    fflush(stdin); //usado no para limpar buffer do teclado no Windows
    __fpurge(stdin);//usado para limpar buffer do teclado no Linux <3
  }
  printf("LISTA DE ESTUDANTES MATRICULADOS===============================\n");
  for(i=0; i < 35; i++){
    printf("[#%d] - %s\n",i+1,students[i].name);
    printf("[Nota 1] %.2f\n",students[i].score[0]);
    printf("[Nota 2] %.2f\n",students[i].score[1]);
    printf("[Nota 3] %.2f\n",students[i].score[2]);
  }
}
