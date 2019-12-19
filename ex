
int Dynamic_sql_select_phone(){
	 EXEC SQL BEGIN DECLARE SECTION;
          const char *stmt = "SELECT title, number,  date_reg "
             "  FROM phone "
             "  WHERE title=? and number=?";
     EXEC SQL END DECLARE SECTION;

     EXEC SQL PREPARE sqlstmt FROM :stmt;

    printf("select title: ");
    scanf("%s", title);
    printf("and number: ");
    scanf("%s", number);

    EXEC SQL EXECUTE sqlstmt INTO :title,  :number, :date_reg USING :title,  :number;
    printf("\t %s \t %s \t %s \n", title, number,  date_reg );



    EXEC SQL COMMIT;
    return 0;
}
int Dynamic_sql_select_subscriptions(){
	 EXEC SQL BEGIN DECLARE SECTION;


          const char *stmt = "SELECT title, number, service_title,n_passport, date_sub "
             "  FROM subscriptions "
             "  WHERE service_title=? and number=? and n_passport=? and date_sub=?";
     EXEC SQL END DECLARE SECTION;
     EXEC SQL PREPARE sqlstmt FROM :stmt;

    printf("select n_passport: ");
    scanf("%s", n_passport);
    printf("and service_title: ");
    scanf("%s", service_title);
    printf("and number: ");
    scanf("%s", number);
    printf("and date_sub: ");
    scanf("%s", date_sub);

    EXEC SQL EXECUTE sqlstmt INTO :title,  :number, :service_title, :n_passport, :date_sub USING :number, :service_title, :n_passport, :date_sub;
    printf("\t %s \t %s \t %s \t %s \t %s \n", title, number, service_title,n_passport, date_sub);



    EXEC SQL COMMIT;
    return 0;
}

int Dynamic_sql_select_contracts(){
	 EXEC SQL BEGIN DECLARE SECTION;

          const char *stmt = "SELECT title, number, date_cont,n_passport "
             "  FROM contracts "
             "  WHERE title=? and number=? and n_passport=? and date_cont=?";
     EXEC SQL END DECLARE SECTION;
     EXEC SQL PREPARE sqlstmt FROM :stmt;

    printf("select n_passport: ");
    scanf("%s", n_passport);
    printf("and title: ");
    scanf("%s", title);
    printf("and number: ");
    scanf("%s", number);
    printf("and date_cont: ");
    scanf("%s", date_cont);

    EXEC SQL EXECUTE sqlstmt INTO :title,  :number, :date_cont, :n_passport USING :title,  :number, :date_cont, :n_passport;
    printf("\t %s \t %s \t %s \t %s  \n", title, number, date_cont, n_passport);



    EXEC SQL COMMIT;
    return 0;
}
int Dynamic_sql_select_calls(){
	 EXEC SQL BEGIN DECLARE SECTION;
          const char *stmt = "SELECT title_inc, title_out, date_call, out_num, incoming_num, duration "
             "  FROM calls "
             "  WHERE incoming_num=? and out_num=? and date_call=?";
     EXEC SQL END DECLARE SECTION;
     EXEC SQL PREPARE sqlstmt FROM :stmt;

    printf("select incoming_num: ");
    scanf("%s", incoming_num);
    printf("and out_num: ");
    scanf("%s", out_num);
    printf("and date_call: ");
    scanf("%s", date_call);
    EXEC SQL EXECUTE sqlstmt INTO :title_inc, :title_out, :date_call, :out_num, :incoming_num, :duration USING :incoming_num,  :out_num, :date_call;
    printf("\t %s \t %s \t %s \t %s \t %s \t %s \n", title_inc, title_out, date_call, out_num, incoming_num, duration);


    EXEC SQL COMMIT;
    return 0;
}