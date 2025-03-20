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
// get the roman numerals value of a char
static int rn_val(char c){
	switch(c){
		// for each char, return its value, numerals can be in any case
		case 'M':
		case 'm':
			return 1000;
		case 'D':
		case 'd':
			return 500;
		case 'C':
		case 'c':
			return 100;
		case 'L':
		case 'l':
			return 50;
		case 'X':
		case 'x':
			return 10;
		case 'V':
		case 'v':
			return 5;
		case 'I':
		case 'i':
			return 1;
		// not a roman numeral character, return -1
		default:
			return -1;
	}
}

// get the int value of a str
int fromRomanNumerals(char* rn){
	// return value
	int ret=0;
	int sign=0;
	//catch negative sign
	if(*rn=='-'){
		sign=1;
		rn++;
	}
	char* bgn=rn;
	char* end=rn;
	// get to end of rn string
	while(*end!=0){
		end++;
	}
	end--;
	int highest=0;
	//go through the string- backwards
	for(char *c=end;c>=bgn;c--){
		if(rn_val(*c)>=highest){
			//normal value, set highest and add to running total ret
			highest=rn_val(*c);
			ret+=rn_val(*c);
		}else{
			//lower than highest, subtract from running total
			ret-=rn_val(*c);
		}
	}
	
	// return final value;
	if(sign)
		return -ret;
	else
		return ret;
}

int toRomanNumerals(int rn, char* orn){
	// return value, holds the number of characters that are needed to hold the roman numeral value
	int ret=0;
	if(rn<0)
	{
		ret++;
		if(orn){
			*orn++='-';
		}
		rn=-rn;
	}

	// possible charcters in roman numerals
	const char *cs="MDCLXVI";
	// charcaters which can create roman numerals structures like iv, ix, il, lx, etc
	const char *cs2="IXCM";
	// integer values of above characters
	const int add[]={1000, 500, 100, 50, 10, 5, 1};
	const int add2[]={1, 10, 100, 1000};
	// convert the integer to string of roman numerals
	for(int i=0;i<sizeof(add)/sizeof(int);i++){
		// if rn is greater than the value of the current  charcater, then add as many of those characters as can fit into that space
		// ex. if rn equals 34 and cs[i] equals 'X'(or 10), than 3 X's can fit into 34. 30 is then subtracted from 34, leaving 4, ready for the next loop
		if(rn>=add[i]){
			int k=rn/add[i];
			for(int j=0;j<k;j++){
				// if orn is not null, then add the next charcter to the user supplied string
				if(orn){
					*orn++=cs[i];
				}
				// increment the return value so the user knows how much string space is needed to store thr roman numerals
				ret++;
			}
			// subtract the value added to the roman numerals string and return
			rn-=k*add[i];
		}
		// look for any possible roman numeral structures of the sort 'IV'
		//start by going through the prefixes to the structure, lowest first
		for(int j=0;j<sizeof(add2)/sizeof(int);j++){
			// if add2[i] would create a negative value(We don't want that!) then ignore that value
			if(add2[j]>rn)
				continue;
			// otherwise, if there is space for this particular construction, then do it
			else if(rn>=add[i]-add2[j]){
				// if orn is not null, then push the prefix onto it, followed by the current character value in add
				if(orn){
					*orn++=cs2[j];
					*orn++=cs[i];
				}
				// increment the length of the string
				ret+=2;
				// cut off the value stored
				rn-=add[i]-add2[j];
				// increment i
				i++;
				//get out of the loop, because we have already found the possible construction
				break;
			}
		}
	}
	// return the length of the string
	return ret;
}
