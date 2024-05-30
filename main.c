/*
This file is part of RomanNumerals.

RomanNumerals is free software: you can redistribute it and/or modify it under the terms
 of the GNU General Public License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

RomanNumerals is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with RomanNumerals. 
If not, see <https://www.gnu.org/licenses/>.*/
#include "RomanNumerals.h"
#include <stdio.h>
#include <stdlib.h>
// show usage info
void showHelp(char *name){
	printf("Usage:\n");
	printf("  To roman numerals:\n\t%s -t 2020\n", name);
	printf("  From roman numerals:\n\t%s -f MMXX\n", name);
}
// main function entry
int main(int argn, char** argv){
	// make sure syntax is followed
	if(argn>=3&&argv[1][0]=='-'){
		switch(argv[1][1]){
			case 't':{
				// get the integer value of the argument
				int l=atoi(argv[2]);
				// get the length of string necessary to store the roman  numeral
				int n=toRomanNumerals(l, NULL);
				// allocate storage for the string (+1 for trailing nul)
				char *c=malloc(n+1);
				// store the roman numerals in c
				toRomanNumerals(l, c);
				// trail with nul
				c[n]=0;
				// print result
				printf("%s\n", c);
				//de-allocate storage
				free(c);
				break;
			}
			case 'f':
				//generate integer from roman numerals and print it
				printf("%d\n", fromRomanNumerals(argv[2]));
				break;
			default:
				// invalid option, show help
				showHelp(*argv);
				return -1;
		}
	}else{
		// not enough arguments, show help
		showHelp(*argv);
		return -2;
	}
	return 0;
}