    unsigned char LED_0F[] = 
    {// 0	 1	  2	   3	4	 5	  6	   7	8	 9	  A	   b	C    d	  E    F    -
    	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x8C,0xBF,0xC6,0xA1,0x86,0xFF,0xbf
    };
    unsigned char LED[4];
    int SCLK = 2;
    int RCLK = 1;
    int DIO = 0;
    void setup ()
    {
      pinMode(SCLK,OUTPUT);
      pinMode(RCLK,OUTPUT);
      pinMode(DIO,OUTPUT);
    }
    void loop()
    {
        LED[0]=1;
    	LED[1]=2;
    	LED[2]=3;
    	LED[3]=4;
    	while(1)
    	{
    		LED4_Display ();
    	} 
      
    }
    
    void LED4_Display (void)
    {
    	unsigned char *led_table;          // 查表指针
    	unsigned char i;
    	//显示第1位
    	led_table = LED_0F + LED[0];
    	i = *led_table;
    	LED_OUT(i);			
    	LED_OUT(0x01);		
        digitalWrite(RCLK,LOW);
        digitalWrite(RCLK,HIGH);
    	//显示第2位
    	led_table = LED_0F + LED[1];
    	i = *led_table;
    	LED_OUT(i);		
    	LED_OUT(0x02);		
        digitalWrite(RCLK,LOW);
        digitalWrite(RCLK,HIGH);
    	//显示第3位
    	led_table = LED_0F + LED[2];
    	i = *led_table;
    	LED_OUT(i);			
    	LED_OUT(0x04);	
        digitalWrite(RCLK,LOW);
        digitalWrite(RCLK,HIGH);
    	//显示第4位
    	led_table = LED_0F + LED[3];
    	i = *led_table;
    	LED_OUT(i);			
    	LED_OUT(0x08);		
        digitalWrite(RCLK,LOW);
        digitalWrite(RCLK,HIGH);
    }
    
    void LED_OUT(unsigned char X)
    {
    	unsigned char i;
    	for(i=8;i>=1;i--)
    	{
    		if (X&0x80) 
                {
                  digitalWrite(DIO,HIGH);
                 }  
                else 
                {
                  digitalWrite(DIO,LOW);
                }
    		X<<=1;
                digitalWrite(SCLK,LOW);
                digitalWrite(SCLK,HIGH);
    	}
    }
    

