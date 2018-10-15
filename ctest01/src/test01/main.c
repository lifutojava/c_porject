#include <stdio.h>
#include <string.h>
#include "header.h"
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

//首先写：#ifndef A_H   （意思是："if not define a.h"，即如果不存在a.h）
//接着写：#define A_H  （那就引入a.h）
//最后写：#endif   （否则不需要引入a.h，即已存在a.h，无需再次引入）
// 有条件的进行 导入
#if  SYSTEM_1 //如果
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#endif

//定義全局變量 及方法的導入
int count;
extern void write_extern();
extern int * getRandom();
extern int max();
extern int populate_array();
extern int getNextRandomValue();
int count2 = 0;

// 宏定义
#define TRUE  1
#define FALSE 0
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n") //宏定义 调用
#define tokenpaster(n) printf ("token" #n " = %d", token##n)	//宏定义粘贴运算符
//#define MESSAGE "My Life!" //测试 宏判断
#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif
#define MAX(x,y) ((x) > (y) ? (x) : (y))

//错误处理
extern int errno ;

/**
 *  typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
 *	typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
 *	typedef
 */
typedef struct Books2
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;

/**
 * 位域
 */
struct bs{
    int a:8;
    int b:2;
    int c:6;
} data;
struct packed_struct {
  unsigned int f1:1;
  unsigned int f2:1;
  unsigned int f3:1;
  unsigned int f4:1;
  unsigned int type:4;
  unsigned int my_int:9;
} pack;
struct bs2{
    unsigned a:4;
    unsigned  :4;    /* 空域 */
    unsigned b:4;    /* 从下一单元开始存放 */
    unsigned c:4;
};
struct k{
    int a:1;
    int  :2;    /* 该 2 位不能使用 */
    int b:3;
    int c:2;
};

/**
 * 结构体:
 */
struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

/**
 * 共用體
 */
union Data
{
   int i;
   float f;
   char  str[20];
};

//函数声明
void prints(void);	//测试字符串
void book(void);	//结构体测试
void printBook(struct Books book);	//打印书信息 : 测试属性调用
void test01(void);	///* 局部变量 */
void test02(void);	///*指針的使用*/
void test03(void);	///* 指針的使用 :  回调函数 */
void test04(void);	////* 函数指针  */
void test05(void);	///* for循環與 文件方法調用 */
void test06(void);	///** 位域的使用 */
void test07(void);	//共用體 : 使用
void test08(void);	//共用體 : 使用
void test09(void);	// typedef
void test10(void);	// test #define
void test11(void);	// 输入和格式化输出
void test12(void);	// putChar getChar
void test13(void);	// gets puts
void test14(void);	// scanf printf
void test15(void);	// file  写
void test16(void);	// file 读
void test17(void);	// 宏 测试
void test18(void);	// 测试 数据类型强制 与 提升
void test19(void);	// 错误处理
void test20(void);	// 错误处理
void test21(void);	// 错误处理
void test22(void);	// 动态内存管理
int square(int x);	//	参数化的宏来定义函数
double factorial(unsigned int i);	//数的阶乘
int fibonaci(int i);	//斐波那契数列
double average(int num,...);	//可变长参数
void test23(void);
void test24(void);
void test25(void);
void test26(void);
void test27(void);
void test28(void);
int x(int num);
void test29(void);
void test30(void);

/**
 *
 * 在使用带有参数的宏之前，必须使用 #define 指令定义。参数列表是括在圆括号内，
 * 且必须紧跟在宏名称的后边。宏名称和左圆括号之间不允许有空格。
 */
//利用参数化的宏来定义函数;
int square(int x) {
   return x * x;
}

#define square(x) ((x) * (x))

/**
 *  要调用上面定义函数的主函数
 */
int main(int argc, char *argv[]) {
//	prints();
//	book();
//	test01();	///* 局部变量 */
//	test02();	///*指針的使用*/
//	test03();	///* 指針的使用 :  回调函数 */
//	test04();	////* 函数指针  */
//	test05();	///* for循環與 文件方法調用 */
//	test06();	//位域的使用
//	test07();	//位域的使用
//	test08();	//位域的使用
//	test09();	//typedef
//	test10();	//test #define
//	test11();	//test #define
//	test12();	//getchar putchar
//	test13();	//gets puts
//	test14();	//scanf printf
//	test15();	//file 写
//	test16();	//file 读
//	test17();	// 宏 测试
	//宏调用
//	message_for("呵呵", "嘿嘿");
//	int token34 = 40;
//	tokenpaster(34);
//	printf("Here is the message: %s\n", MESSAGE);
//	printf("Max between 30 and 20 is %d\n", MAX(31, 31));
//	puts (test());
//	test18();
//	test19();	//错误处理
//	test20();	//错误处理
//	test21();	//错误处理
//    int i = 15;
//    printf("%d 的阶乘为 %f\n", i, factorial(i));
//    int i;
//    for (int i = 0; i < 10; i++)
//    {
//       printf("%d\t\n", fibonaci(i));
//    }
//    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
//    printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
//	test22();

//	   if( argc == 2 )
//	   {
//	      printf("The argument supplied is %s\n", argv[1]);
//	   }
//	   else if( argc > 2 )
//	   {
//	      printf("Too many arguments supplied.\n");
//	   }
//	   else
//	   {
//	      printf("One argument expected.\n");
//	   }
//	test25();	//判断是否时字母
//	test26();	//99
//	test27();	//99
//	test28();	//99
	x(x(8));

	return 0 ;
}



/**
 * 测试书 结构体 的使用:
 */
void book(void) {

	struct Books Book1; /* 声明 Book1，类型为 Books */
	struct Books Book2; /* 声明 Book2，类型为 Books */

	/* Book1 详述 */
	strcpy(Book1.title, "C Programming");
	strcpy(Book1.author, "Nuha Ali");
	strcpy(Book1.subject, "C Programming Tutorial");
	Book1.book_id = 6495407;

	/* Book2 详述 */
	strcpy(Book2.title, "Telecom Billing");
	strcpy(Book2.author, "Zara Ali");
	strcpy(Book2.subject, "Telecom Billing Tutorial");
	Book2.book_id = 6495700;

	/* 输出 Book1 信息 */
	printBook(Book1);
	/* 输出 Book2 信息 */
	printBook(Book2);
}

/**
 * 打印书 属性:
 */
void printBook(struct Books book) {
	printf("Book title : %s\n", book.title);
	printf("Book author : %s\n", book.author);
	printf("Book subject : %s\n", book.subject);
	printf("Book book_id : %d\n", book.book_id);
}

/**
 * 字符串测试:
 */
void prints(void) {

	char str1[12] = "Hello";
	char str2[12] = "World";
	char str3[12];
	int len;

	/* 复制 str1 到 str3 */
	strcpy(str3, str1);
	printf("strcpy( str3, str1) :  %s\n", str3);

	/* 连接 str1 和 str2 */
	strcat(str1, str2);
	printf("strcat( str1, str2):   %s\n", str1);

	/* 连接后，str1 的总长度 */
	len = strlen(str1);
	printf("strlen(str1) :  %d\n", len);
//	   return 0;
}

/* 局部变量 */
void test01(void) {
	/* 局部变量 */
	int a, b;
	int c;
	float f;

	/* 赋值 */
	a = 10;
	b = 20;

	c = a + b;
	printf("value of c : %d \n", c);

	f = 70.0 / 3.0;
	printf("value of f : %f \n", f);
}

/*指針的使用*/
void test02(void){
   /* 一个指向整数的指针 */
   int *p;
   int i;

   p = getRandom();
   for ( i = 0; i < 10; i++ )
   {
	   printf("*(p + [%d]) : %d\n", i, *(p + i) );
   }
}

/* 指針的使用 :  回调函数 */
void test03(void)
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
}

/* 函数指针  */
void test04(void)
{
   /* p 是函数指针 */
   int (* p)(int, int) = & max; // &可以省略
   int a, b, c, d;

   printf("请输入三个数字:");
   scanf("%d %d %d", & a, & b, & c);

   /* 与直接调用函数等价，d = max(max(a, b), c) */
   d = p(p(a, b), c);

   printf("最大的数字是: %d\n", d);
}

/* for循環與 文件方法調用 */
void test05(void)
{
	count = 5;
	write_extern();

	int n[10];
	int i, j;

	for (i = 0; i < 10; i++) {
		n[i] = i + 100;
	}

	for (int a = 0; a < 11; a++) {
		printf("Hello, World! \n");
	}

	for (j = 0; j < 10; j++) {
		printf("Element[%d] = %d\n", j, n[j]);
	}
}
/** 位域的使用 */
void test06(void)
{
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit,*pbit;
    bit.a=1;
    printf("%d\n",bit.a);    /* 以整型量格式输出三个域的内容 */

    bit.a=1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b=7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c=15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n",bit.a,bit.b,bit.c);    /* 以整型量格式输出三个域的内容 */

    pbit=&bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a=0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b&=3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c|=1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);    /* 用指针方式输出了这三个域的值 */

}

/**
 * 共用體 : 使用
 */
void test07(void)
{
	union Data data;    //共用體
	data.i = 10;
	data.f = 220.5;
	strcpy( data.str, "C Programming");

	printf( "data.i : %d\n", data.i);
	printf( "data.f : %f\n", data.f);
	printf( "data.str : %s\n", data.str);

	printf( "Memory size occupied by data : %d\n", sizeof(data));
}
/**
 * 共用體 : 使用
 */
void test08(void)
{
	union Data data;

	data.i = 10;
	printf( "data.i : %d\n", data.i);

	data.f = 220.5;
	printf( "data.f : %f\n", data.f);

	strcpy( data.str, "C Programming");
	printf( "data.str : %s\n", data.str);
}

/**
 * typedef
 */
void test09(void)
{
	Book book;

	strcpy( book.title, "C 教程");
	strcpy( book.author, "Runoob");
	strcpy( book.subject, "编程语言");
	book.book_id = 12345;

	printf( "书标题 : %s\n", book.title);
	printf( "书作者 : %s\n", book.author);
	printf( "书类目 : %s\n", book.subject);
	printf( "书 ID : %d\n", book.book_id);
}

/**
 * test #define
 */
void test10(void)
{
	printf( "TRUE 的值: %d\n", TRUE);
	printf( "FALSE 的值: %d\n", FALSE);

}

/**
 * 输入 和格式化输出
 */
void test11(void)
{
    float f;
    scanf("%f",&f);
    printf("Enter a number: ");
    // %f 匹配浮点型数据
    printf("Value = %f", f);
}

/**
 * putChar getChar
 */
void test12(void)
{
	   int c;

	   printf( "Enter a value :");
	   c = getchar( );

	   printf( "\nYou entered: ");
	   putchar( c );
	   printf( "\n");
}

/**
 * gets puts
 */
void test13(void)
{
	   char str[100];

	   printf( "Enter a value :");
	   gets( str );

	   printf( "\nYou entered: ");
	   puts( str );
}

/**
 * scanf printf
 */
void test14(void)
{
	   char str[100];
	   int i;

	   printf( "Enter a value :");
	   scanf("%s %d", str, &i);

	   printf( "\nYou entered: %s %d ", str, i);
	   printf("\n");
}

/**
 * file  写
 */
void test15(void)
{
	FILE *fp = NULL;
	char str[100];

	fp = fopen("D:/workspace/workspace/c_porject/ctest01/src/test.txt", "w+");
	//获取输入字符串
	gets( str );
//	fprintf(fp, "This is testing for fprintf...\n");
//	fputs("This is testing for fputs...\n", fp);
	fprintf(fp,str);
	fputs(str,fp);
	fclose(fp);
}

/**
 * file  读
 */
void test16(void)
{
	FILE *fp = NULL;
	char buff[255];

//	fp = fopen("D:/workspace/workspace/c_porject/ctest01/src/test.txt", "r");
	fp = fopen("/tmp/test.txt", "r");
	fscanf(fp, "%s", buff); //遇到空格就停止读取了
	printf("1: %s\n", buff );

	fgets(buff, 255, (FILE*)fp); //只能读取一行数据 遇到换行停止
	printf("2: %s\n", buff );

	fgets(buff, 255, (FILE*)fp);
	printf("3: %s\n", buff );
	fclose(fp);
}

/**
 * 宏 测试
 */
void test17(void)
{
	printf("File :%s\n", __FILE__ );
	printf("Date :%s\n", __DATE__ );
	printf("Time :%s\n", __TIME__ );
	printf("Line :%d\n", __LINE__ );
	printf("ANSI :%d\n", __STDC__ );
}

/**
 * c测试 数据类型强制 与 提升
 */
void test18(void)
{
	int  i = 17;
	char c = 'c'; /* ascii 值是 99 */
	float sum;

	sum = i + c;
	printf("Value of sum : %f\n", sum );
}

/**
 * 错误处理
 */
void test19(void)
{
	FILE * pf;
	int errnum;
	pf = fopen ("unexist.txt", "rb");
	if (pf == NULL)
	{
	  errnum = errno;
	  fprintf(stderr, "错误号: %d\n", errno);
	  perror("通过 perror 输出错误");
	  fprintf(stderr, "打开文件错误: %s\n", strerror( errnum ));
	}
	else
	{
	  fclose (pf);
	}
}

/**
 *在进行除法运算时，如果不检查除数是否为零，则会导致一个运行时错误。
 *为了避免这种情况发生，下面的代码在进行除法运算前会先检查除数是否为零：
 */
void test20(void)
{
	int dividend = 20;
	int divisor = 0;
	int quotient;

	if( divisor == 0){
	  fprintf(stderr, "除数为 0 退出运行...\n");
	  exit(-1);
	}
	quotient = dividend / divisor;
	fprintf(stderr, "quotient 变量的值为 : %d\n", quotient );

	exit(0);
}

/**
 *在进行除法运算时，如果不检查除数是否为零，则会导致一个运行时错误。
 *为了避免这种情况发生，下面的代码在进行除法运算前会先检查除数是否为零：
 */
void test21(void)
{
	int dividend = 20;
	   int divisor = 0;
	   int quotient;

	   if( divisor == 0){
	      fprintf(stderr, "除数为 0 退出运行...\n");
	      exit(EXIT_FAILURE);
	   }
	   quotient = dividend / divisor;
	   fprintf(stderr, "quotient 变量的值为: %d\n", quotient );

	   exit(EXIT_SUCCESS);
}

/**
 *  测试 递归 : 数的阶乘
 */
double factorial(unsigned int i)
{
   if(i <= 1)
   {
      return 1;
   }
   return i * factorial(i - 1);
}

/**
 *	斐波那契数列
 */
int fibonaci(int i)
{
   if(i == 0)
   {
      return 0;
   }
   if(i == 1)
   {
      return 1;
   }
   return fibonaci(i-1) + fibonaci(i-2);
}

/**
 * 可变长 参数
 */
double average(int num,...)
{

    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
       sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum/num;
}

/**
 * 动态内存管理
 */
void test22(void)
{
	   char name[100];
	   char *description;

	   strcpy(name, "Zara Ali");

	   /* 动态分配内存 */
	   description = malloc( 30 * sizeof(char) );
	   if( description == NULL )
	   {
	      fprintf(stderr, "Error - unable to allocate required memory\n");
	   }
	   else
	   {
	      strcpy( description, "Zara ali a DPS student.");
	   }
	   /* 假设您想要存储更大的描述信息 */
	   description = realloc( description, 100 * sizeof(char) );
	   if( description == NULL )
	   {
	      fprintf(stderr, "Error - unable to allocate required memory\n");
	   }
	   else
	   {
	      strcat( description, "She is in class 10th");
	   }

	   printf("Name = %s\n", name );
	   printf("Description: %s\n", description );

	   /* 使用 free() 函数释放内存 */
	   free(description);
}

//控制台 输入 输出
void test23(void)
{
    int number;

    // printf() 输出字符串
    printf("输入一个整数: ");

    // scanf() 格式化输入
    scanf("%d", &number);

    // printf() 显示格式化输入
    printf("你输入的整数是: %d", number);
}
// 控制台录入:  两数相加
void test24(void)
{
    int firstNumber, secondNumber, sumOfTwoNumbers;

    printf("输入两个数(以空格分割): ");

    // 通过 scanf() 函数接收用户输入的两个整数
    scanf("%d %d", &firstNumber, &secondNumber);

    // 两个数字相加
    sumOfTwoNumbers = firstNumber + secondNumber;

    // 输出结果
    printf("%d + %d = %d", firstNumber, secondNumber, sumOfTwoNumbers);
}
// 判断是否时 字母
void test25(void)
{
	char c;
	printf("输入需要判断是否时字母的值：");
	scanf("%c",&c);
	if(c>='a'&&c<='z'&&c>='A'&&c<='Z'){
		printf("number %c is 字母", c );
	}else{
		printf("number %c not is 字母", c );
	}
}
// 打印99乘法表
void test26(void)
{
	//外层控制行
	for(int i = 1;i<10;i++)
	{
		//内层控制列
		for(int j = 1;j<=i;j++)
		{
			printf("%d * %d = %d \t", i , j , i*j );
		}
		printf("\n");
	}
}
// 斐波那契数列
void test27(void)
{
	int num; //控制  数列 长度
	scanf("%d",&num);
	int i=0, j=1, k=0 ,var = 1;//设置初始值
	printf("\t斐波纳数列第 \t%d 列\t   ---> \t%d \n \t" , 1 , 0 ); //i =  %d ; j = %d ; k = %d;  ,var , i , j
	printf("斐波纳数列第 \t%d 列\t   ---> \t%d \n \t" , 2 , 1 ); //i =  %d ; j = %d ; k = %d;  ,var , i , j
	while(var<=num){
		k = j+i;
		printf("斐波纳数列第 \t%d 列\t   ---> \t%d \n \t" , var+2 , k ); //i =  %d ; j = %d ; k = %d;  ,var , i , j
		i = j ;
		j = k ;
		var++;
	}
//	for (int var = 1 ; var <= num; var++) {
//		k = j+i;
//		printf("斐波纳数列第 %d 列  ：i =  %d ; j = %d ; k = %d;" , var , i , j , k );
//		i = j ;
//		j = k ;
//		printf(" ---> %d ;\n" , k );
//	}
}
// 输出26个字母
void test28(void)
{
	int i = 'a';
	printf("小写字母：");
	while(i>='a'&&i<='z'){
		printf(" %c ;" , i );
		i++;
	}
	i = 'A';
	printf("\n大写字母：");
	while(i>='A'&&i<='Z'){
		printf(" %c ;" , i );
		i++;
	}
}

int x(int num)
{
	count2++;
	printf("--------------%d   __%d \n",count2,num);
	if(num<=3){
		return 1;
	}else{
		return x(num-2)+x(num-4)+1;
	}
}
