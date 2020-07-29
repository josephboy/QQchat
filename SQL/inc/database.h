#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>


extern void DatabaseClose();
extern int GetUserPassword(char *name, char *password);
extern void DatabaseInit(void);

#endif