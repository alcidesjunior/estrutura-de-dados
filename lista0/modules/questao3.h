int questao3(){
  int a[5],b[5],c[10],i,search;

  for(i=0;i<5;i++){
    printf("Entre com um valor para A[%d]\n",i);
    scanf("%d",&a[i]);
    printf("Entre com um valor para B[%d]\n",i);
    scanf("%d",&b[i]);
  }
  for(i = 0;i < 5; i++){
    c[i*2]=a[i];
    c[i*2+1]=b[i];
  }
  for(i = 0;i < 10; i++){
    printf("%d\n",c[i]);
  }
  printf("Pesquise um valor: ");
  scanf("%d",&search);
  for(i = 0;i < 10; i++){
    if(c[i] == search){
      printf("Valor %d encontrado na posição C[%d]",search,i);
    }
  }
}
