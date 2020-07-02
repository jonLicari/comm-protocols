/* LED Control via USB
 */

unsigned char readbuff[64] absolute 0x500;
unsigned char writebuff[64] absolute 0x540;

char count;

void interrupt() {

	USB_Interrupt_Proc();
}

void main() {

	trisd = 0x00;	// Set port D pins to output
	
	HID_Enable(&readbuff, &writebuff);	// Enabling USB communication

	while(1) {

		while(!HID_Read());
	
		writebuff[count] = readbuff[count];
		
		while(!HID_Write(&writebuff, 64));

			if (strncmp(readbuff, "A", 1) == 0) {
				HID_Write("Success", 64);
				portd.f0 = 1;
				portd.f1 = 1;
				portd.f2 = 1;
				portd.f3 = 1;				
			}
			else {
				HID_Write("Fail", 64);
				portd.f0 = 0;
				portd.f1 = 0;
				portd.f2 = 0;
				portd.f3 = 0;
			}
	}
}
