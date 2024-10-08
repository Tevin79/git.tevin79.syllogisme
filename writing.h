#ifndef WRITING_H
#define WRITING_H

/* Initialise and allocate a table of char* (string).
 * Exemple of usage :
 *   char **propTable = initProp();
 * Initiate and allocate propTable so it can be used later.
 */
char **initProp(void);

/* Add a string at the index of the table of strings previously initiated.
 * Returns 0 if it fails else 1.
 * Exemple of usage :
 *    addProp(propTable, 1, prop);
 * Add the string prop at the index 1 of the table of strings propTable.
 */
int addProp(char **props, int index, char *value);

/* Remove a string in the table of strings previously initiated at the index between 0 and 2.
 * Returns 0 if fail else 1.
 * Exemple of usage :
 *    removeProp(propTable, 1);
 * Removes in the table of strings the element at the index 1.
 */
int removeProp(char **props, int index);

/* Remove an element in the table of strings at the given index and replace it with the value.
 * Returns 0 if fail else 1.
 * Exemple of usage :
 *    replaceProp(propTable, 1, prop);
 * Replaces the value at the index 1 of the table propTable by prop.
 */
int replaceProp(char **props, int index, char *value);

/* Print in the console the props table.
 * Exemple of usage :
 *    printProp(propTable);
 * Prints in the console the element at the index 1 of the table propTable.
 *
 */
void printProps(char **props);

/* Delete and free the table of strings passed in the parameters.
 * Exemple of usage :
 *    freeProp(propTable);
 * Removes and free all the elements inside propTable.
 */
void freeProp(char **props);

#endif //WRITING_H
