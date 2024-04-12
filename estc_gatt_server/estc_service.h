#ifndef ESTC_SERVICE_H__
#define ESTC_SERVICE_H__

#include <stdint.h>

#include "ble.h"
#include "sdk_errors.h"

// TODO: 1. Generate random BLE UUID (Version 4 UUID) and define it in the following format:
#define ESTC_BASE_UUID { 0xFC, 0x87, 0x98, 0x0A, 0x41, 0x69, 0x3C, 0x82, 0x2F, 0x45, 0x58, 0x0E, 0xA3, 0x48, 0xD7, 0x40 }  // UUID: 40d748a3-0e58-452f-823c-6941fa0987fc

// TODO: 2. Pick a random service 16-bit UUID and define it:
#define ESTC_SERVICE_UUID 0x183A

// TODO: 3. Pick a characteristic UUID and define it:
#define ESTC_GATT_CHAR_1_UUID 0xfc83
#define ESTC_NOTIFY_CHAR_UUID 0xfc84
#define ESTC_INDICATION_CHAR_UUID 0xfc85

typedef struct
{
    uint16_t service_handle;
    uint16_t connection_handle;

    ble_gatts_char_handles_t char_handle;
    ble_gatts_char_handles_t notify_char_handle;
    ble_gatts_char_handles_t indication_char_handle;
    // TODO: 6.3. Add handles for characterstic (type: ble_gatts_char_handles_t)
} ble_estc_service_t;

ret_code_t estc_ble_service_init(ble_estc_service_t *service);

ret_code_t estc_ble_char_notify_value_update(ble_estc_service_t *service, uint8_t value);

ret_code_t estc_ble_char_indicate_value_update(ble_estc_service_t *service, uint8_t value);

#endif /* ESTC_SERVICE_H__ */