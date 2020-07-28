#include "database.h"

#define HOST  "localhost"       /*host name*/
#define USER  "root"             /*user name*/
#define PASSWORD  "123"           /*user password*/
#define DB "QQ"                     /*database name*/
#define TABLE_NAME "tb_user"        /* table name */ 

MYSQL sql;  /* QQ database fd */
MYSQL *rsql; /* connect fd */


/**
 * @Function : database init
 * @Description : none
 * @Input : none
 * @Return : none
 */
void DatabaseInit(void)
{
    if (NULL == mysql_init(&sql))
    {
        printf("mysql_init error:%s\n", mysql_error(&sql));
        exit(-1);
    }
    rsql = mysql_real_connect(&sql, HOST, USER, PASSWORD, DB, 0, NULL, 0);
    if (NULL == rsql)
    {
        printf("mysql_real_connect error:%s!\n", mysql_error(&sql));
        exit(-1);
    }
    printf("Connected to QQ database successful!\n");

   
}


void DatabaseClose()
{
    mysql_close(rsql);
}


/**
 * @Function : Add infomation to database
 * @Description : none
 * @Input : user name , user password
 * @Return : none
 */
void InsertDatabaseData(char *name, char *password)
{
    char inser_str[100];

    sprintf(inser_str, "insert into db_user (id, name, password) values ('%s', '%s')", name, password);
    int ret = mysql_real_query(&sql, inser_str, strlen(inser_str));
    if (0 != ret)
    {
        printf("%s:mysql_real_query error:%s\n", __func__, mysql_error(rsql));
        exit(-1);
    }
}

/**
 * @Function : Delete database infomation
 * @Description : none
 * @Input : user name , user password
 * @Return : none
 */
void DeleteDatabaseData(char *name, char *password)
{
    char inser_str[100];

    sprintf(inser_str, "delete from db_user (id, name, password) values ('%s', '%s')", name, password);
    int ret = mysql_real_query(&sql, inser_str, strlen(inser_str));
    if (0 != ret)
    {
        printf("%s:mysql_real_query error:%s\n", __func__, mysql_error(rsql));
        exit(-1);
    }
}


/**
 * @Function : Modify database infomation
 * @Description : none
 * @Input : user name , user password
 * @Return : none
 */
void AlterDatabaseData(char *name, char *password)
{
    char inser_str[100];

    sprintf(inser_str, "update db_user set password = '%s' where name = '%s'", password, name);
    int ret = mysql_real_query(&sql, inser_str, strlen(inser_str));
    if (0 != ret)
    {
        printf("%s:mysql_real_query error:%s\n", __func__, mysql_error(rsql));
        exit(-1);
    }
}


/**
 * @Function : Inquire infomation on database
 * @Description : none
 * @Input : none
 * @Return : none
 */
void InquireDatabaseData(void)
{
    MYSQL_RES *res = NULL;
    MYSQL_ROW row;
    char *query_str = "select * from tb_user";

    /* inquire the table data */
    int ret = mysql_real_query(rsql, query_str, strlen(query_str));
    if (0 != ret)
    {
        printf("%s:mysql_real_query error:%s\n", __func__, mysql_error(rsql));
        exit(-1);
    }

    /* get table result to res */
    res = mysql_store_result(rsql);
    if (NULL == res)
    {
        printf("mysql_store_result error:%s\n", mysql_error(rsql));
        exit(-1);
    }
    
    row = mysql_num_rows(res);
    printf("The total rows is :%d\n", row);

    int fields = mysql_num_fields(res);
    printf("The total fields is: %d\n", fields);

    while ((row = mysql_fetch_row(res))) 
    {
        for (int i = 0; i < fields; i++) 
        {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    
    mysql_free_result(res);
}

int main(void)
{
    DatabaseInit();
    InquireDatabaseData();
    DatabaseClose();
}
