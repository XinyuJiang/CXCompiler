#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXMAX 100
#define WDMAX 50
const float EPSINON = 0.0000001;

enum object{constant, variable, prozedure};
enum object_t{int_t, bool_t, double_t};
struct idtable{
	char name[WDMAX+1];
	enum object kind;
	enum object_t type;
	double value;
	int addr;//存放标识符在数据栈中的相对地址
};
struct idtable table[TXMAX+1];
int tx = 0;
char* id;
void  enter(enum object k, enum object_t t){
	tx = tx+1;
	strcpy(table[tx].name, id);
	//printf("%s\n",table[tx].name);
	table[tx].kind = k;
	table[tx].type = t;
	table[tx].addr = tx+2;
	table[tx].value = 0;//默认值是0
}

int position(char* tid){
	strcpy(table[0].name, tid);//如果return的是0说明没找到
	for(int i = tx; i >= 0; i--){
		if (strcmp(table[i].name, tid)==0)
			return i;
	}
	return -1;
}

void assignv(int t, double val){
	table[t].value = val;
}

double getv(int t){
	if(t > 0)
		return table[t].value;
	return -999999; 
}

int getaddr(int t){
	if(t > 0)
		return table[t].addr;
	return -999999; 
}

int gettype(int t){
	if(t > 0)
		return table[t].type;
	return -1; 
}

int judgeeq(int i, double d){
	return ((d - i <= EPSINON && i <= d) || (0 <= i-d && i- d <= EPSINON) || (0 <= d  && d <= EPSINON) || (0 >= d && i >= -EPSINON));
}