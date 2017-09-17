int questao2(){
  int x[5],y[5],w[5],scanned,i=0,j=0,maior=0,menor;

  //reading list
  do{
    printf("Insira um número: ");
    scanf("%d",&x[i]);
    i++;
  }while(i<5);

  //getting numbers between 10..40
  for(i = 0;i < 5;i++){
    if(x[i] > 10 && x[i] < 40){
      y[j] = x[i];
    }else{
      y[j] = -1;
    }
    j++;
  }

  //printing Y elements
  printf("\nNumeros entre 10 e 40\n");
  for(i = 0;i < 5;i++){
    if(y[i]!=-1){
      printf("[%d]\n",y[i]);
    }
  }

  //elements of X on pair position
  j = 0;
  for(i = 0; i < 5;i++){
    if(i % 2 == 0 && i != 0){
      w[j] = x[i];
    }else{
      w[j] = -1;
    }
    j++;
  }

  //print elements on pair position
  printf("\nElementos em posições pares. Vetor W\n");
  for(i = 0;i < 5;i++){
    if(w[i] != -1){
      printf("%d\n",w[i]);
    }
  }

  //Higher and lower number from X
  printf("\nMaior e menor elemento do Vetor X");
  menor = x[0];
  for(i = 0;i < 5;i++){
    if(x[i] > maior){
      maior = x[i];
    }
    if(x[i] < menor){
      menor = x[i];
    }
  }
  printf("\no maior numero é %d",maior);
  printf("\no menor numero é %d\n",menor);
}
