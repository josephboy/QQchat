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
        Login();
        break;
    case 2: /* register */
        Register();
        break;
    default: /* exit */
        break;
    }
}

/**
 * @Function : user rerister a chat room account
 * @Description : none
 * @Input : none
 * @Return : none
 */
void Register(void)
{
    char name[NAME_MAX_LEN] = {0};
    char password[PASSWORD_MAX_LEN] = {0};
    char password_buf[PASSWORD_MAX_LEN] = {0};
    int count = 0;

    printf("Register Interface\n");
    /* check user name if legal */
    do
    {
        printf("Please input your name:");
        scanf("%s", name);
        if (0 == CheckNameIfExist(name))
        {
            break;
        }
        {
            printf("the user name is already exist\n");
        }
    } while (1);
    /* check user password if legal */
    printf("Please input your passowrd:");
    scanf("%s", password);
    do
    {
        printf("Please input your passowrd again:");
        scanf("%s", password_buf);
        if (strcmp(password, password_buf) != 0)
        {
            if (count++ > MAX_TIMES)
            {
                return;
            }
            printf("The passwords are different\n");
            
        }
        else
        {
            break;
        }
    } while (1);
    
    
    
}   



/**
 * @Function : user login in chat room
 * @Description : none
 * @Input : none
 * @Return : none
 */
void Login(void)
{
    char name[NAME_MAX_LEN] = {0};
    char password[PASSWORD_MAX_LEN] = {0};
    char pw[PASSWORD_MAX_LEN] = {0};

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
    DatabaseInit();
    login();
    return 0;
}