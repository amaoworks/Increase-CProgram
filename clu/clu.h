#ifndef clu_h
#define clu_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_MAX 1000
#define NODE_MAX 500
#define NUM_OPT 20
#define LEN_OPT 6
#define NUM_OPS 200

typedef enum{
	Opd = 0,
	Opt = 1
} Type;

typedef struct{
	int opt;
	double opd;
	Type tp;
} Node;

//括号栈，检测括号是否匹配
char brackets[NUM_OPS];
int bb=0;

int input(Node *in);
int translate(char *p,Node *re,int *len);
double translateopd(char *p,int *len);
int translateopt(char *p,int *len);
int cmp(const char *s,const char *d);
int calculate(Node *n,double *r);
int sclt(int opr,double *opd);
int dclt(int opr,double *opd1,double opd2);
int prid(int c);

#endif
