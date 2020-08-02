#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>

#define TARGET_MAX_LEN 20
#define CONDITION_MAX_LEN 20

extern void DatabaseInit(void);
extern void DatabaseClose();
extern int GetUserPassword(char *name, char *password);
extern int GetUserName(char *name, char *reslut);
extern int CheckNameIfExist(char *name);

#endif