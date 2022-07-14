use library library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity refri is
    port(
        rst : in std_logic;
        clk : in std_logic;
        
        MOEDA : in std_logic(1 downto 0);
        moeda_in : in std_logic;
        moeda_retirada : in std_logic;
        produto_retirado : in std_logic_vector (3 downto 0);

        moeda_bandeija: out std_logic;
        produto_bandeija : out std_logic_vector (3 downto 0)
    );
    end entity refri;

architecture arq of refri is
    constant preco_agua : unsigned(3 downto 0) = "0110";  -- 6 moedas de 25
    constant preco_refri : unsigned(3 downto 0) = "1100";  -- 12 moedas de 25
    constant preco_slagadinho : unsigned(3 downto 0) = "1110";  -- 14 moedas de 25
    constant preco_chocolate : unsigned(3 downto 0) = "1111";  -- 15 moedas de 25
    constant preco_chocolate : unsigned(3 downto 0) = "1111";
    constant rst_valor : std_logic := '1';

    -- sinal decodificador moeda
    signal decodificador_out : std_logic_vector(2 downto 0);

    -- sinal somador
    signal somador_out, A_somador_in, B_somador_in : unsigned(3 downto 0);
    signal soma : in std_logic;

    -- sinal contador
    signal Q_contador_out, D_contador_in : unsigned(3 downto 0);
    signal load_contador, decrementar_contador, limpar_contador : std_logic;

    -- sinal comparador
    signal soma_maior, soma_igual, soma_menor

    -- sinal maquina de estado
    type state_type is (IDLE, S1, S2, S3, S4, S5, S6);
    signal estado, proximo_estado : tipo_estado;

begin
    -- componentes externos combinacionais e comportamento
    --- Decodificador de moeda
    decodificador_out <= "0001" when MOEDA="00" else  -- 25c
                         "0010" when MOEDA="01" else  -- 50c
                         "0100" when MOEDA="10" else  -- 1r
                         "0001";
    
    --- Comparador
    soma_igual <= '1' when Q_contador_out = preco_refri else '0';
    soma_maior <= '1' when Q_contador_out > preco_refri else '0';
    soma_menor <= '1' when Q_contador_out < preco_refri else '0';
    

    --- Somador
    A_somador_in <= decodificador_out;
    B_somador_in <= Q_contador_out;
    SOMADOR: process(clk)
        variable saida : unsigned(3 downto 0);
    begin
        if rising_edge(clk) then
            if rst = rst_valor then
                saida := (othres=>'0')
            else
                if soma = '1' then
                    S := A_somador_in + B_somador_in;
                else
                    saida := saida;
                end if;
            end if;
        end if;
    end process SOMADOR;

    --- Contador
    D_contador_in <= s_somador;
    CONTADOR: process(clk)
        variable Q : unsigned(3 downto 0);
    begin
        if rising_edge(clk) then
            if rst = rst_valor then
                Q := (others => '0');
            else
                if load_contador = '1' then
                    Q := D_contador_in;
                elsif decrementar_contador = '1' then
                    Q := Q - 1;
                else
                    Q := Q;
                end if;
                Q_contador_out <= Q;
            end if;
        end if;
    end process CONTADOR;

    -- Maquina
   SINCRONIA: process(clk)
   begin
    if rising_edge(clk) then
        if rst = rst_val then
            estado <= IDLE;
        else
            estado <= proximo_estado;
        end if;
    end if;
   end process SINCRONIA;

  DECODIFICADOR_ESTADO_OUTPUT: process(clk)
  begin
    if rising_edge(clk) then
        if rst = rst_val then
            moeda_bandeija <= '0';
            produto_bandeija <= '0';

            limpar_contador <= '0';
            decrementar_contador <= '0';
            load_contador <= '0';
            soma <= '0';
        else
            case estado is
                when IDLE =>
                when S1 =>
                when S2 =>
                when S3 =>
                when S4 =>
                when S5 =>
                when S6 =>
                    
            
                when others =>
                    
            
            end case;
        end if;
    end if;
  end process DECODIFICADOR_ESTADO_OUTPUT;



end architecture arq;
