#ifndef _panel_login_h_
#define _panel_login_h_

#define EJE_Y_LINEA_1 -40
#define EJE_Y_LINEA_2 20
#define EJE_Y_LINEA_3 80
#define EJE_Y_LINEA_4 140

#define EJE_X_COLUM_1 -270
#define EJE_X_COLUM_2 -160
#define EJE_X_COLUM_3 -50

#define ANCHO_BOTON 100

static lv_obj_t *caja_password;

void init_panel_login(void);

void handler_boton_7(lv_obj_t *obj, lv_event_t event);
void handler_boton_8(lv_obj_t *obj, lv_event_t event);
void handler_boton_9(lv_obj_t *obj, lv_event_t event);

void handler_boton_4(lv_obj_t *obj, lv_event_t event);
void handler_boton_5(lv_obj_t *obj, lv_event_t event);
void handler_boton_6(lv_obj_t *obj, lv_event_t event);

void handler_boton_1(lv_obj_t *obj, lv_event_t event);
void handler_boton_2(lv_obj_t *obj, lv_event_t event);
void handler_boton_3(lv_obj_t *obj, lv_event_t event);

void handler_boton_punto(lv_obj_t *obj, lv_event_t event);
void handler_boton_0(lv_obj_t *obj, lv_event_t event);
void handler_boton_borrar(lv_obj_t *obj, lv_event_t event);

void handler_boton_aceptar(lv_obj_t *obj, lv_event_t event);

#endif
