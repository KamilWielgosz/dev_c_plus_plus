#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

#include <windows.h>
#include "mysql.h"

static char *opt_host_name = "localhost"; /* server host (default=localhost) */
static char *opt_user_name = "root"; /* username (default=login name) */
static char *opt_password = ""; /* password (default=none) */
static unsigned int opt_port_num = 3306; /* port number (use built-in value) */
static char *opt_socket_name = NULL; /* socket name (use built-in value) */
static char *opt_db_name = "mysql"; /* database name (default=none) */
static unsigned int opt_flags = 0; /* connection flags (none) */

int main (int argc, char *argv[])
{
    MYSQL *conn; /* pointer to connection handler */
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    
    /* initialize connection handler */
    conn = mysql_init (NULL);
    
    /* connect to server */
    mysql_real_connect (conn, opt_host_name, opt_user_name, opt_password,
    opt_db_name, opt_port_num, opt_socket_name, opt_flags);
    
    /* show tables in the database (test for errors also) */
    if(mysql_query(conn, "show tables"))
    {
        fprintf(stderr, "%s \n", mysql_error(conn));
        printf("Press any key to continue. . . ");
        getch();
        exit(1);
    }    
    
    res = mysql_use_result(conn); /* grab the result */
    
    printf("Tables in database\n");
    while((row = mysql_fetch_row(res)) != NULL)
        printf("%s \n", row[0]);
    
    /* disconnect from server */
    mysql_close (conn);
    
    printf("Press any key to continue . . . ");
    getch();
    return 0;
} /* end main function */
