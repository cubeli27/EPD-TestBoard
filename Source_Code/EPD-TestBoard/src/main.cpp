#include "PDLS_Common.h"
#include "Pervasive_Wide_Small.h"

// ----------------------
// Use 417 driver (for your 4.20" screen)
#define SCRN 417
#include "globalupdate_src/demoImageData.h"

// ----------------------
// ESP32-C3 pin configuration
pins_t myBoard =
{
    .scope      = BOARD_EXT3,
    .panelBusy  = 3,
    .panelDC    = 1,
    .panelReset = 2,
    .flashCS    = NOT_CONNECTED,
    .panelCS    = 7,
    .panelCSS   = NOT_CONNECTED,
    .flashCSS   = NOT_CONNECTED,
    .touchInt   = NOT_CONNECTED,
    .touchReset = NOT_CONNECTED,
    .panelPower = NOT_CONNECTED,
    .cardCS     = NOT_CONNECTED,
    .cardDetect = NOT_CONNECTED,
    .button     = NOT_CONNECTED,
    .ledData    = NOT_CONNECTED,
    .nfcFD      = NOT_CONNECTED,
    .imuInt1    = NOT_CONNECTED,
    .imuInt2    = NOT_CONNECTED,
    .weatherInt = NOT_CONNECTED
};

// ----------------------
// Driver instance
Pervasive_Wide_Small myDriver(eScreen_EPD_417_KS_0D, myBoard);

void setup() {
    hV_HAL_begin();
    myDriver.begin();

    // Show the prebuilt demo image
    myDriver.updateNormal(BW_monoBuffer, frameSize);

    // Keep visible for 5 seconds
    hV_HAL_delayMilliseconds(5000);
    hV_HAL_exit();
}

void loop() {
    // Nothing needed
}
