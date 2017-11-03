void arrAdd(double val,double *arr){//add to the last pos of array and shift the entire thing -1 in position
  for(int i=0;i<50-1;i++){
    arr[i]=arr[i+1];
  }
  arr[49]=val;
}

