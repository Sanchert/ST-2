// Copyright 2026 UNN-CS
#ifndef INCLUDE_CIRCLE_TASK_H_
#define INCLUDE_CIRCLE_TASK_H_

#define EARTH_RADIUS_KM 6378.1
#define EARTH_RADIUS_M (EARTH_RADIUS_KM * 1000.0)

/**
 * @brief Решение задачи "Земля и верёвка"
 * @param additional_length Дополнительная длина верёвки в метрах (по умолчанию 1)
 * @return Величина зазора в метрах
 */
double EarthRope(double additioanl_length = 1.0);

/**
 * @brief Решение задачи "Бассейн"
 * @param pool_radius Радиус бассейна в метрах (по умолчанию 3.0)
 * @param road_width Ширина дорожки в метрах (по умолчанию 1.0)
 * @param concrete_price Стоимость бетона за кв.м (по умолчанию 1000)
 * @param fence_price Стоимость ограды за погонный метр (по умолчанию 2000)
 * @return Общая стоимость материалов
 */
double Pool(double pool_radius = 3.0,
           double road_width = 1.0,
           double concrete_price = 1000.0,
           double fence_price = 2000.0);

#endif  // INCLUDE_CIRCLE_TASKS_H_
