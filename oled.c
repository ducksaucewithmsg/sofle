#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM quack_logo[] = {
        // 'DUCK-FLIP', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 
        0x08, 0x10, 0x10, 0x60, 0xc0, 0xc0, 0x70, 0x08, 0x0c, 0x08, 0x90, 0xa0, 0x40, 0x80, 0x80, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xb0, 0x90, 0x88, 0x88, 0x48, 
        0x88, 0x88, 0x88, 0x08, 0x18, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x60, 0x20, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x20, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
        0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x7e, 0x80, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x80, 0x8c, 0x0c, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x77, 0x08, 0x00, 0x01, 0xfe, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x11, 0x90, 0xf0, 0x61, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0xf8, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x18, 0x06, 0x01, 0xc0, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x3f, 0x66, 0x22, 0x36, 0x1c, 0x18, 0x30, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x60, 0x3c, 0x36, 0x23, 0x67, 0x7c, 
        0x10, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0xf8, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0d, 0x08, 0x0c, 0x1f, 0x31, 0xc0, 
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x20, 0x10, 0x0c, 0x03, 0x01, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 
        0x00, 0x00, 0x40, 0xf0, 0x30, 0x20, 0x60, 0xe0, 0x30, 0x10, 0x08, 0x0c, 0x03, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x0f, 0x30, 0x20, 0x42, 0xbd, 0x20, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x60, 
        0xc0, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x2f, 0x10, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0x48, 0x46, 0x81, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x18, 0x20, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x09, 0x0f, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x06, 0x02, 0x01, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x08, 0x10, 0x20, 0x20, 0x40, 0xc0, 0x86, 
        0x8c, 0x88, 0x88, 0x90, 0x88, 0x88, 0x48, 0x6c, 0x10, 0x08, 0x04, 0x03, 0x01, 0x00, 0x00, 0x00
        };
    oled_write_raw_P(quack_logo, sizeof(bananas_logo));
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("quack"), false);
    oled_write_P(PSTR("sofle"), false);
    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("type"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("type"), false);
            break;
        default:
            oled_write_P(PSTR("fn\n"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("qwrt\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("left\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("right"), false);
            break;
        case 3:
            oled_write_P(PSTR("game\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("other"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("LOUD"), led_usb_state.caps_lock);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("num"), led_usb_state.num_lock);    
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
