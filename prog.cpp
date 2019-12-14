/* Processed by ecpg (11.3) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "prog.pgc"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#line 1 "/usr/local/include/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif							/* __CYGWIN__ */
#endif							/* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern "C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 7 "prog.pgc"


#line 1 "/usr/local/include/sqlda.h"
#ifndef ECPG_SQLDA_H
#define ECPG_SQLDA_H

#ifdef _ECPG_INFORMIX_H

#include "sqlda-compat.h"
typedef struct sqlvar_compat sqlvar_t;
typedef struct sqlda_compat sqlda_t;

#else

#include "sqlda-native.h"
typedef struct sqlvar_struct sqlvar_t;
typedef struct sqlda_struct sqlda_t;

#endif

#endif							/* ECPG_SQLDA_H */

#line 8 "prog.pgc"



sqlda_t *sqlda1; /* выходной дескриптор */
sqlda_t *sqlda2; /* входной дескриптор */
/* exec sql begin declare section */

  
 
   


#line 15 "prog.pgc"
 char ConnectionString [] = "phone@localhost:5432" ;
 
#line 16 "prog.pgc"
 char Login [] = "arinashmeleva" ;
 
#line 17 "prog.pgc"
 char Password [] = "" ;
/* exec sql end declare section */
#line 19 "prog.pgc"


/* exec sql begin declare section */
 
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
  

#line 22 "prog.pgc"
 char prep_string [ 256 ] ;
 
#line 23 "prog.pgc"
 char title [ 40 ] ;
 
#line 24 "prog.pgc"
 char n_passport [ 20 ] ;
 
#line 25 "prog.pgc"
 char full_name [ 40 ] ;
 
#line 26 "prog.pgc"
 char network_type [ 10 ] ;
 
#line 27 "prog.pgc"
 char service_title [ 40 ] ;
 
#line 28 "prog.pgc"
 double cost [ 3 ] ;
 
#line 29 "prog.pgc"
 char description [ 256 ] ;
 
#line 30 "prog.pgc"
 char number [ 11 ] ;
 
#line 31 "prog.pgc"
 char date_reg [ 20 ] ;
 
#line 32 "prog.pgc"
 char date_sub [ 20 ] ;
 
#line 33 "prog.pgc"
 char date_cont [ 20 ] ;
 
#line 34 "prog.pgc"
 char title_inc [ 40 ] ;
 
#line 35 "prog.pgc"
 char title_out [ 40 ] ;
 
#line 36 "prog.pgc"
 char date_call [ 30 ] ;
 
#line 37 "prog.pgc"
 char out_num [ 20 ] ;
 
#line 38 "prog.pgc"
 char incoming_num [ 11 ] ;
 
#line 39 "prog.pgc"
 char duration [ 20 ] ;
/* exec sql end declare section */
#line 40 "prog.pgc"


int show_operators(){
	 /* declare OperatorsCursor cursor for select title , network_type from \"operators\" */
#line 44 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare OperatorsCursor cursor for select title , network_type from \"operators\"", ECPGt_EOIT, ECPGt_EORT);}
#line 45 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch OperatorsCursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 48 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \n", title, network_type);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close OperatorsCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 54 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 55 "prog.pgc"

	return 0;

}

int show_services(){

	 /* declare ServicesCursor cursor for select title , service_title , cost , description from \"services\" */
#line 63 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare ServicesCursor cursor for select title , service_title , cost , description from \"services\"", ECPGt_EOIT, ECPGt_EORT);}
#line 64 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch ServicesCursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,(cost),(long)1,(long)3,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(description),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 67 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \t %f \t %s \n", title, service_title, *cost, description);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close ServicesCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 73 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 74 "prog.pgc"

	return 0;

}

int show_owners(){

	 /* declare OwnersCursor cursor for select n_passport , full_name from \"owners\" */
#line 82 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare OwnersCursor cursor for select n_passport , full_name from \"owners\"", ECPGt_EOIT, ECPGt_EORT);}
#line 83 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch OwnersCursor", ECPGt_EOIT, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(full_name),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 86 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \n", n_passport, full_name);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close OwnersCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 92 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 93 "prog.pgc"

	return 0;

}
int show_phone(){

	 /* declare PhoneCursor cursor for select title , number , date_reg from \"phone\" */
#line 100 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare PhoneCursor cursor for select title , number , date_reg from \"phone\"", ECPGt_EOIT, ECPGt_EORT);}
#line 101 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch PhoneCursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_reg),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 104 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \t %s \n", title, number,  date_reg );
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close PhoneCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 110 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 111 "prog.pgc"

	return 0;

}

int show_subscriptions(){


	 /* declare SubscriptionsCursor cursor for select title , number , service_title , n_passport , date_sub from \"subscriptions\" */
#line 120 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare SubscriptionsCursor cursor for select title , number , service_title , n_passport , date_sub from \"subscriptions\"", ECPGt_EOIT, ECPGt_EORT);}
#line 121 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch SubscriptionsCursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_sub),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 124 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \t %s \t %s \t %s \n", title, number, service_title,n_passport, date_sub);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close SubscriptionsCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 130 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 131 "prog.pgc"

	return 0;

}

int show_contracts(){

	 /* declare ContractsCursor cursor for select title , number , date_cont , n_passport from \"contracts\" */
#line 139 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare ContractsCursor cursor for select title , number , date_cont , n_passport from \"contracts\"", ECPGt_EOIT, ECPGt_EORT);}
#line 140 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch ContractsCursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_cont),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 143 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \t %s \t %s  \n", title, number, date_cont, n_passport);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close ContractsCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 149 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 150 "prog.pgc"

	return 0;

}


int show_calls(){

	 /* declare CallsCursor cursor for select title_inc , title_out , date_call , out_num , incoming_num , duration from \"calls\" */
#line 159 "prog.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare CallsCursor cursor for select title_inc , title_out , date_call , out_num , incoming_num , duration from \"calls\"", ECPGt_EOIT, ECPGt_EORT);}
#line 160 "prog.pgc"

	while(1)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch CallsCursor", ECPGt_EOIT, 
	ECPGt_char,(title_inc),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title_out),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_call),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(out_num),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(incoming_num),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(duration),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 163 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \t %s \t %s \t %s \t %s \n", title_inc, title_out, date_call, out_num, incoming_num, duration);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close CallsCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 169 "prog.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 170 "prog.pgc"

	return 0;

}

int Dynamic_sql_insert_operators()
{
/* exec sql begin declare section */

 
        
#line 179 "prog.pgc"
 char stmt [] = "INSERT INTO operators(title,network_type) VALUES(?, ?);" ;
/* exec sql end declare section */
#line 180 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 182 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 184 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 185 "prog.pgc"

        return 0;
}

int Delete_values_opertatos()
{
        printf("select deleted title: ");
        scanf("%s", title);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from operators where title = $1 ", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 193 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 195 "prog.pgc"

				return 0;
}


int Dynamic_sql_select_opertatos()
{
     /* exec sql begin declare section */
              
             
             
     
#line 203 "prog.pgc"
 const char * stmt = "SELECT title,network_type" "  FROM operators " "  WHERE title=?" ;
/* exec sql end declare section */
#line 206 "prog.pgc"




     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 210 "prog.pgc"



    printf("select title: ");
    scanf("%s", title);

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "sqlstmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 216 "prog.pgc"

    printf("\t %s \t %s \n", title, network_type);



    { ECPGtrans(__LINE__, NULL, "commit");}
#line 221 "prog.pgc"

    return 0;
}
int Update_values_operators()
{
        printf("select update title:");
        scanf("%s", title);
        printf("enter new  network_type: ");
        scanf("%s", network_type);


        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update operators set network_type = $1  where title = $2 ", 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 232 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 234 "prog.pgc"

        return 0;
}

int Dynamic_sql_select_more_opertatos()
{
	/* exec sql begin declare section */
              
             
             
     
#line 241 "prog.pgc"
 const char * stmt = "SELECT title,network_type " "  FROM operators " "  WHERE network_type=?" ;
/* exec sql end declare section */
#line 244 "prog.pgc"


     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 246 "prog.pgc"


     /* declare operators_cursor cursor for $1 */
#line 248 "prog.pgc"


			printf("select network_type:");
      scanf("%s", network_type);

     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare operators_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 253 "prog.pgc"




     while (1)
     {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch operators_cursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 259 "prog.pgc"

        if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
				printf("\t %s \t %s \n", title, network_type);
     }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close operators_cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 264 "prog.pgc"


    { ECPGtrans(__LINE__, NULL, "commit");}
#line 266 "prog.pgc"

    return 0;

}
int menu_update_values()
{
char sitem[512];
	while(1)
	{
		printf("	1. operators\n");
		printf("	2. owners\n");
		printf("	3. services\n");
		printf("	4. phone\n");
		printf("	5. subscriptions\n");
		printf("	6. contracts\n");
		printf("	7. calls\n");
		printf("	8. back\n");
		printf("	choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			Update_values_operators();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			show_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			show_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			show_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			show_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			show_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			show_calls();
			printf("_____________________\n");
			break;
		}
		case '8':{
			return 0;

		}
		default: break;
		}
	}
	return 0;
}

int menu_show()
{
char sitem[512];
	while(1)
	{
		printf("	1. operators\n");
		printf("	2. owners\n");
		printf("	3. services\n");
		printf("	4. phone\n");
		printf("	5. subscriptions\n");
		printf("	6. contracts\n");
		printf("	7. calls\n");
		printf("	8. back\n");
		printf("	choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_operators();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("1. show\n");
			show_calls();
			printf("_____________________\n");
			break;
		}
		case '8':{
			return 0;

		}
		default: break;
		}
	}
	return 0;
}
int menu_DeleteValues()
{
char sitem[512];
	while(1)
	{
		printf("	1. operators\n");
		printf("	2. owners\n");
		printf("	3. services\n");
		printf("	4. phone\n");
		printf("	5. subscriptions\n");
		printf("	6. contracts\n");
		printf("	7. calls\n");
		printf("	8. back\n");
		printf("	choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			Delete_values_opertatos();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			show_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			show_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			show_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			show_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			show_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			show_calls();
			printf("_____________________\n");
			break;
		}
		case '8':{
			return 0;

		}
		default: break;
		}
	}
	return 0;
}
int menu_dynamic_sql_insert()
{
char sitem[512];
	while(1)
	{
		printf("	1. operators\n");
		printf("	2. owners\n");
		printf("	3. services\n");
		printf("	4. phone\n");
		printf("	5. subscriptions\n");
		printf("	6. contracts\n");
		printf("	7. calls\n");
		printf("	8. back\n");
		printf("	choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			printf("Title:");
			scanf("%s", title);
			printf("Network type:");
			scanf("%s", network_type);
			Dynamic_sql_insert_operators();
			printf("%s %s %s\n","Add", title, network_type);
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			show_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			show_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			show_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			show_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			show_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			show_calls();
			printf("_____________________\n");
			break;
		}
		case '8':{
			return 0;

		}
		default: break;
		}
	}
	return 0;
}

int menu_dynamic_sql_select_more()
{
char sitem[512];
	while(1)
	{
		printf("	1. operators\n");
		printf("	2. owners\n");
		printf("	3. services\n");
		printf("	4. phone\n");
		printf("	5. subscriptions\n");
		printf("	6. contracts\n");
		printf("	7. calls\n");
		printf("	8. back\n");
		printf("	choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			Dynamic_sql_select_more_opertatos();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			show_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			show_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			show_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			show_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			show_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("8. Dynamic sql select more than one\n");
			show_calls();
			printf("_____________________\n");
			break;
		}
		case '8':{
			return 0;

		}
		default: break;
		}
	}
	return 0;
}
int menu_dynamic_sql_select()
{
char sitem[512];
	while(1)
	{
		printf("	1. operators\n");
		printf("	2. owners\n");
		printf("	3. services\n");
		printf("	4. phone\n");
		printf("	5. subscriptions\n");
		printf("	6. contracts\n");
		printf("	7. calls\n");
		printf("	8. back\n");
		printf("	choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			Dynamic_sql_select_opertatos();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			show_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			show_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			show_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			show_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			show_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			show_calls();
			printf("_____________________\n");
			break;
		}
		case '8':{
			return 0;

		}
		default: break;
		}
	}
	return 0;
}


int menu()
{
	char sitem[512];
	while(1)
	{
		printf("1. show\n");
		printf("3. update values\n");
		printf("5. delete values\n");
		printf("6. Dynamic sql insert\n");
		printf("7. Dynamic sql select one\n");
		printf("8. Dynamic sql select more than one\n");
		printf("9. quit\n");
		printf("choose menu item > ");
		if(scanf("%s", sitem)!=1) break;

if (strlen(sitem)>1) continue;

	switch(sitem[0])
	{
		case '1':
		{
			printf("_____________________\n");
			printf("1. show\n");
			menu_show();
			printf("_____________________\n");
			break;
		}
		 case '3':
			{
				printf("_____________________\n");
				printf("3. update values\n");
				menu_update_values();
				printf("_____________________\n");
				break;
			}
		 case '5':
			{
				printf("_____________________\n");
				printf("5. delete values\n");
				menu_DeleteValues();
				printf("_____________________\n");
				break;
			}
		case '6':
		{
			printf("_____________________\n");
			printf("6. dynamic_sql_insert\n");
			menu_dynamic_sql_insert();
			printf("_____________________\n");
			break;
		}
		case '7':
			{
				menu_dynamic_sql_select();
				break;
			}

		case '8':
			{
				menu_dynamic_sql_select_more();
				break;
			}

		case '9':
		{
			return 0;
		}
		default: break;
		}
	}
	return 0;
}



int main(){

 { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); }
#line 866 "prog.pgc"

 if (sqlca.sqlcode !=0 || strncmp(sqlca.sqlstate,"00",2))
{
	printf("Bad conntected");
	return -1;
}
else
		{
					printf("connect --OK\n");
					menu();
		}
{ ECPGdisconnect(__LINE__, "CURRENT");}
#line 877 "prog.pgc"

printf("disconnect --OK\n");

return 0;
}