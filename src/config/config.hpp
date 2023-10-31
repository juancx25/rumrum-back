#ifndef CONFIG
#define CONFIG

class Config{
    public:
        static const uint8_t LED_PLACA = 2;

        static const uint8_t ENA = 14;
        static const uint8_t IN1 = 12;
        static const uint8_t IN2 = 13;

        static const uint8_t ENB = 4;
        static const uint8_t IN3 = 5;
        static const uint8_t IN4 = 16;

        static const uint8_t LED_ADELANTE = 0;
        static const uint8_t LED_ATRAS = 10;

        static const uint8_t PIN_PARLANTE = 15;

        static const uint8_t PIN_CLK_DISPLAY = 1;
        static const uint8_t PIN_DIO_DISPLAY = 3;
};

#endif