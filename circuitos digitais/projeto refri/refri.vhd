library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity processador is
	port(
		switches : in std_logic_vector(9 downto 0);
		display1 : out std_logic_vector(6 downto 0);
		display2 : out std_logic_vector(6 downto 0);
		display3 : out std_logic_vector(6 downto 0);
		display4 : out std_logic_vector(6 downto 0);
		display5 : out std_logic_vector(6 downto 0);
		display6 : out std_logic_vector(6 downto 0)
	);
end entity processador;

architecture arq of processador is
	signal operacao : std_logic_vector(4 downto 0);
	signal resultado_aritmetico : std_logic_vector(4 downto 0);
	signal resultado_logico : std_logic;
	
	constant SOMA          : std_logic_vector(4 downto 0);
	constant SUBTRACAO     : std_logic_vector(4 downto 0);
	constant MULTIPLICACAO : std_logic_vector(4 downto 0);
	constant DIVISAO       : std_logic_vector(4 downto 0);
	constant MAIOR         : std_logic_vector(4 downto 0);
	constant MENOR         : std_logic_vector(4 downto 0);
	constant MAIOR_IGUAL   : std_logic_vector(4 downto 0);
	constant MENOR_IGUAL   : std_logic_vector(4 downto 0);
	constant IGUAL         : std_logic_vector(4 downto 0);
	constant DIFERENTE     : std_logic_vector(4 downto 0);
	constant JUMP          : std_logic_vector(4 downto 0);
	constant MOV           : std_logic_vector(4 downto 0);
	constant LOAD          : std_logic_vector(4 downto 0);
	constant STORE         : std_logic_vector(4 downto 0);
	constant BEQ           : std_logic_vector(4 downto 0);
	constant BGE           : std_logic_vector(4 downto 0);
	constant BGT           : std_logic_vector(4 downto 0);
	constant BLE           : std_logic_vector(4 downto 0);
	constant BLT           : std_logic_vector(4 downto 0);
	constant BNE           : std_logic_vector(4 downto 0);
	constant BR            : std_logic_vector(4 downto 0);

	
begin
			
OPERACAO : process(switcjes, rst)
end process OPERACAO;

MEMORIA : process()
end process MAMORIA;

DECODIFICADOR : process()
end process DECODIFICADOR;

end architecture arq;