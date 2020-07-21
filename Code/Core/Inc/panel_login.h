#ifndef _panel_login_h_
#define _panel_login_h_

// macros / defines
#define ANCHO_BOTON 100

#define SIZE_PASSWORD_LOGIN 4
#define SIZE_PASSWORD_ENVIO 20
#define NUM_PASSWORDS 3

#define BTN_7 0
#define BTN_8 1
#define BTN_9 2
#define BTN_4 3
#define BTN_5 4
#define BTN_6 5
#define BTN_1 6
#define BTN_2 7
#define BTN_3 8
#define BTN_PUNTO 9
#define BTN_0 10
#define BTN_X 11
#define BTN_ACEPTAR 12
#define N_BOTONES 13

#define EJE_X 0
#define EJE_Y 1

// variables, structs, etc
extern uint8_t puntero_password_recibido;

extern char password_recibido[SIZE_PASSWORD_LOGIN];
extern char passwords_login[NUM_PASSWORDS][SIZE_PASSWORD_LOGIN];
extern char passwords_envio[NUM_PASSWORDS][SIZE_PASSWORD_ENVIO];


// funciones

void init_panel_login(void);
void crear_botones(lv_obj_t **boton, char **texto, lv_obj_t **texto_label, int16_t *eje_x, int16_t *eje_y, lv_event_cb_t* callback);
void crear_caja_password();
void crear_texto_mensajes();


void cb_btn_7(lv_obj_t *obj, lv_event_t event);
void cb_btn_8(lv_obj_t *obj, lv_event_t event);
void cb_btn_9(lv_obj_t *obj, lv_event_t event);

void cb_btn_4(lv_obj_t *obj, lv_event_t event);
void cb_btn_5(lv_obj_t *obj, lv_event_t event);
void cb_btn_6(lv_obj_t *obj, lv_event_t event);

void cb_btn_1(lv_obj_t *obj, lv_event_t event);
void cb_btn_2(lv_obj_t *obj, lv_event_t event);
void cb_btn_3(lv_obj_t *obj, lv_event_t event);

void cb_btn_punto(lv_obj_t *obj, lv_event_t event);
void cb_btn_0(lv_obj_t *obj, lv_event_t event);
void cb_btn_borrar(lv_obj_t *obj, lv_event_t event);

void cb_btn_aceptar(lv_obj_t *obj, lv_event_t event);

void clean_caracter_password();
void push_caracter_password(char caracter);
void pop_caracter_password();
int8_t check_password();

#endif
