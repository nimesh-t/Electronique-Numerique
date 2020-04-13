-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- PROGRAM		"Quartus II 64-Bit"
-- VERSION		"Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"
-- CREATED		"Mon Apr 13 12:25:57 2020"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY \3_Feux_cyclique\ IS 
	PORT
	(
		clock :  IN  STD_LOGIC;
		reset :  IN  STD_LOGIC;
		HEX0 :  OUT  STD_LOGIC_VECTOR(7 DOWNTO 0);
		HEX1 :  OUT  STD_LOGIC_VECTOR(7 DOWNTO 0);
		HEX2 :  OUT  STD_LOGIC_VECTOR(7 DOWNTO 0);
		HEX3 :  OUT  STD_LOGIC_VECTOR(7 DOWNTO 0);
		LEDS :  OUT  STD_LOGIC_VECTOR(9 DOWNTO 0)
	);
END \3_Feux_cyclique\;

ARCHITECTURE bdf_type OF \3_Feux_cyclique\ IS 

COMPONENT affichage_vehicules
	PORT(Vert_V : IN STD_LOGIC;
		 Orange_V : IN STD_LOGIC;
		 Rouge_V : IN STD_LOGIC;
		 Clock : IN STD_LOGIC;
		 Reset : IN STD_LOGIC;
		 LEDS : OUT STD_LOGIC_VECTOR(9 DOWNTO 0)
	);
END COMPONENT;

COMPONENT affichage_pietons
	PORT(Rouge_P : IN STD_LOGIC;
		 Vert_P : IN STD_LOGIC;
		 HEX0 : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		 HEX1 : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		 HEX2 : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		 HEX3 : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
	);
END COMPONENT;

COMPONENT divide_clk_by_50m
	PORT(clock : IN STD_LOGIC;
		 reset : IN STD_LOGIC;
		 clk_div_50M : OUT STD_LOGIC;
		 clk_div_5M : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	clk10 :  STD_LOGIC;
SIGNAL	Orange_V :  STD_LOGIC;
SIGNAL	Rouge_P :  STD_LOGIC;
SIGNAL	Rouge_V :  STD_LOGIC;
SIGNAL	Vert_P :  STD_LOGIC;
SIGNAL	Vert_V :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_19 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_20 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_21 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_6 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_22 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_23 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_24 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_25 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_26 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_27 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_28 :  STD_LOGIC;


BEGIN 
SYNTHESIZED_WIRE_19 <= '1';



PROCESS(SYNTHESIZED_WIRE_20,reset,SYNTHESIZED_WIRE_19)
VARIABLE synthesized_var_for_SYNTHESIZED_WIRE_21 : STD_LOGIC;
BEGIN
IF (reset = '0') THEN
	synthesized_var_for_SYNTHESIZED_WIRE_21 := '0';
ELSIF (SYNTHESIZED_WIRE_19 = '0') THEN
	synthesized_var_for_SYNTHESIZED_WIRE_21 := '1';
ELSIF (RISING_EDGE(SYNTHESIZED_WIRE_20)) THEN
	synthesized_var_for_SYNTHESIZED_WIRE_21 := (NOT(synthesized_var_for_SYNTHESIZED_WIRE_21) AND SYNTHESIZED_WIRE_19) OR (synthesized_var_for_SYNTHESIZED_WIRE_21 AND (NOT(SYNTHESIZED_WIRE_19)));
END IF;
	SYNTHESIZED_WIRE_21 <= synthesized_var_for_SYNTHESIZED_WIRE_21;
END PROCESS;


PROCESS(SYNTHESIZED_WIRE_20,reset,SYNTHESIZED_WIRE_19)
VARIABLE synthesized_var_for_SYNTHESIZED_WIRE_28 : STD_LOGIC;
BEGIN
IF (reset = '0') THEN
	synthesized_var_for_SYNTHESIZED_WIRE_28 := '0';
ELSIF (SYNTHESIZED_WIRE_19 = '0') THEN
	synthesized_var_for_SYNTHESIZED_WIRE_28 := '1';
ELSIF (RISING_EDGE(SYNTHESIZED_WIRE_20)) THEN
	synthesized_var_for_SYNTHESIZED_WIRE_28 := (NOT(synthesized_var_for_SYNTHESIZED_WIRE_28) AND SYNTHESIZED_WIRE_21) OR (synthesized_var_for_SYNTHESIZED_WIRE_28 AND (NOT(SYNTHESIZED_WIRE_21)));
END IF;
	SYNTHESIZED_WIRE_28 <= synthesized_var_for_SYNTHESIZED_WIRE_28;
END PROCESS;


Vert_P <= SYNTHESIZED_WIRE_6 OR SYNTHESIZED_WIRE_22;


Rouge_V <= SYNTHESIZED_WIRE_22 OR SYNTHESIZED_WIRE_23;


SYNTHESIZED_WIRE_22 <= SYNTHESIZED_WIRE_24 AND SYNTHESIZED_WIRE_25 AND SYNTHESIZED_WIRE_21;


Orange_V <= SYNTHESIZED_WIRE_24 AND SYNTHESIZED_WIRE_25 AND SYNTHESIZED_WIRE_26;



b2v_inst15 : affichage_vehicules
PORT MAP(Vert_V => Vert_V,
		 Orange_V => Orange_V,
		 Rouge_V => Rouge_V,
		 Clock => clk10,
		 Reset => reset,
		 LEDS => LEDS);


b2v_inst17 : affichage_pietons
PORT MAP(Rouge_P => Rouge_P,
		 Vert_P => Vert_P,
		 HEX0 => HEX0,
		 HEX1 => HEX1,
		 HEX2 => HEX2,
		 HEX3 => HEX3);


b2v_inst18 : divide_clk_by_50m
PORT MAP(clock => clock,
		 reset => reset,
		 clk_div_50M => SYNTHESIZED_WIRE_20,
		 clk_div_5M => clk10);


PROCESS(SYNTHESIZED_WIRE_20,reset,SYNTHESIZED_WIRE_19)
VARIABLE synthesized_var_for_SYNTHESIZED_WIRE_24 : STD_LOGIC;
BEGIN
IF (reset = '0') THEN
	synthesized_var_for_SYNTHESIZED_WIRE_24 := '0';
ELSIF (SYNTHESIZED_WIRE_19 = '0') THEN
	synthesized_var_for_SYNTHESIZED_WIRE_24 := '1';
ELSIF (RISING_EDGE(SYNTHESIZED_WIRE_20)) THEN
	synthesized_var_for_SYNTHESIZED_WIRE_24 := (NOT(synthesized_var_for_SYNTHESIZED_WIRE_24) AND SYNTHESIZED_WIRE_27) OR (synthesized_var_for_SYNTHESIZED_WIRE_24 AND (NOT(SYNTHESIZED_WIRE_27)));
END IF;
	SYNTHESIZED_WIRE_24 <= synthesized_var_for_SYNTHESIZED_WIRE_24;
END PROCESS;


SYNTHESIZED_WIRE_27 <= SYNTHESIZED_WIRE_21 AND SYNTHESIZED_WIRE_28;


SYNTHESIZED_WIRE_23 <= SYNTHESIZED_WIRE_24 AND SYNTHESIZED_WIRE_28;


SYNTHESIZED_WIRE_6 <= SYNTHESIZED_WIRE_23 AND SYNTHESIZED_WIRE_26;


SYNTHESIZED_WIRE_26 <= NOT(SYNTHESIZED_WIRE_21);



SYNTHESIZED_WIRE_25 <= NOT(SYNTHESIZED_WIRE_28);



Vert_V <= NOT(SYNTHESIZED_WIRE_24);



Rouge_P <= NOT(Vert_P);



END bdf_type;