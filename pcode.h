#include <stdio.h>
#include <string.h>
#include "table.h"
#define CXMAX 200
#define STACKSIZE 500
enum fct{lit, lod, sto, cal, inn, jmp, jpc, opr, red, del, jpcc, jpcc2, jpc2};
struct instruction{
	enum fct f;
	int l;
	int a;
	double v;
	enum object_t type;

};

struct data{
		double value;
		enum object_t type;
	};

struct instruction code[CXMAX+1];//程序存储器，存储解释生成的中间代码
int cx;//记录程序条数

int base(int l, int b, struct data s[STACKSIZE+1]){//b和s在interpret中定义的，这里也要传参
	int rt;
	rt = b;
	while(l > 0){
		rt = (int)s[rt].value;
		l = l-1;
	}
	return rt;
}

void pcode_error(char* msg){
	printf("pcode error:%s\n", msg);
	exit(1);
}

void gen(enum fct f, int l, int a, enum object_t type){
	if(cx > CXMAX)
		printf("program too long!");
	code[cx].f = f;
	code[cx].l = l;
	code[cx].a = a;
	code[cx].type = type;
	cx++;
}
void genplus(enum fct f, int l, int a, enum object_t type, double v){//为lit专门使用的命令生成代码
	if(cx > CXMAX)
		printf("program too long!");
	code[cx].f = f;
	code[cx].l = l;
	code[cx].a = a;
	code[cx].v = v;
	code[cx].type = type;
	cx++;
}

void interpret(){
	struct data s[STACKSIZE+1];//数据存储器，存储数据

	int p=0;//程序地址寄存器
	int t=2;//地址寄存器
	struct instruction i;//指令寄存器
	int b=0;//基本地址寄存器,书上的pcode从1开始，这里简单起见从0开始

	int ti = tx;
	// s[0].value = 0,s[0].type = int_t;//静态链接
	// s[1].value = 0,s[1].type = int_t;//动态链接
	// s[2].value = 0,s[2].type = int_t;//返回地址
	printf("**********interpret************\n");
	do{
		i = code[p];
		p = p+1;
		switch(i.f){
			case lit:
				t += 1;
				s[t].value = i.v;
				s[t].type = i.type;	
				//printf("lit,%d,%lf\n",t,s[t].value);
				break;
			case lod:
				t += 1;
				s[t] = s[(base(i.l,b,s)+i.a)];
				break;
			case sto:
				//printf("%lf\n",s[t].value);
				if(s[(base(i.l,b,s)+i.a)].type == int_t){
					s[(base(i.l,b,s)+i.a)].value = (int)s[t].value;
				}
				else
					s[(base(i.l,b,s)+i.a)] = s[t];
				t = t-1;
				//printf("sto,%d,%lf\n",base(i.l,b,s)+i.a,s[base(i.l,b,s)].value);
				break;
			case cal:
				s[t+1].value = base(i.l,b,s);
				s[t+2].value = b;
				s[t+3].value = p;
				b = t+1;
				p = i.a;
				break;
			case inn:
				t = t+ i.a;
				//printf("inn,%d\n",t);
				break;
			case jmp:
				p = i.a;
				break;
			case jpc:
				if(judgeeq(0, s[t].value))
					p = i.a;
				t = t-1;
				break;
			case opr:
				if(i.a == 0){
					t = b-1;
					p = s[t+3].value;
					b = s[t+2].value;
				}
				else if(i.a == 1){
					s[t].value = 1-s[t].value;
				}
				else if(i.a == 2){
					t = t-1;
					if(s[t].type == bool_t || s[t+1].type == bool_t)
						pcode_error("plus operation cannot be used to bool type");
					if(!(s[t].type == int_t && s[t+1].type == int_t))
						s[t].type = double_t;
					s[t].value = s[t].value+s[t+1].value;
					//printf("after plus:%d,%lf\n",t,s[t].value);
				}
				else if(i.a == 3){
					t = t-1;
					if(s[t].type == bool_t || s[t+1].type == bool_t)
						pcode_error("minus operation cannot be used to bool type");
					if(!(s[t].type == int_t && s[t+1].type == int_t))
						s[t].type = double_t;
					s[t].value = s[t].value-s[t+1].value;
					//printf("after minus:%d,%lf\n",t,s[t].value);

				}
				else if(i.a == 4){
					t = t-1;
					if(s[t].type == bool_t || s[t+1].type == bool_t)
						pcode_error("times operation cannot be used to bool type");
					if(!(s[t].type == int_t && s[t+1].type == int_t))
						s[t].type = double_t;
					s[t].value = s[t].value*s[t+1].value;
					//printf("after times:%d,%lf\n",t,s[t].value);
				}
				else if(i.a == 5){
					t = t-1;
					if(s[t].type == bool_t || s[t+1].type == bool_t)
						pcode_error("plus operation cannot be used to bool type");
					s[t].type = int_t;
					s[t].value = (int)s[t].value/s[t+1].value;
				}
				else if(i.a == 6){
					if(s[t].type != int_t)
						pcode_error("ord operation canne be used to double or bool type");
					s[t].value = (int)s[t].value%2;
					s[t].type = bool_t;
				}
				else if(i.a == 8){
					t = t-1;
					if(s[t].type != s[t+1].type && (s[t].type == bool_t || s[t+1].type == bool_t))
						pcode_error("different type cannot be compared;");	
					s[t].value = (s[t].value == s[t+1].value);
					s[t].type = bool_t;
				}
				else if(i.a == 9){
					t = t-1;
					if(s[t].type != s[t+1].type && (s[t].type == bool_t || s[t+1].type == bool_t))
						pcode_error("different type cannot be compared;");	
					s[t].value = (s[t+1].value != s[t].value);
					s[t].type = bool_t;
				}
				else if(i.a == 10){
					t = t-1;
					if(s[t].type != s[t+1].type && (s[t].type == bool_t || s[t+1].type == bool_t))
						pcode_error("different type cannot be compared;");	
					//printf("less than:%lf < %lf\n",s[t+1].value, s[t].value);
					s[t].value = (s[t+1].value < s[t].value);
					s[t].type = bool_t;
					//printf("%lf\n",s[t].value);
				}
				else if(i.a == 11){
					t = t-1;
					//printf("beq,%lf,%lf\n",s[t].value,s[t+1].value);
					if(s[t].type != s[t+1].type && (s[t].type == bool_t || s[t+1].type == bool_t))
						pcode_error("different type cannot be compared;");	
					s[t].value = (s[t+1].value >= s[t].value);
					s[t].type = bool_t;
				}
				else if(i.a == 12){
					t = t-1;
					if(s[t].type != s[t+1].type && (s[t].type == bool_t || s[t+1].type == bool_t))
						pcode_error("different type cannot be compared;");	
					s[t].value = (s[t+1].value > s[t].value);					
					s[t].type = bool_t;
				}
				else if(i.a == 13){
					t = t-1;
					if(s[t].type != s[t+1].type && (s[t].type == bool_t || s[t+1].type == bool_t))
						pcode_error("different type cannot be compared;");	
					s[t].value = (s[t+1].value <= s[t].value);
					s[t].type = bool_t;
				}
				else if(i.a == 14){//and
					t = t-1;
					if(s[t].type != bool_t || s[t+1].type != bool_t)
						pcode_error("and operation should be used to bool type");
					s[t].value = (int)s[t].value && (int)s[t+1].value;
					s[t].type = bool_t;
				}
				else if(i.a == 15){//or
					t = t-1;
					if(s[t].type != bool_t || s[t+1].type != bool_t)
						pcode_error("or operation should be used to bool type");
					s[t].value = (int)s[t].value || (int)s[t+1].value;
					s[t].type = bool_t;
				}
				else if(i.a == 16){//complement
					t = t-1;
					if(s[t].type != int_t || s[t+1].type != int_t)
						pcode_error("this operation should be used to int type");
					s[t].value = (int)s[t].value % (int)s[t+1].value;
					//printf("after minus:%d,%lf\n",t,s[t].value);
				}
				else if(i.a == 17){//xor
					t = t-1;
					if(s[t].type == double_t || s[t+1].type == double_t)
						pcode_error("this operation should be used to int or bool type");
					s[t].value = (int)s[t].value ^ (int)s[t+1].value;
				}
				else if(i.a == 18){//为switch的第一条case专门设计的比较是否相等的指令，switch的aexpr还存在栈中，case的aexpr被覆盖成判断是否相等
					if(s[t].type != int_t || s[t-1].type != int_t)
						pcode_error("this two operation should be int type");	
					//printf("%lf, %lf\n",s[t].value, s[t-1].value);
					s[t].value = ((int)s[t].value == (int)s[t-1].value);
					s[t].type = bool_t;
				}
				else if(i.a == 19){//为switch第一条后的case专门设计的比较是否相等的指令，switch的aexpr还存在栈中，case的aexpr被覆盖成判断是否相等
					t = t-1;
					if(s[t+1].type != int_t || s[t-1].type != int_t)
						pcode_error("this two operation should be int type");	
					//printf("%lf, %lf\n",s[t].value, s[t-1].value);
					s[t].value = ((int)s[t+1].value == (int)s[t-1].value);
					s[t].type = bool_t;
				}
				break;
			case red:
				//printf("%lf,%lf,%lf,%lf,%lf",s[0].value,s[1].value,s[2].value,s[3].value,s[4].value);
				if(i.type == double_t){
					printf("%lf\n", s[(base(i.l,b,s)+i.a)].value);
		 		}
		 		else if(i.type == int_t){
					printf("%d\n", (int)s[(base(i.l,b,s)+i.a)].value);
		 		}
		 		else{
		 			if(s[(int)(base(i.l,b,s)+i.a)].value == 0)
						printf("false\n");
					else
						printf("true\n");
		 		}
				break;
			case del://删除数据栈栈顶元素；结合opr 0 18 语句，每个switchcase尝试配对后需要删掉栈顶元素
				t = t-i.a;
				break;
				
			case jpcc://为Switch专门设计的jpc；不会删除栈顶的元素。如果某一个case成立的话后面的case都可以忽略， 因此要记录下case的比较情况
				if(judgeeq(0, s[t].value))
					p = i.a;
				break;
			case jpcc2://为Switch专门设计的jpc；不会删除栈顶的元素。如果某一个case成立的话后面的case都可以忽略， 因此要记录下case的比较情况
				if(judgeeq(1, s[t].value))
					p = i.a;
				break;
			case jpc2:
				if(judgeeq(0, 1-s[t].value))
					p = i.a;
					//printf("jpc2:%d\n",judgeeq(1, s[t].value));}
				t = t-1;
				break;
		}
	}
	while(p != 0 && p < cx);
}

void printpcode(){
	int i;
	for(i = 0; i < cx; i++){
		if(i < 10)
			printf("%d:     %d, %d, %d, %d\n",i, code[i].f, code[i].l, code[i].a, code[i].type);
		else
			printf("%d:    %d, %d, %d, %d\n",i, code[i].f, code[i].l, code[i].a, code[i].type);
	}
}