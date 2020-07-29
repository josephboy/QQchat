#include "login.h"
#include "database.h"



/**
 * @Function : QQ Chat Room main page
 * @Description : none
 * @Input : none
 * @Return : none
 */
void interface(void)
{
    int mode = 0;
    printf("Welcome to QQ chat room !\n");
    printf("Please select function:\n");
    printf("1、login\t 2、register\t 3、exit\n");
    scanf("%d", &mode);
    switch (mode)
    {
    case 1: /* login */
        
        break;
    case 2: /* register */

        break;
    default: /* exit */
        break;
    }
}


void login(void)
{
    char name[NAME_MAX_LEN] = {0};
    char password[PASSWORD_MAX_LEN] = {0};
    char pw[PASSWORD_MAX_LEN] = {0};

    DatabaseInit();
    printf("Login Interface\n");
    printf("Please input your name:");
    scanf("%s", name);
    printf("Please input your password:");
    scanf("%s", password);

    if (0 == GetUserPassword(name, pw))
    {
        //printf("%s:GetUserPassword Successfully!\n", __func__);
        if (strcmp(password, pw) == 0)
        {
            printf("Login Successfully!\n");
        }
        else
        {
            printf("Login Failed! Please check your password\n");
        }
        
    }
    else
    {
        printf("Login Failed! Please check your name\n");
    }
    
}


int main(void)
{
    login();
    return 0;
}