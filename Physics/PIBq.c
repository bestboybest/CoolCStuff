#include <stdio.h>

//Question: Find and order (nx,ny,nz) in ascending order of their energies such that sum of squares of quantum numbers <= 60 and find degeneracy of energy state for which sum of squares of quantum numbers = 54.

int count = 0;
int energylevels[60][3];

void main(){

 //Theoretically, since nx^2+ny^2 + nz^2 = 60, max value of nx^2 = 60, nx = root60 = 7.smtg, so max value of nx = ny = nz = 7
 for (int nx = 1; nx < 8; nx++){
  for (int ny = 1; ny < 8; ny++){
    for (int nz = 1; nz < 8; nz++){
      if(nx*nx + ny*ny + nz*nz <= 60){
        energylevels[count][0] = nx;
        energylevels[count][1] = ny;
        energylevels[count][2] = nz;
        count++;
      }
    }
  }
 }

 //bubble sort to sort the energy levels
 int temp;
 for (int i = count - 1; i > 0; i--){
    for (int j = 0; j < i; j++){
        if(energylevels[j+1][0]*energylevels[j+1][0]+energylevels[j+1][1]*energylevels[j+1][1]+energylevels[j+1][2]*energylevels[j+1][2] < energylevels[j][0]*energylevels[j][0] + energylevels[j][1]*energylevels[j][1]+energylevels[j][2]*energylevels[j][2]){
            temp = energylevels[j+1][0];
            energylevels[j+1][0] = energylevels[j][0];
            energylevels[j][0] = temp;
            temp = energylevels[j+1][1];
            energylevels[j+1][1] = energylevels[j][1];
            energylevels[j][1] = temp;
            temp = energylevels[j+1][2];
            energylevels[j+1][2] = energylevels[j][2];
            energylevels[j][2] = temp;
        }
    }
 }

 //print the nx ny nz values in order in form (nx ny nz) - nx^2 + ny^2 + nz^2 and check degeneracy of 54 while looping
  int degen = 0;
  for (int i = 0; i < count; i++){
    printf("\n(%d, %d, %d) - %d\n", energylevels[i][0], energylevels[i][1], energylevels[i][2], energylevels[i][0]*energylevels[i][0]+energylevels[i][1]*energylevels[i][1]+energylevels[i][2]*energylevels[i][2]);
    if(energylevels[i][0]*energylevels[i][0]+energylevels[i][1]*energylevels[i][1]+energylevels[i][2]*energylevels[i][2] == 54){
        degen++;
    }
}
 printf("\nDegeneracy of energy level corresponding to nx^2 + ny^2 + nz^2 = 54 is %d\n", degen);

}