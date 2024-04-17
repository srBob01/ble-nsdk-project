#include "pwm_ble.h"


static nrfx_pwm_t pwm_inst     = NRFX_PWM_INSTANCE(0);

volatile nrf_pwm_values_individual_t pwm_values;

static nrf_pwm_sequence_t const    m_rgb_seq =
{
    .values              = (nrf_pwm_values_t){.p_individual = (nrf_pwm_values_individual_t *)&pwm_values},
    .length              = NRF_PWM_VALUES_LENGTH(pwm_values),
    .repeats             = 0
};

static nrfx_pwm_config_t pwm_config =
{
    .output_pins =
    {
        LED_2 | NRFX_PWM_PIN_INVERTED,
        LED_3 | NRFX_PWM_PIN_INVERTED,
        LED_4 | NRFX_PWM_PIN_INVERTED,
        NRFX_PWM_PIN_NOT_USED
    },
    .irq_priority = APP_IRQ_PRIORITY_LOWEST,
    .base_clock = NRF_PWM_CLK_1MHz,
    .count_mode = NRF_PWM_MODE_UP,
    .top_value = RGB_LED_TOP_VALUE,
    .load_mode = NRF_PWM_LOAD_INDIVIDUAL,
    .step_mode = NRF_PWM_STEP_AUTO
};

static void pwm_rgb_evt_handler(nrfx_pwm_evt_type_t event_type)
{
}

void pwm_set_rgb_color_ble(color_rgb_t * color)
{
    pwm_values.channel_0 = color->red;
    pwm_values.channel_1 = color->green;
    pwm_values.channel_2 = color->blue;
    pwm_values.channel_3 = 0;
}

void pwm_init_ble(color_rgb_t * color)
{
    nrfx_pwm_init(&pwm_inst, &pwm_config, pwm_rgb_evt_handler);

    pwm_set_rgb_color_ble(color);

    nrfx_pwm_simple_playback(&pwm_inst, &m_rgb_seq, NUMBER_OF_PLAYBACKS, NRFX_PWM_FLAG_LOOP);
}