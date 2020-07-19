#include "lvgl.h"
#include "panel_login.h"
#include "usb.h"

void init_panel_login(void)
{
    // Columna 1
    lv_obj_t *texto_7; // Botón 7
    lv_obj_t *boton_7 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_7, handler_boton_7);
    lv_obj_set_width(boton_7, ANCHO_BOTON);

    lv_obj_align(boton_7, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_1, EJE_Y_LINEA_1);
    texto_7 = lv_label_create(boton_7, NULL);
    lv_label_set_text(texto_7, "7");

    lv_obj_t *texto_8; // Botón 8
    lv_obj_t *boton_8 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_8, handler_boton_8);
    lv_obj_set_width(boton_8, ANCHO_BOTON);
    lv_obj_align(boton_8, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_2, EJE_Y_LINEA_1);
    texto_8 = lv_label_create(boton_8, NULL);
    lv_label_set_text(texto_8, "8");

    lv_obj_t *texto_9; // Botón 9
    lv_obj_t *boton_9 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_9, handler_boton_9);
    lv_obj_set_width(boton_9, ANCHO_BOTON);
    lv_obj_align(boton_9, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_3, EJE_Y_LINEA_1);
    texto_9 = lv_label_create(boton_9, NULL);
    lv_label_set_text(texto_9, "9");

    // Columna 2
    lv_obj_t *texto_4; // Botón 4
    lv_obj_t *boton_4 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_4, handler_boton_4);
    lv_obj_set_width(boton_4, ANCHO_BOTON);
    lv_obj_align(boton_4, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_1, EJE_Y_LINEA_2);
    texto_4 = lv_label_create(boton_4, NULL);
    lv_label_set_text(texto_4, "4");

    lv_obj_t *texto_5; // Botón 5
    lv_obj_t *boton_5 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_5, handler_boton_5);
    lv_obj_set_width(boton_5, ANCHO_BOTON);
    lv_obj_align(boton_5, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_2, EJE_Y_LINEA_2);
    texto_5 = lv_label_create(boton_5, NULL);
    lv_label_set_text(texto_5, "5");

    lv_obj_t *texto_6; // Botón 6
    lv_obj_t *boton_6 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_6, handler_boton_6);
    lv_obj_set_width(boton_6, ANCHO_BOTON);
    lv_obj_align(boton_6, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_3, EJE_Y_LINEA_2);
    texto_6 = lv_label_create(boton_6, NULL);
    lv_label_set_text(texto_6, "6");

    // Columna 3
    lv_obj_t *texto_1; // Botón 1
    lv_obj_t *boton_1 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_1, handler_boton_1);
    lv_obj_set_width(boton_1, ANCHO_BOTON);
    lv_obj_align(boton_1, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_1, EJE_Y_LINEA_3);
    texto_1 = lv_label_create(boton_1, NULL);
    lv_label_set_text(texto_1, "1");

    lv_obj_t *texto_2; // Botón 2
    lv_obj_t *boton_2 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_2, handler_boton_2);
    lv_obj_set_width(boton_2, ANCHO_BOTON);
    lv_obj_align(boton_2, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_2, EJE_Y_LINEA_3);
    texto_2 = lv_label_create(boton_2, NULL);
    lv_label_set_text(texto_2, "2");

    lv_obj_t *texto_3; // Botón 3
    lv_obj_t *boton_3 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_3, handler_boton_3);
    lv_obj_set_width(boton_3, ANCHO_BOTON);
    lv_obj_align(boton_3, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_3, EJE_Y_LINEA_3);
    texto_3 = lv_label_create(boton_3, NULL);
    lv_label_set_text(texto_3, "3");

    // Columna 4
    lv_obj_t *texto_punto; // Botón .
    lv_obj_t *boton_punto = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_punto, handler_boton_punto);
    lv_obj_set_width(boton_punto, ANCHO_BOTON);
    lv_obj_align(boton_punto, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_1, EJE_Y_LINEA_4);
    texto_punto = lv_label_create(boton_punto, NULL);
    lv_label_set_text(texto_punto, ".");

    lv_obj_t *texto_0; // Botón 0
    lv_obj_t *boton_0 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_0, handler_boton_0);
    lv_obj_set_width(boton_0, ANCHO_BOTON);
    lv_obj_align(boton_0, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_2, EJE_Y_LINEA_4);
    texto_0 = lv_label_create(boton_0, NULL);
    lv_label_set_text(texto_0, "0");

    lv_obj_t *texto_borrar; // Botón borrar
    lv_obj_t *boton_borrar = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(boton_borrar, handler_boton_borrar);
    lv_obj_set_width(boton_borrar, ANCHO_BOTON);
    lv_obj_align(boton_borrar, NULL, LV_ALIGN_CENTER, EJE_X_COLUM_3, EJE_Y_LINEA_4);
    texto_borrar = lv_label_create(boton_borrar, NULL);
    lv_label_set_text(texto_borrar, "x");

    // Caja password
    caja_password = lv_textarea_create(lv_scr_act(), NULL); // Caja password
    lv_textarea_set_text(caja_password, "");
    lv_textarea_set_pwd_mode(caja_password, true);
    lv_textarea_set_one_line(caja_password, true);
    lv_textarea_set_cursor_hidden(caja_password, false);
    lv_textarea_set_max_length(caja_password, 5); // máximo 5 chars. Si no quieres límite, apágalo
    lv_obj_set_width(caja_password, 250);
    lv_obj_set_pos(caja_password, 450, 180);
    lv_page_set_scrollbar_mode(caja_password, LV_SCROLLBAR_MODE_OFF); // para que no se vea el scroll

    lv_obj_t *pwd_label = lv_label_create(lv_scr_act(), NULL); // Texto password
    lv_label_set_text(pwd_label, "Password:");
    lv_obj_align(pwd_label, caja_password, LV_ALIGN_OUT_TOP_LEFT, 0, -10);

    // Botón enviar password
    lv_obj_t *label;
    lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(btn1, handler_boton_aceptar);
    lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, 130, 140);
    label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, "Aceptar");
}

void handler_boton_7(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '7');
    }
}

void handler_boton_8(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '8');
    }
}

void handler_boton_9(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '9');
    }
}

void handler_boton_4(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '4');
    }
}

void handler_boton_5(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '5');
    }
}

void handler_boton_6(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '6');
    }
}

void handler_boton_1(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '1');
    }
}

void handler_boton_2(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '2');
    }
}

void handler_boton_3(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '3');
    }
}

void handler_boton_punto(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '.');
    }
}

void handler_boton_0(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '0');
    }
}

void handler_boton_borrar(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_del_char(caja_password);
    }
}

void handler_boton_aceptar(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        keyboard_write(TECLA_H);
        keyboard_write(TECLA_O);
        keyboard_write(TECLA_L);
        keyboard_write(TECLA_A);
        keyboard_write(TECLA_SPACE);
        keyboard_write(TECLA_M);
        keyboard_write(TECLA_U);
        keyboard_write(TECLA_N);
        keyboard_write(TECLA_D);
        keyboard_write(TECLA_O);
        keyboard_write(TECLA_ENTER);

        HAL_Delay(30);
        // mirar si el password coincide
    }
}