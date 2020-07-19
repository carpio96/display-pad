#include "usb.h"

void usb_init()
{
  buffer[0] = 0x00; //to control Ctrl ,Shift ,Alt ….
  buffer[1] = 0x00;
  buffer[2] = 0x0b;
  buffer[3] = 0x00;
  buffer[4] = 0x00;
  buffer[5] = 0x00;
  buffer[6] = 0x00;
  buffer[7] = 0x00;
  buffer[8] = 0x00;
  USBD_HID_SendReport(&hUsbDeviceFS, buffer, sizeof(buffer));
}

void keyboard_write(uint8_t char1){

    buffer[2]=char1;
    USBD_HID_SendReport(&hUsbDeviceFS,buffer,sizeof(buffer));
    HAL_Delay(50);
} 
