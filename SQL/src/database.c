#include "database.h"

#define HOST  "localhost"       /*host name*/
#define USER  "root"             /*user name*/
#define PASSWORD  "123"           /*user password*/
#define DB "QQ"                     /*database name*/

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

void InsertData(void)
{
    char *inser_str = "insert into db_user (id, name, password) values (1, 'joseph', '123')";
    
    //int ret = mysql_real_query(&sql, inser_str, sizeof(quad_t))
}

void InquireData(void)
{
    MYSQL_RES *res = NULL;
    MYSQL_ROW row;
    char *query_str = "select * from db_user";

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
    InquireData();
    DatabaseClose();
}
