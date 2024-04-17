#ifndef PWM_BLE_H
#define PWM_BLE_H

#include "nrfx_systick.h"
#include "nrfx_pwm.h"
#include "nrfx_gpiote.h"
#include "app_util_platform.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_log_backend_usb.h"

#include "gpio_module.h"
#include "color_module.h"

#define NUMBER_OF_PLAYBACKS 1

#ifndef GPIO_PWM_DUTY_CYCLE_PERIOD_US
#define GPIO_PWM_DUTY_CYCLE_PERIOD_US 1000
#endif
extern volatile nrf_pwm_values_individual_t pwm_values;

void pwm_set_rgb_color_ble(color_rgb_t * color);

void pwm_init_ble(color_rgb_t * color);

#endif