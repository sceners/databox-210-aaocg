/*

 ****** This key-gen was done for educational purposes only !!! ******

 *  by TNB/AAOCG/
 *  www.aaocg.prv.pl
 *
 *  program:  DataBox 2.1 from SimpleWebFX
 *  location: http://www.simplewebfx.com
 *  what:     key-file generator source

name!=Thomas Weiser
druga litera name musi byc inna niz pierwsza
 */

#include <conio.h>
#include <stdio.h>
#include <string.h>

#define NAME_LEN 10
char KEY_FILE_NAME[] = "databox.reg";

char magic[] = "hackertwat";

int main()
{
	int i;
	char name[16], key[16];
	FILE *f;
	cputs("SimpleWebFX * DataBox v2.1 *\n\rKey-file generator by TNB/AAOCG/\n\r\n\r");
	// get name
	name[0] = NAME_LEN+1; //max lenght + '\0'
	while (1)
	{
		cprintf("Your name (max. 10 chars): "); cgets( name );
		if ( name[2]!=name[2+1] ) break;
		else cputs("\a\n\rSorry man, but this name is illegal for authors of DataBox...\n\r\n\r");
	}
	// padding
	if ( (i=name[1])<10 )
		for (;i<10;i++) name[2+i]='_';
	name[2+NAME_LEN]=0;

	// calculate key
	for (i=0;i<NAME_LEN;i++)
		key[i] = (int(name[i+2]+magic[i]))%10+'0';
	key[NAME_LEN] = 0;

	// write to file
	cputs("\n\r\n\rWriting key-file...");

	if ( (f = fopen( KEY_FILE_NAME, "w+b" ))==NULL )
	{
		cputs("\aCan't open file !?!\n\r");
		perror(KEY_FILE_NAME);
		return -1;
	}
	fputs( name+2, f );
	fputs( "\r\n", f );
	fputs( key, f );

	cputs("OK\n\r");

	fclose(f); //who need it ??
	cprintf("Now, You must copy file '%s' to DataBox's directory!\n\r\n\rany key...", KEY_FILE_NAME );
	getch();
	return 0;
}
//eof