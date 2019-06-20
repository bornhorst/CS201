/*
Ryan Bornhorst
HW1
CS201
*/

#include <stdio.h>
#include "hw1given.h"
#include <string.h>

int main(int argc, char* argv[])
{
/*initialize variables*/
char** array = NULL;
int array2[200];
int i,j;
char file[30];
int num_runs = 0;
char num[6];
int row[1];
int column[1];
int curr_row = 0,curr_col = 0;
int count = 0,count2 = 0,random = 0;
int check_row = 0;
double prob = 0;

/*prompt user*/
printf("Type the name of the text file to load with the .txt extention:" 
	"(Ex: plinko1.txt,plinko2.txt,plinko3.txt): ");
scanf("%s",file);
printf("How man times would you like to run the simulation? ");
scanf("%i",&num_runs);

/*create file and open a txt file containing board*/
FILE *ptr_file = NULL;

ptr_file = fopen(file,"r");

/*only open the file if typed correctly*/
if(ptr_file == NULL){
	printf("\nYou typed the name of the file incorrectly. Rerun the program.\n");
	return -1;
}
/*scan first row of array and set rows and columns*/
for(i=0;i<7;i++){
	fscanf(ptr_file,"%c",&num[i]);
}

/*set columns*/	
for(i=0;i<1;i++){
	column[i] = atoi(&num[i]);
}
/*set rows*/
for(i=0;i<1;i++){
	row[i] = atoi(&num[i+3]);
}
/*close file*/
fclose(ptr_file);

/*check number of rows*/
if(row[0] <10)
	check_row = 5;
else
	check_row = 7;

/*reopen file*/
ptr_file = fopen(file,"r");

/*store the columns/rows of the array into num*/
for(i=0;i<check_row;i++)
	fscanf(ptr_file,"%c",&num[i]);

/*dynamically allocate array for game board using rows/columns*/
array = (char**)malloc(sizeof(char*)*(row[0]+1));
for(i=0;i<(row[0]+1);i++){
	array[i]=(char*)malloc(sizeof(char*)*(column[0]+1));
}
/*scan file and allocate characters to dynamic array*/
for(i=0;i<(row[0]+1);i++){
	for(j=0;j<(column[0]+1);j++){
		fscanf(ptr_file,"%c",&array[i][j]);
	}
}
/*close file*/
fclose(ptr_file);
	
/*print the game board*/
printf("\nThis is the game board for %s: \n\n",file);
for(i=0;i<(row[0]+1);i++){
	for(j=0;j<(column[0]+1);j++){
		printf("%c",array[i][j]);
	}
}
printf("\n");

/*initialize column array to zeros*/
for(i=0;i<(column[0]+1);i++)
	array2[i] = 0;

/*Initialize Random Int*/
InitRandom();
/*Run the specified number of times*/
while(count2 != num_runs){
/*Set Starting Point Within the Array*/
curr_row = 0;
curr_col = GetRandom(1,(column[0]-2));
/*run until we get to the last row*/
	while((curr_row != (row[0]-1))){
	/*move down until an X is encountered*/
		if((array[curr_row+1][curr_col]) != 'X'){
			curr_row = curr_row+1;
		}/*if there is an X but both sides are free. randomly pick a side*/
		else if(((array[curr_row+1][curr_col-1])!='X')
			&&((array[curr_row+1][curr_col+1])!='X')){
				random = GetRandom(1,2);
				if(random == 1){/*go left*/
					curr_row = curr_row+1;
					curr_col = curr_col-1;
				}
				else if(random == 2){/*go right*/
					curr_row = curr_row+1;
					curr_col = curr_col+1;
				}
		}/*X on the right, go left*/
		else if(((array[curr_row+1][curr_col-1])!='X')
			&&((array[curr_row+1][curr_col+1]) =='X')){
				curr_row = curr_row+1;
				curr_col = curr_col-1;
		}
		else{/*X on the left, go right*/
			curr_row = curr_row+1;
			curr_col = curr_col+1;
		}
		count = count + 1;
	}
	/*increment a counter if the plinko landed there*/
	array2[curr_col] = array2[curr_col]+1;
	count2 = count2+1;
}

/*print out the results of playing the game x number of times*/
printf("\nThese are the results after %i simulations: \n\n",num_runs);
for(i=0;i<(column[0]);i++){
	prob = (array2[i])/(float)num_runs;
	printf("Column: %3i    Ratio: %5i/%i     " 
	"Probability: %.3f ",i+1,array2[i],num_runs,prob);
	printf("\n");
}

/*free 2d array*/
for(i=0;i<(row[0]+1);i++){
	free(array[i]);
}
free(array);

return 0;

}

