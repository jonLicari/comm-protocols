/*	This example shows data transfer between two buffers
 *  located in USB RAM. Data read in from HID can be stored 
 *	in writebuff, written to readbuff, and then accessed 
 *	from readbuff to be used elsewhere by the MCU.
 */
unsigned char readbuff[64] absolute 0x500;
unsigned char writebuff[64] absolute 0x540;

char count;

void interrupt() {
	USB_Interrupt_Proc();
}

void main() {
	HID_Enable(&readbuff, &writebuff);	// Enabling USB communication

	while(1) {
		while(!HID_Read());	// While there is data to read
		for (count = 0; count < 64; count++) {
			writebuff[count] = readbuff[count]+1;
			while(!HID_Write(&writebuff, 64));
		}
	}
}
