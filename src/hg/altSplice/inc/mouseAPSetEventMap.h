/* mouseAPSetEventMap.h was originally generated by the autoSql program, which also 
 * generated mouseAPSetEventMap.c and mouseAPSetEventMap.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef MOUSEAPSETEVENTMAP_H
#define MOUSEAPSETEVENTMAP_H

#ifndef JKSQL_H
#include "jksql.h"
#endif

#define MOUSEAPSETEVENTMAP_NUM_COLS 6

struct mouseAPSetEventMap
/* Mapping from skip probe sets to includes and gene probe sets. */
    {
    struct mouseAPSetEventMap *next;  /* Next in singly linked list. */
    char *geneName;	/* Gene Name */
    char *skipPSet;	/* Skipping probe set. */
    unsigned incCount;	/* Number of include probe sets. */
    char **incPSets;	/* Names of include probe sets. */
    unsigned geneCount;	/* Number of gene probe sets. */
    char **genePSets;	/* Names of gene probe sets. */
    };

struct mouseAPSetEventMap *mouseAPSetEventMapLoad(char **row);
/* Load a mouseAPSetEventMap from row fetched with select * from mouseAPSetEventMap
 * from database.  Dispose of this with mouseAPSetEventMapFree(). */

struct mouseAPSetEventMap *mouseAPSetEventMapLoadAll(char *fileName);
/* Load all mouseAPSetEventMap from whitespace-separated file.
 * Dispose of this with mouseAPSetEventMapFreeList(). */

struct mouseAPSetEventMap *mouseAPSetEventMapLoadAllByChar(char *fileName, char chopper);
/* Load all mouseAPSetEventMap from chopper separated file.
 * Dispose of this with mouseAPSetEventMapFreeList(). */

#define mouseAPSetEventMapLoadAllByTab(a) mouseAPSetEventMapLoadAllByChar(a, '\t');
/* Load all mouseAPSetEventMap from tab separated file.
 * Dispose of this with mouseAPSetEventMapFreeList(). */

struct mouseAPSetEventMap *mouseAPSetEventMapLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all mouseAPSetEventMap from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with mouseAPSetEventMapFreeList(). */

void mouseAPSetEventMapSaveToDb(struct sqlConnection *conn, struct mouseAPSetEventMap *el, char *tableName, int updateSize);
/* Save mouseAPSetEventMap as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. Strings are automatically escaped to allow insertion into the database. */

struct mouseAPSetEventMap *mouseAPSetEventMapCommaIn(char **pS, struct mouseAPSetEventMap *ret);
/* Create a mouseAPSetEventMap out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new mouseAPSetEventMap */

void mouseAPSetEventMapFree(struct mouseAPSetEventMap **pEl);
/* Free a single dynamically allocated mouseAPSetEventMap such as created
 * with mouseAPSetEventMapLoad(). */

void mouseAPSetEventMapFreeList(struct mouseAPSetEventMap **pList);
/* Free a list of dynamically allocated mouseAPSetEventMap's */

void mouseAPSetEventMapOutput(struct mouseAPSetEventMap *el, FILE *f, char sep, char lastSep);
/* Print out mouseAPSetEventMap.  Separate fields with sep. Follow last field with lastSep. */

#define mouseAPSetEventMapTabOut(el,f) mouseAPSetEventMapOutput(el,f,'\t','\n');
/* Print out mouseAPSetEventMap as a line in a tab-separated file. */

#define mouseAPSetEventMapCommaOut(el,f) mouseAPSetEventMapOutput(el,f,',',',');
/* Print out mouseAPSetEventMap as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* MOUSEAPSETEVENTMAP_H */

