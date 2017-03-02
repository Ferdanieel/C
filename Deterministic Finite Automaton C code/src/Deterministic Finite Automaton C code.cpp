//============================================================================
// Name        : DFA- C code.cpp
// Author      : Daniel Fernandez
// Version     : v1
// Copyright   : Free-Software License
// Description : Deterministic Finite Automaton
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

enum STATE{START, N, NA, NAN, NANO};
enum STATE state=START;

enum STATE Start(int c);
enum STATE n(int c);
enum STATE Na(int c);
enum STATE Nan(int c);
enum STATE Nano(int c);

// States = {START, N, NA, NAN, NANO}
// Input Alphabet = {n,a,o}
// Initial State = {START}
// Final State = {NANO}

// Transitions' Table
//
//	&		n	  	a		o
//	START	N		START	START
//	N		N		NA		START
//	NA		NAN		START	START
//	NAN		N		START	NANO
//	NANO	START	START	START

// Program function: Recognize the word "nano".
// User Manual:
// 1. Write a word and press ENTER. (it could contain the word "nano" or not)
// 2. Press SPACE to scroll through the string and verify whether it contains the word "nano",
//    if it is, then the program will display "String found".
//
//
//

int main(void) {
	int c;
	while((c=getchar()) != ' '){
		if(state==START){
			state=Start(c);
		}
		else if(state==N){
			state=n(c);
		}
		else if(state==NA){
			state=Na(c);
		}
		else if(state==NAN){
			state=Nan(c);
		}
		else if(state==NANO){
			cout<< "String found";
			state=Start(c);
		}
	}
	return EXIT_SUCCESS;
}

enum STATE Start(int c){
	enum STATE state;
	if((char)c=='n') state=N;
	else state=START;
	return state;
}

enum STATE n(int c){
	enum STATE state=N;
	if((char)c=='n') state=N;
	else if ((char)c=='a') state=NA;
	else state=START;
	return state;
}

enum STATE Na(int c){
	enum STATE state=NA;
	if((char)c=='n') state=NAN;
	else state=START;
	return state;
}

enum STATE Nan(int c){
	enum STATE state=NAN;
	if((char)c=='o') state=NANO;
	else if ((char)c=='n') state=N;
	else if ((char)c=='a') state=NA;
	return state;
}

enum STATE Nano(int c){
	enum STATE state=START;
	return state;
}
