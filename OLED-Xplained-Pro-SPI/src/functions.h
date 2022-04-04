
// Função LEDS INIT:
void led_init(void){
	// Configurando LED1 OLED:
	pmc_enable_periph_clk(LED1_PIO_ID);
	pio_configure(LED1_PIO, PIO_OUTPUT_0, LED1_PIO_IDX_MASK, PIO_DEFAULT);
	// Configurando LED2 OLED:
	pmc_enable_periph_clk(LED2_PIO_ID);
	pio_configure(LED2_PIO, PIO_OUTPUT_0, LED2_PIO_IDX_MASK, PIO_DEFAULT);
	// Configurando LED3 OLED:
	pmc_enable_periph_clk(LED3_PIO_ID);
	pio_configure(LED3_PIO, PIO_OUTPUT_0, LED3_PIO_IDX_MASK, PIO_DEFAULT);
	// Configurando LED placa:
	pmc_enable_periph_clk(LED_PIO_ID);
	pio_configure(LED_PIO, PIO_OUTPUT_0, LED_PIO_IDX_MASK, PIO_DEFAULT);
	// Configurando botão 1 OLED:
	pmc_enable_periph_clk(BUT1_PIO_ID);
	pio_configure(BUT1_PIO, PIO_INPUT, BUT1_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUT1_PIO, BUT1_PIO_IDX_MASK, 60);
	pio_handler_set(BUT1_PIO,BUT1_PIO_ID,	BUT1_PIO_IDX_MASK,PIO_IT_EDGE,but1_callback);
	pio_enable_interrupt(BUT1_PIO, BUT1_PIO_IDX_MASK);
	pio_get_interrupt_status(BUT1_PIO);
	NVIC_EnableIRQ(BUT1_PIO_ID);
	NVIC_SetPriority(BUT1_PIO_ID, 4);
	// Configurando botão 2 OLED:
	pmc_enable_periph_clk(BUT2_PIO_ID);
	pio_configure(BUT2_PIO, PIO_INPUT, BUT2_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUT2_PIO, BUT2_PIO_IDX_MASK, 60);
	pio_handler_set(BUT2_PIO,BUT2_PIO_ID,	BUT2_PIO_IDX_MASK,PIO_IT_EDGE,but2_callback);
	pio_enable_interrupt(BUT2_PIO, BUT2_PIO_IDX_MASK);
	pio_get_interrupt_status(BUT2_PIO);
	NVIC_EnableIRQ(BUT2_PIO_ID);
	NVIC_SetPriority(BUT2_PIO_ID, 4);
	// Configurando botão 3 OLED:
	pmc_enable_periph_clk(BUT3_PIO_ID);
	pio_configure(BUT3_PIO, PIO_INPUT, BUT3_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUT3_PIO, BUT3_PIO_IDX_MASK, 60);
	pio_handler_set(BUT3_PIO,BUT3_PIO_ID,	BUT3_PIO_IDX_MASK,PIO_IT_EDGE,but3_callback);
	pio_enable_interrupt(BUT3_PIO, BUT3_PIO_IDX_MASK);
	pio_get_interrupt_status(BUT3_PIO);
	NVIC_EnableIRQ(BUT3_PIO_ID);
	NVIC_SetPriority(BUT3_PIO_ID, 4);
	// Configurando botão placa:
	pmc_enable_periph_clk(BUT_PIO_ID);
	pio_configure(BUT_PIO, PIO_INPUT, BUT_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUT_PIO, BUT_IDX_MASK, 60);
	pio_handler_set(BUT_PIO,BUT_PIO_ID,	BUT_IDX_MASK,PIO_IT_EDGE,but_callback);
	pio_enable_interrupt(BUT_PIO, BUT_IDX_MASK);
	pio_get_interrupt_status(BUT_PIO);
	NVIC_EnableIRQ(BUT_PIO_ID);
	NVIC_SetPriority(BUT_PIO_ID, 4);
}

// Função but callback OLED1:
void but1_callback(void)
{
	if (!pio_get(BUT1_PIO, PIO_INPUT,BUT1_PIO_IDX_MASK)){
		but1_flag = 1;
		} else{
		but1_flag = 0;
	}
	
}

// Função but callback OLED2:
void but2_callback(void)
{
	if (pio_get(BUT2_PIO, PIO_INPUT,BUT2_PIO_IDX_MASK)){
		but2_flag = 1;
		} else{
		but2_flag = 0;
	}
	
}

// Função but callback OLED3:
void but3_callback(void)
{
	if (pio_get(BUT3_PIO, PIO_INPUT,BUT3_PIO_IDX_MASK)){
		but3_flag = 1;
		} else{
		but3_flag = 0;
	}
	
}

// Função but callback placa:
void but_callback(void)
{
	if (pio_get(BUT_PIO, PIO_INPUT,BUT_IDX_MASK)){
		but_flag = 1;
		} else{
		but_flag = 0;
	}
}

// Função pisca LED
