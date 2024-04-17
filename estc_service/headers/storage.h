#include "nrf_fstorage.h"
#include "nrf_fstorage_sd.h"
#include "color_module.h"
#include "app_error.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_log_backend_usb.h"

#define FSTORAGE_ADDRESS        0xde000
#define FSTORAGE_ADDRESS_END    FSTORAGE_ADDRESS + 0xfff

uint32_t color_value_flash;

void init_flash(nrf_fstorage_t *fstorage);

void fstorage_evt_handler(nrf_fstorage_evt_t * p_evt);

void save_to_flash(color_rgb_t *m_color_value, nrf_fstorage_t *fstorage, uint32_t *color_value_flash);

void read_from_flash(nrf_fstorage_t *fstorage, uint32_t *color_value_flash, color_rgb_t *m_color_value);
