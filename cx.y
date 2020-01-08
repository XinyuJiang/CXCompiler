%{
 #include <stdio.h>
 #include <string.h>
 #include "pcode.h"
 int yylex(void);
 FILE *yyin;
 int yyerror(char*);
 extern int yylineno;
 extern char* yytext;
 #define MAXLOOP 10
 int cx1[MAXLOOP];//if的嵌套栈
 int cx1count = 0;
 int cx2[MAXLOOP];//while的嵌套栈
 int cx2count = 0;
 int cx3[MAXLOOP];//case的嵌套栈
 int cx3count = 0;
 int cx4[MAXLOOP];//break的数组。因为语句中可能有多个break所以还是要一个数据结构来存储每一个位置
 int cx4count = 0;
 int cx5[MAXLOOP];//回标for语句中jpc用.每三条语句为一组，组内第一个记录for中第二个表达式之前的位置，第二个记录第二个表达式之后的位置，第三个记录stmt结束位置
 int cx5count = 0;
 int cx6[MAXLOOP];//continue的数组。因为语句中可能有多个continue所以还是要一个数据结构来存储每一个位置
 int cx6count = 0;
 int cx61[MAXLOOP];//continue的数组。应对do while，repeat until的情况
 int cx61count = 0;
 int cx7[MAXLOOP]; //exit返回地址
 int cx7count = 0;
 int cx8[MAXLOOP];//do while的嵌套栈
 int cx8count = 0;
 int cx9[MAXLOOP];//repeat until的嵌套栈
 int cx9count = 0;
 %}
%union
{
	double var;
	char* name;
}
 %start program
 %token <var> NUM RNUM
 %token <name> ID RELOP
 %token INT BOOL DOUBLE CONST IF ELSE SWITCH CASE WHILE DO FOR REPEAT UNTIL BREAK CONTINUE EXIT WRITE READ PLUS MINUS TIMES DIVIDES COMPLEMENT ODD XOR SPLUS SMINUS ASSIGN OR AND NOT SEMI COLON LP RP LB RB LAN RAN LETTER DIGIT BLANK ANNO TRUE FALSE
 %type <var> aterm aexpr afactor bexpr bterm bfactor rel
 %%
 program: block{
 	int temp;
 	for(temp = 0; temp < cx7count; temp++)
 		code[cx7[temp]-1].a = cx;
 }
 ;
 block: LB decls stmts RB
 ;
 decls: decls decl|
 ;
 decl: INT ID SEMI{
 	id = $2;
	printf("aid\n");
	gen(inn,0,1,int_t);
 	enter(variable,int_t);
 }| 
 BOOL ID SEMI{
  	id = $2;
	printf("bid\n");
	gen(inn,0,1,bool_t);
 	enter(variable,bool_t);
 }| 
 DOUBLE ID SEMI{
  	id = $2;
	printf("bid\n");
	gen(inn,0,1,bool_t);
 	enter(variable,double_t);
 }|CONST INT ID {
	id = $3;
	gen(inn,0,1,int_t);
 	enter(constant,int_t);
 }ASSIGN aexpr SEMI{
 	int t = position($3);
	if(t > 0){
		gen(sto,0,getaddr(t),gettype(t));
	}
	else{
	yyerror("this variable don't exists.");
	}
 }| 
 CONST BOOL ID {
	id = $3;
	gen(inn,0,1,bool_t);
 	enter(constant,bool_t);
 }ASSIGN bexpr SEMI{
 	int t = position($3);
	if(t > 0){
		gen(sto,0,getaddr(t),bool_t);
	}
	else{
		yyerror("this variable don't exists.");
	}
 }| 
 CONST DOUBLE ID {
	id = $3;
	gen(inn,0,1,bool_t);
 	enter(constant,double_t);
 }ASSIGN aexpr SEMI{
 	int t = position($3);
 	if(t > 0){
		gen(sto,0,getaddr(t),gettype(t));
	}
	else{
	yyerror("this variable don't exists.");
	}
 }
 ;
 stmts: stmts stmt|
 ;
 stmt: ID ASSIGN aexpr SEMI{
 	//printf("process int or double;\n");
	int t = position($1);
	if(t > 0){
		if(table[t].kind != variable)
			yyerror("this identifier should be a variable!");
		else if(table[t].type == 1){
			if(!(judgeeq(1,$3)||judgeeq(0,$3))) {
				yyerror("this bool variable cannot be assigned by number excepts 1 and 0");
			}
			else{
				gen(sto,0,getaddr(t),bool_t);
			}
		}
		else{
			gen(sto,0,getaddr(t),gettype(t));
		}
	}
	else{
	yyerror("this variable don't exists.");
	}
 }|
 ID ASSIGN bexpr SEMI{
 	//printf("process bool;\n");
	int t = position($1);
	if(t > 0){
		if(table[t].kind != variable)
			yyerror("this identifier should be a variable!");
		else if(table[t].type != 1){
			yyerror("this variable is not boolean type.");
		}
		else{
			gen(sto,0,getaddr(t),bool_t);
		}
	}
	else{
		yyerror("this variable don't exists.");	
	}
 }|
 IF LP bexpr RP {
 	printf("process if\n");
 	cx1[cx1count] = cx;
 	cx1count+=1;
 	gen(jpc,0,0,int_t);
 }stmt {
	cx1[cx1count] = cx;
 	cx1count+=1;
 	gen(jmp,0,0,int_t);
 } elses|
 WHILE {
 	printf("process while\n");
 	cx2[cx2count] = cx;
 	cx2count+=1;
 }LP bexpr RP {
 	cx2[cx2count] = cx;
 	cx2count+=1;
 	gen(jpc,0,0,int_t);
 }stmt{
	int temp;
	for(temp = 0; temp < cx6count; temp++){
 		code[cx6[temp]-1].a = cx;
 	}
 	cx6count = 0;

 	gen(jmp,0,cx2[cx2count-2],int_t);
	code[cx2[cx2count-1]].a = cx;
	cx2count -= 2;
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }|
 FOR LP ID ASSIGN aexpr SEMI{
 	printf("process int variable;\n");
	int t = position($3);
	if(t > 0){
		if(table[t].kind != variable)
			yyerror("this identifier should be a variable!");
		else if(table[t].type == 1){
			if(!(judgeeq(1,$5)||judgeeq(0,$5))) {
				yyerror("this bool variable cannot be assigned by number excepts 1 and 0");
			}
			else{
				gen(sto,0,getaddr(t),bool_t);
			}
		}
		else{
			gen(sto,0,getaddr(t),gettype(t));
		}
	}
	else{
	yyerror("this variable don't exists.");
	}
	cx5[cx5count] = cx;
	cx5count+=1;
 }rel SEMI {
 	gen(jpc,0,0,int_t);//不满足跳到stmt后结束循环
 	gen(jmp,0,0,int_t);//否则执行stmt
 	cx5[cx5count] = cx;//注意gen和cx[cxcount]语句的先后，此时存储的是jmp后的那一条语句的位置。
 	cx5count+=1; 
 }selfop {
   	gen(jmp,0,cx5[cx5count-2],int_t);//跳到第二个表达式前
 	cx5[cx5count] = cx;
 	cx5count+=1;
 	code[cx5[cx5count-2]-1].a = cx;
 }RP stmt{
 	int temp;
  	//continue
  	for(temp = 0; temp < cx6count; temp++){
 		code[cx6[temp]-1].a = cx;
 	}
 	cx6count = 0;
 	//跳到第二个表达式后
 	gen(jmp,0,cx5[cx5count-2],int_t);
 	code[cx5[cx5count-2]-2].a = cx;
 	cx5count -= 3;
 	//break
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }|
 DO {
	cx61[cx61count] = cx;
 	cx61count += 1;
 	cx8[cx8count] = cx;
 	cx8count += 1;
 	//printf("oooops%d\n",cx);
 }stmt
 WHILE LP bexpr RP { 	
 	gen(jpc2,0,code[cx8[cx8count-1]].a,int_t);
 	cx8count -= 1;
 	int temp;
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }|
 REPEAT {
	cx61[cx61count] = cx;
 	cx61count += 1;
 	cx9[cx9count] = cx;
 	cx9count += 1;
 }stmts
 UNTIL LP bexpr RP { 	
 	gen(jpc,0,code[cx9[cx9count-1]].a,int_t);
 	cx9count -= 1;
 	int temp;
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }|
 WRITE aexpr SEMI|
 READ ID SEMI{
 	int t = position($2);
 	if(t > 0){
 		gen(red, 0, getaddr(t), gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists.");
 	}
 }|
 block|
 SWITCH LP aexpr RP LB cases RB{
 	int temp;
 	//printf("cxxxxxxxxxxxx%d\n",cx);
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 		//printf("%d\n",cx4[temp]);
 	}
 	cx4count = 0;
 }|
 selfop SEMI|
 BREAK SEMI{
 	gen(jmp,0,0,int_t);
 	cx4[cx4count] = cx;
 	cx4count += 1;
 }|
 CONTINUE SEMI{
  	if(cx61count != 0){
 		gen(jmp,0,cx61[cx61count - 1],int_t);
 		cx61count -= 1;
 	}
 	else{
	 	gen(jmp,0,0,int_t);
	 	cx6[cx6count] = cx;
	 	cx6count += 1;
	}
 }|
 EXIT LP RP SEMI{
 	gen(jmp,0,0,int_t);
 	cx7[cx7count] = cx;
 	cx7count += 1;
 }
 ;
 selfop:ID SPLUS{
 	int t = position($1);
 	if(t > 0){
 		gen(lod,0,getaddr(t),gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists."); 		
 	}
  	genplus(lit,0,1,int_t,1);
 	gen(opr,0,2,int_t);
 	gen(sto,0,getaddr(t),bool_t);
 }|
 ID SMINUS{
 	int t = position($1);
 	if(t > 0){
 		gen(lod,0,getaddr(t),gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists."); 		
 	}
  	genplus(lit,0,1,int_t,1);
 	gen(opr,0,3,int_t);
 	gen(sto,0,getaddr(t),bool_t);
 }
 elses:ELSE {
 	printf("else statement\n");
 	code[cx1[cx1count-2]].a = cx;
 } stmt {
 	code[cx1[cx1count-1]].a = cx;
 	cx1count -= 2;
 }|{
 	cx1count-=1;
 	code[cx1[cx1count]].a = cx;
 	cx1count-=1;
 	code[cx1[cx1count]].a = cx;
 	//printf("code:%d,%d\n",code[cx1[cx1count]].f,cx);
 }
 ;
 cases:cases CASE aexpr {
 	//现在数据栈栈顶t是上一次的比较结果，t-1是switch里的aexpr的值
 	gen(jpcc2,0,cx+2,bool_t);//如果t是1那么直接忽略case语句,也就是往后跳2条语句
 	gen(opr,0,19,bool_t);//走到这里说明上一次的case语句不符合，也就没必要再存了，因此现在t-1是switch的aexpr，t是第二次比较的结果
 	cx3[cx3count] = cx;
 	cx3count+=1;
 	gen(jpc,0,0,int_t);
 }COLON stmts{
 	code[cx3[cx3count-1]].a = cx;
 	//gen(del,0,1,int_t);//栈顶比较完后就删了，保证栈顶变成t
 }|
 CASE aexpr {
 	gen(opr,0,18,bool_t);//t-1是switch的aexpr，t是第二次比较的结果，
 	cx3[cx3count] = cx;
 	printf("cx3:%d\n",cx3[cx3count]);
 	cx3count+=1;
 	gen(jpcc,0,0,int_t);//这一条肯定是第一条case，因此要保留第一个比较结果
 }COLON stmts{
 	code[cx3[cx3count-1]].a = cx;
 	//gen(del,0,1,int_t);
 }
 ;
 aexpr: aterm PLUS aterm{
 	gen(opr,0,2,int_t);
 	}|
 aterm MINUS aterm{
 	gen(opr,0,3,int_t);
 	}|
 aterm{
 }|
 ID ASSIGN aexpr{
	yyerror("cannot apply multiply assign symbol.");
 }
 ;
 aterm: afactor TIMES afactor{
 	gen(opr,0,4,int_t);
 	}|
 afactor DIVIDES afactor{
 	gen(opr,0,5,int_t);
 	}|
 afactor COMPLEMENT afactor{
 	gen(opr,0,16,int_t);
 	}|
 afactor XOR afactor{
 	gen(opr,0,17,int_t);
 	}|
 afactor|
 aterm PLUS aterm{
 	yyerror("cann't apply more than one plus without p."); 		
 	}|
 aterm MINUS aterm{
 yyerror("cann't apply more than one minus without p."); 		
 }
 ;
 afactor: ID{
 	int t = position($1);
 	if(t > 0){
 		gen(lod,0,getaddr(t),gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists."); 		
 	}
 }|
 NUM{
 	genplus(lit,0,$1,int_t,$1);
 	}|
 RNUM{
 	genplus(lit,0,$1,double_t,$1);
 	}|
 LP aexpr RP{
 }
 ;
 bexpr: bexpr OR bterm{
 	gen(opr,0,15,bool_t);
 	}|
 bterm|
 ODD afactor{
 	gen(opr,0,6,bool_t); 	
 }|
 ID ASSIGN bexpr{
	yyerror("cannot apply multiply assign symbol.");
 }
 ;
 bterm: bterm AND bfactor{
 	gen(opr,0,14,bool_t);
 }|
 bfactor
 ;
 bfactor: ID{
 	int t = position($1);
 	if(t > 0){
 		if(table[t].type != 1)
			yyerror("this variable is not boolean type.");
		else{
 			gen(lod,0,getaddr(t),gettype(t));
		}
 	}
 	else{
 		yyerror("this variable don't exists"); 	
 	}
 }|
 TRUE{
  	printf("bool variable;\n");
 	genplus(lit,0,1,bool_t,1);
 }|
 FALSE{
 	genplus(lit,0,0,bool_t,1);
 }|
 NOT bfactor{
 	gen(opr,0,1,bool_t);
 	}|
 LP bexpr RP|
 rel
 ;
 rel: ID RELOP aexpr{
 	int t = position($1);
 	double temp = 0;
 	if(t > 0){
 		if(table[t].type != 0){
			yyerror("this variable don't have correct type.");		
 		}
 	}
 	else{
 		yyerror("this variable don't exists."); 	
 	}
 	if(strcmp($2, "<") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,10,bool_t);
 	}
 	else if(strcmp($2, "<=") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,13,bool_t);
 	}
 	else if(strcmp($2, ">") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,12,bool_t);
 	}
 	else if(strcmp($2, ">=") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,11,bool_t);
 	}
 	else if(strcmp($2, "==") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,8,bool_t);
 	}
 	else if(strcmp($2, "!=") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,9,bool_t);
 	}
 	else
 		yyerror("wrong relop type\n");	
 }|
 NUM RELOP aexpr{
 	printf("num,relop,expr\n");
 	if(strcmp($2, "<") == 0){
 	 	genplus(lit,0,$1,int_t,$1);
 	 	gen(opr,0,10,bool_t);
 	}
 	else if(strcmp($2, "<=") == 0){
 	 	genplus(lit,0,$1,int_t,$1);
 	 	gen(opr,0,13,bool_t);
 	}
 	else if(strcmp($2, ">") == 0){
 	 	genplus(lit,0,$1,int_t,$1);
 	 	gen(opr,0,12,bool_t);
 	}
 	else if(strcmp($2, ">=") == 0){
 	 	genplus(lit,0,$1,int_t,$1);
 	 	gen(opr,0,11,bool_t);
 	}
 	else if(strcmp($2, "==") == 0){
 	 	genplus(lit,0,$1,int_t,$1);
 	 	gen(opr,0,8,bool_t);
 	}
 	else if(strcmp($2, "!=") == 0){
 	 	genplus(lit,0,$1,int_t,$1);
 	 	gen(opr,0,9,bool_t);
 	}
 	else
 		yyerror("wrong relop type\n");
 }|
 RNUM RELOP aexpr{
 	printf("rnum,relop,expr\n");
 	if(strcmp($2, "<") == 0){
 	 	genplus(lit,0,$1,double_t,$1);
 	 	gen(opr,0,10,bool_t);
 	}
 	else if(strcmp($2, "<=") == 0){
 	 	genplus(lit,0,$1,double_t,$1);
 	 	gen(opr,0,13,bool_t);
 	}
 	else if(strcmp($2, ">") == 0){
 	 	genplus(lit,0,$1,double_t,$1);
 	 	gen(opr,0,12,bool_t);
 	}
 	else if(strcmp($2, ">=") == 0){
 	 	genplus(lit,0,$1,double_t,$1);
 	 	gen(opr,0,11,bool_t);
 	}
 	else if(strcmp($2, "==") == 0){
 	 	genplus(lit,0,$1,double_t,$1);
 	 	gen(opr,0,8,bool_t);
 	}
 	else if(strcmp($2, "!=") == 0){
 	 	genplus(lit,0,$1,double_t,$1);
 	 	gen(opr,0,9,bool_t);
 	}
 	else
 		yyerror("wrong relop type\n");
 }
 ;
 %%
 int main(int argc, char *argv[])
 {
 	int i;
 	for(i = 0; i < argc ; i++){
 		if (strcmp(argv[i],"-f") == 0 && argc > i)
 		{
 			yyin = fopen(argv[++i] ,"r");
 		}
 	}
 	printf("**********CX Compiler:************\n");
	yyparse();
	printf("************pcode:****************\n");
	printpcode();
	interpret();

	return 0;
 }
 int yyerror(char *msg)
 {
 printf("Error encountered: %d:  %s at %s\n", yylineno, msg, yytext);
 return 1;
 }