#include "estc_service.h"

#include "app_error.h"
#include "nrf_log.h"

#include "ble.h"
#include "ble_gatts.h"
#include "ble_srv_common.h"

ret_code_t estc_ble_service_init(ble_estc_service_t *service)
{
    ret_code_t error_code = NRF_SUCCESS;

    // TODO: 3. Add service UUIDs to the BLE stack table using `sd_ble_uuid_vs_add`
    ble_uuid128_t base_128_uuid = {ESTC_BASE_UUID};
    
    ble_uuid_t service_uuid = {
        .uuid = ESTC_SERVICE_UUID,
        .type = BLE_UUID_TYPE_VENDOR_BEGIN
    };

    error_code = sd_ble_uuid_vs_add(&base_128_uuid, &service_uuid.type);

    APP_ERROR_CHECK(error_code);

    // TODO: 4. Add service to the BLE stack using `sd_ble_gatts_service_add`

    error_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY, &service_uuid, &service->service_handle);

    APP_ERROR_CHECK(error_code);

    NRF_LOG_DEBUG("%s:%d | Service UUID: 0x%04x", __FUNCTION__, __LINE__, service_uuid.uuid);
    NRF_LOG_DEBUG("%s:%d | Service UUID type: 0x%02x", __FUNCTION__, __LINE__, service_uuid.type);
    NRF_LOG_DEBUG("%s:%d | Service handle: 0x%04x", __FUNCTION__, __LINE__, service->service_handle);

    return NRF_SUCCESS;
}
