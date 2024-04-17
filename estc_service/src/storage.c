#include "storage.h"
#include <string.h>

void init_flash(nrf_fstorage_t *fstorage)
{
    int ret = nrf_fstorage_init(fstorage, &nrf_fstorage_sd, NULL);
    APP_ERROR_CHECK(ret);
}

void fstorage_evt_handler(nrf_fstorage_evt_t * p_evt)
{
    if (p_evt->result != NRF_SUCCESS)
    {
        NRF_LOG_INFO("ERROR with fstorage using");
        return;
    }

}

void save_to_flash(color_rgb_t *m_color_value, nrf_fstorage_t *fstorage, uint32_t *color_value_flash)
{
    int ret;

    if (!nrf_fstorage_is_busy(fstorage))
    {
        ret = nrf_fstorage_erase(fstorage, FSTORAGE_ADDRESS, 1, NULL);
        APP_ERROR_CHECK(ret);

        *color_value_flash = 0;

        memcpy(color_value_flash, m_color_value, sizeof(color_rgb_t));

        ret = nrf_fstorage_write(fstorage, FSTORAGE_ADDRESS, color_value_flash, sizeof(uint32_t), NULL);
        APP_ERROR_CHECK(ret);
    }
}

void read_from_flash(nrf_fstorage_t *fstorage, uint32_t *color_value_flash, color_rgb_t *m_color_value)
{
    int ret = nrf_fstorage_read(fstorage, FSTORAGE_ADDRESS, color_value_flash, sizeof(*color_value_flash));
    memcpy(m_color_value, color_value_flash, sizeof(*m_color_value));
    APP_ERROR_CHECK(ret);
}