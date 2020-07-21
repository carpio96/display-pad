#include "lvgl.h"
#include "panel_login.h"
#include "usb.h"

char password_recibido[SIZE_PASSWORD_LOGIN] = {0};
uint8_t una_vez = 0;
uint8_t puntero_password_recibido = 0;
lv_obj_t *caja_password;
lv_obj_t *area_texto_mensajes;
lv_obj_t *texto_password;

char *simbolo_btn[N_BOTONES] = {"7", "8", "9", "4", "5", "6", "1", "2", "3", ".", "0", "x", "Aceptar"};

int16_t eje_x[N_BOTONES] = {-270, -160, -50, -270, -160, -50, -270, -160, -50, -270, -160, -50, 130};
int16_t eje_y[N_BOTONES] = {-40, -40, -40, 20, 20, 20, 80, 80, 80, 140, 140, 140, 140};

lv_obj_t *label_btn[N_BOTONES];
lv_obj_t *boton[N_BOTONES];

lv_event_cb_t cb_bt[N_BOTONES] = {cb_btn_7, cb_btn_8, cb_btn_9, cb_btn_4, cb_btn_5, cb_btn_6, cb_btn_1,
                                  cb_btn_2, cb_btn_3, cb_btn_punto, cb_btn_0, cb_btn_borrar, cb_btn_aceptar};

char passwords_login[NUM_PASSWORDS][SIZE_PASSWORD_LOGIN] =
    {
        {'5', '9', '1', '6'}, // password 0
        {'4', '4', '8', '8'}, // password 1
        {'1', '2', '3', '4'}, // password 2
};

char password[NUM_PASSWORDS][SIZE_PASSWORD_ENVIO] =
    {{"a25pn22zwx19v"},
     {"1234567890abc"},
     {"defghijklmnop"}};

// inicialización de estructuras
void init_panel_login(void)
{
    crear_botones(boton, simbolo_btn, label_btn, eje_x, eje_y, cb_bt);
    crear_caja_password();
    crear_texto_mensajes();
}

void crear_botones(lv_obj_t **boton, char **texto, lv_obj_t **texto_label, int16_t *eje_x, int16_t *eje_y, lv_event_cb_t *callback)
{
    for (int i = BTN_7; i <= BTN_ACEPTAR; i++)
    {
        boton[i] = lv_btn_create(lv_scr_act(), NULL);
        lv_obj_set_event_cb(boton[i], callback[i]);
        lv_obj_set_width(boton[i], ANCHO_BOTON);

        lv_obj_align(boton[i], NULL, LV_ALIGN_CENTER, eje_x[i], eje_y[i]);
        texto_label[i] = lv_label_create(boton[i], NULL);
        lv_label_set_text(texto_label[i], texto[i]);
    }
}

void crear_caja_password()
{
    caja_password = lv_textarea_create(lv_scr_act(), NULL); // Caja password
    lv_textarea_set_text(caja_password, "");
    lv_textarea_set_pwd_mode(caja_password, false);
    lv_textarea_set_one_line(caja_password, true);
    lv_textarea_set_cursor_hidden(caja_password, false);
    lv_textarea_set_max_length(caja_password, SIZE_PASSWORD_LOGIN); // máximo X chars. Si no quieres límite, apágalo
    lv_obj_set_width(caja_password, 250);
    lv_obj_set_pos(caja_password, 450, 180);
    lv_page_set_scrollbar_mode(caja_password, LV_SCROLLBAR_MODE_OFF); // para que no se vea el scroll

    texto_password = lv_label_create(lv_scr_act(), NULL); // Texto password
    lv_label_set_text(texto_password, "Password:");
    lv_obj_align(texto_password, caja_password, LV_ALIGN_OUT_TOP_LEFT, 0, -10);
}

void crear_texto_mensajes()
{
    area_texto_mensajes = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(area_texto_mensajes, LV_LABEL_LONG_SROLL_CIRC); /*Circular scroll*/
    lv_obj_set_width(area_texto_mensajes, 150);
    lv_label_set_recolor(area_texto_mensajes, true);
    lv_label_set_text(area_texto_mensajes, "");
    lv_obj_align(area_texto_mensajes, NULL, LV_ALIGN_CENTER, 125, 20);
}

// callbacks de los botones
void cb_btn_7(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '7');
        push_caracter_password('7');
    }
}

void cb_btn_8(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '8');
        push_caracter_password('8');
    }
}

void cb_btn_9(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '9');
        push_caracter_password('9');
    }
}

void cb_btn_4(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '4');
        push_caracter_password('4');
    }
}

void cb_btn_5(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '5');
        push_caracter_password('5');
    }
}

void cb_btn_6(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '6');
        push_caracter_password('6');
    }
}

void cb_btn_1(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '1');
        push_caracter_password('1');
    }
}

void cb_btn_2(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '2');
        push_caracter_password('2');
    }
}

void cb_btn_3(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '3');
        push_caracter_password('3');
    }
}

void cb_btn_punto(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '.');
    }
}

void cb_btn_0(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_add_char(caja_password, '0');
        push_caracter_password('0');
    }
}

void cb_btn_borrar(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_textarea_del_char(caja_password);
        pop_caracter_password();
    }
}

void cb_btn_aceptar(lv_obj_t *obj, lv_event_t event)
{
    clean_caracter_password();
    lv_textarea_set_text(caja_password, "");

    int8_t retorno = check_password();

    if (retorno != -1)
    {
        lv_label_set_text(area_texto_mensajes, "#00ff00 Correcto!");

        if (una_vez)
        {
            keyboard_print(password[retorno]);
            una_vez = 0;
        }
    }
    else
    {
        lv_label_set_text(area_texto_mensajes, "#ff0000 Error!");
    }
}

// otras
void clean_caracter_password()
{
    puntero_password_recibido = 0; // limpiamos el puntero
}

void push_caracter_password(char caracter)
{
    password_recibido[puntero_password_recibido] = caracter;
    puntero_password_recibido++;
    una_vez = 1;
}

void pop_caracter_password()
{
    if (puntero_password_recibido > 0) // evitamos underflows raros
    {
        puntero_password_recibido--;
    }
}

int8_t check_password()
{
    int8_t estado = -1; // -1 = error

    for (uint8_t n_password = 0; n_password < NUM_PASSWORDS; n_password++)
    {
        uint8_t i = 0;

        for (i = 0; i < SIZE_PASSWORD_LOGIN; i++)
        {
            if (password_recibido[i] != passwords_login[n_password][i]) // si un char no coincide
            {
                i = 0;
                break; // piramos
            }
        }

        if (i != 0) // si el password fue correcto
        {
            estado = n_password; // devolvemos qué password fue correcto
            break;
        }
    }

    return estado;
}