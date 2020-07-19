#ifndef _usb_h_
#define _usb_h_

#include "usbd_hid.h"
#include "usbd_def.h"
#include "usb_device.h" // de aquí pillamos el handler del usb

// USB media codes
#define USB_HID_SCAN_NEXT 0x01
#define USB_HID_SCAN_PREV 0x02
#define USB_HID_STOP 0x04
#define USB_HID_EJECT 0x08
#define USB_HID_PAUSE 0x10
#define USB_HID_MUTE 0x20
#define USB_HID_VOL_UP 0x40
#define USB_HID_VOL_DEC 0x80

// USB keyboard codes
#define USB_HID_MODIFIER_LEFT_CTRL 0x01
#define USB_HID_MODIFIER_LEFT_SHIFT 0x02
#define USB_HID_MODIFIER_LEFT_ALT 0x04
#define USB_HID_MODIFIER_LEFT_GUI 0x08 // (Win/Apple/Meta)

#define USB_HID_MODIFIER_RIGHT_CTRL 0x10
#define USB_HID_MODIFIER_RIGHT_SHIFT 0x20 // en el usb HID surt 0xE5
#define USB_HID_MODIFIER_RIGHT_ALT 0x40
#define USB_HID_MODIFIER_RIGHT_GUI 0x80


#define TECLA_3 91

#define TECLA_A 4
#define TECLA_B 5
#define TECLA_C 6
#define TECLA_D 7
#define TECLA_E 8
#define TECLA_F 9
#define TECLA_G 10
#define TECLA_H 11
#define TECLA_I 12
#define TECLA_J 13
#define TECLA_K 14
#define TECLA_L 15
#define TECLA_M 16
#define TECLA_N 17
#define TECLA_O 18
#define TECLA_P 19
#define TECLA_Q 20
#define TECLA_R 21
#define TECLA_S 22
#define TECLA_T 23
#define TECLA_U 24
#define TECLA_V 25
#define TECLA_W 26
#define TECLA_X 27
#define TECLA_Y 28
#define TECLA_Z 29

#define TECLA_SPACE 0x2c
#define TECLA_ENTER 0x28

#define KB_ID 0
#define KB_MODIFIERS 1
#define KB_KEY1 2
#define KB_KEY2 3
#define KB_KEY3 4


uint8_t buffer[9]; // 9 = nº màxim de dades

void usb_init();
void keyboard_write(uint8_t char1);


#endif
