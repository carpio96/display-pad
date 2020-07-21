#include "string.h"
#include "usb.h"

uint8_t keyboardHID[9];

void usb_init()
{
  keyboardHID[0] = 0x00; //to control Ctrl ,Shift ,Alt ….
  keyboardHID[1] = 0x00;
  keyboardHID[2] = 0x0b;
  keyboardHID[3] = 0x00;
  keyboardHID[4] = 0x00;
  keyboardHID[5] = 0x00;
  keyboardHID[6] = 0x00;
  keyboardHID[7] = 0x00;
  keyboardHID[8] = 0x00;
  USBD_HID_SendReport(&hUsbDeviceFS, keyboardHID, sizeof(keyboardHID));
}

void keyboard_write_char(char caracter)
{
  keyboardHID[KB_KEY1] = caracter;
  USBD_HID_SendReport(&hUsbDeviceFS, keyboardHID, sizeof(keyboardHID));
  HAL_Delay(50);
}

void keyboard_print(char *texto)
{
  for (uint16_t i = 0; i < strlen(texto); i++)
  {
    switch (mirar_simbolo(texto[i]))
    {
    case MINUSCULAS:
      keyboard_write_char(LETRA_MINUSCULA(texto[i]));
      break;

    case MAYUSCULAS:
      keyboard_write_char(USB_HID_KEY_CAPSLOCK); // bloq. mayúsculas on
      keyboard_write_char(LETRA_MAYUSCULA(texto[i]));
      keyboard_write_char(USB_HID_KEY_CAPSLOCK); // bloq. mayúsculas off
      break;

    case NUMEROS:
      if (texto[i] == '0')
      {
        keyboard_write_char(TECLA_0);
      }
      else
      {
        keyboard_write_char(NUMERO(texto[i]));
      }
      break;

    default:
      break;
    }
  }
}

uint8_t mirar_simbolo(char simbolo)
{
  uint8_t tipo_simbolo = 0;

  if ((simbolo >= 'a' && simbolo <= 'z')) // letras minúsculas
  {
    tipo_simbolo = MINUSCULAS;
  }

  if ((simbolo >= 'A' && simbolo <= 'Z')) // letras mayúsculas
  {
    tipo_simbolo = MAYUSCULAS;
  }

  if ((simbolo >= '0' && simbolo <= '9')) // números
  {
    tipo_simbolo = NUMEROS;
  }

  return tipo_simbolo;
}
