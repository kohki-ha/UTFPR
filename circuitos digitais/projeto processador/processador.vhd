library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity processador is
	port(
		switches :  in std_logic_vector(9 downto 0);
		display0 : out std_logic_vector(6 downto 0);
		display1 : out std_logic_vector(6 downto 0);
		display2 : out std_logic_vector(6 downto 0);
		display3 : out std_logic_vector(6 downto 0);
		display4 : out std_logic_vector(6 downto 0);
		display5 : out std_logic_vector(6 downto 0)
	);
end entity processador;

architecture arq of processador is
	type men_t is array (0 to 15) of std_logic_vector(9 downto 0);
	signal mem : men_t := (
	"1010100010", "1101010010", "0010010111", "0110010110",
	"1000110011", "0001110101", "1111111111", "1101011010",
	"1001101011", "1100010100", "1011010011", "0110110111",
	"1100110110", "1101010111", "1111001100", "0110101111"
	);
	signal mem_endereco  : std_logic_vector(4 downto 0);
	signal mem_out       : std_logic_vector(9 downto 0);
	
	signal operar                 : std_logic_vector(4 downto 0);
	signal PC                     : std_logic_vector(4 downto 0);
	signal A                      : std_logic_vector(0 to 4);
	signal B                      : std_logic_vector(0 to 5);
	signal AA                     : std_logic_vector(5 downto 0);
	signal BB                     : std_logic_vector(5 downto 0);
	signal resultado_aritmetico   : std_logic_vector(5 downto 0);
	signal resultado_multiplicacao : std_logic_vector(11 downto 0);
	signal resultado_logico       : std_logic;
	signal Cout, Cin              : std_logic;
	
	shared variable resultado_fatorial  : integer := 1;	
	
	constant SOMA          : std_logic_vector(4 downto 0) := "00001";
	constant SUBTRACAO     : std_logic_vector(4 downto 0) := "00010";
	constant MULTIPLICACAO : std_logic_vector(4 downto 0) := "00011";
	constant DIVISAO       : std_logic_vector(4 downto 0) := "00100";
	constant MAIOR         : std_logic_vector(4 downto 0) := "00101";
	constant MENOR         : std_logic_vector(4 downto 0) := "00110";
	constant MAIOR_IGUAL   : std_logic_vector(4 downto 0) := "00111";
	constant MENOR_IGUAL   : std_logic_vector(4 downto 0) := "01000";
	constant IGUAL         : std_logic_vector(4 downto 0) := "01001";
	constant DIFERENTE     : std_logic_vector(4 downto 0) := "01010";
	constant JUMP          : std_logic_vector(4 downto 0) := "01011";
	constant MOV           : std_logic_vector(4 downto 0) := "01100";
	constant LOAD1         : std_logic_vector(4 downto 0) := "01101";
	constant LOAD2         : std_logic_vector(4 downto 0) := "01110";
	constant STORE1        : std_logic_vector(4 downto 0) := "01111";
	constant STORE2        : std_logic_vector(4 downto 0) := "10000";
	constant BEQ           : std_logic_vector(4 downto 0) := "10001";
	constant BGE           : std_logic_vector(4 downto 0) := "10010";
	constant BGT           : std_logic_vector(4 downto 0) := "10011";
	constant BLE           : std_logic_vector(4 downto 0) := "10100";
	constant BLT           : std_logic_vector(4 downto 0) := "10101";
	constant BNE           : std_logic_vector(4 downto 0) := "10110";
	constant BR            : std_logic_vector(4 downto 0) := "10111";
	constant fatorial      : std_logic_vector(4 downto 0) := "11000";

	
begin
	MEMORIA : process(switches, mem, mem_endereco, mem_out)
	begin
		mem_endereco <= switches(9 downto 5);
		mem_out <= mem(to_integer(unsigned(mem_endereco)));
	end process MEMORIA;

	OPERACAO : process(switches, mem_out, A, B, operar, resultado_aritmetico, resultado_logico)
	variable contador1           : integer := 1;
	variable contador2           : integer := 0;
	variable lock                : integer := 0;
	variable decimal_conv        : integer := 0;
	begin
		A <= mem_out(4 downto 0);
		B <= mem_out(9 downto 5);
		operar <= switches(4 downto 0);
		
		case operar is
			when SOMA =>
				PC <= operar;
				if A(0)='1' and B(0)='1' then
					resultado_aritmetico <= ("00" & A(4 downto 1)) + ("00" & B(4 downto 1));
					cout <= resultado_aritmetico(1);
					resultado_aritmetico(0) <= '1';
				end if;
				
				if A(0)='1' and B(0)='0' and A(4 downto 1) > B(4 downto 1) then
					resultado_aritmetico <= ("00" & A(4 downto 1)) - ("00" & B(4 downto 1));
					resultado_aritmetico(0) <= '1';
				end if;
				
				if A(0)='1' and B(0)='0' and A(4 downto 1) < B(4 downto 1) then
					resultado_aritmetico <= ("00" & B(4 downto 1)) - ("00" & A(4 downto 1));
					resultado_aritmetico(0) <= '0';
				end if;
				
				if A(0)='0' and B(0)='0' then
					resultado_aritmetico <= ("00" & A(4 downto 1)) + ("00" & B(4 downto 1));
					resultado_aritmetico(0) <= '0';
				end if;
				
			when SUBTRACAO =>
				PC <= operar;
				if A(0)='1' and B(0)='1' and A(4 downto 1) > B(4 downto 1) then						-- (a - b)
					resultado_aritmetico <= ("00" & A(4 downto 1)) - ("00" & B(4 downto 1));
					resultado_aritmetico(0) <= '1';
				end if;
				
				if A(0)='1' and B(0)='1' and A(4 downto 1) < B(4 downto 1) then						-- (a - b)
					resultado_aritmetico <= ("00" & B(4 downto 1)) - ("00" & A(4 downto 1));
					resultado_aritmetico(0) <= '0';
					cout <= resultado_aritmetico(1);
				end if;
				
				if A(0)='0' and B(0)='1' then																		-- ((-a) - b)
					resultado_aritmetico <= ("00" & A(4 downto 1)) + ("00" & B(4 downto 1));
					resultado_aritmetico(0) <= '0';
				end if;
				
				if A(0)='0' and B(0)='0' and A(4 downto 1) > B(4 downto 1) then						-- ((-a) - (-b))
					resultado_aritmetico <= ("00" & A(4 downto 1)) - ("00" & B(4 downto 1));
					resultado_aritmetico(0) <= '0';
				end if;
					
				if A(0)='0' and B(0)='0' and A(4 downto 1) < B(4 downto 1) then						-- ((-a) - (-b))
					resultado_aritmetico <= ("00" & A(4 downto 1)) - ("00" & B(4 downto 1));
					resultado_aritmetico(0) <= '1';
				end if;
				
				if A(0)='1' and B(0)='0' then																		-- (a - (-b))
					resultado_aritmetico <= ("00" & A(4 downto 1)) + ("00" & B(4 downto 1));
					cout <= resultado_aritmetico(1);
					resultado_aritmetico(0) <= '1';
				end if;
				
			when MULTIPLICACAO =>
				PC <= operar;
				AA <= ("00" & A(4 downto 1));
				BB <= ("00" & B(4 downto 1));
				resultado_multiplicacao <= std_logic_vector(unsigned(AA) * unsigned(BB));
				
			when DIVISAO =>
				PC <= operar;
				AA <= ("00" & A(4 downto 1));
				BB <= ("00" & B(4 downto 1));
				resultado_aritmetico <= std_logic_vector(unsigned(AA) / unsigned(BB));
				
			when MAIOR =>
				PC <= operar;
				if A > B then
					resultado_logico <= '1';
				else
					resultado_logico <= '0';
				end if;
				
			when MENOR =>
				PC <= operar;
				if A < B then
					resultado_logico <= '1';
				else
					resultado_logico <= '0';
				end if;
				
			when MAIOR_IGUAL =>
				PC <= operar;
				if A >= B then
					resultado_logico <= '1';
				else
					resultado_logico <= '0';
				end if;
				
			when MENOR_IGUAL =>
				PC <= operar;
				if A <= B then
					resultado_logico <= '1';
				else
					resultado_logico <= '0';
				end if;
				
			when IGUAL =>
				PC <= operar;
				if A = B then
					resultado_logico <= '1';
				else
					resultado_logico <= '0';
				end if;
				
			when DIFERENTE =>
				PC <= operar;
				if A /= B then
					resultado_logico <= '1';
				else
					resultado_logico <= '0';
				end if;
				
			when JUMP =>
				PC <= operar;
				mem_endereco <= switches(4 downto 0);
				mem_out <= mem(to_integer(unsigned(mem_endereco)));
			
			when MOV =>
				PC <= operar;
				A <= B;
			
			when LOAD1 =>
				PC <= operar;
				A <= mem_out(4 downto 0);
				
			when LOAD2 =>
				PC <= operar;
				B <= mem_out(9 downto 5);
			
			when STORE1 =>
				PC <= operar;
				mem(to_integer(unsigned(mem_endereco))) <= (A & "00000");
				
			when STORE2 =>
				PC <= operar;
				mem(to_integer(unsigned(mem_endereco))) <= ("00000" & B);
			
			when BEQ =>
				if A  = B then
					operar <= PC;
				else
					PC <= PC + "00100";
				end if;
			
			when BGE =>
				if A  >= B then
					operar <= PC;
				else
					PC <= PC + "00100";
				end if;
			
			when BGT =>
				if A  > B then
					operar <= PC;
				else
					PC <= PC + "00100";
				end if;
			
			when BLE =>
				if A  <= B then
					operar <= PC;
				else
					PC <= PC + "00100";
				end if;
			
			when BLT =>
				if A  < B then
					operar <= PC;
				else
					PC <= PC + "00100";
				end if;
			
			when BNE =>
				if A  /= B then
					operar <= PC;
				else
					PC <= PC + "00100";
				end if;
			
			when BR =>
				PC <= PC + "00100";
				
			when fatorial =>
			
				for contador1 in 4 downto 1 loop
					if lock = 0 and A(contador1) = '1' then
						decimal_conv := 1;
						lock := 1;
					end if;
					if A(contador1) = '0' and lock = 1 then
						decimal_conv := decimal_conv + decimal_conv;
					elsif lock = 1 then
						decimal_conv := decimal_conv + decimal_conv + 1;
					end if;
				end loop;
				
				--for contador2 in 1 to decimal_conv loop
				--	resultado_fatorial := resultado_fatorial * contador2;
				--end loop;
			
			when others =>
				resultado_multiplicacao <= "000000000000";
				resultado_aritmetico    <= "000000";
				resultado_logico        <= '0';
				resultado_fatorial      := 0;
			
		end case;
	end process OPERACAO;

	DECODIFICADOR : process(switches, resultado_aritmetico, resultado_logico)
	begin
		if operar /= "00000" and operar < "00011" then
			case resultado_int is
				when 
				
			end case;
		end if;
		
		if operar /= "00000" and operar = "00011" then
			case resultado_multiplicacao is
				
			end case;
		end if;
		
		if operar /= "00000" and operar = "00100" then
			case resultado_aritmetico is
				
			end case;
		end if;
		
		if operar /= "00000" and operar >= "00101" and operar <= "01010" then
			case resultado_logico is
				
			end case;
		end if;
		
		if operar = "00000" then
			display0 <="11111110";
			display1 <="00000000";
			display2 <="11111110";
			display3 <="00000000";
			display4 <="11111110";
			display5 <="00000000";

		end if;
	end process DECODIFICADOR;

end architecture arq;