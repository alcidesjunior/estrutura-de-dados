int questao1(){
  int number[5],ordered[5], i=0,j,k, scanned = 0,current_number, pair = 0, odd = 0,odd_greater_fifty=0;
  float average=0;
  do{
    printf("Digite um numero:\n");
    scanf("%d", &scanned);
    //check if number less 256
    if(scanned < 256){
      number[i] = scanned;
      //check if is pair or odd
      if(scanned%2 == 0){
        pair++;
      }else{
        odd ++;
        //if number is greater than 50, generate a average of odd
        if(scanned>50){
          average += scanned;
          odd_greater_fifty++;
        }
      }
      i = ++i;
    }
  }while(i<5);
  //sort desc numbers
  for(i=0;i<5;i++){
    for(j = i + 1;j < 5;j++){
      if(number[i] < number[j]){
        current_number = number[i];
        number[i] = number[j];
        number[j] = current_number;
      }
    }
  }
  //print number sortead by DESC
  printf("=========DESC ORDER===========\n");
  for(k=0;k<5;k++){
    printf("%d \n",number[k]);
  }
  printf("Pair: %d\n",pair);
  printf("Odd: %d\n",odd);
  printf("Average of odds greater than 50: %f\n",(average/odd_greater_fifty));
}
