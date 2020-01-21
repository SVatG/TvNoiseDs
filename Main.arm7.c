#include <nds.h>

#include "Hardware.h"

void VcountHandler() {
	inputGetAndSend();
}

void VblankHandler(void) {
	// Empty
}

int main()
{
	powerOn(POWER_SOUND);

	irqInit();
	fifoInit();

	SetYtrigger(80);

	
	irqSet(IRQ_VCOUNT, VcountHandler);
	irqSet(IRQ_VBLANK, VblankHandler);

	initClockIRQ();

	irqEnable( IRQ_VBLANK | IRQ_VCOUNT | IRQ_NETWORK);   

	readUserSettings();

	SOUND14TMR=SOUNDxTMR_FREQ(44100);
	SOUND14CNT=SOUNDxCNT_VOLUME_MAX|SOUNDxCNT_PAN_MID
			|SOUNDxCNT_LOOP|SOUNDxCNT_PSG|SOUNDxCNT_START;
	SOUND15TMR=SOUNDxTMR_FREQ(44100);
	SOUND15CNT=SOUNDxCNT_VOLUME_MAX|SOUNDxCNT_PAN_MID
			|SOUNDxCNT_LOOP|SOUNDxCNT_PSG|SOUNDxCNT_START;

	SOUNDBIAS=SOUNDBIAS_NORMAL;
	SOUNDCNT=SOUNDCNT_VOLUME_MAX|SOUNDCNT_ENABLE;

	for(;;)
	{
		swiWaitForVBlank();
	}
}
