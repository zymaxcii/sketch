EESchema Schematic File Version 4
LIBS:555-blinker-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -150 3050 -50 
Entry Bus Bus
	2950 -50  3050 50  
Entry Bus Bus
	2950 50   3050 150 
$Comp
L Timer:LM555 U1
U 1 1 63BE61EF
P 5400 2850
F 0 "U1" H 5250 3450 50  0000 C CNN
F 1 "LM555" H 5250 3350 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 5400 2850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm555.pdf" H 5400 2850 50  0001 C CNN
	1    5400 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 63BE62D2
P 4100 2400
F 0 "R1" H 4170 2446 50  0000 L CNN
F 1 "100K" H 4170 2355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4030 2400 50  0001 C CNN
F 3 "~" H 4100 2400 50  0001 C CNN
	1    4100 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 63BE6306
P 4100 3000
F 0 "R2" H 4170 3046 50  0000 L CNN
F 1 "100K" H 4170 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4030 3000 50  0001 C CNN
F 3 "~" H 4100 3000 50  0001 C CNN
	1    4100 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 63BE6330
P 6600 1950
F 0 "R3" H 6670 1996 50  0000 L CNN
F 1 "330" H 6670 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6530 1950 50  0001 C CNN
F 3 "~" H 6600 1950 50  0001 C CNN
	1    6600 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 63BE634C
P 6600 2950
F 0 "R4" H 6670 2996 50  0000 L CNN
F 1 "330" H 6670 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6530 2950 50  0001 C CNN
F 3 "~" H 6600 2950 50  0001 C CNN
	1    6600 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 63BE6677
P 6600 3300
F 0 "D2" V 6638 3183 50  0000 R CNN
F 1 "LED" V 6547 3183 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 6600 3300 50  0001 C CNN
F 3 "~" H 6600 3300 50  0001 C CNN
	1    6600 3300
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 63BE6718
P 6600 2350
F 0 "D1" V 6638 2233 50  0000 R CNN
F 1 "LED" V 6547 2233 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 6600 2350 50  0001 C CNN
F 3 "~" H 6600 2350 50  0001 C CNN
	1    6600 2350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 63BE6ABC
P 4100 2100
F 0 "#PWR0101" H 4100 1950 50  0001 C CNN
F 1 "VCC" H 4117 2273 50  0000 C CNN
F 2 "" H 4100 2100 50  0001 C CNN
F 3 "" H 4100 2100 50  0001 C CNN
	1    4100 2100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 63BE6B52
P 5400 2150
F 0 "#PWR0102" H 5400 2000 50  0001 C CNN
F 1 "VCC" H 5417 2323 50  0000 C CNN
F 2 "" H 5400 2150 50  0001 C CNN
F 3 "" H 5400 2150 50  0001 C CNN
	1    5400 2150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 63BE6B6B
P 4750 2200
F 0 "#PWR0103" H 4750 2050 50  0001 C CNN
F 1 "VCC" H 4767 2373 50  0000 C CNN
F 2 "" H 4750 2200 50  0001 C CNN
F 3 "" H 4750 2200 50  0001 C CNN
	1    4750 2200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0104
U 1 1 63BE6B84
P 6600 1600
F 0 "#PWR0104" H 6600 1450 50  0001 C CNN
F 1 "VCC" H 6617 1773 50  0000 C CNN
F 2 "" H 6600 1600 50  0001 C CNN
F 3 "" H 6600 1600 50  0001 C CNN
	1    6600 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 63BE6B9D
P 5400 3650
F 0 "#PWR0105" H 5400 3400 50  0001 C CNN
F 1 "GND" H 5405 3477 50  0000 C CNN
F 2 "" H 5400 3650 50  0001 C CNN
F 3 "" H 5400 3650 50  0001 C CNN
	1    5400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 63BE6BB6
P 6600 3650
F 0 "#PWR0106" H 6600 3400 50  0001 C CNN
F 1 "GND" H 6605 3477 50  0000 C CNN
F 2 "" H 6600 3650 50  0001 C CNN
F 3 "" H 6600 3650 50  0001 C CNN
	1    6600 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2100 4100 2250
Wire Wire Line
	5900 2850 6150 2850
Wire Wire Line
	6150 2850 6150 3400
Wire Wire Line
	6150 3400 4100 3400
Wire Wire Line
	4100 3400 4100 3150
Wire Wire Line
	5900 3050 6000 3050
Wire Wire Line
	6000 3050 6000 3300
Wire Wire Line
	6600 1600 6600 1800
Wire Wire Line
	6600 2100 6600 2200
Wire Wire Line
	6600 2500 6600 2650
Wire Wire Line
	6600 3100 6600 3150
Wire Wire Line
	6600 3450 6600 3650
Wire Wire Line
	5900 2650 6600 2650
Connection ~ 6600 2650
Wire Wire Line
	6600 2650 6600 2800
Wire Wire Line
	5400 3250 5400 3650
Wire Wire Line
	4900 2650 4600 2650
Wire Wire Line
	4600 2650 4600 3300
Wire Wire Line
	4100 2550 4100 2650
Wire Wire Line
	6000 3300 4600 3300
Wire Wire Line
	4600 2650 4100 2650
Connection ~ 4600 2650
Connection ~ 4100 2650
Wire Wire Line
	4100 2650 4100 2850
Wire Wire Line
	4750 2200 4750 3050
Wire Wire Line
	4750 3050 4900 3050
NoConn ~ 4900 2850
Wire Wire Line
	5400 2150 5400 2450
$Comp
L Device:Battery_Cell BT1
U 1 1 63BE9A9C
P 7450 2700
F 0 "BT1" H 7568 2796 50  0000 L CNN
F 1 "Battery_Cell" H 7568 2705 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" V 7450 2760 50  0001 C CNN
F 3 "~" V 7450 2760 50  0001 C CNN
	1    7450 2700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0107
U 1 1 63BE9AE4
P 7450 2300
F 0 "#PWR0107" H 7450 2150 50  0001 C CNN
F 1 "VCC" H 7467 2473 50  0000 C CNN
F 2 "" H 7450 2300 50  0001 C CNN
F 3 "" H 7450 2300 50  0001 C CNN
	1    7450 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 63BE9AFF
P 7450 3000
F 0 "#PWR0108" H 7450 2750 50  0001 C CNN
F 1 "GND" H 7455 2827 50  0000 C CNN
F 2 "" H 7450 3000 50  0001 C CNN
F 3 "" H 7450 3000 50  0001 C CNN
	1    7450 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2800 7450 2900
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 63BEAC9D
P 7900 2350
F 0 "#FLG0101" H 7900 2425 50  0001 C CNN
F 1 "PWR_FLAG" V 7900 2478 50  0000 L CNN
F 2 "" H 7900 2350 50  0001 C CNN
F 3 "~" H 7900 2350 50  0001 C CNN
	1    7900 2350
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 63BEB302
P 7900 2900
F 0 "#FLG0102" H 7900 2975 50  0001 C CNN
F 1 "PWR_FLAG" V 7900 3028 50  0000 L CNN
F 2 "" H 7900 2900 50  0001 C CNN
F 3 "~" H 7900 2900 50  0001 C CNN
	1    7900 2900
	0    1    1    0   
$EndComp
Wire Wire Line
	7900 2350 7450 2350
Wire Wire Line
	7450 2300 7450 2350
Connection ~ 7450 2350
Wire Wire Line
	7450 2350 7450 2500
Wire Wire Line
	7900 2900 7450 2900
Connection ~ 7450 2900
Wire Wire Line
	7450 2900 7450 3000
$EndSCHEMATC
