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
int main(){
	printf("%d\n", fromRomanNumerals("mmxxiv"));
	fflush(stdout);
	char out[128]="";
	int l=toRomanNumerals(2024, out);
	printf("%d: %s\n", l, out);
	for(int i=0;i<=50;i++){
		int l=toRomanNumerals(i, out);
		out[l]=0;
		printf("%d: %d: %s\n", i, l, out);
		fflush(stdout);
	}
}