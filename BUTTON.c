#include "DIO.h"

void BUTTON_init(unsigned char portname,unsigned char pinnumber)
{
	DIO_setPINDir(portname,pinnumber,0);
}
unsigned char BUTTON_read(unsigned char portname,unsigned char pinnumber)
{
	return DIO_readPIN(portname,pinnumber);
}