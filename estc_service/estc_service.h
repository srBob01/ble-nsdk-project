#ifndef ESTC_SERVICE_H__
#define ESTC_SERVICE_H__

#include <stdint.h>

#include "ble.h"
#include "sdk_errors.h"

#include "color_module.h"


// TODO: 1. Generate random BLE UUID (Version 4 UUID) and define it in the following format:
#define ESTC_BASE_UUID  {0x6e, 0xdc, 0x54, 0xbf, 0x5c, 0x0c, /* - */ 0xa5, 0xa6, /* - */ 0xae, 0x4c, /* - */ 0x92, 0xf0, /* - */ 0xdd, 0xee, 0x27, 0xad }

// TODO: 2. Pick a random service 16-bit UUID and define it:
#define ESTC_SERVICE_UUID 0x92f0

// TODO: 3. Pick a characteristic UUID and define it:
// #define ESTC_GATT_CHAR_1_UUID 0x0001
#define ESTC_GATT_CHAR_1_UUID        0x1234
#define ESTC_NOTIFY_CHAR_UUID        0x1235
#define ESTC_INDICATION_CHAR_UUID    0x1236

typedef struct
{
    uint16_t service_handle;
    uint16_t connection_handle;

    ble_gatts_char_handles_t color_write_handle;
    ble_gatts_char_handles_t color_notify_handle;
} ble_estc_service_t;

ret_code_t estc_ble_service_init(ble_estc_service_t *service);
ret_code_t estc_ble_char_color_write_update(ble_estc_service_t *service, color_rgb_t value);
ret_code_t estc_ble_char_color_notify_update(ble_estc_service_t *service, color_rgb_t value);

#endif /* ESTC_SERVICE_H__ */