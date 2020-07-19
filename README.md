# Display-pad:


![Display](https://github.com/victorgg1993/display-pad/tree/master/Img/modulo.jpg)

Implementación módulo con pantalla táctil que envía texto ( emulando un teclado USB ) cuando la contraseña de acceso es correcta.

+ __Core__ - Carpeta con el código principal.
    - Inc - Headers del código generado por el usuario y el autogenerado.
    - Src - Archivos fuente del código generado por el usuario y el autogenerado. También contiene el main.

* __Drivers__ - Capa de abstracción generada por el fabricante.

+ __FATFS__ - Capa de abstracción para poder usar el formato FAT32. Seguramente acabará fuera.

* __MiddleWares__ - Distintos módulos usados ( usb, fatFS, LVGL).
    - __Third_Party/FatFs__ - Librería para poder usar el formato Fat32.
    - __Third_Party/FreeRTOS__ - Librería para usar el sistema operativo FreeRTOS. Da problemas de stack con LVGL, de momento no se usa, quizás acabará fuera.
    - __Third_Party/LVGL__ - Librería que se encarga de generar todos los gráficos, botones, sliders, etc. La capa de abstracción está dentro de la propia librería en __lv_hal__ .
     
+ __USB_DEVICE__ - Capa de abstracción para poder usar la librería USB.

* __NewProject.ioc__ - Archivo STM32CubeMX para la configuración del dispositivo STM32F446RE nucleo.

+ __openocd.cfg__ - Documento de configuración para openOCD. Desde el makefile puedes flashear el binario en el microcontrolador.


# Comandos:

Compilar:

```
make all
```

Limpiar el proyecto:

```
make clean
```

Flashear código compilado en el micro:

```
make burn
```
