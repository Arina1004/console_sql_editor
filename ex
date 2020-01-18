int select_operators_with_join(){
	EXEC SQL BEGIN DECLARE SECTION;
		const char *stmt="SELECT o.title, o.network_type ,p.number, p.date_reg"
		"FROM phone AS p"
		"INNER JOIN operators AS o ON p.title = o.title WHERE p.date_reg >= ?;";
	EXEC SQL END DECLARE SECTION;
	printf("SELECT o.title, o.network_type ,p.number, p.date_reg, FROM phone AS p INNER JOIN operators AS o ON p.title = o.title WHERE p.date_reg >= ?: ");
	scanf("%s", date_reg);
	EXEC SQL PREPARE select_stmt FROM :stmt;
  EXEC SQL DECLARE select_with_join_one_cursor CURSOR FOR select_stmt;
  EXEC SQL OPEN select_with_join_one_cursor USING :date_reg;

  while(1) {
    EXEC SQL FETCH select_with_join_one_cursor INTO :title, :network_type, :number, :date_reg;
    if (sqlca.sqlcode == ECPG_NOT_FOUND) {printf("Not found\n");}
    if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
    printf("title: %s\t network_type:%s\t number: %s\t  date_reg: %s\t\n", title, network_type, number, date_reg);
  }
  EXEC SQL CLOSE select_with_join_one_cursor;
  EXEC SQL COMMIT;

  return 0;


}