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
 char cost [ 10 ] ;
 
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
 
#line 40 "prog.pgc"
 char strSelect [ 256 ] ;
/* exec sql end declare section */
#line 41 "prog.pgc"

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
	ECPGt_char,(cost),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(description),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 67 "prog.pgc"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
		printf("\t %s \t %s \t %s \t %s \n", title, service_title, cost, description);
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

int show_all()
{
	/* exec sql begin declare section */  
		 
		 
		 
		
#line 177 "prog.pgc"
 int colcount ;
 
#line 178 "prog.pgc"
 char str [ 1024 ] ;
 
#line 179 "prog.pgc"
 char colName [ 1024 ] ;
 
#line 180 "prog.pgc"
 int index ;
/* exec sql end declare section */
#line 181 "prog.pgc"



		{ ECPGprepare(__LINE__, NULL, 0, "mystr", strSelect);}
#line 184 "prog.pgc"

		ECPGallocate_desc(__LINE__, "myDescr");
#line 185 "prog.pgc"

		/* declare show_cursor cursor for $1 */
#line 186 "prog.pgc"

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare show_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "mystr", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 187 "prog.pgc"

		while (1) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from show_cursor", ECPGt_EOIT, 
	ECPGt_descriptor, "myDescr", 1L, 1L, 1L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 189 "prog.pgc"

				if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
				{ ECPGget_desc_header(__LINE__, "myDescr", &(colcount));
}
#line 191 "prog.pgc"

				for(index =1; index <= colcount; index++)
				{
					{ ECPGget_desc(__LINE__, "myDescr", index,ECPGd_data,
	ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);
}
#line 194 "prog.pgc"

					{ ECPGget_desc(__LINE__, "myDescr", index,ECPGd_name,
	ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);
}
#line 195 "prog.pgc"

					printf( "%s: %s\t",colName,str);
					}
						printf( "\n");}
				printf( "\n");
	{ ECPGdeallocate(__LINE__, 0, NULL, "mystr");}
#line 200 "prog.pgc"

	ECPGdeallocate_desc(__LINE__, "myDescr");
#line 201 "prog.pgc"


    { ECPGtrans(__LINE__, NULL, "commit");}
#line 203 "prog.pgc"

    return 0;
}

int Dynamic_sql_insert_operators()
{
/* exec sql begin declare section */

 
        
#line 211 "prog.pgc"
 char stmt [] = "INSERT INTO operators(title,network_type) VALUES(?, ?);" ;
/* exec sql end declare section */
#line 212 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 214 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 216 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 217 "prog.pgc"

        return 0;
}
int Dynamic_sql_insert_owners()
{
/* exec sql begin declare section */

 
        
#line 224 "prog.pgc"
 char stmt [] = "INSERT INTO owners(n_passport, full_name) VALUES(?, ?);" ;
/* exec sql end declare section */
#line 225 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 227 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(full_name),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 229 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 230 "prog.pgc"

        return 0;
}
int Dynamic_sql_insert_services()
{
/* exec sql begin declare section */

 
        
#line 237 "prog.pgc"
 char stmt [] = "INSERT INTO services(title, service_title, cost, description) VALUES(?, ?, ?, ?);" ;
/* exec sql end declare section */
#line 238 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 240 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(cost),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(description),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 242 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 243 "prog.pgc"

        return 0;
}

int Dynamic_sql_insert_subscriptions()
{
/* exec sql begin declare section */

 
        
#line 251 "prog.pgc"
 char stmt [] = "INSERT INTO subscriptions(title, number, service_title,n_passport, date_sub) VALUES(?, ?, ?, ?, ?);" ;
/* exec sql end declare section */
#line 252 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 254 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_sub),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 256 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 257 "prog.pgc"

        return 0;
}

int Dynamic_sql_insert_phone()
{
/* exec sql begin declare section */

 
        
#line 265 "prog.pgc"
 char stmt [] = "INSERT INTO phone(title, number,  date_reg ) VALUES(?, ?, ?);" ;
/* exec sql end declare section */
#line 266 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 268 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_reg),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 270 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 271 "prog.pgc"

        return 0;
}
int Dynamic_sql_insert_contracts()
{
/* exec sql begin declare section */

 
				
#line 278 "prog.pgc"
 char stmt [] = "INSERT INTO contracts(title, number,  date_reg,n_passport ) VALUES(?, ?, ?, ?);" ;
/* exec sql end declare section */
#line 279 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 281 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_reg),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 283 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 284 "prog.pgc"

        return 0;
}
int Dynamic_sql_insert_calls()
{
/* exec sql begin declare section */

 
				
#line 291 "prog.pgc"
 char stmt [] = "INSERT INTO calls(title_inc, title_out, date_call, out_num, incoming_num, duration ) VALUES(?, ?, ?, ?,?,?);" ;
/* exec sql end declare section */
#line 292 "prog.pgc"


       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);}
#line 294 "prog.pgc"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 296 "prog.pgc"

       { ECPGtrans(__LINE__, NULL, "commit");}
#line 297 "prog.pgc"

        return 0;
}

int Delete_values_opertatos()
{
        printf("select deleted title: ");
        scanf("%s", title);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from operators where title = $1 ", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 305 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 307 "prog.pgc"

				return 0;
}

int Delete_values_owners()
{
        printf("select deleted n_passport: ");
        scanf("%s", n_passport);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from owners where n_passport = $1 ", 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 315 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 317 "prog.pgc"

				return 0;
}
int Delete_values_services()
{
        printf("select deleted title: ");
        scanf("%s", title);
				printf("and service_title: ");
        scanf("%s", service_title);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from services where title = $1  and service_title = $2 ", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 326 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 328 "prog.pgc"

				return 0;
}
int Delete_values_subscriptions()
{
        printf("select deleted n_passport: ");
        scanf("%s", n_passport);
				printf("and service_title: ");
        scanf("%s", service_title);
				printf("and number: ");
        scanf("%s", number);
				printf("and date_sub: ");
        scanf("%s", date_sub);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from subscriptions where n_passport = $1  and service_title = $2  and number = $3  and date_sub = $4 ", 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_sub),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 341 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 343 "prog.pgc"

				return 0;
}
int Delete_values_phone()
{
        printf("select deleted title: ");
        scanf("%s", title);
				printf("and number: ");
        scanf("%s", number);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from phone where title = $1  and number = $2 ", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 353 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 355 "prog.pgc"

				return 0;
}
int Delete_values_contracts()
{
        printf("select deleted n_passport: ");
        scanf("%s", n_passport);
				printf("and title: ");
        scanf("%s", title);
				printf("and number: ");
        scanf("%s", number);
				printf("and date_cont: ");
        scanf("%s", date_cont);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from contracts where n_passport = $1  and title = $2  and number = $3  and date_cont = $4 ", 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_cont),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 368 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 370 "prog.pgc"

				return 0;
}

int Delete_values_calls()
{
        printf("select deleted incoming_num: ");
        scanf("%s", incoming_num);
				printf("and out_num: ");
        scanf("%s", out_num);
				printf("and date_call: ");
        scanf("%s", date_call);
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from calls where incoming_num = $1  and out_num = $2  and date_call = $3 ", 
	ECPGt_char,(incoming_num),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(out_num),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_call),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 382 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 384 "prog.pgc"

				return 0;
}

int Dynamic_sql_select()
{
	/* exec sql begin declare section */  
		 
		 
		 
		
#line 390 "prog.pgc"
 int colcount ;
 
#line 391 "prog.pgc"
 char str [ 1024 ] ;
 
#line 392 "prog.pgc"
 char colName [ 1024 ] ;
 
#line 393 "prog.pgc"
 int index ;
/* exec sql end declare section */
#line 394 "prog.pgc"



		{ ECPGprepare(__LINE__, NULL, 0, "mystr", strSelect);}
#line 397 "prog.pgc"

		ECPGallocate_desc(__LINE__, "myDescr");
#line 398 "prog.pgc"
 /* declare my_cursor cursor for $1 */
#line 398 "prog.pgc"
 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare my_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "mystr", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 398 "prog.pgc"

		while (1) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from my_cursor", ECPGt_EOIT, 
	ECPGt_descriptor, "myDescr", 1L, 1L, 1L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 400 "prog.pgc"

				if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
				{ ECPGget_desc_header(__LINE__, "myDescr", &(colcount));
}
#line 402 "prog.pgc"

				for(index =1; index <= colcount; index++)
				{
					{ ECPGget_desc(__LINE__, "myDescr", index,ECPGd_data,
	ECPGt_char,(str),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);
}
#line 405 "prog.pgc"

					{ ECPGget_desc(__LINE__, "myDescr", index,ECPGd_name,
	ECPGt_char,(colName),(long)1024,(long)1,(1024)*sizeof(char), ECPGd_EODT);
}
#line 406 "prog.pgc"

					printf( "%s: %s\t",colName,str);
					}
						printf( "\n");}
				printf( "\n");
	{ ECPGdeallocate(__LINE__, 0, NULL, "mystr");}
#line 411 "prog.pgc"

	ECPGdeallocate_desc(__LINE__, "myDescr");
#line 412 "prog.pgc"


    { ECPGtrans(__LINE__, NULL, "commit");}
#line 414 "prog.pgc"

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
#line 425 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 427 "prog.pgc"

        return 0;
}
int Update_values_owners()
{
        printf("select update where full_name:");
        scanf("%s", full_name);
        printf("enter new  n_passport: ");
        scanf("%s", n_passport);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update owners set full_name = $1  where n_passport = $2 ", 
	ECPGt_char,(full_name),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 437 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 439 "prog.pgc"

        return 0;
}
int Update_values_services()
{
				printf("select update where title: ");
				scanf("%s", title);
				printf("service_title: ");
				scanf("%s", service_title);
				printf("enter new cost: ");
				scanf("%s", cost);
				printf("description: ");
				scanf("%s", description);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update services set description = $1  where title = $2  and service_title = $3 ", 
	ECPGt_char,(description),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 453 "prog.pgc"

				{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update services set cost = $1  where title = $2  and service_title = $3 ", 
	ECPGt_char,(cost),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 454 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 456 "prog.pgc"

        return 0;
}
int Update_values_phone()
{
			printf("select update where title: ");
			scanf("%s", title);
			printf("number: ");
			scanf("%s", number);
			printf("enter new date_reg: ");
			scanf("%s", date_reg);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update phone set date_reg = $1  where title = $2  and number = $3 ", 
	ECPGt_char,(date_reg),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 468 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 470 "prog.pgc"

        return 0;
}
int Update_values_subscriptions()
{
			printf("select update where number: ");
			scanf("%s", number);
			printf("service_title: ");
			scanf("%s", service_title);
			printf("n_passport: ");
			scanf("%s", n_passport);
			printf("date_sub: ");
			scanf("%s", date_sub);
			printf("enter new title: ");
			scanf("%s", title);
      { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update subscriptions set title = $1  where n_passport = $2  and service_title = $3  and number = $4  and date_sub = $5 ", 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n_passport),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(service_title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(number),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_sub),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 485 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 487 "prog.pgc"

        return 0;
}

int Update_values_contracts()
{
			printf("No update");
        return 0;
}
int Update_values_calls()
{
			printf(" select update where out_num: ");
			scanf("%s", out_num);
			printf("incoming_num: ");
			scanf("%s", incoming_num);
			printf("date_call: ");
			scanf("%s", date_call);
      printf("enter new title_inc: ");
			scanf("%s", title_inc);
			printf("title_out: ");
			scanf("%s", title_out);
			printf("duration: ");
			scanf("%s", duration);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update calls set title_inc = $1  and title_out = $2  and duration = $3  where incoming_num = $4  and out_num = $5  and date_call = $6 ", 
	ECPGt_char,(title_inc),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(title_out),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(duration),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(incoming_num),(long)11,(long)1,(11)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(out_num),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date_call),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 511 "prog.pgc"


        { ECPGtrans(__LINE__, NULL, "commit");}
#line 513 "prog.pgc"

        return 0;
}
int Dynamic_sql_select_more_opertatos()
{
	/* exec sql begin declare section */
              
             
             
     
#line 519 "prog.pgc"
 const char * stmt = "SELECT title,network_type " "  FROM operators " "  WHERE network_type=?" ;
/* exec sql end declare section */
#line 522 "prog.pgc"


     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 524 "prog.pgc"


     /* declare operators_cursor cursor for $1 */
#line 526 "prog.pgc"


			printf("select network_type:");
      scanf("%s", network_type);

     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare operators_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 531 "prog.pgc"



     while (1)
     {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch operators_cursor", ECPGt_EOIT, 
	ECPGt_char,(title),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(network_type),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 536 "prog.pgc"

        if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
				printf("\t %s \t %s \n", title, network_type);
     }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close operators_cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 541 "prog.pgc"


    { ECPGtrans(__LINE__, NULL, "commit");}
#line 543 "prog.pgc"

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
			Update_values_owners();

			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			Update_values_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			Update_values_subscriptions();

			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			Update_values_phone();

			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			Update_values_contracts();

			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("3. update values\n");
			Update_values_calls();

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
			strcpy(strSelect, "select * from operators");
			show_all();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("1. show\n");
			strcpy(strSelect, "select * from owners");
			show_all();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("1. show\n");
			strcpy(strSelect, "select * from services");
			show_all();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("1. show\n");
			strcpy(strSelect, "select * from subscriptions");
			show_all();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("1. show\n");
			strcpy(strSelect, "select * from phone");
			show_all();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("1. show\n");
			strcpy(strSelect, "select * from contracts");
			show_all();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("1. show\n");
			strcpy(strSelect, "select * from calls");
			show_all();
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
			Delete_values_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			Delete_values_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			Delete_values_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			Delete_values_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			Delete_values_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("5. delete values\n");
			Delete_values_calls();
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
			printf("Title: ");
			scanf("%s", title);
			printf("Network type: ");
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
			printf("n_passport: ");
			scanf("%s", n_passport);
			printf("full_name: ");
			scanf("%s", full_name);
			Dynamic_sql_insert_owners();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			printf("title: ");
			scanf("%s", title);
			printf("service_title: ");
			scanf("%s", service_title);
			printf("cost: ");
			scanf("%s", cost);
			printf("description: ");
			scanf("%s", description);
			Dynamic_sql_insert_services();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			printf("title: ");
			scanf("%s", title);
			printf("number: ");
			scanf("%s", number);
			printf("service_title: ");
			scanf("%s", service_title);
			printf("n_passport: ");
			scanf("%s", n_passport);
			printf("date_sub: ");
			scanf("%s", date_sub);
			Dynamic_sql_insert_subscriptions();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			printf("title: ");
			scanf("%s", title);
			printf("number: ");
			scanf("%s", number);
			printf("date_reg: ");
			scanf("%s", date_reg);
			Dynamic_sql_insert_phone();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			printf("title: ");
			scanf("%s", title);
			printf("number: ");
			scanf("%s", number);
			printf("date_cont: ");
			scanf("%s", date_cont);
			printf("n_passport: ");
			scanf("%s", n_passport);
			Dynamic_sql_insert_contracts();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("6. Dynamic sql insert\n");
			printf("title_inc: ");
			scanf("%s", title_inc);
			printf("title_out: ");
			scanf("%s", title_out);
			printf("date_call: ");
			scanf("%s", date_call);
			printf("out_num: ");
			scanf("%s", out_num);
			printf("incoming_num: ");
			scanf("%s", incoming_num);
			printf("duration: ");
			scanf("%s", duration);
			Dynamic_sql_insert_calls();
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
			strcpy(strSelect, "select * from operators");
			Dynamic_sql_select();
			printf("_____________________\n");
			break;
		}
		case '2':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			strcpy(strSelect, "select * from owners");
			Dynamic_sql_select();
			printf("_____________________\n");
			break;
		}
		case '3':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			strcpy(strSelect, "select * from services");
			Dynamic_sql_select();
			printf("_____________________\n");
			break;
		}
		case '5':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			strcpy(strSelect, "select * from subscriptions");
			Dynamic_sql_select();
			printf("_____________________\n");
			break;
		}
		case '4':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			strcpy(strSelect, "select * from phone");
			Dynamic_sql_select();
			printf("_____________________\n");
			break;
		}
		case '6':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			strcpy(strSelect, "select * from contracts");
			Dynamic_sql_select();
			printf("_____________________\n");
			break;
		}
		case '7':
		{
			printf("_____________________\n");
			printf("7. Dynamic sql select one\n");
			strcpy(strSelect, "select * from calls");
			Dynamic_sql_select();
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
#line 1211 "prog.pgc"

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
#line 1222 "prog.pgc"

printf("disconnect --OK\n");

return 0;
}