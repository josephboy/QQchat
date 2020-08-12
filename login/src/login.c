#include "login.h"
#include "database.h"


static void Register(void);
static int Login(void);

/**
 * @Function : QQ Chat Room main page
 * @Description : none
 * @Input : none
 * @Return : none
 */
int Interface(void)
{
    int mode = 0;
    int ret = 1;

    printf("\n");
    printf("\t\t*******************************************\n");
    printf("\t\t****     Welcome to QQ chat room !     ****\n");
    printf("\t\t*******************************************\n");
    printf("\n");
    do
    {
        printf("\t\t\tPlease select function:\n");
        printf("\t\t1、login\t 2、register\t 3、exit\n");
        scanf("%d", &mode);
        switch (mode)
        {
            case 1: /* login */
                ret = Login();
                break;
            case 2: /* register */
                Register();
                ret = Login();
                break;
            default: /* exit */
                ret = 0;
                break;
        }
    }while (ret);

}

/**
 * @Function : user rerister a chat room account
 * @Description : none
 * @Input : none
 * @Return : none
 */
static void Register(void)
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
            if (++count > MAX_TIMES)
            {
                printf("Excessive number of errors\n");
                return;
            }
            printf("The passwords are different\n");
            
        }
        else
        {
            break;
        }
    } while (1);
    
    if (0 != AddUserCount(name, password))
    {
        printf("[%s] Register failed \n", __func__);
    }

    printf("%s user register successfully!\n", name);
    
}   



/**
 * @Function : user login in chat room
 * @Description : none
 * @Input : none
 * @Return : none
 */
static int Login(void)
{
    char name[NAME_MAX_LEN] = {0};
    char password[PASSWORD_MAX_LEN] = {0};
    char pw[PASSWORD_MAX_LEN] = {0};
    int ret = -1;

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
            ret = 0;
        }
        else
        {
            printf("Login Failed! Please check your password\n");
            ret = -1;
        }
        
    }
    else
    {
        printf("Login Failed! Please check your name\n");
        ret = -1;
    }
    return ret;
    
}

#if 0
int main(void)
{
    DatabaseInit();
    Interface();
    return 0;
}
#endif