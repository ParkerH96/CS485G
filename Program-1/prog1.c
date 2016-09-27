//CS485G Project 1
//Parker Householder

#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	//If there are not 2 arguments
	if(argc != 2){
		//This program is not being used correctly, print out Usage info
		printf("Usage: ./prog1 FILENAME.\n");
		return(1);
	}

	//If the access of the file is returning -1
	if(access(argv[1], F_OK) == -1){
		//The file DNE so print an error message letting the user know
		printf("%s: No such file or directory.\n", argv[1]);
		return(1); 
	}

	//Create a file	
	FILE *file;
	
	//Open the file with the name being the 2nd argument
	file = fopen(argv[1], "r");

	//Initialize a value (for the array size) and i for for loops
	int value, i;

	//Read in the first integer which is the array size
	fread(&value, 4, 1, file);

	//Create an array with size value
	unsigned int int_array[value];

	//Read in the rest of the integers based on the size of int_array (value)
	for(i = 0; i < value; i += 1){
		fread(&int_array[i], 4, 1, file);
	}

	//close the file
	fclose(file);

	//Imitialize variables
	char command_line[256];
	bool flag = true;

	while(flag){		

	//Gather the whole line of input from the user (the command)
	fgets(command_line, 256, stdin);

	//Initialize token character that gathers the first section of the string until a space or newline
	char *token = strtok(command_line, "  \n");

	//if statement for when token is != 2. This will deal with several error cases 
	// as well as handle the 1 character length commands
	if(strlen(token) != 2){
		//If statement for if the command is greater than 2 characters
		if(strlen(token) > 2){
			//No such command exists so prompt error message
			printf("Unexpected Character.\n");
			return(1);
		}
		//else if for when the command is exactly 1 character
		else if(strlen(token) == 1){
			//Initialize variables to store the element indexes and an output
			int element1, element2, sum;

			//Switch on the first character/only character
			switch(token[0]){
				//Handle the p error case where only p was typed
				case 'p': printf("Invalid p command.\n");
					  return(1);
					  break;

				//Handle the b error case where only b was typed
				case 'b': printf("Invalid b command.\n");
					  return(1);
					  break;

				//Handle the quit case where the user wants to quit
				case 'q': return(0);

				//Handle the command "+"
				case '+':
					//If statement to handle any and all errors resulting in invalid commands of this type 
					if(command_line[2] == '\0' || command_line[4] == '\0' || command_line[2] == ' ' || command_line[2] == '\n' || command_line[4] == ' ' || command_line[4] == '\n'){
						printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
						return(1);
					}
		
					//Gather the first argument for this command
					token = strtok(NULL, " \n");
					element1 = atoi(token);
	
					//Gather the second argument for this command
					token = strtok(NULL, " \n");
					element2 = atoi(token);
					
					//If statement for handling array bounds errors
					if(element1 >= value || element2 >= value){
						printf("Element index is out of range.\n");
						return(1);			
					}
			
					//Perform the addition and then print the resulting
					// value in hex form
					sum = int_array[element1] + int_array[element2];
					printf("%08x \n", sum);
				
					break;
				
				//Handle the command "&"
				case '&':
					//If statement to handle any and all errors resulting in invalid commands of this type 
                                        if(command_line[2] == '\0' || command_line[4] == '\0' || command_line[2] == ' ' || command_line[2] == '\n' || command_line[4] == ' ' || command_line[4] == '\n'){
                                                printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                return(1);
                                        }

					//Gather the first argument for this command
					token = strtok(NULL, " \n");
                                        element1 = atoi(token);

					//Gather the second argument for this command
                                        token = strtok(NULL, " \n");
                                        element2 = atoi(token);
	
					//If statement for handling array bounds errors
					if(element1 >= value || element2 >= value){
                                                printf("Element index is out of range.\n");                  
                                                return(1);
                                        } 
	
					//Perform the bit wise and, then print the resulting
					// value in hex form
                                        sum = int_array[element1] & int_array[element2];
                                        printf("%08x \n", sum);

					break;

				//Handle the command "|"
				case '|':
					//If statement to handle any and all errors resulting in invalid commands of this type 
                                        if(command_line[2] == '\0' || command_line[4] == '\0' || command_line[2] == ' ' || command_line[2] == '\n' || command_line[4] == ' ' || command_line[4] == '\n'){
                                                printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                return(1);
                                        }

					//Gather the first argument for this command
					token = strtok(NULL, " \n");
                                        element1 = atoi(token);

					//Gather the second argument for this command
                                        token = strtok(NULL, " \n");
                                        element2 = atoi(token);
			
					//If statement for handling array bounds errors
                                        if(element1 >= value || element2 >= value){
                                                printf("Element index is out of range.\n");
                                                return(1);
                                        }

					//Perform the bit wise or, then print the resulting
					// value in hex form
                                        sum = int_array[element1] | int_array[element2];
                                        printf("%08x \n", sum);
                                 
				       break;

				//Hand the command "^"
				case '^':
					//If statement to handle any and all errors resulting in invalid commands of this type 
                                        if(command_line[2] == '\0' || command_line[4] == '\0' || command_line[2] == ' ' || command_line[2] == '\n' || command_line[4] == ' ' || command_line[4] == '\n'){
                                                printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                return(1);
                                        }

					//Gather the first argument for this command
					token = strtok(NULL, " \n");
                                        element1 = atoi(token);

					//Gather the second argument for this command
                                        token = strtok(NULL, " \n");
                                        element2 = atoi(token);

					//If statement for handling array bounds errors
                                        if(element1 >= value || element2 >= value){
                                                printf("Element index is out of range.\n");
                                                return(1);
                                        }

					//Perform the bit wise xor then print the resulting
					// value in hex form
                                        sum = int_array[element1] ^ int_array[element2];
                                        printf("%08x \n", sum);
                                        
					break;
				
				//Handle the command ">"	
				case '>':
					//If statement to handle any and all errors resulting in invalid commands of this type 
                                        if(command_line[2] == '\0' || command_line[4] == '\0' || command_line[2] == ' ' || command_line[2] == '\n' || command_line[4] == ' ' || command_line[4] == '\n'){
                                                printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                return(1);
                                        }

					unsigned int o1, e3;
	
					//Gather the first argument for this command
					token = strtok(NULL, " \n");
					element1 = atoi(token);

					//Gather the second argument for this command
                                        token = strtok(NULL, " \n");
                                        e3 = atoi(token);

					//If statement for handling array bounds errors
                                        if(element1 >= value){
                                                printf("Element index is out of range.\n");
                                                return(1);
                                        }
	
					//Perform the shift right then print the resulting
					// value in hex form
					o1 = int_array[element1] >> e3;
                                        printf("%08x \n", o1);

                                        break;
				//Handle the command "<"
				case '<':
				
					//If statement to handle any and all errors resulting in invalid commands of this type 
                                        if(command_line[2] == '\0' || command_line[4] == '\0' || command_line[2] == ' ' || command_line[2] == '\n' || command_line[4] == ' ' || command_line[4] == '\n'){
                                                printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                return(1);
                                        }
					
					//Use unsigned int
					unsigned int output, e2;

					//Gather the first argument for this command
                                        token = strtok(NULL, " \n");
                                        element1 = atoi(token);	
			
					//Gather the second argument for this command
                                        token = strtok(NULL, " \n");
                                        e2 = atoi(token);

					//If statement for handling array bound errors
                                        if(element1 >= value){
                                                printf("Element index is out of range.\n");
                                                return(1);
                                        }

					//Perform the shift left then print the resulting
					// value in hex form
                                        output = int_array[element1] << e2;
                                        printf("%08x \n", output);
                                        
					break;
				
				//Handle anything else. In other words this would be include
				// any unexpected characters
				default:  printf("Unexpected Character.\n");
					  return(0);
			}
		}
	}
	//Else if for when the command is exactly two characters. This will deal primarily
	// with correct commands starting with p and b but will also deal with minor error
	// cases such as invalid p and b commands as well unrecognized commands
	else if(strlen(token) == 2){
		//Initialize an int to store the element index passed through
        	int e1;

		//Switch on the first character in the command
                switch(token[0]){	
			//Handle the commands that begin with p
            		case 'p':
				//Switch on the second character in the command
                        	switch(token[1]){
					//Handle the 'pd' command
                                	case 'd':
						//If statement for null, space, and newline arguments
						if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
							printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
							return(1);
						}

						//Gather the argument for this command
                                        	token = strtok(NULL, " \n");
                                                e1 = atoi(token);

						//If statement for handling bounds error
                                                if(e1 >= value){
                                                	printf("Element index is out of range.\n");
                                                       	return(1);
                                                }

						//Print the given element in decimal form
                                                printf("%d \n", int_array[e1]);
                                               
						break;
					
					//Handle the 'px' command
                                        case 'x':
						//If statement for null, space, and newline arguments
                                                if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
                                                        printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
							return(1);
                                                }

						//Gather the argument for this command
                                                token = strtok(NULL, " \n");
                                                e1 = atoi(token);

						//If statement for handling bounds error
                                                if(e1 >= value){
                                                	printf("Element index is out of range.\n");
                                                        return(1);
                                                }

						//Print the given element in hexadecimal form
                                                printf("%x \n", int_array[e1]);

                                                break;
   					
					//Handle the 'po' command
                                        case 'o':
						//If statement for null, space, and newline arguments
                                                if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
                                                        printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
							return(1);
                                                }
	
						//Gather the argument for this command
                                                token = strtok(NULL, " \n");
                                                e1 = atoi(token);
						
						//If statement for handling bounds error
                                                if(e1 >= value){
                                                	printf("Element index is out of range.\n");
                                                        return(1);
                                                }

						//Print the given element in octal form
                                                printf("%o \n", int_array[e1]);
			
                                                break;	
					
					//Default case for handling any other second character that follows a p
                                        default: 
						//There are no other p commands therefore it is invalid
						printf("Invalid p command.\n");
						return(1); 
                                }

                                break;

			//Handle the commands that begin with b
                        case 'b':
				//Switch on the second character in the command
				switch(token[1]){
					
					//Handle the 'b0' command
					case '0':
						//If statement for null, space, and newline arguments
                                                if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
                                                        printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
							return(1);
                                                }

						//Gather the argument for this command
						token = strtok(NULL, " \n");
						e1 = atoi(token);
						
						//If statament to handle bounds error
						if(e1 >= value){
							printf("Element index is out of range.\n");
							return(1);
						}	
					
						//Print the first 2 bytes of the element in hex form
						printf("%02x \n", (int_array[e1] >> 0) & 0xff);
						break;			
	
					//Handle the 'b1' command
					case '1': 
						//If statement for null, space, and newline arguments
                                                if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
                                                        printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                        return(1);
                                                }

						//Gather the argument for this command
						token = strtok(NULL, " \n");
                                                e1 = atoi(token);

						//If statement to handle bounds error
                                                if(e1 >= value){
                                                        printf("Element index is out of range.\n");
                                                        return(1);
                                                }

						//Print the second 2 bytes of the element in hex form
                                                printf("%02x \n", (int_array[e1] >> 8) & 0xff);
                                                break;
			
					//Handle the 'b2' command
					case '2':
						//If statement for null, space, and newline arguments
                                                if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
                                                        printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                        return(1);
                                                }

						//Gather the argument for this command
						token = strtok(NULL, " \n");
                                                e1 = atoi(token);

						//If statement to handle bounds error
                                                if(e1 >= value){
                                                        printf("Element index is out of range.\n");
                                                        return(1);
                                                }

						//Print the third 2 bytes of the element in hex form
                                                printf("%02x \n", (int_array[e1] >> 16) & 0xff);
                                                break;
	
					//Handle the 'b3' command
					case '3': 
						//If statement for null, space, and newline arguments
                                                if(command_line[3] == ' ' || command_line[3] == '\0' || command_line[3] == '\n'){
                                                        printf("Invalid command. Not enough arguments were given or were incorrectly given.\n");
                                                        return(1);
                                                }

						//Gather the argument for this command
						token = strtok(NULL, " \n");
                                                e1 = atoi(token);

						//If statement to handle counds error
                                                if(e1 >= value){
                                                        printf("Element index is out of range.\n");
                                                        return(1);
                                                }

						//Print the last 2 bytes of the element in hex form
                                                printf("%02x \n", ((int_array[e1] >> 24) & 0xff));
                                                break;

					//default case to handle any other b commands
					default: 	
						//there are no other b commands therefore it is invalid
						printf("Invalid b command.\n");
						return(1);
				}
				break;
			//Handle any commands (of characters in length) that aren't p or b commands
                        default: printf("Unrecognized command.\n"); //No other commands so it is invalid
				 return(1);
                }
        }
	

	}

	return(0);
}
