#ifndef SDF_STRING_H
#define SDF_STRING_H
#include "base.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define CLSTRING_INIT (char *)malloc(sizeof(char *))
//初始化字符串
SDF_STRING *newStr(){
    SDF_STRING *stringVariable = NULL;
    stringVariable -> value = CLSTRING_INIT;
    stringVariable -> head = &stringVariable->value[0];
    stringVariable -> end = stringVariable->head;
    stringVariable -> iterator = CLSTRING_INIT;
    stringVariable -> size = 0;
    return stringVariable;
}

//释放字符串
SDF_STRING *delStr(SDF_STRING *stringVariable){
    free(stringVariable -> value);
    free(stringVariable -> iterator);
    stringVariable -> value = NULL;
    stringVariable -> head = NULL;
    stringVariable -> end = NULL;
    stringVariable->iterator = NULL;
    return stringVariable;
}

SDF_STRING* clrStr(SDF_STRING *stringVariable){
    for(int i = 0; i < strlen(stringVariable -> value); i++){
		stringVariable -> value[i] = '\0';
	}
	free(stringVariable -> value);
	stringVariable -> value = NULL;
	stringVariable -> value = CLSTRING_INIT;
	return stringVariable;
}

SDF_STRING* strCopy(SDF_STRING *targetStringVariable,SDF_STRING *stringVariable){
    targetStringVariable -> value = strcpy(targetStringVariable -> value,stringVariable -> value);
    return targetStringVariable;
}

SDF_STRING* CstrCopy(SDF_STRING *stringVariable,char *CstringVariable){
    stringVariable -> value = strcpy(stringVariable -> value, CstringVariable);
    return stringVariable;
}

char *getStrValue(SDF_STRING *stringVariable){
    char *buffer = CLSTRING_INIT;
    buffer = strcpy(buffer,stringVariable -> value);
    return buffer;
}

SDF_STRING* addCend(SDF_STRING *stringVariable , char *CstringVariable){
	stringVariable -> value = strcat(stringVariable -> value , CstringVariable);
	return stringVariable;
}

SDF_STRING* addCbegin(SDF_STRING* stringVariable , char *CstringVariable){
	stringVariable -> value = strcat(CstringVariable , stringVariable -> value);
	return stringVariable;
}

SDF_STRING* addEnd(SDF_STRING *targetStringVariable, SDF_STRING *stringVariable){
    targetStringVariable -> value = strcat(targetStringVariable -> value, stringVariable -> value);
    return targetStringVariable;
}

SDF_STRING* addBegin(SDF_STRING *targetStringVariable, SDF_STRING *stringVariable){
    targetStringVariable -> value = strcat(stringVariable -> value,targetStringVariable -> value);
    return targetStringVariable;
}

SDF_STRING* insCstr(SDF_STRING *stringVariable,int index,char *insertStringVariable){
    int rightStringLength = (strlen(stringVariable -> value) - index) + 1;
	int leftStringLength = (strlen(stringVariable -> value) - rightStringLength) + 1;
	char leftString[leftStringLength];
	char rightString[rightStringLength];
	char *buffer = CLSTRING_INIT;
	for(int i = 0; i < index; i++){
		leftString[i] = stringVariable -> value[i];
	}
    for(int i = index; i < strlen(stringVariable -> value); i++){
		rightString[i] = stringVariable -> value[i];
	}
	stringVariable = clrStr(stringVariable);
	buffer = (char *)strcat(leftString , insertStringVariable);
	stringVariable -> value = strcat(buffer , rightString);
	return stringVariable;
}
SDF_STRING* insStr(SDF_STRING *stringVariable,int index,SDF_STRING *insertStringVariable){
    int rightStringLength = (strlen(stringVariable -> value) - index) + 1;
	int leftStringLength = (strlen(stringVariable -> value) - rightStringLength) + 1;
	char leftString[leftStringLength];
	char rightString[rightStringLength];
	char *buffer = CLSTRING_INIT;
	for(int i = 0; i < index; i++){
		leftString[i] = stringVariable -> value[i];
	}
    for(int i = index; i < strlen(stringVariable -> value); i++){
		rightString[i] = stringVariable -> value[i];
	}
	stringVariable = clrStr(stringVariable);
	buffer = (char *)strcat(leftString , insertStringVariable -> value);
	stringVariable -> value = strcat(buffer , rightString);
	return stringVariable;
}

SDF_STRING* delIndexStr(SDF_STRING *stringVariable, int index){
    int i = 0;
	for(i = index + 1; i <= strlen(stringVariable -> value); i++){
		stringVariable -> value[i-1] = stringVariable -> value[i];
	}
	stringVariable -> value[i] = '\0';
	return stringVariable;
}

SDF_STRING* delAreaStr(SDF_STRING *stringVariable , int startIndex, int endIndex){
    char left_string[startIndex+1],right_string[endIndex+1];
	for(int i = 0; i < startIndex; i++){
		left_string[i] = stringVariable -> value[i];
	}
	int count = 0;
	for(int i = endIndex; i < strlen(stringVariable -> value); i++){
		right_string[count] = stringVariable -> value[i];
		count++;
	}
	stringVariable -> value = strcat(left_string , right_string);
	return stringVariable;
}

SDF_STRING* getSubStr(SDF_STRING *stringVariable,int startIndex,int endIndex){
	char buffer[(endIndex - startIndex)+1];
	int count = 0;
	for(int i = startIndex; i <= endIndex; i++){
		buffer[count] = stringVariable -> value[i];
		count++;
	}
	stringVariable -> value = &buffer[0];
	return stringVariable;
}

SDF_STRING* intToStr(int numberVariable){
	SDF_STRING *buffer = newStr();
	sprintf((buffer -> value), "%d",  numberVariable);
	return buffer;
}

SDF_STRING *doubleToStr(double numberVariable){
	SDF_STRING *buffer = newStr();
	sprintf((buffer -> value), "%lf",  numberVariable);
	return buffer;
}

long strToInt(SDF_STRING *stringVariable){
	return atol(stringVariable -> value);
}

double strToDouble(SDF_STRING *stringVariable){
	return atof(stringVariable -> value);
}

int compStr(SDF_STRING *firstStringVariable,SDF_STRING *secodeStringVariable){
	if(!strcmp(firstStringVariable -> value, secodeStringVariable -> value)){
		return $true;
	}
	return $false;
}

int compCstr(SDF_STRING *firstStringVariable,char *secodeStringVariable){
	if(!strcmp(firstStringVariable -> value, secodeStringVariable)){
		return $true;
	}
	return $false;
}

int sizeofStr(SDF_STRING *stringVariable){
	if(stringVariable -> value == NULL){
		return -1;
	}
	return strlen(stringVariable -> value);
}

int distance(SDF_STRING *stringVariable,SDF_STRING *firstString,SDF_STRING *secondString){

}

int distancecs(SDF_STRING *stringVariable,char *firstString,SDF_STRING *secondString){

}

int distancesc(SDF_STRING *stringVariable,SDF_STRING *firstString,char *secondString){

}

int findCstr(SDF_STRING *stringVariable,char *findString){

}

int findStr(SDF_STRING *stringVariable,SDF_STRING *findString){
	
}

int isStrNull(SDF_STRING *stringVariable){
	if (stringVariable -> value == NULL){
		return -1;
	}
	if(strlen(stringVariable -> value = 0)){
		return $true;
	}
	return strlen(stringVariable -> value);
}
#endif