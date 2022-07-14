library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;
use ieee.math_real.all;

entity painel_controle is
	port(
		switches           :  in std_logic_vector(1 downto 0);
		
		func_led_air_speed : out std_logic;
		func_led_height    : out std_logic;
		func_led_level     : out std_logic;
		
		alert_too_fast  : out std_logic;
		alert_too_slow  : out std_logic;
		alert_too_heigh : out std_logic;
		alert_too_low   : out std_logic;
		
		display1 : out std_logic_vector(6 downto 0);
		display2 : out std_logic_vector(6 downto 0);
		display3 : out std_logic_vector(6 downto 0);
		display4 : out std_logic_vector(6 downto 0)
	);
end entity painel_controle;

architecture arq of painel_controle is
	type estado is (estado_A, estado_B, estado_C, estado_D, estado_E);		-- A: inicial || B: velocidade || C: altitude || D: inclinação || E: saida
	
	signal proximo, atual: estado;
	signal velocidade  : std_logic_vector(8 downto 0);
	signal inclinacao  : std_logic_vector(6 downto 0);
	signal altitude  : std_logic_vector(12 downto 0);
	signal num_a   : std_logic_vector(8 downto 0) := "011001000";
	signal num_b   : std_logic_vector(8 downto 0) := "000000001";
	signal num_c   : std_logic_vector(8 downto 0) := "000000001";
	
	shared variable aux     : integer := 0;
	shared variable unidade : integer := 0;
	shared variable dezena  : integer := 0;
	shared variable centena : integer := 0;
	shared variable milhar  : integer := 0;
	
	shared variable rand_num : integer := 0;
	
begin
	process(switches, proximo)
	begin
		if switches = "00" then
			atual <= estado_A;
		elsif switches(0) = '1' or switches(1) = '1' then
			atual <= proximo;
		end if;
	end process;
	
	process(atual, switches)
		variable seed1, seed2 : positive;
		variable rand : real;
		variable range_rand : real;
	begin
		case(atual) is
			when estado_A =>		-- (00) inicial
				display1 <= "0000000";
				display2 <= "0000000";
				display3 <= "0000000";
				display4 <= "0000000";
				
				func_led_air_speed <= '0';
				func_led_height    <= '0';
				func_led_level     <= '0';
				
				alert_too_fast  <= '0';
				alert_too_slow  <= '0';
				alert_too_heigh <= '0';
				alert_too_low   <= '0';
				
				if switches = "01" then
					proximo <= estado_B;
				elsif switches = "11" then
					proximo <= estado_C;
				elsif switches = "10" then
					proximo <= estado_D;
				else
					proximo <= estado_A;
				end if;
				
			when estado_B =>		-- (01) velocidade
				func_led_air_speed <= '1';
				range_rand := 500.0;
				uniform(seed1, seed2, rand);
				rand_num := integer(rand * range_rand);
				velocidade <= std_logic_vector(to_unsigned(rand_num, velocidade'length));
				
				aux := to_integer(signed(velocidade));
				proximo <= estado_E;
				
			when estado_C =>		-- (11) altitude
				func_led_height    <= '1';
				range_rand := 5000.0;
				uniform(seed1, seed2, rand);
				rand_num := integer(rand * range_rand);
				altitude <= std_logic_vector(to_unsigned(rand_num, altitude'length));
				
				aux := to_integer(signed(altitude));
				proximo <= estado_E;
				
			when estado_D =>		-- (10) inclinação
				func_led_level     <= '1';
				range_rand := 100.0;
				uniform(seed1, seed2, rand);
				rand_num := integer(rand * range_rand);
				inclinacao <= std_logic_vector(to_unsigned(rand_num, inclinacao'length));
				if inclinacao > "1100100" then
					proximo <= estado_A;
				else
					aux := to_integer(signed(inclinacao));
					proximo <= estado_E;
				end if;
			
			when estado_E =>		-- saida
				if velocidade > "110010000" then		-- 400
					alert_too_fast  <= '1';
				end if;
				
				num_a <= "011001000";
				num_b <= "000000001" - ("000" & inclinacao);
				num_c <= std_logic_vector(unsigned(num_a) / unsigned(num_b));
				if inclinacao >= "0000000"  and velocidade < num_c then
					alert_too_slow  <= '1';
				end if;
				
				if altitude > ('0' & "101110111000") then
					alert_too_heigh <= '1';
				end if;
				
				if altitude < ("00000" & "11001000") and inclinacao < "000000" then
					alert_too_low   <= '0';
				end if;
				
				if aux <= 9 then
					aux := aux - 1;
					unidade := unidade + 1;
				elsif aux <= 99 then
					aux := aux - 10;
					dezena := dezena + 1;
				elsif aux <= 999 then
					aux := aux - 100;
					centena := centena + 1;
				elsif aux <= 9999 then
					aux := aux - 1000;
					milhar := milhar + 1;
				end if;
					
				case unidade is
					when 0 =>
						display1 <= "11111100";
					when 1 =>
						display1 <= "01100000";
					when 2 =>
						display1 <= "11011010";
					when 3 =>
						display1 <= "11110010";
					when 4 =>
						display1 <= "01100110";
					when 5 =>
						display1 <= "10110110";
					when 6 =>
						display1 <= "10111110";
					when 7 =>
						display1 <= "11100000";
					when 8 =>
						display1 <= "11111110";
					when 9 =>
						display1 <= "11110110";
					when others =>
						display1 <= "00000000";
				end case;
					
				case dezena is
					when 0 =>
						display2 <= "11111101";
					when 1 =>
						display2 <= "01100001";
					when 2 =>
						display2 <= "11011011";
					when 3 =>
						display2 <= "11110011";
					when 4 =>
						display2 <= "01100111";
					when 5 =>
						display2 <= "10110111";
					when 6 =>
						display2 <= "10111111";
					when 7 =>
						display2 <= "11100001";
					when 8 =>
						display2 <= "11111111";
					when 9 =>
						display2 <= "11110111";
					when others =>
						display2 <= "00000001";
				end case;
					
				case centena is
					when 0 =>
						display3 <= "11111101";
					when 1 =>
						display3 <= "01100001";
					when 2 =>
						display3 <= "11011011";
					when 3 =>
						display3 <= "11110011";
					when 4 =>
						display3 <= "01100111";
					when 5 =>
						display3 <= "10110111";
					when 6 =>
						display3 <= "10111111";
					when 7 =>
						display3 <= "11100001";
					when 8 =>
						display3 <= "11111111";
					when 9 =>
						display3 <= "11110111";
					when others =>
						display3 <= "00000001";
				end case;
					
				case milhar is
					when 0 =>
						display4 <= "11111101";
					when 1 =>
						display4 <= "01100001";
					when 2 =>
						display4 <= "11011011";
					when 3 =>
						display4 <= "11110011";
					when 4 =>
						display4 <= "01100111";
					when 5 =>
						display4 <= "10110111";
					when 6 =>
						display4 <= "10111111";
					when 7 =>
						display4 <= "11100001";
					when 8 =>
						display4 <= "11111111";
					when 9 =>
						display4 <= "11110111";
					when others =>
						display4 <= "00000001";
				end case;
			
			when others =>
				proximo <= estado_A;
				
		end case;
				
	end process;

end architecture arq;