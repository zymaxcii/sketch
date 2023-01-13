EESchema Schematic File Version 4
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
$Comp
L Device:LED D1
U 1 1 63BBC307
P 6550 1750
F 0 "D1" V 6588 1633 50  0000 R CNN
F 1 "LED 2V" V 6497 1633 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 6550 1750 50  0001 C CNN
F 3 "~" H 6550 1750 50  0001 C CNN
	1    6550 1750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 63BBC3D9
P 6550 2600
F 0 "R1" H 6620 2646 50  0000 L CNN
F 1 "330" H 6620 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6480 2600 50  0001 C CNN
F 3 "~" H 6550 2600 50  0001 C CNN
	1    6550 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 63BBC578
P 5350 2150
F 0 "BT1" H 5458 2196 50  0000 L CNN
F 1 "5V" H 5458 2105 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" V 5350 2210 50  0001 C CNN
F 3 "~" V 5350 2210 50  0001 C CNN
	1    5350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1900 6550 2450
Wire Wire Line
	5350 1950 5350 1350
Wire Wire Line
	5350 1350 6550 1350
Wire Wire Line
	6550 1350 6550 1600
Wire Wire Line
	5350 2350 5350 2900
Wire Wire Line
	5350 2900 6550 2900
Wire Wire Line
	6550 2900 6550 2750
$EndSCHEMATC
